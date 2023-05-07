library(data.table)
library(ggplot2)
library(magrittr)
# 
#' measure raw value leading to wheel positions following the Ackerman geometry
#' measurement followed steps of 5 units of increment
#' The left wheel had 5 increment and the right wheel was being adapted up until the center, 
#' while the right wheel accented in five increment for the right side.
# 

ratios <- fread("
L R
0 5
5 11
10  13
15  19
20  22
25  25
30  28
35  34
40  37
45  41
50  50
54  55
64  65
67  70
70  75
73  80
75  85
78  90
80  95
84  100
")

#' Compute the mean raw value between the left and right actuator
ratios[, mean := (L + R)/2]

#' Remove the center value from the computed mean. 
ratios[, angle := mean - 50]

#' data exploratory compute the halved difference between L and R raw value
ratios[, diff := (L-R) / 2]

#' maintain half the samples and the center (10 step increments)
ratios[, id := 1:.N]
ratios[, keep := (id %% 2 == 0 | mean == 50) ]

# ratios <- ratios[keep == TRUE]

#' separate the associations in three vectors

inputValue <- ratios[keep == TRUE, angle]
outputLeft <- ratios[keep == TRUE, L]
outputRight <- ratios[keep == TRUE, R]

#' convert the association in c++ arrays

paste0("float inputValue[", length(inputValue), "] = {", paste(inputValue, collapse = ", " ), "};")
paste0("int outputLeft[", length(inputValue),"] = {", paste(outputLeft, collapse = ", " ), "};")
paste0("int outputRight[", length(inputValue),"] = {", paste(outputRight, collapse = ", " ), "};")

######

# float inputValue[11] = {-42, -33, -25, -15.5, -7, 0, 4.5, 18.5, 26.5, 34, 42};
# int outputLeft[11] = {5, 15, 25, 35, 45, 50, 54, 67, 73, 78, 84};
# int outputRight[11] = {11, 19, 25, 34, 41, 50, 55, 70, 80, 90, 100};
 
"
ratios
     L   R id mean angle diff
 1:  5  11  2  8.0 -42.0 -3.0
 2: 15  19  4 17.0 -33.0 -2.0
 3: 25  25  6 25.0 -25.0  0.0
 4: 35  34  8 34.5 -15.5  0.5
 5: 45  41 10 43.0  -7.0  2.0
 6: 50  50 11 50.0   0.0  0.0
 7: 54  55 12 54.5   4.5 -0.5
 8: 67  70 14 68.5  18.5 -1.5
 9: 73  80 16 76.5  26.5 -3.5
10: 78  90 18 84.0  34.0 -6.0
11: 84 100 20 92.0  42.0 -8.0

" %>% invisible

#' Angle to left 
ggplot(ratios, aes(angle, L, color= keep)) + 
  geom_point() + geom_line() + theme_minimal()

#' Angle to Right
ggplot(ratios, aes(angle, R, color= keep)) + 
  geom_point() + geom_line()+ theme_minimal()

#' Angle to Right
ggplot(ratios, aes(L, R, color= keep)) + 
  geom_point() + geom_line()+ theme_minimal()

melt(ratios[keep == T, .(angle, L, R)], id.var = "angle") %>%
  ggplot(aes(angle, value, color = variable)) +
    geom_vline(xintercept = 0) + 
    geom_point() + geom_line() + theme_minimal()  



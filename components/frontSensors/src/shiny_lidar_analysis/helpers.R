# @Author: Petros Morfiris, Konstantinos L. Papageorgiou - Agrofelis 2023

trim_filename <- function(filename)
  gsub("data\\.(.*)\\.log.*", "\\1", filename) %>%
    gsub("--", "-", .)

move_file <- function(filename, datapath) {

  data_dir <- "data/lidar/"

  trimmed_filename <- trim_filename(filename)

  file_dir <- paste0(data_dir, trimmed_filename, "/")
  dir.create(file_dir)

  new_filepath <- paste0(file_dir, filename)
  file.copy(datapath, new_filepath)

  untar(new_filepath, exdir = file_dir)

  list(
    log_path = paste0(file_dir, "data/archive/lidar.log"),
    data_path = file_dir
  )
}

shape_dataset <- function(log_path, data_path) {

  dat <- data.table(x = readLines(log_path))

  empty_lines <- which(dat$x == "")

  split_lines <- lapply(seq_along(empty_lines), function(i) {
    c(if(i == 1) 1 else empty_lines[i - 1] + 1, empty_lines[i] - 1)
  })

  deg_vs_dist <- lapply(seq_along(split_lines), function(chunk) {

    tilt_servo_dat <- dat[split_lines[[chunk]][1]:split_lines[[chunk]][2]]
    tilt_servo_dat[1, x := gsub("<.*>", "", x)]
    tilt_servo_dat[, x := gsub("\\[|\\]", "", x)]

    deg_vs_dist <- lapply(seq_len(nrow(tilt_servo_dat)), function(i) {

      res <- tilt_servo_dat[i, x] %>%
        tstrsplit("\\|") %>%
        tstrsplit(",")

      data.table(
        degrees = as.double(res[[1]]),
        distance = as.double(res[[2]]),
        chunk = chunk
      )
    }) %>% rbindlist

  }) %>% rbindlist

  setorder(deg_vs_dist, "chunk", "degrees")

  fwrite(deg_vs_dist, paste0(data_path, "/deg_vs_dist.csv"))

}

plot_lidar <- function(dat, use_plot_line) {

  vis_dat <- copy(dat)

  setnames(vis_dat, c(1,2), c("x", "y"))

  ggplot(vis_dat, aes(x = x, y = y)) +
    geom_point(alpha = 0.2, colour = "#2fa4e7") +
    xlim(c(0.01, 360)) +
    ylim(0, vis_dat[, max(y)]) +
    labs(x = "Degrees", y = "Distance") +
    theme_minimal() + {
      if(use_plot_line)
        geom_smooth(color = "#2fa4e7", span = 0.25, se = FALSE, fullrange = TRUE, alpha = 0.2)
    }
}

svg_plot <- function(gg) {
  ss <- svgstring(width = 6, height = 5)
  print(gg)
  dev.off()
  HTML(ss())
}

get_dirnames <- function() {
  list.files("data/lidar")
}

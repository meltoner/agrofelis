This folder accommodates the development of a networking server running on docker 
upon which all modules are connected to broadcast their data and receive their commands. 
The server uses the Serial interface the HTTP and the web sockets interfaces and is able to 
record, route, and broadcast the combined information to recipients of interest.


Consider node js, which appears to be more suitable for the job.
- https://gist.github.com/gabonator/3fae3e455c9d7518af71

- https://snyk.io/blog/choosing-the-best-node-js-docker-image/
- https://snyk.io/blog/10-best-practices-to-containerize-nodejs-web-applications-with-docker/

node:16.17.0-bullseye-slim.






# obsolete. 
The server is implemented in the R language and makes use of the following libraries.

https://github.com/rstudio/httpuv
https://www.losant.com/blog/how-to-access-serial-devices-in-docker
https://cran.r-project.org/web/packages/serial/index.html
https://www.rdocumentation.org/packages/serial/versions/3.0/topics/serial

https://github.com/me-no-dev/ESPAsyncWebServer/issues/23

https://github.com/hallard/WebSocketToSerial


library(serial)

con <- serialConnection(
	name = "amega",port = "ttyACM0",
    mode = "9600,n,8,1",
 
    translation = "crlf"
)
open(con)

write.serialConnection(con, "<15, 1>") 
write.serialConnection(con, "<16, 0>") 

write.serialConnection(con, "<16, 100>") 
while(T)
	if((message = read.serialConnection(con))!="")
		print(message)

summary(con)
close(con)

 

This folder accommodates the development of a networking server running on docker 
upon which all modules are connected to broadcast their data and receive their commands. 
The server uses the Serial interface the HTTP and the web sockets interfaces and is able to 
record, route, and broadcast the combined information to recipients of interest.


Agrofelis unificator. The node js software server unifies all modules coming from usb / serial and wifi. There are two usb modules the software integrates the arduino mega running the linear steer module controlling the brakes and the steering of the vehicle and the Front sensors module controlling the lidar data and its tilt mechanism.
The unficator software moreover integrates modules via wifi and the http protocol employing in the two wifi power relay modules as via websockets the two dual motor hub driver modules.
The unificator software is responsible for routing appropriately the data across the different modules as well as records and rotates the data received from all modules.

The application will rotate and compress the lidar and module data and maintain the last 50 compressed data logs corresponding to approximately 50 minutes and 125 mb of data.


Using node js, which appears to be more suitable for the job.


- https://gist.github.com/gabonator/3fae3e455c9d7518af71
- https://snyk.io/blog/choosing-the-best-node-js-docker-image/
- https://snyk.io/blog/10-best-practices-to-containerize-nodejs-web-applications-with-docker/


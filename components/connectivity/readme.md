# Infrastructure provisioning, computing elements and data fusion

## Abstract

The document presents the procedure to provision the main computing element of the robot and initiate its services. The peripheral elements establishing and attaching to the local Agrofelis WIFI network and its USB hub are enumerated. The GPU component and the neural network accelerator tapping to the USB3 interface of the Jetson Nano are presented. The Agrofelis Unificator software, connecting all Agrofelis modules is introduced and its source code and features presented. Lightweight structural elements 3d printed to compensate for the additional space needed by the USB cables as well as designed to secure the components and the USB hub in their compartment, are provided. The document concludes with a list of the components used and indicative suppliers, aiding the replication of the of the Agrofelis computing systems.

## Introduction


## Jetson nano operating system provisioning

The main computing element of the Agrofelis Robot is a relatively low cost fully fledged GPU capable computer, optimised for small footprint, energy consumption aimed for AI applications. 


To initialise the computer one needs the same components needed for a regular computer. That is keyboard a mouse, a monitor and a hard disk (sd). An operating system can be written to the sd card by using a turnkey Ubuntu based image configured by Nvidia conveniently having installed most of the needed software. The official [getting started document](https://developer.nvidia.com/embedded/learn/get-started-jetson-nano-2gb-devkit) can be followed to get acquainted with embedded computer and boot-strap it. 

Following NVdia's documentation the 6.4 GB compressed operating system image, can be downloaded from the following link.

- [https://developer.nvidia.com/jetson-nano-2gb-sd-card-image](https://developer.nvidia.com/jetson-nano-2gb-sd-card-image)

Because the file is rather large, we recommend downloading it from a fast, stable internet connection. To write the image to the sd card, a windows or a Linux computer can be utilised with the [balenaEtcher](https://etcher.balena.io/#download-etcher) as recommended by the Nvida documentation. Once the sd card is written it can be slotted in its placeholder and the computer can be connected with a 5v power supply. 

Upon system initialization the USB WiFi adapter or a network cable can be attached and used to connect with an internet in order to get the latest available updates, using the following commands.

	apt-get update
	apt-get get upgrade
	apt-get autoremove
	apt-get dist-upgrade

Using the following commands two handy tools, one for monitoring the hardware resource of the computer and the second for multiplexing multiple command terminals, can be installed using the following command.

	apt-get install htop screen

Once the Jetson nano has been connected into the network the monitor, keyboard and mouse and be removed and the computer can be operated using and ssh terminal. Although not crucial, the computer can also be setup-ed to stream its monitor using the VNC open source software by issuing the following commands. 

	mkdir -p ~/.config/autostart
	cp /usr/share/applications/vino-server.desktop ~/.config/autostart/.
	gsettings set org.gnome.Vino prompt-enabled false
	gsettings set org.gnome.Vino require-encryption false
	gsettings set org.gnome.Vino authentication-methods "['vnc']"
	gsettings set org.gnome.Vino vnc-password $(echo -n 'agrofelis'|base64)

The commands initialise a remote desktop server which can be handy when debugging for the first time the video camera, or alter the WiFi network settings or other setting provided by the graphical user interface of the operating system. 

## Agrofelis services

As observed, the operating system can be setup-ed with just a handful commands, primarily because all common requirements have already been provisioned by Nvida in the aforementioned image. Another very useful software already pre-installed in the system is the Nvida Docker. Docker allows to containerize arbitrary computing environments, instantiate multiple instance of them as well revert, reuse or extend their definitions. Employing the Docker technology in the Agrofelis software stack means that its systems are easily reproducible, their definitions are transparent and their execution is somewhat isolated from the main operating system. Employing Docker moreover, allows the operating system to remain clean of the applications dependencies and new technologies can be evaluated without the fear of "polluting" the system. The NVdia Docker variation installed, can interface with the GPU hardware of the embedded computer, which enables to containerize also AI applications. 










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


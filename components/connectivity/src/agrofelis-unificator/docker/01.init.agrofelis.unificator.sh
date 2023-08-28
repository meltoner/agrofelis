#!/bin/bash
# @author Konstantinos Papageorgiou 2023
dockerName="agrofelis.unificator"
instance=${1:-1}
dockerIP="172.20.35."$instance
dockerNetwork="agrofelis-network"
rinstanceImageKey="agrofelis.unificator:core"
dockerNameInstance=$dockerName$instance
####################################
echo 'KERNEL=="ttyACM[0-9]*",MODE="0666"'>/etc/udev/rules.d/99-serial.rules
echo 'KERNEL=="ttyUSB[0-9]*",MODE="0666"'>>/etc/udev/rules.d/99-serial.rules

rinstanceInstance=$(\
	docker run -d -it --rm --privileged --name $dockerNameInstance \
	-v /web-pub/connectivity/src/agrofelis-unificator/server/:/project/ \
	-v /web-pub/data/:/data/ \
	-v /dev/ttyACM0:/dev/ttyACM0 \
	-v /dev/ttyUSB1:/dev/ttyUSB1 \
	-p 8080:8080 \
	-w /project/ \
	-e dockerIP=$dockerIP -e dockerNameInstance=$dockerNameInstance -e rinstanceInstance=$rinstanceInstance \
	$rinstanceImageKey /usr/local/bin/node serial-ws.js \
)
#/bin/bash
#/usr/local/bin/node serial-ws.js \
#docker network connect --ip $dockerIP $dockerNetwork $rinstanceInstance
docker attach $rinstanceInstance

#!/bin/bash
# @author Konstantinos Papageorgiou 2023
dockerName="agrofelis.os"
instance=${1:-1}
dockerIP="172.20.35."$instance
dockerNetwork="agrofelis-network"
rinstanceImageKey="agrofelis.os:core"
dockerNameInstance=$dockerName$instance
####################################
echo 'KERNEL=="ttyACM[0-9]*",MODE="0666"'>/etc/udev/rules.d/99-serial.rules
rinstanceInstance=$(\
	docker run -d -it --rm --privileged --name $dockerNameInstance \
	-v /web-pub/:/web-pub/ \
	-v /dev/ttyACM0:/dev/ttyACM0 \
	-w /web-pub/ \
	-e dockerIP=$dockerIP -e dockerNameInstance=$dockerNameInstance -e rinstanceInstance=$rinstanceInstance \
	$rinstanceImageKey /bin/bash \
)
docker network connect --ip $dockerIP $dockerNetwork $rinstanceInstance
docker attach $rinstanceInstance

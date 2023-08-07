#!/bin/bash
# @author Konstantinos Papageorgiou 2023
dockerName="agrofelis.os.unificator"
instance=${1:-1}
dockerIP="172.20.45."$instance
dockerNetwork="agrofelis-network"
rinstanceImageKey="agrofelis.os.unificator:code"
dockerNameInstance=$dockerName$instance
####################################
echo 'KERNEL=="ttyACM[0-9]*",MODE="0666"'>/etc/udev/rules.d/99-serial.rules

rinstanceInstance=$(\
	docker run -d -it --rm --privileged --name $dockerNameInstance \
	-v /dev:/dev \
	-v /web-pub/:/web-pub/ \
	-w /web-pub/ \
	-e dockerIP=$dockerIP -e dockerNameInstance=$dockerNameInstance -e rinstanceInstance=$rinstanceInstance \
	$rinstanceImageKey /bin/bash \
)
docker network connect --ip $dockerIP $dockerNetwork $rinstanceInstance
docker attach $rinstanceInstance

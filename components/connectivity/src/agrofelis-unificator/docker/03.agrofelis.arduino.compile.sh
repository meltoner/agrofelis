#!/bin/bash
# @author Konstantinos Papageorgiou 2023
dockerName="agrofelis.os.arduino"
instance=${1:-1}
dockerIP="172.20.35."$instance
dockerNetwork="agrofelis-network"
rinstanceImageKey="agrofelis.os.arduino:core"
dockerNameInstance=$dockerName$instance
####################################
echo 'KERNEL=="ttyACM[0-9]*",MODE="0666"'>/etc/udev/rules.d/99-serial.rules

rinstanceInstance=$(\
	docker run -d -it --rm --privileged --name $dockerNameInstance \
	-v /web-pub/arduino/2023/:/project/ \
	-v /dev/ttyACM0:/dev/ttyACM0 \
	-p 8080:8080 \
	-w /project/ \
	-e dockerIP=$dockerIP -e dockerNameInstance=$dockerNameInstance -e rinstanceInstance=$rinstanceInstance \
	$rinstanceImageKey /bin/bash compile.sh \
)
docker attach $rinstanceInstance
#!/bin/bash
# @author melt kp@eworx.gr 2023
####################################
dockerName="NGINX"
instance=${1:-1}
dockerIP="172.20.132."$instance
dockerNetwork="agrofelis-network"
dockerNameInstance=$dockerName$instance
####################################

rdsenseInstance=$(docker run -d -it --privileged --restart unless-stopped --name $dockerNameInstance \
	-p 80:80 \
	-v /web-pub/connectivity/src/agrofelis-unificator/docker/images/NGINX/mime.types:/etc/nginx/mime.types \
	-v /web-pub/connectivity/src/agrofelis-unificator/docker/images/NGINX/nginx.conf:/etc/nginx/nginx.conf \
    -v /web-pub/connectivity/src/agrofelis-unificator/docker/images/NGINX/conf.d/default.conf:/etc/nginx/conf.d/default.conf \
	-v /web-pub/www/:/usr/share/nginx/html/ \
	nginx:alpine)

echo $rdsenseInstance


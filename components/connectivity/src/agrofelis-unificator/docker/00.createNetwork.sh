#!/bin/bash
# @author kp 2023
docker network create --subnet 172.20.0.0/16 --ip-range 172.20.240.0/20 agrofelis-network

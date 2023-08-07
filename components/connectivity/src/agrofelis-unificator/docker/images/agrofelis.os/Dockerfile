FROM ubuntu:22.04
MAINTAINER "Konstantinos Papageorgiou"
ENV LANG='en_US.UTF-8' LANGUAGE='en_US:en' LC_ALL='en_US.UTF-8' TZ='Europe/Athens'
RUN apt-get update && apt-get install -y apt-utils && apt-get update && \
	export DEBIAN_FRONTEND=noninteractive; \
	apt-get install -y --no-install-recommends apt-transport-https ca-certificates software-properties-common gpg-agent ; \
	apt-get install -y tzdata locales; \
	ln -fs /usr/share/zoneinfo/Europe/Athens /etc/localtime; \
	dpkg-reconfigure --frontend noninteractive tzdata; \
	locale-gen en_US.UTF-8 ; \
	apt-get install -y --no-install-recommends htop openssh-client screen iputils-ping libcurl4-openssl-dev libssl-dev rsync lbzip2 bzip2 curl nano; \	
	adduser --disabled-password --gecos '' melt; \	
	rm -rf /var/lib/apt/lists/*;


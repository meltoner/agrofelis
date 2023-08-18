# agrofelis.os unificator server - 2023
FROM agrofelis.os:core
MAINTAINER "Konstantinos Papageorgiou"

RUN apt-get update && apt-get install -y --no-install-recommends\
	libxt-dev libxml2-dev gdebi-core r-base r-base-dev;\	
 	rm -rf /var/lib/apt/lists/*;\
	export packages="'data.table', 'fst'";\
	echo "" > ~/.Rprofile;Rscript -e "packages <- c($packages);install.packages(packages);"

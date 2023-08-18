echo Compiling
arduino-cli compile --fqbn arduino:avr:mega linearSteer
echo Uploading
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:mega linearSteer 
#echo Serial printing
#cat /dev/ttyACM0
#arduino-cli monitor -p /dev/ttyACM0 
#/web-pub/connectivity/src/agrofelis-unificator/docker/01.init.agrofelis.unificator.sh

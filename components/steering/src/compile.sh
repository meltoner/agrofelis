echo Compiling
time arduino-cli compile --fqbn arduino:avr:mega linearSteer
echo Uploading
time arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:mega linearSteer 
echo Serial printing
#cat /dev/ttyACM0
arduino-cli monitor -p /dev/ttyACM0 
 
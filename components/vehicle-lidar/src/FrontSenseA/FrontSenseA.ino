/** 
 * Front sensors module - Agrofelis 
 *
 * The project uses an ESPR32, due to it compact size to intergrate sensors installed in the front location of the robot providing information aiding the awareness of the robots enviroment.
 * More specifically the module utilises a servo motor to be able to tilt a lidar and a gyroscope in order to be able to take a 3d scann of its front. 
 * The module moreover intergrates a gps module and establishes a serial link over usb with the the backbone of system.
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023 Agrofelis project 
 */

#include "Context.h"
#include "Invoker.h"

#include "FrontSensorsController.h"
 
#include "LD06forArduino.h"
LD06forArduino ld06;

FrontSensorsController controller = FrontSensorsController();

Context context = Context();
Invoker invoker = Invoker();

//-----------------------------------------

void setup() {
  ld06.Init(16);
  Serial.begin(115200);
  context.setup();
  controller.setup(context);
  invoker.setup(context);
}

void apply_interval_0(){}

void apply_interval_1(){
   controller.apply();
}

void apply_interval_2(){}

void apply_interval_3(){
  Serial.println();
  controller.print();
}

void apply_interval_4(){}

void apply_interval_5(){}

void run_invoker(int i){
    switch(i){
      case 0: apply_interval_0(); break;
      case 1: apply_interval_1(); break;
      case 2: apply_interval_2(); break;
      case 3: apply_interval_3(); break;
      case 4: apply_interval_4(); break;
      case 5: apply_interval_5(); break;
      case 100: break;
    }
}

void loop(){

  ld06.read_lidar_data();
  ld06.print();

  int actionIndex = invoker.apply();
  while(actionIndex != 100){
    run_invoker(actionIndex);
    actionIndex = invoker.apply();
  }
}

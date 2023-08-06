/** 
 * Dual Linear actuators steering controller - Agrofelis 
 *
 * The project uses an Arduino mega and few components to sense and control two linear actuators, to establish a steering system.
 * The module utilises Serial interface to share the internal state of the components as well as to control them.
 * The module consist of custom PCB that hosts two current sensors, two motor drivers and two inlets for two potentiometer used a feedback 
 * sensor to sense the steer degree of the wheels. The software enables to control each linear actuator individually as well as in a synchronized 
 * manner based on the Ackerman geometry and the physical orientation of the vehicle. The valid ratios of the wheels are measured in fine steps 
 * and persisted in an association map than can interpolate the values within these steps. 
 * 
 * Upon initialization the linear actuators are driven to reach the minimum and maximal points to dynamically derive the center and the bounds of
 * applicable movement. Moreover, the minimum voltage needed to achieve a movement is derived as the lowest applicable speed. 
 * 
 * The module provides an interface to make both linear actuators seek and reach the desired position. 
 * Last the module moves the linear actuators such that at any point in time the Ackerman geometry is met, requiring to move the motors in different speeds
 * to accommodate for their distance differences. With this feature the vehicle can move while the steering module actuates to the desired position.
 * 
 * @Author - Konstantinos L. Papageorgiou / mail kp at rei.gr - 2023 Agrofelis project 
 */

#include "Context.h"
#include "Invoker.h"


#include "SteeringController.h"

SteeringController controller = SteeringController::SteeringController();

Context context = Context::Context();
Invoker invoker = Invoker::Invoker();

//-----------------------------------------

void setup() {
  context.setup();
  controller.setup(context);
  invoker.setup(context);
}

void apply_interval_0(){

}

void apply_interval_1(){
   controller.apply();
}

void apply_interval_2(){
  controller.steer.apply();
}

void apply_interval_3(){
  Serial.println();
  controller.steer.print();
}

void apply_interval_4(){
}

void apply_interval_5(){
}

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
  int actionIndex = invoker.apply();
  while(actionIndex != 100){
    run_invoker(actionIndex);
    actionIndex = invoker.apply();
  }
}

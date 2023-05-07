
#include "Context.h"
#include "Invoker.h"
#include "Blink.h"

#include "Controller.h"

Controller controller = Controller::Controller();

Context context = Context::Context();
Invoker invoker = Invoker::Invoker();

Blink blink(53);
 
//-----------------------------------------

void setup() {
  context.setup();
  controller.setup(context);
  
  blink.setup(context);
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
  blink.apply();
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

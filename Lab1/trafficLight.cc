#include "trafficLight.h"

Trafficlight::Trafficlight(sc_module_name name)
  : sc_module(name)
{
  N_trafficlight.initialize(false);
  S_trafficlight.initialize(false);
  W_trafficlight.initialize(false);
  E_trafficlight.initialize(false);

  SC_METHOD(evaluate_trafficlight_method);
  dont_initialize();
  sensitive << N_sensor << S_sensor << E_sensor << W_sensor;
}
 

void Trafficlight::evaluate_trafficlight_method()
{
  bool N_car = N_sensor->read();
  bool S_car = S_sensor->read();
  bool E_car = E_sensor->read();
  bool W_car = W_sensor->read();


  if (N_car) {
    N_light_event.notify();
  }
  if (S_car) {
    
  }
  if (E_car) {
    
  }
  if (W_car) {
    
  }

  // if (N_car & S_car) {
  //   N_trafficlight->write(true);
  //   S_trafficlight->write(true);
  //   E_trafficlight->write(false);
  //   W_trafficlight->write(false);
  // }
  // else if (N_car & !S_car) {
  //   N_trafficlight->write(true);
  //   S_trafficlight->write(false);
  //   E_trafficlight->write(false);
  //   W_trafficlight->write(false);
  // }
  // else if (!N_car & S_car) {
  //   N_trafficlight->write(false);
  //   S_trafficlight->write(true);
  //   E_trafficlight->write(false);
  //   W_trafficlight->write(false);
  // }
  // else if (E_car & W_car) {
  //   N_trafficlight->write(false);
  //   S_trafficlight->write(false);
  //   E_trafficlight->write(true);
  //   W_trafficlight->write(true);
  // }
  // else if (E_car & !W_car) {
  //   N_trafficlight->write(false);
  //   S_trafficlight->write(false);
  //   E_trafficlight->write(true);
  //   W_trafficlight->write(false);
  // }
  // else if (!E_car & W_car) {
  //   N_trafficlight->write(false);
  //   S_trafficlight->write(false);
  //   E_trafficlight->write(false);
  //   W_trafficlight->write(true);
  // }
  // else {
  //   N_trafficlight->write(false);
  //   S_trafficlight->write(false);
  //   E_trafficlight->write(false);
  //   W_trafficlight->write(false);
  // }
}

void n_light_thread()
{
  for(;;){
    wait(N_light_event)
    
  }
}

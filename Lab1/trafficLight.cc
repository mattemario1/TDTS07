#include "trafficLight.h"

Trafficlight::Trafficlight(sc_module_name name)
  : sc_module(name)
{
  N_trafficlight.initialize(false);
  S_trafficlight.initialize(false);
  W_trafficlight.initialize(false);
  E_trafficlight.initialize(false);

  roadState = NOTHING;

  SC_THREAD(N_light_thread);
  SC_THREAD(S_light_thread);
  SC_THREAD(E_light_thread);
  SC_THREAD(W_light_thread);

  SC_METHOD(evaluate_trafficlight_method);
  dont_initialize();
  sensitive << N_sensor << S_sensor << E_sensor << W_sensor;
}
 

void Trafficlight::evaluate_trafficlight_method()
{
  N_car.write(N_sensor->read() | N_car.read());
  S_car.write(S_sensor->read() | S_car.read());
  E_car.write(E_sensor->read() | E_car.read());
  W_car.write(W_sensor->read() | W_car.read());
}

// void NW_road_direction_method()
// {
//   if (N_car.read() | S_car.read()){
//     roadState.write(NS);
//   }
//   else if (W_car.read() | E_car.read()){
//     roadState.write(EW);
//   }
// }



void Trafficlight::N_light_thread()
{
  for(;;){
    if (roadState.read() != EW && N_car.read()) {
      N_trafficlight->write(true);
      roadState.write(NS);
      wait(5, SC_SEC);
      N_trafficlight->write(false);
      N_car.write(false);
      if (S_car.read() == false)
        roadState.write(NOTHING);
    }
  }
}

void Trafficlight::S_light_thread()
{
  for(;;){
    if (roadState.read() != EW && S_car.read()) {
      S_trafficlight->write(true);
      roadState.write(NS);
      wait(5, SC_SEC);
      S_trafficlight->write(false);
      S_car.write(false);
      if (N_car.read() == false)
        roadState.write(NOTHING);
    }
  }
}

void Trafficlight::E_light_thread()
{
  for(;;){
    if (roadState.read() != NS && E_car.read()) {
      E_trafficlight->write(true);
      roadState.write(EW);
      wait(5, SC_SEC);
      E_trafficlight->write(false);
      E_car.write(false);
      if (W_car.read() == false)
        roadState.write(NOTHING);
    }
  }
}

void Trafficlight::W_light_thread()
{
  for(;;){
    if (roadState.read() != NS && W_car.read()) {
      W_trafficlight->write(true);
      roadState.write(EW);
      wait(5, SC_SEC);
      W_trafficlight->write(false);
      W_car.write(false);
      if (E_car.read() == false)
        roadState.write(NOTHING);
    }
  }
}
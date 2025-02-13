#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <systemc.h>

SC_MODULE(Trafficlight) {

  sc_in<bool> N_sensor;
  sc_in<bool> S_sensor;
  sc_in<bool> E_sensor;
  sc_in<bool> W_sensor;
  sc_out<bool> N_trafficlight;
  sc_out<bool> S_trafficlight;
  sc_out<bool> E_trafficlight;
  sc_out<bool> W_trafficlight;

  // sc_event light_event;


  enum directionState {NS,EW,NOTHING};
  sc_signal<directionState> roadState;
  sc_signal<bool> N_car;
  sc_signal<bool> S_car;
  sc_signal<bool> E_car;
  sc_signal<bool> W_car;
  sc_signal<bool> N_car_old;
  sc_signal<bool> S_car_old;
  sc_signal<bool> E_car_old;
  sc_signal<bool> W_car_old;

  SC_HAS_PROCESS(Trafficlight);
  Trafficlight(sc_module_name name);

  void evaluate_trafficlight_method();
  void road_direction_method();

  void N_light_thread();
  void S_light_thread();
  void E_light_thread();
  void W_light_thread();


};

#endif // TRAFFICLIGHT_H
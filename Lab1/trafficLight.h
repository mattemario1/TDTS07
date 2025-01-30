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

  sc_event N_light_event;

  SC_HAS_PROCESS(Trafficlight);
  Trafficlight(sc_module_name name);

  void evaluate_trafficlight_method();

  void n_light_thread();

};

#endif // TRAFFICLIGHT_H
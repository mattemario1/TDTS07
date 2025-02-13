#include "trafficLight.h"

Trafficlight::Trafficlight(sc_module_name name)
  : sc_module(name)
{
  N_trafficlight.initialize(false);
  S_trafficlight.initialize(false);
  W_trafficlight.initialize(false);
  E_trafficlight.initialize(false);

  roadState = true;

  SC_THREAD(change_state_thread);

  SC_METHOD(evaluate_trafficlight_method);
  dont_initialize();
  sensitive << N_sensor << S_sensor << E_sensor << W_sensor << change_state_done;
}
 

void Trafficlight::evaluate_trafficlight_method()
{
  if (!waitState.read()) {
    if (roadState.read()) {
        if (N_sensor.read()) {
          N_trafficlight->write(true);
        }
        if (S_sensor.read()) {
          S_trafficlight->write(true);
        }
        E_trafficlight->write(false);
        W_trafficlight->write(false);
        if (E_sensor.read() || W_sensor.read()) {
          change_state_event.notify(7,SC_SEC);
        }
    } else if (!roadState.read()) {
        if (E_sensor.read()) {
          E_trafficlight->write(true);
        }
        if (W_sensor.read()) {
          W_trafficlight->write(true);
        }
        N_trafficlight->write(false);
        S_trafficlight->write(false);
        if (N_sensor.read() || S_sensor.read()) {
          change_state_event.notify(7,SC_SEC);
        }
    }
  } else {
    N_trafficlight->write(false);
    S_trafficlight->write(false);
    W_trafficlight->write(false);
    E_trafficlight->write(false);
  }
}

void Trafficlight::change_state_thread()
{
  for (;;) {
    wait(change_state_event);
    roadState.write(!roadState.read());
    cout << roadState.read() << endl;
    change_state_done.notify();
    waitState.write(true);
    wait(2, SC_SEC);
    waitState.write(false);
    change_state_done.notify();
  }
}
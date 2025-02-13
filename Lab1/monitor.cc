#include <cassert>
#include "monitor.h"

Monitor::Monitor(sc_module_name name, char *outfile)
  : sc_module(name)
{
  assert(outfile != 0);
  out = new ofstream(outfile);
  assert(*out);

  SC_METHOD(monitor_method);
  dont_initialize();
  sensitive << N_trafficlight << S_trafficlight << E_trafficlight << W_trafficlight << N_sensor << S_sensor << E_sensor << W_sensor;
}

Monitor::~Monitor()
{
  delete out;
}

void Monitor::monitor_method()
{
  int N_light = N_trafficlight->read();
  int S_light = S_trafficlight->read();
  int E_light = E_trafficlight->read();
  int W_light = W_trafficlight->read();
  int N_sensors = N_sensor->read();
  int S_sensors = S_sensor->read();
  int E_sensors = E_sensor->read();
  int W_sensors = W_sensor->read();
  *out << "Traffic Light(" << sc_time_stamp() << ") = " << N_light << S_light << E_light << W_light << endl << "Sensor(" << sc_time_stamp() << ") = " << N_sensors << S_sensors << E_sensors << W_sensors << endl;
}


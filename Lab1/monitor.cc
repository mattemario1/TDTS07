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
  sensitive << N_trafficlight << S_trafficlight << E_trafficlight << W_trafficlight;
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
  *out << "Traffic Light(" << sc_time_stamp() << ") = " << N_light << S_light << E_light << W_light << endl;
}


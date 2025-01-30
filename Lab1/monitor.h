#ifndef MONITOR_H
#define MONITOR_H

#include <systemc.h>
#include <fstream>

using std::ofstream;

SC_MODULE(Monitor) {
  sc_in<bool> N_trafficlight;
  sc_in<bool> S_trafficlight;
  sc_in<bool> E_trafficlight;
  sc_in<bool> W_trafficlight;

  SC_HAS_PROCESS(Monitor);
  Monitor(sc_module_name name, char *outfile);
  ~Monitor();

  void monitor_method();

  ofstream *out;
};

#endif // MONITOR_H

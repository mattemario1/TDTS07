#include <systemc.h>
#include "trafficLight.h"
#include "input_gen.h"
#include "monitor.h"

int sc_main(int argc, char **argv)
{
  // The command-line arguments are as follows:
  // 1. the simulation time (in seconds),
  // 2. the file with input data (see input.txt), and
  // 3. the file to write output data.
  assert(argc == 4);

  sc_time sim_time(atof(argv[1]), SC_SEC);
  char *infile = argv[2];
  char *outfile = argv[3];

  // Create channels.
  sc_signal<bool> N_car_sig;
  sc_signal<bool> S_car_sig;
  sc_signal<bool> E_car_sig;
  sc_signal<bool> W_car_sig;
  sc_signal<bool> N_light_sig;
  sc_signal<bool> S_light_sig;
  sc_signal<bool> E_light_sig;
  sc_signal<bool> W_light_sig;

  // Instantiate modules.
  Trafficlight trafficlight("Trafficlight");
  Generator gen("Generator", infile);
  Monitor monitor("Monitor", outfile);

  // Connect the channels to the ports.
  trafficlight(N_car_sig, S_car_sig, E_car_sig, W_car_sig, N_light_sig, S_light_sig, E_light_sig, W_light_sig);
  gen(N_car_sig, S_car_sig, E_car_sig, W_car_sig);
  monitor(N_light_sig, S_light_sig, E_light_sig, W_light_sig);

  // Start the simulation.
  sc_start(sim_time);

  return 0;
}

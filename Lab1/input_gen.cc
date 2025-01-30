#include "input_gen.h"
#include <cassert>

Generator::Generator(sc_module_name name, char *datafile)
  : sc_module(name)
{
  assert(datafile != 0);       // An input file should be given.

  in = new ifstream(datafile); // Open the input file.
  assert(*in);                 // Check that everything is OK.

  SC_THREAD(generate_thread);

  N_sensor.initialize(false);
  S_sensor.initialize(false);
  E_sensor.initialize(false);
  W_sensor.initialize(false);
}

Generator::~Generator()
{
  delete in;
}

void Generator::generate_thread()
{
  bool N_car, S_car, W_car, E_car;
  for (;;) {
    wait(1, SC_SEC);     // Generate new inputs every second.
    *in >> N_car >> S_car >> E_car >> W_car; // Read from the input file.
    N_sensor->write(N_car);
    S_sensor->write(S_car);
    E_sensor->write(E_car);
    W_sensor->write(W_car);
  }
}

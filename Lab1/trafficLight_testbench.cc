#include <systemc.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "trafficLight.h"
#include "input_gen.h"
#include "monitor.h"

void generate_random_cars(const std::string& filename, int numRows);


int sc_main(int argc, char **argv)
{
  // The command-line arguments are as follows:
  // 1. the simulation time (in seconds),
  // 2. the file with input data (see input.txt), and
  // 3. the file to write output data.
  assert(argc == 4);

  char *infile = argv[2];
  sc_time sim_time(atof(argv[1]), SC_SEC);

  if (std::strstr(infile, "input_file_random.txt")){
    generate_random_cars(infile, atof(argv[1]));
  } 

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
  monitor(N_light_sig, S_light_sig, E_light_sig, W_light_sig, N_car_sig, S_car_sig, E_car_sig, W_car_sig);

  // Start the simulation.
  sc_start(sim_time);

  return 0;
}

void generate_random_cars(const std::string& filename, int numRows)
{
  // Open file for writing
  std::ofstream outFile(filename);

  cout << "hello" << std::endl;

  if (!outFile) {
    std::cerr << "Error opening file for writing." << std::endl;
    return;
  }

  std::srand(static_cast<unsigned int>(std::time(0)));

  for (int i = 0; i < numRows/5; ++i) {
    int randomBit = std::rand() % 16; 

    for (int n = 4; n >= 0; --n) {
      for (int j = 3; j >= 0; --j) {
          outFile << ((randomBit >> j) & 1) << " ";
      }
      outFile << std::endl; 
    }

  }

  // Close the file
  outFile.close();
}


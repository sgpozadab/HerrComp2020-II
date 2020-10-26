#include "md-simul.h"
#include <string>
#include <fstream>

int main(void)
{
  Particle ball;
  //double Ek = 0.0, Ep = 0.0;

  // start system
  initial_conditions(ball);
  compute_force(ball);
  print(ball, 0.0);
  start_integration(ball, DT);

  // evolve
  for(int istep = 0; istep < NSTEPS; ++istep) {
    time_integration(ball, DT);
    Ek_in_phase(ball, DT); //Compute Ek in phase
    compute_force(ball);
    print(ball, istep*DT);
    if (istep % 10 == 0) {
      std::string fname = "simuldata/simul-" + std::to_string(istep) + ".csv";
      std::ofstream fout(fname);
      fout << ball.Rx << ", "
           << ball.Ry << ", "
           << ball.Rz << ", "
           << ball.mass << ", "
           << ball.rad << "\n";
      fout.close();
    }
  }

  return 0;
}

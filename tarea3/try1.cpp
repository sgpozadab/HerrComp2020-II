#include <cmath>
#include <cstdlib>
#include <iostream>

double sumup(int NMAX);
//double sumdown(int NMAX);
double sum = 0.0;

int main(int argc, char **argv)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  const double exact = M_PI*M_PI/6.0;
  const int NMAX = std::atoi(argv[1]);
  std::cout << sumup(NMAX) << "\t" << exact << std::endl;

  return 0;
}

double sumup(int NMAX)
{
  for (int i=1; i<=NMAX; ++i){
    sum += 1.0/(i*i);
  }
  return sum;
}

/*double sumdown(int NMAX)
{
  for (int i=NMAX; i>=1; i--){
    sum += sum + 1.0/(i*i);
  }
  return sum;
  }*/

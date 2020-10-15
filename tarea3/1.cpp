#include <cmath>
#include <cstdlib>
#include <iostream>

double sumup(int NMAX);
double sumdown(int NMAX);

int main(int argc, char **argv)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  const double exact = M_PI*M_PI/6.0;
  const int NMAX = std::atoi(argv[1]);
  double df = std::fabs(sumup(NMAX)-exact)/exact;
  double dg = std::fabs(sumdown(NMAX)-exact)/exact;
  std::cout << df << "\t" << dg << std::endl;

  return 0;
}

double sumup(int NMAX)
{
  double sum = 0.0;
  for (int i=1; i<=NMAX; ++i){
    sum += 1.0/(i*i);
  }
  return sum;
}

double sumdown(int NMAX)
{
  double sum=0.0;
  for (int i=NMAX; i>=1; --i){
    sum += 1.0/(i*i);
  }
  return sum;
}



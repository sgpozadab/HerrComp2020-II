#include <cmath>
#include <cstdlib>
#include <iostream>

double myatan(double x, int n);

int main(int argc, char **argv)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  const int NSTEPS = std::atoi(argv[1]); //53
  const double x = std::atof(argv[2]); //4.2
  const double exact = std::atan(x);
  double my = myatan(x, NSTEPS);
  double diff = std::fabs(my-exact)/exact;
  std::cout << diff << std::endl;

  return 0;
}

double ainicial(int NSTEPS){
  double var = 1.0;
  for(int i = 1; i <= NSTEPS; ++i)
    var *= 1/1.414213562373095;
  return var;
}

double ev(int NSTEPS){
  double eval = 1.0;
  for(int i = 1; i <= NSTEPS; ++i)
    eval *= 1/2.0;
  return eval;
}

double binicial(double x){
  double var2 = x/(1.0+std::sqrt(1+x*x));
  return var2;
}

double myatan(double x, int NSTEPS){
  double a=ainicial(NSTEPS); double b=binicial(x);
  double c=1.0; double d=1.0; double f=1.0;
  while(1-a>ev(NSTEPS)){
      c=2.0*c/(1+a);
      d=2.0*a*b/(1+b*b);
      d=d/(1.0+std::sqrt(1-d*d));
      d=(b+d)/(1.0-b*d);
      b=d/(1.0+std::sqrt(1+d*d));
      a=2.0*std::sqrt(a)/(1+a);
      f=c*std::log((1.0+b)/(1-b));
  }

  return f;
}

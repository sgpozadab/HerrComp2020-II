#include <iostream>
#include <cstdlib>

double esc(int n);

int main(int argc, char **argv)
{
  const int n = std::atoi(argv[1]);
  std::cout << esc(n) << std::endl;

  return 0;
}

double esc(int n)
{
  double var = 1.0;
  for(int i = 1; i <= n; ++i)
   var *= 2.0;
  return var;
}

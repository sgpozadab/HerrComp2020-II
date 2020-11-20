#include<iostream>
#include<omp.h>

int main(int arc, char **argv)
{
  double x = 25; // global
  #pragma omp parallel
  {
    int tid = omp_get_thread_num();
    int nth = omp_get_num_threads();
    std::cout << "My tid: " << tid << std::endl;
    std::cout << "My nth: " << nth << std::endl;
  }

  return 0;
}

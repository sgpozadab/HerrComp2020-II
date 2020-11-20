#include <iostream>
#include <cmath>
#include <functional>
#include <mpi.h>
#include <chrono>

using fptr  = double(double);

void print_elapsed(auto start, auto end);
double f(double x);
double simpson(fptr fun, double a, double b);

const int N = 6000000;
const double xmin = 0.0;
const double xmax = 100.0;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int pid = 0, nthreads = 0;

    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Comm_size(MPI_COMM_WORLD, &nthreads);
    
    /*const int NSlocal = N/nthreads;
    double * data = new double [nthreads] {0.0};


    for (int ilocal = 0; ilocal < NSlocal; ++ilocal) {
      data[ilocal] = simpson(f,)
      }*/

    
    std::cout.precision(15); std::cout.setf(std::ios::scientific);

    auto start  = std::chrono::steady_clock::now();
    double integral  = simpson(f, xmin, xmax);
    auto end  = std::chrono::steady_clock::now();
    
    std::cout << "tiempo:\t";
    print_elapsed(start, end);

    std::cout << "valor de la integral:\t" << integral << '\n';

    MPI_Finalize();
    return 0;
}

double f(double x)
{
    return std::pow(x,2);
}


double simpson(fptr fun, double a, double b)
{

    const double h = (b-a)/N;
    double suma = 0;
    double aux1 = 0, aux2 = 0;
 
    //int tid = omp_get_thread_num();
    //int SL = N/nthreads;
    
    //#pragma omp parallel for num_threads (nthreads) reduction(+:aux1,aux2)
    
      for(int ii = 1; ii <= N/2 - 1; ++ii) {
        double x = a + 2*ii*h;
        aux1 += fun(x);
      }
      for(int ii = 1; ii <= N/2; ++ii) {
        double x = a + (2*ii-1)*h;
        aux2 += fun(x);
      }
      suma = h*(fun(a) + 2*aux1 + 4*aux2 + fun(b))/3;

    return suma;
}

void print_elapsed(auto start, auto end)
{
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()/1000.0 << "\n";
}

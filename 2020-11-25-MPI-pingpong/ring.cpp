// Ring: pid 0 sends a counter to pid 1. Pid 1 increments it by pid.
// pid 1 sends to pid 2; pid2 increments by pid, and so on

#include <iostream>
#include <numeric>
#include <cstdlib>
#include "mpi.h"

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  int pid = 0, nproc = 0;

  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &nproc);

  int counter = 0;
  int tag = 0;
  
  //while(counter < NPINGPONG) {
    if (0 == pid) {
      MPI_Send(&counter, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
      MPI_Recv(&counter, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } else {
      MPI_Recv(&counter, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      counter+=pid;
      MPI_Send(&counter, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
    }
    //}

  if (0 == pid) {
    std::cout << counter << std::endl;
  }
  
  MPI_Finalize();
  return 0;
}

//MPI_Send(&counter, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
//MPI_Recv(&counter, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

/*if (0 == pid) {
      MPI_Send(&counter, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
      MPI_Recv(&counter, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } if(1 == pid){
      MPI_Recv(&counter, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      counter+=pid;
      MPI_Send(&counter, 1, MPI_INT, 2, tag, MPI_COMM_WORLD);
    } if(2 == pid){
      MPI_Recv(&counter, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      counter+=pid;
      MPI_Send(&counter, 1, MPI_INT, 3, tag, MPI_COMM_WORLD);
    } else {
      MPI_Recv(&counter, 1, MPI_INT, 2, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      counter+=pid;
      MPI_Send(&counter, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
    }*/

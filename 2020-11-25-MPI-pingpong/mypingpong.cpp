// Pingpong: pid 0 sends a counter to pid 1. Pid 1 increments it, and sends it back. pid 0 prints it
// NPINGPONG: Number of ping pong interchange

//Send 0 -> 1 and Recv 1 -> 0

#include <iostream>
#include <numeric>
#include <cstdlib>
#include "mpi.h"

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  const int NPINGPONG = std::atoi(argv[1]);
  int pid = 0, nproc = 0;

  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &nproc);

  int cont = 0;
  int tag = 1;

  if(pid==0){
    MPI_Send(&cont,1,MPI_int,1,tag,MPI_COMM_WORLD);
    MPI_Recv(&cont,1,MPI_int,1,tag,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
  } else {
    MPI_Recv(&cont,1,MPI_int,0,tag,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
    cont++;
    MPI_Send(&cont,1,MPI_int,0,tag,MPI_COMM_WORLD);
  }


  MPI_Finalize();
  return 0;
}


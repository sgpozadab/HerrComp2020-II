#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int argc, char **argv)
{
  srand(2);
  //para numeros entre -1 y 1
  Eigen::MatrixXd m = Eigen::MatrixXd::Random(3,3);
  std::cout<< m <<std::endl;
  
  return 0;
}

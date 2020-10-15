#include <iostream>
#include <cmath>

using namespace std;

float N=0.3;

float func1(float x){
  float f=5-sqrt(25+x*x);
  return f;
}

float func2(float x){
  float f=-x*x/(5+sqrt(25+x*x));
  return f;
}

float func3(float x){
  float f=-x*x/(5+sqrt((5+x)*(5+x)-10*x));
  return f;
}

int main(){

 cout.precision(8);
 cout.setf(std::ios::scientific);
 
  for(float n=0.0; n<=N; n=n+0.01){
    cout<<n<<"\t"<<func1(n)<<"\t"<<func2(n)<<"\t"<<func3(n)<<"\n";
  }
  return 0;
}

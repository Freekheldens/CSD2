#include <iostream>


int sumsqaures(int *x){
  std::cout << "From whitin sumsquares:" << *x << std::endl;
  *x = 46;
}

int main (){

  int getal = 52;

  std::cout << getal << std::endl;
  sumsqaures(&getal);
  std::cout << getal << std::endl;

  return 0;
}

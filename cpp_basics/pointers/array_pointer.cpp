#include <iostream>


int sumsqaures(int *block){
  int total=0;
    for(int i=0; i<10; i++) total += block[i]*block[i];
    return total;
}



int main (){

  int *lijst = new int[10];

  for(int i=0; i<10; i++) lijst[i] = i;

  for(int i=0; i<10; i++){
    std::cout << *(lijst+i) << std::endl;
  }

  sumsqaures(lijst);

  std::cout << sumsqaures(lijst) << std::endl;

  return 0;
}

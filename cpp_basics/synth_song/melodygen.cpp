#include "melodygen.h"
#include "amsynth.h"
#include "mixsynth.h"
#include <random>



Melodygen::Melodygen() {
}

Melodygen::~Melodygen() {
}

void Melodygen::AMplay(){

  random_device dev;
  mt19937 rng(dev());
  uniform_int_distribution<std::mt19937::result_type> dist6(1,8);

  cout << dist6(rng) << endl;

}

void Melodygen::Mixplay(){
}

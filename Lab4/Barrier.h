#include "Semaphore.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <thread>
#include <vector>

/*! \class Barrier
    \brief A Barrier Implementation

   Uses C++11 features such as mutex and condition variables to implement a Barrier class using Semaphores

*/
class Barrier
{
private:

  int count;
  //needs thread num
  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> barrier1;
  std::shared_ptr<Semaphore> barrier2;

public:

  Barrier::Barrier();
  Barrier::~Barrier();
  Barrier::Barrier(int count);
  Barrier::~Barrier(int count);
  void setCount(int count);
  int getCount();
  void waitForAll();
  
};

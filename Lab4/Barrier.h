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
 
  // bool condition = true; /*! condition for loop in barrierFunction()*/
  // int count = 0; /*!< Holds the thread count */
  // int num_of_threads; /*! Number of threads in array*/
    void taskOne();
    void taskTwo();
    int getInput();
    void barrierFunction(std::shared_ptr <Semaphore> mutex,std::shared_ptr<Semaphore> barrier1, std::shared_ptr<Semaphore> barrier2, int num_of_threads);
    

public:
    void run();
};

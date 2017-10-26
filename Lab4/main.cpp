#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/

int main(void){

  std::cout << "input number of threads\n";
  std::cout << "Type in 0 the exit\n";
  
  /*!< Creates a barrier object */
  std::shared_ptr<Barrier> barrierObj( new Barrier); 

  barrierObj->run();
  
  return 0;
}

#include "Barrier.h"
#include <thread>
#include <vector>

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/

/*! displays the first function in the barrier being executed */
void taskOne(std::shared_ptr <Barrier> barrierObj){
  std::cout << "first " << std::endl;
}

/*! diplays the second function in the barrier being executed */
void taskTwo(std::shared_ptr <Barrier> barrierObj){
  std::cout << "second " << std::endl;
}

int main(void){
  int count;
  std::cin >> count;
  std::vector<std::thread> threadArray(count);
  std::shared_ptr<Barrier> barrierOBJ( new Barrier(threadArray.size()));
  
  return 0;
}

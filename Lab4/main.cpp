#include "Barrier.h"
#include <thread>
#include <vector>

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/

/*! displays the first function in the barrier being executed */
void task(std::shared_ptr <Barrier> barrierObj){

  std::cout << "first " << std::endl;
  barrierObj->waitForAll();
  std::cout << "second" << std::endl;
}

int main(void){
  int count;
  std::cout << "Type in an int" << std::endl;
  std::cin >> count;
  /*!< An array of threads*/
  std::vector<std::thread> threadArray(count);
  /*!< Pointer to barrier object*/
  std::shared_ptr<Barrier> barrierObj( new Barrier(threadArray.size()));

  for(int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,barrierObj);
  }

  for(int i = 0; i < threadArray.size(); i++){
    threadArray[i].join();
  }
  
  return 0;
}

#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>
#include <thread>
#include <vector>
/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/

int main(void){
  /*!< mutex lock*/
  std::shared_ptr<Semaphore> mutex( new Semaphore(1)); 
  /*!< first barrier*/
  std::shared_ptr<Semaphore> barrier1( new Semaphore(0)); 
  /*!< second barrier*/
  std::shared_ptr<Semaphore> barrier2( new Semaphore(1)); 

  std::cout << "input number of threads" << std::endl;
  std::cout << "Type in 0 the exit\n";
  /*!< allows the user to set the amount of threads created*/
  int num_of_threads = getInput(); 
  /*!< array of threads */
  std::vector<std::thread> threadsArray(num_of_threads); 

  for(int i = 0; i < threadsArray.size(); i++){
  threadsArray[i]=std::thread(barrierFunction,mutex,barrier1,barrier2, threadsArray.size());
  }

  for(int i = 0; i < threadsArray.size(); i++){
    threadsArray[i].join();
  }
 
  return 0;
}

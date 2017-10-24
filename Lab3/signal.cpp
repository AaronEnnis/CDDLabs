#include "Semaphore.h"
#include <iostream>
#include <thread>

/*! \class Signal
    \brief An Implementation of a mutex lock Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a mutex lock using Semaphores

*/
/*!< global count for checkIn() function*/
int count = 1; 
/*! Only allows one thread to access the global variable 'count' at a time*/
void checkIn(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << "number " << count << " logged in\n";
  count++;
  theSemaphore->Signal();
}

int main(void){ 
  std::thread threadOne, threadTwo, threadThree;
  std::shared_ptr<Semaphore> sem( new Semaphore(1));
  /**< Launch the threads  */
  std::cout << "Launched from the main\n";
  threadOne = std::thread (checkIn,sem);
  threadTwo = std::thread (checkIn,sem);
  threadThree = std::thread (checkIn,sem);
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  return 0;
}

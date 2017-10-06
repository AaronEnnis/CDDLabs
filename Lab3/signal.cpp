#include "Semaphore.h"
#include <iostream>
#include <thread>

int count = 1;

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

#include "Semaphore.h"
#include <iostream>
#include <thread>

int count = 0;
bool condition = true;

void taskOne(std::shared_ptr<Semaphore> barrier1, std::shared_ptr<Semaphore> barrier2){
  theSemaphore->Wait();
  std::cout << "number " << count << " logged in\n";
  count++;
  theSemaphore->Signal();
}

void taskTwo(std::shared_ptr<Semaphore> barrier1, std::shared_ptr<Semaphore> barrier2){
  theSemaphore->Wait();
  std::cout << "number " << count << " logged in\n";
  count--;
  theSemaphore->Signal();
}

int main(void){
  std::thread threadArray[10];
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> barrier1( new Semaphore(0));
  std::shared_ptr<Semaphore> barrier2( new Semaphore(1));
  /**< Launch the threads  */
  while(condition){
    threadArray=std::thread(taskOne,mutex,barrier1,barrier2);

    threadArray=std::thread(taskTwo,mutex,barrier1,barrier2);
  }

  return 0;
}

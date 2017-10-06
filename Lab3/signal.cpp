#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> firstSem){
  std::cout <<"I ";
  std::cout << "must ";
  secondSem->Signal();
  firstSem->Wait();
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  secondSem->Signal();
}

int main(void){
  std::thread threadOne, threadTwo, threadThree;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskOne,sem);
  threadTwo=std::thread(taskTwo,sem);
  threadThree=std::thread(taskThree,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  return 0;
}

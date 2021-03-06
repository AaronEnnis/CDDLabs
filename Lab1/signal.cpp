//Author: Aaron Ennis
//Program name: signal
//Purpose: create an example of a signaling with semaphores

#include "Semaphore.h"
#include <iostream>
#include <thread>
/*! \class Signal
    \brief An Implementation of Threads Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement Semaphores in thread functions 

*/
/*! displays a message first*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout <<"I must print first"<<std::endl;
  theSemaphore->Signal();
}
/*! displays a message second*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This will appear second "<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}

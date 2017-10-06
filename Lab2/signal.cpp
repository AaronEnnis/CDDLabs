#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> firstSem,std::shared_ptr<Semaphore>  secondSem){
  std::cout <<"I ";
  std::cout << "must ";
  secondSem->Signal();
  firstSem->Wait();
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  secondSem->Signal();
}
void taskTwo(std::shared_ptr<Semaphore> firstSem, std::shared_ptr<Semaphore> secondSem){
  secondSem->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  firstSem->Signal();
  secondSem->Wait();
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1,sem2);
  threadTwo=std::thread(taskOne,sem1,sem2);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}

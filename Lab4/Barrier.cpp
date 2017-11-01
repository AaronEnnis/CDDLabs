#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/
/*! Barrier constructor*/
Barrier::Barrier(){

  this->count = 0;
  threadNum = 0;
  condition = false;
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  std::shared_ptr<Semaphore> barrier1(new Semaphore(0));
  std::shared_ptr<Semaphore> barrier2(new Semaphore(1));

}
/*! Barrier with parameter constructor*/
Barrier::Barrier(int count){

  this->count = count;
  threadNum = 0;
  condition = false;
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  std::shared_ptr<Semaphore> barrier1(new Semaphore(0));
  std::shared_ptr<Semaphore> barrier2(new Semaphore(1));
}
/*! Barrier deconstructor*/
Barrier::~Barrier(){

}

/*! sets count value*/
void Barrier::setCount(int x){

  this->count = x;
}
/*! returns count value*/
int Barrier::getCount(){

  return this->count;
}

/*! first phase of the barrier*/
void Barrier::phaseOne(){

  mutex->Wait();
  threadNum++;

  if (threadNum == count){
    barrier1->Signal();
  }
  mutex->Signal();
  barrier1->Wait();


}
/*! second phase of the barrier after all threads complete phase one*/
void Barrier::phaseTwo(){
  
  mutex->Wait();
  threadNum--;

  if (count == 0){
    barrier2->Signal();
  }
  mutex->Signal();
  barrier2->Wait();
}

/*! waits for all the threads before starting second half of code*/ 
void Barrier::waitForAll(){

  phaseOne();
  phaseTwo();
}




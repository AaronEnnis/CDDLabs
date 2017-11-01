#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/
/*! Barrier constructor*/
Barrier::Barrier(){

  this->count = 0;
  threadNum = 0;
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  std::shared_ptr<Semaphore> barrier1(new Semaphore(0));
  std::shared_ptr<Semaphore> barrier2(new Semaphore(0));

}
/*! Barrier with parameter constructor*/
Barrier::Barrier(int count){

  this->count = count;
  threadNum = 0;
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  std::shared_ptr<Semaphore> barrier1(new Semaphore(0));
  std::shared_ptr<Semaphore> barrier2(new Semaphore(0));
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

/*! creates a barrier for the threads for 2 functions */ 
void Barrier::waitForAll(){
       
  mutex->Wait();
  threadNum++;
  if(threadNum == count){
    barrier2->Wait();
    barrier1->Signal();      
  }
    
  mutex->Signal();
  barrier1->Wait();
  barrier1->Signal();  

  mutex->Wait();
  threadNum--;
  if(threadNum == 0){
    barrier1->Wait();
    barrier2->Signal();
  }
    
  mutex->Signal();
  barrier2->Wait();
  barrier2->Signal();

}





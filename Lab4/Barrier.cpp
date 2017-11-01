#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/
/*! Barrier constructor*/
Barrier::Barrier(){

  this->count = count0;
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  std::shared_ptr<Semaphore> barrier1(new Semaphore(0));
  std::shared_ptr<Semaphore> barrier2(new Semaphore(0));
}
/*! Barrier with parameter constructor*/
Barrier::Barrier(int count){

  this->count = count;
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  std::shared_ptr<Semaphore> barrier1(new Semaphore(0));
  std::shared_ptr<Semaphore> barrier2(new Semaphore(0));
}
/*! Barrier deconstructor*/
Barrier::~Barrier(){

}
/*! Barrier with parameter deconstructor*/
Barrier::~Barrier(int count){

}
/*! sets count value*/
void setCount(int count){

  this->count = count;
}
/*! returns count value*/
int getCount(){

  return this->count;
}

/*! creates a barrier for the threads for 2 functions */ 
void Barrier::waitForAll(){
  
    while(condition){
      
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
      condition = false;
    }
    
    mutex->Signal();
    barrier2->Wait();
    barrier2->Signal();
    
  }
}





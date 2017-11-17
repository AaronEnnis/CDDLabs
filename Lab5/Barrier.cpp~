//Author: Aaron Ennis
//Program name: barrier
//Purpose: create re-useable barrier class

#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/
/*! Barrier constructor*/
Barrier::Barrier(){

  count = 0;
  threadNum = 0;
  turnstile = 0;
  mutex=std::make_shared<Semaphore>(1);
  barrier1=std::make_shared<Semaphore>(0);
  barrier2=std::make_shared<Semaphore>(1);

}
/*! Barrier with parameter constructor*/
Barrier::Barrier(int count){

  this->count = count;
  turnstile = 0;
  threadNum = 0;
  mutex=std::make_shared<Semaphore>(1);
  barrier1=std::make_shared<Semaphore>(0);
  barrier2=std::make_shared<Semaphore>(1);
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

/*! waits for all the threads and checks which turnstile is active*/ 
void Barrier::waitForAll(){

  if(turnstile == 0){
    phaseOne();
  }
  else{
    phaseTwo();
  }

}
/*! this is the first turnstile for the barrier*/
void Barrier::phaseOne(){

  mutex->Wait();
  threadNum++;
  if(threadNum == count){
    barrier2->Wait();
    barrier1->Signal();
    turnstile = 1;
  }
  mutex->Signal();
  barrier1->Wait();
  barrier1->Signal();
}
/*! this is the second turnstile for the barrier*/
void Barrier::phaseTwo(){

  mutex->Wait();
  threadNum--;
  if(threadNum == 0){
    barrier1->Wait();
    barrier2->Signal();
    turnstile = 0;
  }
  mutex->Signal();
  barrier2->Wait();
  barrier2->Signal();
}

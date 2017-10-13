#include "Semaphore.h"
#include <iostream>
#include <thread>

int count = 0;

void taskOne(){
  std::cout << "first " << count << "\n";
}

void taskTwo(){
  std::cout << "second " << count << "\n";
}

void barrierFunction(std::shared_ptr<Semaphore> mutex,std::shared_ptr<Semaphore> barrier1, std::shared_ptr<Semaphore> barrier2){

    bool condition = true;
  
    while(condition){
    mutex->Wait();
    count++;
    if(count == threadArray.size() - 1){
      barrier2->Wait();
      barrier1->Signal();      
    }
    mutex->Signal();
    barrier1->Wait();
    barrier1->Signal();

    taskOne();

    mutex->Wait();
    count--;
    if(count == 0){
      barrier1->Wait();
      barrier2->Signal();
      condition = false;
    }
    mutex->Signal();
    barrier2->Wait();
    barrier2->Signal();

    taskTwo();
  }


}

int main(void){
  std::array<std::thread,10> threadArray;
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> barrier1( new Semaphore(0));
  std::shared_ptr<Semaphore> barrier2( new Semaphore(1));
  /**< Launch the threads  */

  for(int i = 0; i < threadArray.size();i++){
  threadArray[i]=std::thread(barrierFunction, mutex, barrier1, barrier2);
  }

  return 0;
}

#include "Semaphore.h"
#include <iostream>
#include <thread>

int count = 0;
bool condition = true;

void taskOne(){
  std::cout << "first " << count << "\n";
}

void taskTwo(){
  std::cout << "second " << count << "\n";
}

void barrierFunction(std::shared_ptr <Semaphore> mutex,std::shared_ptr<Semaphore> barrier1, std::shared_ptr<Semaphore> barrier2, int arraySize){
  
    while(condition){
    mutex->Wait();
    count++;
    if(count == arraySize){
      barrier2->Wait();
      barrier1->Signal();      
    }
    taskOne();
    mutex->Signal();
    barrier1->Wait();
    barrier1->Signal();  

    mutex->Wait();
    count--;
    if(count == 0){
      barrier1->Wait();
      barrier2->Signal();
      condition = false;
    }
    taskTwo();
    mutex->Signal();
    barrier2->Wait();
    barrier2->Signal();
    
  }


}

int main(void){
  std::thread thread1, thread2, thread3, thread4, thread5;
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> barrier1( new Semaphore(0));
  std::shared_ptr<Semaphore> barrier2( new Semaphore(1));
  /**< Launch the threads  */

  thread1=std::thread(barrierFunction, mutex, barrier1, barrier2, 5);
  thread2=std::thread(barrierFunction, mutex, barrier1, barrier2, 5);
  thread3=std::thread(barrierFunction, mutex, barrier1, barrier2, 5);
  thread4=std::thread(barrierFunction, mutex, barrier1, barrier2, 5);
  thread5=std::thread(barrierFunction, mutex, barrier1, barrier2, 5);

  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();
  thread5.join();
  
  return 0;
}

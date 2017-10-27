#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/

/*! displays the first function in the barrier being executed */
void taskOne(int count){
  std::cout << "first " << count << "\n";
}

/*! diplays the second function in the barrier being executed */
void taskTwo(int count){
  std::cout << "second " << count << "\n";
}

int main(void){

  /*!< pointer to taskOne() function*/
  void (*task1)(int);
  /*!< pointer to taskTwo() function*/
  void (*task2)();
  task1 = &taskOne;
  task2 = &taskTwo;
  std::cout << "input number of threads\n";
  std::cout << "Type in 0 the exit\n";

  int num;
  std::cin >> num;
  
  /*!< Creates a barrier object */
  Barrier barrierObj(num, *task1, task2); 

  //barrierObj->run();
  
  return 0;
}

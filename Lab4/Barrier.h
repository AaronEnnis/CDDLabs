#include "Semaphore.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <thread>
#include <vector>

/*! \class Barrier
    \brief A Barrier Implementation

   Uses C++11 features such as mutex and condition variables to implement a Barrier class using Semaphores

*/
class Barrier
{
private:
    /*! condition for loop in barrierFunction()*/
    bool condition;
    /*!< Holds the thread count */
    int count; 
    int getInput();
    void barrierFunction(std::shared_ptr <Semaphore> mutex,std::shared_ptr<Semaphore> barrier1, std::shared_ptr<Semaphore> barrier2, int num_of_threads);
    std::vector<std::thread> threadsArray();
    /*!< mutex lock*/
    std::shared_ptr<Semaphore> mutex; 
    /*!< first barrier*/
    std::shared_ptr<Semaphore> barrier1; 
    /*!< second barrier*/
    std::shared_ptr<Semaphore> barrier2;
    //void (Barrier:: *barrier_ptr)(void);
  

public:
    void run();
    Barrier (int num_of_threads);
    Barrier();
};

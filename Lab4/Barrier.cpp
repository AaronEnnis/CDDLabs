#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/
/*!< global count to display barrier function is working correctly*/
int count = 0;

bool condition = true;

Barrier::Barrier(){

}

Barrier::Barrier(int num_of_threads, &task1, int task2){
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> barrier1( new Semaphore(0));
  std::shared_ptr<Semaphore> barrier2( new Semaphore(0));
  std::vector<std::thread> threadsArray(num_of_threads);
  task1_ptr = task1;
  task2_ptr = task2;

  for(int i = 0; i < threadsArray.size(); i++){
    threadsArray[i]=std::thread(&Barrier::barrierFunction,this,mutex,barrier1,barrier2,threadsArray.size(), *task1_ptr, *task2_ptr);
   }
  for(int i = 0; i < threadsArray.size(); i++){
     threadsArray[i].join();
   }
}

/*!Only allows the user to input integer */
int Barrier::getInput()
{
	/*!< the value of characters in a string*/
	int value = 0;
	/*!< individual character in a string*/
	int inchar = 0;
	/*!< gets each individual character from a srting of characters*/
	inchar = getchar();
	/*!< checks ASCII values of inputted characters for integers and breaks when value is equal to 10(enter key) of the chracter is not a integer*/
	if (inchar > 47 && inchar < 58)
	{
		while (inchar != 10)
		{
			/*!< puts each character back together creating a string*/
			value = value * 10 + (inchar - 48);			
			if (inchar > 57 || inchar < 48)
			{
				std::cout << "\nInvalid input\n";
				value = 0;
				break;
			}
			inchar = getchar();
		}
	}
	/*!< displays 'Invalid input' if the enter key is the first character inputted*/
	else if (inchar == 10)
	{
		std::cout << "\nInvalid input\n";
		value = -1;
	}
	/*!< displays 'Invalid input' if non-integer values is inputted first*/
	else {
		std::cout << "\nInvalid input\n";
		value = 0;
	}
	return value;
}

/*! creates a barrier for the threads for 2 functions */ 
void Barrier::barrierFunction(std::shared_ptr <Semaphore> mutex,std::shared_ptr<Semaphore> barrier1, std::shared_ptr<Semaphore> barrier2, int num_of_threads, &task1, &task2){
  
    while(condition){
      
    mutex->Wait();
    count++;
    if(count == num_of_threads){
      barrier2->Wait();
      barrier1->Signal();      
    }
    this->*task1_ptr(this->count);
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
    this->*task2_ptr(this->count);
    mutex->Signal();
    barrier2->Wait();
    barrier2->Signal();
    
  }
}

void Barrier::run(){ 

    /*!< allows the user to set the amount of threads created*/
    //int num_of_threads = getInput();
    
  //  for(int i = 0; i < this->threadsArray.size(); i++){
  //  this->threadsArray[i]=std::thread(barrierFunction,mutex,barrier1,barrier2,this->threadsArray.size());
  //}
  //for(int i = 0; i < this->threadsArray.size(); i++){
    //   this->threadsArray[i].join();
    //}
}





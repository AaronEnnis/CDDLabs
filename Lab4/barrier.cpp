#include "Semaphore.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <thread>
#include <vector>

int count = 0;
bool condition = true;

/*! diaplays the first function in the barrier being executed */
void taskOne(){
  std::cout << "first " << count << "\n";
}

/*! diaplays the second function in the barrier being executed */
void taskTwo(){
  std::cout << "second " << count << "\n";
}

/*! creates a barrier for the threads for 2 functions */ 
void barrierFunction(std::shared_ptr <Semaphore> mutex,std::shared_ptr<Semaphore> barrier1, std::shared_ptr<Semaphore> barrier2, int num_of_threads){
  
    while(condition){
      
    mutex->Wait();
    count++;
    if(count == num_of_threads){
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

/*!Only allows the user to input integer */
int getInput()
{
	int value = 0;
	int inchar = 0;
	inchar = getchar();
	if (inchar > 47 && inchar < 58)
	{
		while (inchar != 10)
		{
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
	else if (inchar == 10)
	{
		std::cout << "\nInvalid input\n";
		value = -1;
	}
	else {
		std::cout << "\nInvalid input\n";
		value = 0;
	}
	return value;
}

int main(void){

  std::shared_ptr<Semaphore> mutex( new Semaphore(1)); /*!< mutex lock*/
  std::shared_ptr<Semaphore> barrier1( new Semaphore(0)); /*!< first barrier*/
  std::shared_ptr<Semaphore> barrier2( new Semaphore(1)); /*!< second barrier*/

  std::cout << "input number of threads" << std::endl;
  std::cout << "Type in 0 the exit\n";
  int num_of_threads = getInput();  /*!< allows the user to set the amount of threads created*/
  std::vector<std::thread> threadsArray(num_of_threads); /*!< array of threads */

  for(int i = 0; i < threadsArray.size(); i++){
  threadsArray[i]=std::thread(barrierFunction,mutex,barrier1,barrier2, threadsArray.size());
  }

  for(int i = 0; i < threadsArray.size(); i++){
    threadsArray[i].join();
  }
 
  return 0;
}

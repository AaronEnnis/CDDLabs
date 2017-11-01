#include "Semaphore.h"
#include <mutex>
#include <condition_variable>

/*! \class Barrier
    \brief A Barrier Implementation

   Uses C++11 features such as mutex and condition variables to implement a Barrier class using Semaphores

*/
class Barrier
{
private:
    int count; /*!< Holds the thread count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    Semaphore(unsigned int uiCount=0)
      : m_uiCount(uiCount) { };
    void Wait();
    void Signal();

};

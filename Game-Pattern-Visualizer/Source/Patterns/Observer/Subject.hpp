#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <algorithm>
#include <vector>

#include "Observer.hpp"

namespace GPV
{

class Subject
{
    std::vector<Observer *> m_observers;

   public:
    Subject();
    void addObserver(Observer *observer);
    void removeObserver(Observer *observer);
    // Usually it's protected when the class inherite from the Subject class
    // in this case it is public because Subject will be an instance of the calling class
    // so it can notify, cannot make the calling class a friend because there is to much coupling
    void notify();
};

}  // namespace GPV

#endif
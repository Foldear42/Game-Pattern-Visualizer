/**
 * @ Author: Foldear
 * @ Filename: Subject.hpp
 * @ Modified time: 2025-10-15 09:10:17
 * @ Description:
 */

#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "Observer.hpp"
#include <vector>

namespace GPV
{

class Subject
{
    std::vector<Observer *> m_observers;

  public:
    Subject();
    void addObserver(Observer *observer);
    void removeObserver(Observer *observer);

  protected:
    void notify();
};

} // namespace GPV

#endif
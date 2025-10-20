/**
 * @ Author: Foldear
 * @ Filename: Subject.cpp
 * @ Modified time: 2025-10-20 10:36:18
 * @ Description:
 */

#include "Subject.hpp"

namespace GPV
{

Subject::Subject() {}

void Subject::addObserver(Observer *observer)
{
    m_observers.push_back(observer);
}

void Subject::removeObserver(Observer *observer)
{
    auto it = std::find(m_observers.begin(), m_observers.end(), observer);
    if (it != m_observers.end())
    {
        m_observers.erase(it);
    }
}

void Subject::notify()
{
    for (Observer *observer : m_observers)
    {
        observer->onNotify();
    }
}

} // namespace GPV
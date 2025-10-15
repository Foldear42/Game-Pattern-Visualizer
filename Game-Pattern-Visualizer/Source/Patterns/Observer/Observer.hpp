/**
 * @ Author: Foldear
 * @ Filename: Observer.hpp
 * @ Modified time: 2025-10-15 10:34:36
 * @ Description:
 */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

namespace GPV
{

class Observer
{

  public:
    virtual ~Observer() {}
    virtual void onNotify() = 0;
};

} // namespace GPV

#endif
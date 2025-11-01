#ifndef OBSERVER_HPP
#define OBSERVER_HPP

namespace GPV
{

class Observer
{
   public:
    virtual ~Observer()
    {
    }
    virtual void onNotify() = 0;
};

}  // namespace GPV

#endif
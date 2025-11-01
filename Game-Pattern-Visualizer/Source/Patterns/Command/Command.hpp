#ifndef COMMAND_HPP
#define COMMAND_HPP

namespace GPV
{

class Command
{
   public:
    virtual ~Command()
    {
    }
    virtual void execute() = 0;
};

}  // namespace GPV
#endif
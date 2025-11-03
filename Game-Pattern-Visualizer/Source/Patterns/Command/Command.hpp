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
    virtual void undo() = 0;
    virtual std::string getInfo() const = 0;
};

}  // namespace GPV
#endif
/**
 * @ Author: Foldear
 * @ Filename: Command.hpp
 * @ Modified time: 2025-05-26 15:12:32
 * @ Description: Interface for command dependent entities (Command Pattern)
 */

#ifndef COMMAND_HPP
#define COMMAND_HPP

namespace GPV
{

class Command
{
  public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

} // namespace GPV
#endif
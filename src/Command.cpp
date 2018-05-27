#include <string>
#include <vector>
#include "Command.h"

Command::Command(std::string name, CommandType type, std::function<void(std::vector<std::string>)> func) : name_(name), type_(type), func_(func) 
{

}

const std::string& Command::Name() const
{
  return name_;
}

const CommandType Command::Type() const
{
  return type_;
}

void Command::Execute(std::vector<std::string>& args) const
{
  func_(args);
}
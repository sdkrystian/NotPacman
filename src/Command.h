// Copyright 2018 Krystian Stasiowski

#pragma once
#include <string>
#include <functional>
#include <vector>

enum class CommandType
{
  STANDARD,
  DEBUG
};

class Command
{
public:
  Command(std::string name, CommandType type, std::function<void(std::vector<std::string>)> func);
  const std::string& Name() const;
  const CommandType Type() const;
  void Execute(std::vector<std::string>& args) const;
private:
  std::string name_;
  CommandType type_;
  std::function<void(std::vector<std::string>)> func_;
};

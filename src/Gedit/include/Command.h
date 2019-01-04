#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>


class Command {
public:
  Command() = default;
  void executeLine(const std::string& line);
private:
  void createImage();
  char name;
  std::vector<std::string> args;
};

#endif
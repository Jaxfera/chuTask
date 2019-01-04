#include "Command.h"

#include <sstream>

void Command::executeLine(const std::string& line) {
  std::istringstream linestream(line);
  std::string arg;

  linestream >> name;

  while(linestream >> arg) {
    args.push_back(arg);
  }
}
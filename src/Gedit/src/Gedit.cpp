#include "Gedit.h"

#include <iostream>

#include "Command.h"

std::string Gedit::getInput() {
  // Show prompt
  std::cout << "> ";

  // Get all arguments
  std::string line;
  std::getline(std::cin, line);
  return std::move(line);
}

void Gedit::start() {
  while(true) {
    Command command = Command::parse(getInput());
    if(command.getName() == 'X') {
      return;
    }
    command.execute();
  }
}

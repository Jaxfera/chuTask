#include "Command.h"

#include <sstream>
#include <algorithm>

#include "Screen.h"

static Screen& screen = *(Screen::getScreen());

Command Command::parse(const std::string& line) {
  Command command;
  std::istringstream linestream(line);
  std::string arg;

  char name;
  linestream >> name;
  command.setName(name);

  while(linestream >> arg) {
    command.getArgs().emplace_back(std::move(arg.c_str()));
  }

  return command;
}

void Command::createImage() {
  const int m = std::stoi(args[0]);
  const int n = std::stoi(args[1]);
  screen.createImage(m, n);
}

void Command::clearImage() {
  screen.clearImage();
}

void Command::colourPixel() {
  const int x = std::stoi(args[0])-1;
  const int y = std::stoi(args[1])-1;
  const char c = args[2][0];
  screen.colourPixel(x, y, c);
}

void Command::print() {
  screen.print();
}

void Command::execute() {
  switch(name) {
    case 'I':
      createImage();
      break;
    case 'C':
      clearImage();
      break;
    case 'L':
      colourPixel();
      break;
    case 'S':
      print();
      break;
  }
}
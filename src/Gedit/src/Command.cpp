#include "Command.h"

#include <sstream>
#include <algorithm>

#include "Screen.h"

static Screen& screen = *(Screen::getScreen());
#define MAXWIDTH Screen::getScreen()->getM()
#define MAXHEIGHT Screen::getScreen()->getN()

static int getIntegerInput(std::string input, const int upperBoundary) {
  int retval = std::stoi(input);
  retval--;
  return std::clamp(retval, 0, upperBoundary);
}

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
  const int x = getIntegerInput(args[0], MAXWIDTH);
  const int y = getIntegerInput(args[1], MAXHEIGHT);
  const char c = args[2][0];
  screen.colourPixel(x, y, c);
}

void Command::print() {
  screen.print();
}

void Command::drawVertical() {
  const int x = getIntegerInput(args[0], MAXWIDTH);
  const int y1 = getIntegerInput(args[1], MAXHEIGHT);
  const int y2 = getIntegerInput(args[2], MAXHEIGHT);
  const char c = args[3][0];
  screen.drawVertical(x, y1, y2, c);
}

void Command::drawHorizontal() {
  const int x1 = getIntegerInput(args[0], MAXWIDTH);
  const int x2 = getIntegerInput(args[1], MAXWIDTH);
  const int y = getIntegerInput(args[2], MAXHEIGHT);
  const char c = args[3][0];
  screen.drawHorizontal(x1, x2, y, c);
}

void Command::fillRegion() {
  const int x = getIntegerInput(args[0], MAXWIDTH);
  const int y = getIntegerInput(args[1], MAXHEIGHT);
  const char c = args[2][0];
  screen.fillRegion(x, y, c);
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
    case 'V':
      drawVertical();
      break;
    case 'H':
      drawHorizontal();
      break;
    case 'F':
      fillRegion();
      break;
  }
}
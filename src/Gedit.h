#ifndef GEDIT_H
#define GEDIT_H

#include <string>

class Gedit {
public:
  Gedit() = default;
  void start();
private:
  std::string getInput();
};

#endif
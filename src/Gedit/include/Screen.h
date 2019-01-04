#ifndef SCREEN_H
#define SCREEN_H

#include <vector>

class Screen {
public:
  static Screen* getScreen();
  ~Screen();
  void createImage(const int m, const int n);
private:
  Screen() = default;
  static Screen* screen;
  std::vector<char> pixels; // The character displays the 'colour'
};

#endif
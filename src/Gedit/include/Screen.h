#ifndef SCREEN_H
#define SCREEN_H

#include <vector>

class Screen {
public:
  static Screen* getScreen();
  ~Screen();
  void createImage(const int m, const int n);
  void clearImage();
  void print();
  void colourPixel(const int x, const int y, const char c);
private:
  Screen() = default;
  static Screen* screen;
  std::vector<char> pixels; // The character displays the 'colour'
  int m;
  int n;
};

#endif
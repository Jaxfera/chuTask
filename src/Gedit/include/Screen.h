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
  void drawVertical(const int x, const int y1, const int y2, const char c);
  void drawHorizontal(const int x1, const int x2, const int y, const char c);
  void fillRegion(const int x, const int y, const char c);
  inline int getM() const { return m; }
  inline int getN() const { return n; }
private:
  Screen() = default;
  const bool hasColour(const int x1, const int y1, const char c);
  const bool checkIfInBounds(const int x, const int y);
  const char getPixelColour(const int x, const int y);
  static Screen* screen;
  std::vector<char> pixels; // The character displays the 'colour'
  int m;
  int n;
};

#endif
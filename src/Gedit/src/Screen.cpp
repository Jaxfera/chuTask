#include "Screen.h"

#include <iostream>

Screen* Screen::screen;

Screen::~Screen() {
  delete screen;
}

Screen* Screen::getScreen() {
  if(screen == nullptr) {
    screen = new Screen();
  }
  return screen;
}

void Screen::createImage(const int m, const int n) {
  this->m = m;
  this->n = n;
  clearImage();
}

void Screen::clearImage() {
  pixels = std::vector<char>(m*n, 'O');
}

void Screen::print() {
  for(int y = 0; y < n; y++) {
    for(int x = 0; x < m; x++) {
      std::cout << pixels[m*y+x];
    }
    std::cout << '\n';
  }
}

void Screen::colourPixel(const int x, const int y, const char c) {
  pixels[y*m+x] = c;
}
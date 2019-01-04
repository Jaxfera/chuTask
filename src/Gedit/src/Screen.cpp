#include "Screen.h"

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

}
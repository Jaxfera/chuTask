#include <iostream>
#include <vector>
#include <string>

/* Commands:
 * I M N - Creates a new M x N image with all pixels coloured white (O).
 * C - Clears the table, setting all pixels to white (O).
 * L X Y C - Colours the pixel (X,Y) with colour C.
 * V X Y1 Y2 C - Draw a vertical segment of colour C in column X between rows Y1 and Y2.
 * H X1 X2 Y C - Draw a horizontal segment of colour C in row Y between columns X1 and X2.
 * F X Y C - Fill the region R with the colour C. R is defined as: Pixel (X,Y) belongs to R. Any other pixel which is the same colour as (X,Y) and shares a common side with any pixel in R also belongs tso this region.
 * S - Show the contents of the current image
 * X - Terminate the session
 */

using namespace std;

class Command {
public:
  Command() = default;
  virtual char getName();
  virtual void setName(char name);
protected:
  char name;
};

char Command::getName() {
  return name;
}

void Command::setName(char name) {
  this->name = name;
}

class Gedit {
public:
  Gedit() = default;
  void start();
private:
  void processLine();
};

void Gedit::start() {
  // Print command prompt
  cout << "> ";
  string input;
  cin >> input;
}

int main() {
  Gedit demo;
  demo.start();
}

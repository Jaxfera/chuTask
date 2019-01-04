/* Commands:
 * V X Y1 Y2 C - Draw a vertical segment of colour C in column X between rows Y1 and Y2.
 * H X1 X2 Y C - Draw a horizontal segment of colour C in row Y between columns X1 and X2.
 * F X Y C - Fill the region R with the colour C. R is defined as: Pixel (X,Y) belongs to R. Any other pixel which is the same colour as (X,Y) and shares a common side with any pixel in R also belongs tso this region.
 */

#include "Gedit.h"

int main() {
  Gedit demo;
  demo.start();
}

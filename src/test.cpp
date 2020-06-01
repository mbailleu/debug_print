#include "debug_print.h"

int main() {
  int x = 2;
  float y = 3.0;
  int & z = x;
  debug_print(x, y, z);
  debug_vars(x, y, z);
}

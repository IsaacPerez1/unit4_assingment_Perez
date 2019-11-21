#ifndef COLOR_H
#define COLOR_H
#include <string>

//Function prototypes
std::string color(int);
std::string color();

std::string color(int color) {
  return "\x1b[" + std::to_string(color) + ";1m";
}

std::string reset() {
  return "\x1b[0m";
}
#endif
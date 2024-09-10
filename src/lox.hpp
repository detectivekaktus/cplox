#ifndef LOX_HPP
#define LOX_HPP

#include <iostream>

class Lox {
public:
  Lox();
  ~Lox();
  int compile(std::string path, std::string output);
};

#endif

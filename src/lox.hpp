#ifndef LOX_HPP
#define LOX_HPP

#include <iostream>

class Lox {
public:
  Lox();
  ~Lox();
  int compile(const std::string path, const std::string output);
};

#endif

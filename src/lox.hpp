#ifndef LOX_HPP
#define LOX_HPP

#include <iostream>
using namespace std;

class Lox {
public:
  Lox();
  ~Lox();
  int runFile(const string filename);
  int runRepl();
private:
  int run(string source);
};

#endif

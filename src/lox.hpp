#ifndef LOX
#define LOX

#include <iostream>

using namespace std;

class Lox {
public:
  Lox();
  ~Lox();
  int runFile(string source);
  int runRepl();
private:
  int run(string source);
};

Lox::Lox() {

}

Lox::~Lox() {

}

#endif

#include "lox.hpp"

int main(int argc, char **argv) {
  if (argc > 2) {
    cout << "Usage: " << argv[0] << " [ script.lox ]" << endl;
    exit(64);
  }
  auto lox = new Lox();
  if (argc == 2) {
    lox->runFile(argv[1]);
  } else {
    lox->runRepl();
  }
  return 0;
}

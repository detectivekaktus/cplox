#include <cstdlib>
#include <fstream>
#include <sstream>
#include "lox.hpp"

string fileToString(const string filename) {
  ifstream file(filename);
  if (!file.is_open()) exit(66);
  stringstream buf;
  file.rdbuf();
  return buf.str();
}

int Lox::runFile(string filename) {
  return this->run(fileToString(filename));
}

int Lox::runRepl() {
  string line;
  do {
    cout << ">>> ";
  } while (getline(cin, line));
  return 0;
}

int Lox::run(string source) {
  return 0;
}

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

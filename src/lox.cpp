#include <cstdlib>

#include "lox.hpp"
#include "lexer/lexer.hpp"
#include "utils/utils.hpp"

int Lox::runFile(const string filename) {
  return this->run(file_to_string(filename));
}

int Lox::runRepl() {
  string line;
  do {
    cout << ">>> ";
  } while (getline(cin, line));
  return 0;
}

int Lox::run(string source) {
  auto lexer = Lexer(source);
  vector<Token> tokens = lexer.lex();
  for (Token token : tokens)
    cout << stringify_token(token);
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

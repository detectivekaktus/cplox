#include "lox.hpp"
#include "lexer/lexer.hpp"
#include "utils/utils.hpp"

Lox::Lox() {}

Lox::~Lox() {}

int Lox::compile(const std::string path, const std::string output) {
  auto lexer = std::make_unique<Lexer>(file2String(path));
  auto tokens = lexer->lex();
  for (const Token& token : *tokens) {
    std::cout << stringify_token(token) << std::endl;
  }
  return 0;
}

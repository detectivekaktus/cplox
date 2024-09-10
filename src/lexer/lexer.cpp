#include "lexer.hpp"

Lexer::Lexer() {}

Lexer::~Lexer() {}

std::unique_ptr<std::vector<Token>> Lexer::lex(const std::string source) {
  auto tokens = std::make_unique<std::vector<Token>>();
  return tokens;
}

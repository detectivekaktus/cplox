#include "lox.hpp"
#include "lexer/lexer.hpp"
#include "utils/utils.hpp"

Lox::Lox() {}

Lox::~Lox() {}

int Lox::compile(const std::string path, const std::string output) {
  auto lexer = std::make_unique<Lexer>(file2String(path));
  auto tokens = lexer->lex();
  if (lexer->hadError) {
    std::cerr << "Too many errors. Aborting..." << std::endl;
    exit(1);
  }
  for (const Token& token : *tokens)
    std::cout << token.val << std::endl;
  return 0;
}

#include "lox.hpp"
#include "lexer/lexer.hpp"
#include "parser/parser.hpp"
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
  auto parser = std::make_unique<Parser>(std::move(tokens));
  auto stmts = parser->parse();
  if (parser->hadError) {
    std::cerr << "Too many errors. Aborting..." << std::endl;
    exit(1);
  }
  for (const Statement& stmt : *stmts)
    std::cout << std::to_string(static_cast<int>(stmt.type)) << " " << stmt.left << " " << stmt.op << " " << stmt.right << std::endl;
  return 0;
}

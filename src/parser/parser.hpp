#ifndef LOX_PARSER
#define LOX_PARSER

#include <string>
#include <memory>
#include <vector>
#include "../lexer/lexer.hpp"

enum class StatementType {
  VAR_DECLARATION
};

typedef struct {
  StatementType type;
  std::string left;
  std::string op;
  std::string right;
} Statement;

class Parser {
public:
  Parser(const std::unique_ptr<std::vector<Token>> tokens);
  ~Parser();
  std::unique_ptr<std::vector<Statement>> parse();

  size_t errors;
  bool hadError;
private:
  std::unique_ptr<std::vector<Token>> tokens;
  std::unique_ptr<std::vector<Statement>> stmts;
};

#endif

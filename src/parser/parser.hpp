#ifndef LOX_PARSER
#define LOX_PARSER

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "../lexer/lexer.hpp"

enum class StatementType {
  VAR_DECLARATION,
  EXPRESSION,
  PRINT
};

typedef struct {
  StatementType type;
  std::string left;
  std::string right;
} Statement;

enum class ExpressionType {
  EQUALITY,
  COMPARISON,
  TERM,
  FACTOR,
  UNARY,
  PRIMARY
};

typedef struct {
  ExpressionType type;
  std::string val;
} Expression;

class Parser {
public:
  Parser(std::unique_ptr<std::vector<Token>>&& tokens);
  ~Parser();
  std::unique_ptr<std::vector<Statement>> parse();

  size_t errors;
  bool hadError;
private:
  std::unique_ptr<std::vector<Token>> tokens;
  std::unique_ptr<std::vector<Statement>> stmts;

  size_t cur;
  bool expect(TokenType type);
  Token shift(TokenType type, std::string msg);
  void consume(TokenType type, std::string msg);

  Statement declaration();
  Statement statement();
  Statement print();
  Statement expressionStatement();

  Expression expression();
  Expression equality();
  Expression term();
  Expression factor();
  Expression unary();
  Expression primary();
};

#endif

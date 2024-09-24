#include "parser.hpp"

Parser::Parser(std::unique_ptr<std::vector<Token>>&& tokens) {
  this->tokens = std::move(tokens);
  this->errors = 0;
  this->hadError = false;
  this->stmts = std::make_unique<std::vector<Statement>>();
  this->cur = 0;
}

Parser::~Parser() { }

bool Parser::expect(TokenType type) {
  if (this->tokens->at(this->cur).type == type) {
    this->cur++;
    return true;
  }
  return false;
}

Token Parser::shift(TokenType type, std::string msg) {
  if (this->tokens->at(this->cur).type == type) {
    this->cur++;
    return this->tokens->at(this->cur - 1);
  }
  this->errors++;
  this->hadError = true;
  return NULL;
}

void Parser::consume(TokenType type, std::string msg) {
  if (this->tokens->at(this->cur).type == type) {
    this->cur++;
    return true;
  }
  this->errors++;
  this->hadError = true;
  std::cerr << msg << std::endl;
  return false;
}

std::unique_ptr<std::vector<Statement>> Parser::parse() {
  Token tkn = this->tokens[this->cur];
  while (tkn.type != TokenType::END_OF_FILE) {
    this->stmts->push_back(this->declaration());
    tkn = this->token[++this->cur];
  }
  return std::move(this->stmts);
}

Statement Parser::declaration() {
  if (this->expect(TokenType::VAR)) {
    Statement stmt;
    stmt.type = StatementType::VAR_DECLARATION;
    Token tkn = this->shift(TokenType::IDENTIFIER, "Expected identifier after `var` keyword.");
    stmt.left = tkn.val;
    if (this->expect(TokenType::EQUAL)) {
      Expression expr = this->expression();
      stmt.right = expr.val;
    }
    this->consume(TokenType::SEMICOLON, "Expected semicolon after a statement.");
    return stmt;
  }
  else this->statement();
}

Statement Parser::statement() {
  if (this->expect(TokenType::PRINT))
    this->print();
  else
    this->expressionStatement();
}

Statement Parser::print() {
  Statement stmt;
  stmt.type = StatementType::PRINT;
  Expression expr = this->expression();
  stmt.right = expr.val;
  this->consume(TokenType::SEMICOLON, "Expected semicolon after a statement.");
  return stmt;
}

Statement Parser::expressionStatement() {
  Statement stmt;
  stmt.type = StatementType::EXPRESSION;
  Expression expr = this->expression();
  stmt.left = expr.val;
  this->consume(TokenType::SEMICOLON, "Expected semicolon after a statement.");
  return stmt;
}

// Taken from https://craftinginterpreters.com/parsing-expressions.html
//
// The grammar schema of the Lox programming language is the following:
// expression -> equality ;
// equality   -> comparison ( ( "!=" | "==" ) comparison )* ;
// comparison -> term ( ( ">" | ">=" | "<" | "<=" ) term )* ;
// term       -> factor ( ( "-" | "+" ) factor )* ;
// factor     -> unary ( ( "/" | "*" ) unary )* ;
// unary      -> ( "!" | "-" ) unary | primary ;
// primary    -> NUMBER | STRING | "true" | "false" | "nil" | "(" expression ")" ;

Expression Parser::expression() {
  return equality();
}

Expression Parser::equality() {

}

Expression Parser::comparison() {

}

Expression Parser::term() {

}

Expression Parser::factor() {

}

Expression Parser::unary() {

}

Expression Parser::primary() {

}

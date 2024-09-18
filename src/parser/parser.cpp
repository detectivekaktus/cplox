#include "parser.hpp"

Parser::Parser(std::unique_ptr<std::vector<Token>>&& tokens) {
  this->tokens = std::move(tokens);
  this->errors = 0;
  this->hadError = false;
  this->stmts = std::make_unique<std::vector<Statement>>();
  this->cur = 0;
}

Parser::~Parser() { }

void Parser::addStatement(std::vector<Token> *tkns) {
  uint32_t i = 0;
  switch (tkns->at(i).type) {
    case TokenType::VAR: {
      Statement stmt;
      stmt.type = StatementType::VAR_DECLARATION;
      stmt.left = tkns->at(++i).val;
      stmt.op = tkns->at(++i).val;
      stmt.right = tkns->at(++i).val;
      this->stmts->push_back(stmt);
    } break;
    case TokenType::IDENTIFIER: {
      Statement stmt;
      stmt.type = StatementType::VAR_REFERENCE;
      stmt.left = tkns->at(i++).val;
      this->stmts->push_back(stmt);
    } break;
    default: {
      assert(0 && "Not implemented");
    } break;
  }
}

std::unique_ptr<std::vector<Statement>> Parser::parse() {
  while (this->tokens->at(this->cur).type != TokenType::END_OF_FILE) {
    Token tkn = this->tokens->at(this->cur);
    std::vector<Token> tkns;
    while (tkn.type != TokenType::END_OF_FILE) {
      if (tkn.type == TokenType::SEMICOLON) {
        tkns.push_back(tkn);
        this->cur++;
        break;
      }
      tkns.push_back(tkn);
      tkn = this->tokens->at(++this->cur);
    }
    if (tkn.type != TokenType::SEMICOLON && tkn.type != TokenType::END_OF_FILE) {
      std::cerr << "Statement wasn't closed with a semicolon" << std::endl;
      this->hadError = true;
      this->errors++;
    }
    this->addStatement(&tkns);
  }
  return std::move(this->stmts);
}

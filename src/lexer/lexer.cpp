#include "lexer.hpp"

string ttypetostr(TokenType type) {
  switch (type) {
    case TokenType::VAR:         return "VAR";
    case TokenType::EQUAL:       return "EQUAL";
    case TokenType::SEMICOLON:   return "SEMICOLON";
    case TokenType::IDENTIFIER:  return "IDENTIFIER";
    case TokenType::NUMBER:      return "NUMBER";
    case TokenType::STRING:      return "STRING";
    case TokenType::END_OF_FILE: return "END_OF_FILE";
  }
}

string stringify_token(Token token) {
  stringstream ss;
  ss << "{type: " << ttypetostr(token.type) << ", val: \"" << token.val << "\"}";
  return ss.str();
}

Lexer::Lexer(string source) {
  this->source = source;
  this->pos = 0;
}

Lexer::~Lexer() { }

void Lexer::advance() {
  this->pos++;
}

bool Lexer::isAtEnd() {
  return this->pos >= this->source.length();
}

vector<Token> Lexer::lex() {
  vector<Token> tokens;
  while (!this->isAtEnd()) {
    advance();
  }
  tokens.push_back({.type=TokenType::END_OF_FILE, .val=""});
  return tokens;
}

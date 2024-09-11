#include "lexer.hpp"

Lexer::Lexer(const std::string source) {
  this->cur = 0;
  this->errors = 0;
  this->hadError = false;
  this->source = source;
  this->tokens = std::make_unique<std::vector<Token>>();
}

Lexer::~Lexer() { }

bool Lexer::isAtEnd() {
  return this->cur >= this->source.length();
}

void Lexer::addToken(TokenType type, std::string val) {
  Token token;
  token.type = type;
  token.val = val;
  this->tokens->push_back(token);
  this->cur++;
}

void Lexer::error(std::string msg) {
  std::cerr << msg << std::endl;
  this->hadError = true;
  this->errors++;
}

std::unique_ptr<std::vector<Token>> Lexer::lex() {
  while (!this->isAtEnd()) {
    char c = this->source[this->cur];
    switch (c) {
      case '(': this->addToken(TokenType::LEFT_PAREN, "("); break;
      case ')': this->addToken(TokenType::RIGHT_PAREN, ")"); break;
      case '{': this->addToken(TokenType::LEFT_BRACE, "{"); break;
      case '}': this->addToken(TokenType::RIGHT_BRACE, "}"); break;
      case ',': this->addToken(TokenType::COMMA, ","); break;
      case '.': this->addToken(TokenType::DOT, "."); break;
      case '-': this->addToken(TokenType::MINUS, "-"); break;
      case '+': this->addToken(TokenType::PLUS, "+"); break;
      case ';': this->addToken(TokenType::SEMICOLON, ";"); break;
      case '*': this->addToken(TokenType::STAR, "*"); break;
      
      case ' ': case '\n': case '\r': case '\t': this->cur++; break;

      default: {
        this->error("Unknown token " + c);
      } break;
    }
  }
  this->addToken(TokenType::END_OF_FILE, "EOF");
  return std::move(this->tokens);
}

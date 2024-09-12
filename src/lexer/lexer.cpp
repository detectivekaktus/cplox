#include "lexer.hpp"

Lexer::Lexer(const std::string source) {
  this->cur = 0;
  this->displayColumn = 0;
  this->displayLine = 0;
  this->errors = 0;
  this->hadError = false;
  this->source = source;
  this->tokens = std::make_unique<std::vector<Token>>();
}

Lexer::~Lexer() { }

bool Lexer::isAtEnd() {
  return this->cur >= this->source.length();
}

void Lexer::advance() {
  this->cur++;
  this->displayColumn++;
}

bool Lexer::isNext(const char c) {
  if (this->isAtEnd()) return false;
  if (this->source[this->cur + 1] != c) return false;
  this->advance();
  return true;
}

void Lexer::addToken(TokenType type, std::string val) {
  Token token;
  token.type = type;
  token.val = val;
  this->tokens->push_back(token);
  this->advance();
}

void Lexer::error(std::string msg) {
  std::cerr << msg << std::endl;
  this->hadError = true;
  this->errors++;
  this->cur++;
  this->displayColumn++;
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
      case '/': {
        if (this->isNext('/')) {
          this->advance();
          while (this->source[this->cur] != '\n' && !this->isAtEnd()) this->advance();
        }
        else this->addToken(TokenType::SLASH, "/");
      } break;
      case '"': {
        size_t start = this->cur;
        this->advance();
        while ((this->source[this->cur] != '\n' && this->source[this->cur] != '"') && !this->isAtEnd())
          this->advance();
        if (this->source[this->cur] == '\n' || this->isAtEnd())
          this->error(std::to_string(this->displayLine + 1) + ":" + std::to_string(this->displayColumn + 1) + " Unterminated string literal");
        std::string str = this->source.substr(start, cur - start);
        str.erase(0, 1);
        str.erase(str.length(), 1);
        this->addToken(TokenType::STRING, str);
      } break;

      case '=': this->isNext('=') ? this->addToken(TokenType::EQUAL_EQUAL, "==")   : this->addToken(TokenType::EQUAL, "="); break;
      case '!': this->isNext('=') ? this->addToken(TokenType::BANG_EQUAL, "!=")    : this->addToken(TokenType::BANG, "!"); break;
      case '>': this->isNext('=') ? this->addToken(TokenType::GREATER_EQUAL, ">=") : this->addToken(TokenType::GREATER, ">"); break;
      case '<': this->isNext('=') ? this->addToken(TokenType::LESS_EQUAL, "<=")    : this->addToken(TokenType::LESS, "<"); break;
      
      case ' ': case '\r': case '\t': this->advance(); break;
      case '\n': {
        this->cur++;
        this->displayColumn = 0;
        this->displayLine++;
      } break;

      default: {
        if (isdigit(c)) {
          size_t start = this->cur;
          while (isdigit(this->source[this->cur]) && !this->isAtEnd()) this->advance();
          if (this->source[this->cur] == '.') {
            this->advance();
            while (isdigit(this->source[this->cur]) && !this->isAtEnd()) this->advance();
          }
          this->addToken(TokenType::NUMBER, this->source.substr(start, this->cur - start));
        }
        else
          this->error(std::to_string(this->displayLine + 1) + ":" + std::to_string(this->displayColumn + 1) +
                      " Unexpected character found: `" + std::string(1, c) + "`");
      } break;
    }
  }
  this->addToken(TokenType::END_OF_FILE, "EOF");
  return std::move(this->tokens);
}

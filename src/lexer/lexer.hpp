#ifndef LOX_LEXER
#define LOX_LEXER

#include <cctype>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

enum class TokenType {
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, STAR, SLASH,
  
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  IDENTIFIER, NUMBER, STRING,

  AND, CLASS, ELSE, FALSE, TRUE, FOR,
  IF, NIL, OR, PRINT, RETURN, SUPER, THIS,
  VAR, WHILE,

  END_OF_FILE
};

static std::unordered_map<std::string, TokenType> keywords = {
  {"and", TokenType::AND},
  {"class", TokenType::CLASS},
  {"else", TokenType::ELSE},
  {"true", TokenType::TRUE},
  {"false", TokenType::FALSE},
  {"for", TokenType::FOR},
  {"if", TokenType::IF},
  {"nil", TokenType::NIL},
  {"or", TokenType::OR},
  {"print", TokenType::PRINT},
  {"return", TokenType::RETURN},
  {"super", TokenType::SUPER},
  {"this", TokenType::THIS},
  {"var", TokenType::VAR},
  {"while", TokenType::WHILE},
};

typedef struct {
  TokenType type;
  std::string val;
} Token;

class Lexer {
public:
  Lexer(const std::string source);
  ~Lexer();
  std::unique_ptr<std::vector<Token>> lex();

  size_t errors;
  bool hadError;
private:
  size_t displayColumn;
  size_t displayLine;

  size_t cur;
  std::string source;
  std::unique_ptr<std::vector<Token>> tokens;

  bool isAtEnd();
  void advance();
  bool isNext(const char c);

  void addToken(TokenType type, std::string val);
  void error(std::string msg);

  bool isAlpha(char c);
  bool isAlphaNumeric(char c);
};

#endif

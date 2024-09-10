#ifndef LOX_LEXER
#define LOX_LEXER

#include <iostream>
#include <vector>
#include <string>
#include <memory>

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

typedef struct {
  TokenType type;
  std::string val;
} Token;

class Lexer {
public:
  Lexer(const std::string source);
  ~Lexer();
  std::unique_ptr<std::vector<Token>> lex();
};

#endif

#ifndef LOX_LEXER
#define LOX_LEXER

#include <vector>
#include <string>
#include <memory>

enum class TokenType {
  EQUAL,
  SEMICOLON,

  IDENTIFIER,
  NUMBER,
  STRING,

  END_OF_FILE
};

typedef struct {
  TokenType type;
  std::string val;
} Token;

class Lexer {
public:
  Lexer();
  ~Lexer();
  std::unique_ptr<std::vector<Token>> lex(const std::string source);
};

#endif

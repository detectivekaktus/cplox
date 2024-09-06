#ifndef LOX_LEXER_HPP
#define LOX_LEXER_HPP

#include <sstream>
#include <vector>
using namespace std;

enum class TokenType {
  VAR,
  EQUAL,
  SEMICOLON,

  IDENTIFIER,
  NUMBER,
  STRING,
  
  END_OF_FILE
};

typedef struct {
  TokenType type;
  string val;
} Token;

class Lexer {
public:
  Lexer(string source);
  ~Lexer();
  vector<Token> lex();
private:
  int pos;
  string source;

  void advance();
  bool isAtEnd();
};

string stringify_token(Token token);

#endif

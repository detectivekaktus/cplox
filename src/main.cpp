#include "lox.hpp"
#include <memory>

#define WRONG_ARGS 64

void usage(std::string name) {
  std::cout << "Usage: " << name << " [ script.lox ]" << std::endl;
  std::cout << "  -c: compiles the source lox script to javascript" << std::endl;
  std::cout << "  -o: outputs a javascript script with a user-defined name" << std::endl;
}

void crash(std::string name, std::string msg, int exitCode) {
  std::cout << msg << std::endl;
  usage(name);
  exit(exitCode);
}

int main(int argc, char **argv) {
  if (argc < 2) crash(argv[0], "Not enough arguments.", WRONG_ARGS);

  std::string inputFile;
  std::string outputFile = "out.js";
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-o") {
      if (i + 1 < argc) outputFile = (std::string) argv[i];
      else crash(argv[0], "-o flag requires a new filename.", WRONG_ARGS);
    }
    else inputFile = arg;
  }

  auto lox = std::make_unique<Lox>();
  lox->compile(inputFile, outputFile);

  return 0;
}

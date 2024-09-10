#include "utils.hpp"

std::string file2String(const std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) exit(66);
  std::stringstream buf;
  file.rdbuf();
  return buf.str();
}

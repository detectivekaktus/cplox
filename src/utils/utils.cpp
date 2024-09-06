#include "utils.hpp"

string file_to_string(const string filename) {
  ifstream file(filename);
  if (!file.is_open()) exit(66);
  stringstream buf;
  file.rdbuf();
  return buf.str();
}

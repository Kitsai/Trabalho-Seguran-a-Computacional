#include <iostream>
#include <utility>

#include "../include/Permutations.h"
#include "../include/Transformer.h"
#include "../include/defines.h"

int main() {
  block entrada("10100100");

  block perm = Permutations::inverse_ip(Permutations::ip(entrada));

  std::cout << perm << '\n';

  return 0;
}

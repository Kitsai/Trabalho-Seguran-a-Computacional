#ifndef PERMUTATOR_H
#define PERMUTATOR_H

#include "defines.h"
#include <bitset>

class Permutations {
public:
  static main_key p10(const main_key chave);
  static sub_key p8(const main_key chave);
  static block ip(const block bloco);
  static block inverse_ip(const block bloco);
  static block ep(const half_block bloco);
  static half_block p4(const half_block bloco);
  static block switch_halfs(const block bloco);
  static half_block ls1(const half_block bloco);
  static half_main_key ls1(const half_main_key chave);
};
#endif // !PERMUTATOR_H

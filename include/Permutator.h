#ifndef PERMUTATOR_H
#define PERMUTATOR_H

#include "defines.h"
#include <bitset>

class Permutator {
public:
  [[nodiscard]] static main_key p10(const main_key chave);
  [[nodiscard]] static sub_key p8(const main_key chave);
  [[nodiscard]] static block ip(const block bloco);
  [[nodiscard]] static block inverse_ip(const block bloco);
  [[nodiscard]] static block ep(const half_block bloco);
  [[nodiscard]] static half_block p4(const half_block bloco);
  [[nodiscard]] static block switch_halfs(const sub_key chave);
};
#endif // !PERMUTATOR_H

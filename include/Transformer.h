#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "defines.h"
#include <string>
#include <utility>

class Transformer {
public:
  static std::pair<quarter_block, quarter_block>
  separate(const half_block bloco);
  static std::pair<half_block, half_block> separate(const block bloco);
  static std::pair<half_main_key, half_main_key> separate(const main_key chave);
  static half_block combine(const quarter_block b1, const quarter_block b2);
  static block combine(const half_block b1, const half_block b2);
  static main_key combine(const half_main_key k1, const half_main_key k2);
  static block transform_input(const std::string entrada);
  static main_key transform_key(const std::string chave);
};
#endif // !TRANSFORMER_H

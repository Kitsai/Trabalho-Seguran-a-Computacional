#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "defines.h"
#include <utility>

class Transformer {
public:
  static std::pair<quarter_block, quarter_block>
  separate(const half_block bloco);
  static std::pair<half_block, half_block> separate(const block bloco);

  static half_block combine(const quarter_block b1, const quarter_block b2);
  static block combine(const half_block b1, const half_block b2);
};
#endif // !TRANSFORMER_H

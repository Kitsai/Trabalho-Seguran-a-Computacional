#include "../include/Transformer.h"
#include <utility>

std::pair<quarter_block, quarter_block>
Transformer::separate(const half_block bloco) {
  quarter_block first;
  quarter_block second;

  first[0] = bloco[0];
  first[1] = bloco[1];

  second[0] = bloco[2];
  second[1] = bloco[3];

  return {first, second};
}

std::pair<half_block, half_block> Transformer::separate(const block bloco) {
  half_block first;
  half_block second;

  for (int i = 0; i < 4; i++)
    first[i] = bloco[i];

  for (int i = 0; i < 4; i++)
    second[i] = bloco[i + 4];

  return {first, second};
}

block Transformer::combine(const half_block b1, const half_block b2) {
  block ret;

  for (int i = 0; i < 8; i++)
    ret[i] = (i < 4) ? b1[i] : b2[i - 4];

  return ret;
}

half_block Transformer::combine(const quarter_block b1,
                                const quarter_block b2) {
  half_block ret;

  for (int i = 0; i < 8; i++)
    ret[i] = (i < 4) ? b1[i] : b2[i - 4];

  return ret;
}

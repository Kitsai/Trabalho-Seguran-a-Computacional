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

  return {second, first};
}

std::pair<half_block, half_block> Transformer::separate(const block bloco) {
  half_block first;
  half_block second;

  for (int i = 0; i < 4; i++)
    first[i] = bloco[i];

  for (int i = 0; i < 4; i++)
    second[i] = bloco[i + 4];

  return {second, first};
}

std::pair<half_main_key, half_main_key>
Transformer::separate(const main_key chave) {
  half_main_key first;
  half_main_key second;

  for (int i = 0; i < 5; i++)
    first[i] = chave[i];

  for (int i = 0; i < 5; i++)
    second[i] = chave[i + 5];

  return {second, first};
}

block Transformer::combine(const half_block left, const half_block right) {
  block ret;

  for (int i = 0; i < 8; i++)
    ret[i] = (i < 4) ? right[i] : left[i - 4];

  return ret;
}

half_block Transformer::combine(const quarter_block left,
                                const quarter_block right) {
  half_block ret;

  for (int i = 0; i < 4; i++)
    ret[i] = (i < 2) ? right[i] : left[i - 2];

  return ret;
}

main_key Transformer::combine(const half_main_key left,
                              const half_main_key right) {
  main_key ret;

  for (int i = 0; i < 10; i++)
    ret[i] = (i < 5) ? right[i] : left[i - 5];

  return ret;
}

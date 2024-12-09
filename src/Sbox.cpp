#include "../include/Sbox.h"

Sbox::Sbox(sbox_matrix matrix) : matrix(matrix) {}

quarter_block Sbox::apply(half_block bloco) {
  const char row = get_row_bits(bloco);

  const char col = get_col_bits(bloco);

  const char ret = matrix[col][row];

  return quarter_block(ret);
}

char Sbox::get_row_bits(const half_block bloco) const {
  quarter_block ret;
  ret[0] = bloco[3];
  ret[1] = bloco[0];

  unsigned long long retUll = ret.to_ullong();
  return static_cast<char>(retUll);
}

char Sbox::get_col_bits(const half_block bloco) const {
  quarter_block ret;
  ret[0] = bloco[2];
  ret[1] = bloco[1];

  unsigned long long retUll = ret.to_ullong();
  return static_cast<char>(retUll);
}

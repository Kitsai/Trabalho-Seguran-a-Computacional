#include "../include/Sbox.h"

Sbox::Sbox(sbox_matrix matrix) : matrix(matrix) {}

quarter_block Sbox::apply(half_block bloco) {
  ull row = get_row_bits(bloco);

  ull col = get_col_bits(bloco);

  ull ret = matrix[row][col];

  return quarter_block(ret);
}

ull Sbox::get_row_bits(const half_block bloco) const {
  quarter_block ret;
  ret[0] = bloco[0];
  ret[1] = bloco[3];

  return ret.to_ullong();
}

ull Sbox::get_col_bits(const half_block bloco) const {
  quarter_block ret;
  ret[0] = bloco[1];
  ret[1] = bloco[2];

  return ret.to_ullong();
}

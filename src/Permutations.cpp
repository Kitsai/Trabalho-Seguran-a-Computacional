#include "../include/Permutations.h"

main_key Permutations::p10(const main_key chave) {
  main_key ret;
  for (int i = 0; i < 10; i++)
    ret[i] = chave[p10_order[i]];

  return ret;
}

sub_key Permutations::p8(const main_key chave) {
  sub_key ret;
  for (int i = 0; i < 8; i++)
    ret[i] = chave[p8_order[i]];

  return ret;
}

block Permutations::ip(const block bloco) {
  block ret;
  for (int i = 0; i < 8; i++)
    ret[i] = bloco[ip_order[i]];

  return ret;
}

block Permutations::inverse_ip(const block bloco) {
  block ret;
  for (int i = 0; i < 8; i++)
    ret[i] = bloco[inverse_ip_order[i]];

  return ret;
}

block Permutations::ep(const half_block bloco) {
  block ret;
  for (int i = 0; i < 8; i++)
    ret[i] = bloco[ep_order[i]];

  return ret;
}

half_block Permutations::p4(const half_block bloco) {
  half_block ret;
  for (int i = 0; i < 4; i++)
    ret[i] = bloco[p4_order[i]];

  return ret;
}

block Permutations::switch_halfs(const block bloco) {
  block ret;
  for (int i = 0; i < 4; i++)
    ret[i] = bloco[i + 4];

  for (int i = 0; i < 4; i++)
    ret[i + 4] = bloco[i];

  return ret;
}

half_block Permutations::ls1(const half_block bloco) {
  half_block ret = bloco << 1;
  ret[3] = bloco[0];
  return ret;
}

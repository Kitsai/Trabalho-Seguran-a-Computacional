#include "../include/Permutations.h"

main_key Permutations::p10(const main_key chave) {
  main_key ret;
  for (int i = 0; i < 10; i++)
    ret[9 - i] = chave[9 - p10_order[i]];

  return ret;
}

sub_key Permutations::p8(const main_key chave) {
  sub_key ret;
  for (int i = 0; i < 8; i++)
    ret[7 - i] = chave[9 - p8_order[i]];

  return ret;
}

block Permutations::ip(const block bloco) {
  block ret;
  for (int i = 0; i < 8; i++)
    ret[7 - i] = bloco[7 - ip_order[i]];

  return ret;
}

block Permutations::inverse_ip(const block bloco) {
  block ret;
  for (int i = 0; i < 8; i++)
    ret[7 - i] = bloco[7 - inverse_ip_order[i]];

  return ret;
}

block Permutations::ep(const half_block bloco) {
  block ret;
  for (int i = 0; i < 8; i++)
    ret[7 - i] = bloco[3 - ep_order[i]];

  return ret;
}

half_block Permutations::p4(const half_block bloco) {
  half_block ret;
  for (int i = 0; i < 4; i++)
    ret[3 - i] = bloco[3 - p4_order[i]];

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
  ret[0] = bloco[3];
  return ret;
}

half_main_key Permutations::ls1(const half_main_key chave) {
  half_main_key ret = chave << 1;
  ret[0] = chave[4];
  return ret;
}

half_main_key Permutations::ls2(const half_main_key chave) {
  half_main_key ret = chave << 2;
  ret[0] = chave[3];
  ret[1] = chave[4];
  return ret;
}

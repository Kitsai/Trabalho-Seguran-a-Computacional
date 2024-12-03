#include "../include/Permutator.h"

main_key Permutator::p10(const main_key chave) {
  main_key ret;
  for (int i = 0; i < 10; i++)
    ret[i] = chave[p10_order[i]];

  return ret;
}

sub_key Permutator::p8(const main_key chave) {
  sub_key ret;
  for (int i = 0; i < 8; i++)
    ret[i] = chave[p8_order[i]];

  return ret;
}

block Permutator::ip(const block bloco) {
  block ret;
  for (int i = 0; i < 8; i++)
    ret[i] = bloco[ip_order[i]];

  return ret;
}

block Permutator::inverse_ip(const block bloco) {
  block ret;
  for (int i = 0; i < 8; i++)
    ret[i] = bloco[inverse_ip_order[i]];

  return ret;
}

block Permutator::ep(const half_block bloco) {
  block ret;
  for (int i = 0; i < 8; i++)
    ret[i] = bloco[ep_order[i]];

  return ret;
}

half_block Permutator::p4(const half_block bloco) {
  half_block ret;
  for (int i = 0; i < 4; i++)
    ret[i] = bloco[p4_order[i]];

  return ret;
}

block Permutator::switch_halfs(const block bloco) {
  block ret;
  for (int i = 0; i < 4; i++)
    ret[i] = bloco[i + 4];

  for (int i = 0; i < 4; i++)
    ret[i + 4] = bloco[i];

  return ret;
}

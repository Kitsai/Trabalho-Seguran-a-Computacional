#include "../include/FeistelRound.h"
#include "../include/Permutations.h"
#include "../include/Transformer.h"

// Exemplo de inicialização das sboxes
FeistelRound::FeistelRound(sub_key chave)
    : kx(chave), s0(s0_matrix), s1(s1_matrix) {}

FeistelRound::FeistelRound() : kx(), s0(s0_matrix), s1(s1_matrix) {}

void FeistelRound::set_key(sub_key kx) { this->kx = kx; }

block FeistelRound::apply(block caracter) {
  auto sep_char = Transformer::separate(caracter);

  half_block fresult = fFunc(sep_char.second);

  half_block XORresult = sep_char.first ^ fresult;

  return Transformer::combine(XORresult, sep_char.second);
}

half_block FeistelRound::fFunc(half_block bloco) {
  block expResult = Permutations::ep(bloco);

  block XOR_result = expResult ^ kx;

  auto sep_char = Transformer::separate(XOR_result);

  quarter_block s0_res = s0.apply(sep_char.first);
  quarter_block s1_res = s1.apply(sep_char.second);

  half_block sbox_result = Transformer::combine(s0_res, s1_res);

  return Permutations::p4(sbox_result);
}

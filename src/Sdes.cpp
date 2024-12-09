#include "../include/Sdes.h"
#include "../include/FeistelRound.h"
#include "../include/KeyGenerator.h"
#include "../include/Permutations.h"
#include <cassert>
#include <climits>

Sdes::Sdes(main_key chave) : f1(), f2() {
  std::pair<sub_key, sub_key> subkeys = KeyGenerator::generateSubKeys(chave);

  f1.set_key(subkeys.first);
  f2.set_key(subkeys.second);
}

block Sdes::encrypt(block plainText) {
  plainText = Permutations::ip(plainText);

  plainText = f1.apply(plainText);

  plainText = Permutations::switch_halfs(plainText);

  plainText = f2.apply(plainText);

  plainText = Permutations::inverse_ip(plainText);

  return plainText;
}

block Sdes::decrypt(block cypherText) {
  cypherText = Permutations::ip(cypherText);
  cypherText = f2.apply(cypherText);
  cypherText = Permutations::switch_halfs(cypherText);
  cypherText = f1.apply(cypherText);
  cypherText = Permutations::inverse_ip(cypherText);

  return cypherText;
}

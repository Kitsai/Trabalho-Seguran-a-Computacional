#include "../include/Sdes.h"
#include "../include/FeistelRound.h"
#include "../include/KeyGenerator.h"
#include "../include/Permutator.h"
#include <cassert>
#include <climits>

Sdes::Sdes(main_key chave) : f1(), f2() {
  std::pair<sub_key, sub_key> subkeys = KeyGenerator::generateSubKeys(chave);

  f1.set_key(subkeys.first);
  f2.set_key(subkeys.second);
}

std::string Sdes::encrypt(std::string plainText, main_key chave) {
  std::string ret = "";
  for (char c : plainText) {
    ret += encrypt_char(c);
  }

  return ret;
}

char Sdes::encrypt_char(const char c) {
  block b(c);

  b = apply_encryption(b);

  unsigned long long i = b.to_ullong();
  return static_cast<char>(i);
}

block Sdes::apply_encryption(block b) {
  b = Permutator::ip(b);

  b = f1.apply(b);

  b = Permutator::switch_halfs(b);

  b = f2.apply(b);

  b = Permutator::inverse_ip(b);

  return b;
}

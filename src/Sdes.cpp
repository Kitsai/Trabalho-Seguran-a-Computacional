#include "../include/Sdes.h"
#include "../include/FeistelRound.h"
#include "../include/KeyGenerator.h"
#include "../include/Permutations.h"
#include <cassert>
#include <climits>
#include <string>

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
  b = Permutations::ip(b);

  b = f1.apply(b);

  b = Permutations::switch_halfs(b);

  b = f2.apply(b);

  b = Permutations::inverse_ip(b);

  return b;
}

std::string Sdes::decrypt(std::string cypherText, main_key chave) {
  std::string ret = "";
  for (char c : cypherText) {
    ret += decrypt_char(c);
  }

  return ret;
}

char Sdes::decrypt_char(const char c) {
  block b(c);

  b = apply_decryption(b);

  unsigned long long i = b.to_ullong();
  return static_cast<char>(i);
}

block Sdes::apply_decryption(block b) {
  b = Permutations::ip(b);
  b = f2.apply(b);
  b = Permutations::switch_halfs(b);
  b = f1.apply(b);
  b = Permutations::inverse_ip(b);

  return b;
}

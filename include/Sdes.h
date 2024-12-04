#ifndef SDES_H
#define SDES_H

#include "FeistelRound.h"
#include "defines.h"
#include <bitset>
#include <string>

class Sdes {
private:
  FeistelRound f1;
  FeistelRound f2;

public:
  Sdes(main_key chave);
  std::string encrypt(std::string plainText, main_key chave);
  std::string decrypt(std::string cypherText, main_key chave);

private:
  char encrypt_char(const char c);
  block apply_encryption(block b);
  char decrypt_char(const char c);
  block apply_decryption(block b);
};
#endif // !SDES_H

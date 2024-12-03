#ifndef SDES_H
#define SDES_H

#include "defines.h"
#include <bitset>
#include <string>

class Sdes {
public:
  std::string encrypt(std::string plainText, main_key chave);
  std::string decrypt(std::string cypherText, main_key chave);
};
#endif // !SDES_H

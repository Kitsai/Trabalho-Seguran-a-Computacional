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
  block encrypt(block plainText);
  block decrypt(block cypherText);
};
#endif // !SDES_H

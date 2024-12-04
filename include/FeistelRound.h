#ifndef FEISTEL_ROUND_H
#define FEISTEL_ROUND_H

#include "Sbox.h"
#include "defines.h"
#include <bitset>
class FeistelRound {
private:
  sub_key kx;

  half_block l;
  half_block r;

  Sbox s0;
  Sbox s1;

public:
  block apply(block caracter);
  FeistelRound(sub_key kx);
  FeistelRound();
  void set_key(sub_key kx);

private:
  half_block fFunc(half_block block);
};
#endif // !FEISTEL_ROUND_H

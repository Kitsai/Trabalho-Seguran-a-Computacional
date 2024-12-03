#ifndef FEISTEL_ROUND_H
#define FEISTEL_ROUND_H

#include "defines.h"
#include <bitset>
class FeistelRound {
private:
  sub_key kx;

  half_block l;
  half_block r;

public:
  char apply(char caracter);
  FeistelRound(sub_key kx);

private:
  half_block fFunc(half_block block);
};
#endif // !FEISTEL_ROUND_H

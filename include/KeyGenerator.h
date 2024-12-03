#ifndef KEY_GENERATOR_H
#define KEY_GENERATOR_H

#include "defines.h"
#include <bitset>
#include <string>
#include <utility>

class KeyGenerator {
public:
  std::pair<sub_key, sub_key> generateSubKeys(main_key chave);
};
#endif // !KEY_GENERATOR_H

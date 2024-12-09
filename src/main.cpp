#include <iostream>
#include <string>

#include "../include/Sdes.h"
#include "../include/Transformer.h"

int main() {
  std::string chave_st;
  main_key chave;
  std::string entrada_st;
  block bloco;

  int mode;

  std::cout << "Entre com sua chave: ";
  std::getline(std::cin, chave_st);

  chave = Transformer::transform_key(chave_st);

  std::cout << "Entre com a entrada: ";
  std::getline(std::cin, entrada_st);

  bloco = Transformer::transform_input(entrada_st);

  Sdes sdes(chave);

  std::cout << "Digite 1 para encriptar e 2 para decriptar: ";
  std::cin >> mode;

  do {
    if (mode == 1)
      sdes.encrypt(bloco);
    else if (mode == 2)
      sdes.decrypt(bloco);
  } while (mode == 1 || mode == 2);
  std::cout << chave << ' ' << bloco << '\n';

  return 0;
}

#include <iostream>
#include <string>

#include "../include/KeyGenerator.h"
#include "../include/Sdes.h"
#include "../include/Transformer.h"

int main() {
  std::string chave_st;
  main_key chave;
  std::string entrada_st;
  block bloco;

  int mode;

  block result;

  std::cout << "Entre com sua chave: ";
  std::getline(std::cin, chave_st);

  chave = Transformer::transform_key(chave_st);

  std::cout << "Entre com a entrada: ";
  std::getline(std::cin, entrada_st);

  bloco = Transformer::transform_input(entrada_st);

  Sdes sdes(chave);

  std::cout << "Digite 1 para encriptar e 2 para decriptar: ";
  std::cin >> mode;

  if (mode == 1) {
    std::cout << "Starting encryption\n";
    result = sdes.encrypt(bloco);
  } else if (mode == 2)
    result = sdes.decrypt(bloco);
  else
    std::cout << "opção inválida.\n";

  std::cout << "Chave: " << chave << " Entrada: " << bloco << '\n';
  auto subkeys = KeyGenerator::generateSubKeys(chave);
  std::cout << "Subchaves: " << subkeys.first << ' ' << subkeys.second << '\n';
  std::cout << "Result: " << result << '\n';
  return 0;
}

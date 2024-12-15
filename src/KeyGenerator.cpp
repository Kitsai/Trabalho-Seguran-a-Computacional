#include "../include/KeyGenerator.h"
#include "../include/Permutations.h"
#include "../include/Transformer.h"

std::pair<sub_key, sub_key> KeyGenerator::generateSubKeys(const main_key chave){

    main_key chave_aux;
    chave_aux = Permutations::p10(chave);

    std::pair<half_main_key, half_main_key> main_key_block = Transformer::separate(chave_aux);

    half_main_key main_key_block_l = Permutations::ls1(main_key_block.first);
    half_main_key main_key_block_r = Permutations::ls1(main_key_block.second);

    main_key k1_main = Transformer::combine(main_key_block_l, main_key_block_r);
    sub_key k1 = Permutations::p8(k1_main);

    main_key_block_l = Permutations::ls2(main_key_block_l);
    main_key_block_r = Permutations::ls2(main_key_block_r);

    main_key k2_main = Transformer::combine(main_key_block_l, main_key_block_r);
    sub_key k2 = Permutations::p8(k2_main);

    return {k1, k2};
}
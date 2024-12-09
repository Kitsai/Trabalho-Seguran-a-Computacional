#include "../include/FeistelRound.h"

// Exemplo de inicialização das sboxes
FeistelRound::FeistelRound(sub_key chave)
    : kx(chave), s0(s0_matrix), s1(s1_matrix) {}

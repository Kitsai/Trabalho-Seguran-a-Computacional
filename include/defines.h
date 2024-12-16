#ifndef DEFINES_H
#define DEFINES_H

#include <array>
#include <bitset>

using main_key = std::bitset<10>;
using half_main_key = std::bitset<5>;
using sub_key = std::bitset<8>;
using block = std::bitset<8>;
using half_block = std::bitset<4>;
using quarter_block = std::bitset<2>;
using ull = unsigned long long;
using sbox_matrix = std::array<std::array<ull, 4>, 4>;

constexpr std::array<ull, 10> p10_order{2, 4, 1, 6, 3, 9, 0, 8, 7, 5};
constexpr std::array<ull, 8> p8_order{5, 2, 6, 3, 7, 4, 9, 8};
constexpr std::array<ull, 4> p4_order{1, 3, 2, 0};
constexpr std::array<ull, 8> ip_order{1, 5, 2, 0, 3, 7, 4, 6};
constexpr std::array<ull, 8> inverse_ip_order{3, 0, 2, 4, 6, 1, 7, 5};
constexpr std::array<ull, 8> ep_order{3, 0, 1, 2, 1, 2, 3, 0};

constexpr sbox_matrix s0_matrix{1, 0, 3, 2, 3, 2, 1, 0, 0, 2, 1, 3, 3, 1, 3, 2};

constexpr sbox_matrix s1_matrix{0, 1, 2, 3, 2, 0, 1, 3, 3, 0, 1, 0, 2, 1, 0, 3};

#endif // !DEFINES_H

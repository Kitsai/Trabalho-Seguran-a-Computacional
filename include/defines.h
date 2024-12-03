#ifndef DEFINES_H
#define DEFINES_H

#include <array>
#include <bitset>

using main_key = std::bitset<10>;
using sub_key = std::bitset<8>;
using block = std::bitset<8>;
using half_block = std::bitset<4>;

constexpr std::array<char, 10> p10_order{2, 4, 1, 6, 3, 9, 0, 8, 7, 5};
constexpr std::array<char, 8> p8_order{5, 2, 6, 3, 7, 4, 9, 8};
constexpr std::array<char, 4> p4_order{1, 3, 2, 0};
constexpr std::array<char, 8> ip_order{1, 5, 2, 0, 3, 7, 4, 6};
constexpr std::array<char, 8> inverse_ip_order{3, 0, 2, 4, 6, 1, 7, 5};
constexpr std::array<char, 8> ep_order{3, 0, 1, 2, 1, 2, 3, 0};
#endif // !DEFINES_H

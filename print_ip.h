#pragma once

#include <iostream>
#include <concepts>
#include <type_traits>

template<class T>
concept Integer = std::integral<T>;

//template<Integer T>
//void print_ip(){
//    std::cout <<
//}

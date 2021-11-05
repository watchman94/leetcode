//
// Created by Kiven on 2021/11/3.
//

#ifndef LEETCODE_CHECKPRIME_H
#define LEETCODE_CHECKPRIME_H

#include<type_traits>
#include<cmath>
using namespace std;

template<unsigned n1, unsigned n2>
struct IsPrimeHelper{
    static constexpr bool value = n1 % n2 && IsPrimeHelper<n1, n2 - 1>::value;
};

template<unsigned n1>
struct IsPrimeHelper<n1, 1>{
    static constexpr bool value = true;
};

//IsPrime class
template<unsigned n>
struct IsPrime{
    static constexpr bool value = IsPrimeHelper<n, static_cast<unsigned>(n / 2)>::value;
};

template<>
struct IsPrime<0>{
    static constexpr bool value = false;
};

template<>
struct IsPrime<1>{
    static constexpr bool value = false;
};

template<>
struct IsPrime<2>{
    static constexpr bool value = true;
};

template<unsigned n>
constexpr bool isPrimeValue = IsPrime<n>::value;

template<unsigned n>
constexpr bool isPrimeFunc(){
    if constexpr (n < 2) return false;
    else if constexpr (n == 2) return true;

    int i = 2;
    for(; i <= n / 2 && n % i; i++);
    return i > n / 2;
}

void primeTest(){
    static_assert(isPrimeValue<1> == false);
    static_assert(isPrimeValue<2> == true);
    static_assert(isPrimeValue<7> == true);
    static_assert(isPrimeValue<8> == false);
    static_assert(isPrimeValue<101> == true);

    static_assert(isPrimeFunc<1>() == false);
    static_assert(isPrimeFunc<2>() == true);
    static_assert(isPrimeFunc<7>() == true);
    static_assert(isPrimeFunc<8>() == false);
    static_assert(isPrimeFunc<101>() == true);
}


#endif //LEETCODE_CHECKPRIME_H

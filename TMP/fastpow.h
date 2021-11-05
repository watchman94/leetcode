#include<type_traits>
using namespace std;

template<unsigned x, unsigned n>
constexpr unsigned fastPowFunc(){
	unsigned res = 1;
	unsigned tmp = x;
	unsigned tn = n;
	while(tn){
		if(n & 1) res *= tmp;
		tmp *= tmp;
		tn = tn >> 1;
	}
	return res;
}


template<unsigned res, unsigned tmp, unsigned n>
struct FastPowHelper;


template<unsigned x, unsigned n>
struct FastPow{
	constexpr static unsigned value = FastPowHelper<1, x, n>::value;
};


template<unsigned res, unsigned tmp, unsigned n>
struct FastPowHelper{
	constexpr static unsigned value = n & 1 ? FastPowHelper<res * tmp, tmp * tmp, n / 2>::value : \
					          FastPowHelper<res, tmp * tmp, n / 2>::value;
};

template<unsigned res, unsigned tmp>
struct FastPowHelper<res, tmp, 0>{
	constexpr static unsigned value = res;
};


template<unsigned x, unsigned n>
constexpr unsigned FastPowValue = FastPow<x, n>::value;

void test(){
	static_assert(fastPowFunc<5, 0>() == 1);
	static_assert(fastPowFunc<5, 1>() == 5);
	static_assert(fastPowFunc<5, 3>() == 125);

	static_assert(FastPowValue<5, 0> == 1);
	static_assert(FastPowValue<5, 1> == 5);
	static_assert(FastPowValue<5, 3> == 125);
}

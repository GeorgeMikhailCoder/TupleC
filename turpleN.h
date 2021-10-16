#include <vector>

template <
    int N,
    typename T,
    typename ... Types
>
struct TupleType :
    TupleType <N-1, Types...>
{
    using type1 = T;
    using type2 = TupleType<N - 1, Types...>;
    type1 a;
    type2 b;
};

template<typename T>
struct TupleType<0, T> {
using type1 = T;
type1 a;
};




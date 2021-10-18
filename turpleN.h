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
    type1 single;
    type2 difficult;

    TupleType() {};

    TupleType(T arg, Types ... args) :difficult(args...)
    {
        single = arg;
    };

    template<class T, class ... Types>
    T goToItem(int index)
    {
        if (index == N)
            return single;
        else
            difficult.goToItem<Types ...>(index-1);
    }


    template<int k>
    void some()
    {
        return k;
    }

    
    

    template<int k>
    type1 operator [](int )
    {
        if (k == N)
            return single;
    }


    //  template<int index>
    //  type1 operator [](int )
    //  {
    //          return single;
    //  }
};

template<typename type1>
struct TupleType<0, type1> {
    type1 single;

    TupleType() {};
    TupleType(type1 a)
    {
        single = a;
    }



    type1 operator [](int )
    {
        return single;
    }
    

};

template <
    int N,
    typename T,
    typename ... Types
>
class Tuple : public TupleType<N, T, Types...>
{
public:


    auto operator [](int index)
    {
        return decltype(TupleType::operator [](index))TupleType::operator [](index);
    }
};


#include <vector>
#include<string>

using namespace std;

template <
    int N,
    typename T,
    typename ... Types
>
struct TupleType :
    TupleType <N - 1, Types...>
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

    template<class S>
    S get(int index){
        return *(S*) this->voidGet(index);
    
    }

    void* voidGet(int index)
    {
        if (index == N)
        {
            return &single;
        }
        else
            return difficult.voidGet(index);
    }

    void* operator[](int index)
    {
        if (index == N)
        {
            return &single;
        }
        else
            return difficult.operator[](index);
    }


    template<class S>
    S operator [](int index)
    {
        S* tmp = new S();
        *tmp = get<S>(index);
        return *tmp;
    }



};

template<typename type1>
struct TupleType<0, type1> {
    type1 single;

    TupleType() {};
    TupleType(type1 a)
    {
        single = a;
    }

    template<class S>
    S get(int index) {
        if (index == 0)
            return static_cast<S>(&single);
    }

    void* voidGet(int)
    {
        return &single;
    }

    void* operator [](int )
    {
        return &single;
    }
    
    template<class S>
    S operator [](int index)
    {
        S* tmp = new S();
        *tmp = get<S>(index);
        return *tmp;
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


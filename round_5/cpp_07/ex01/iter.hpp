#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>


template <typename T, typename F> 
void iter(T*x, size_t len, const F& fun)
{
    for (size_t i = 0; i < len; i++)
        fun(x[i]);
}

#endif
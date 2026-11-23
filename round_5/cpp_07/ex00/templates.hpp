#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>
#include <string>

template <typename T> 
void swap(T& x, T& y)
{
    T z = x;
    x = y;
    y = z;
}

template <typename T> 
T max(T x, T y)
{
    return ((x > y) ? x : y);
}

template <typename T> 
T min(T x, T y)
{
    return ((x < y) ? x : y);
}

#endif
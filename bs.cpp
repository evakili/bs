#include <iostream>

using value_t = int;
using position_t = value_t*;
using difference_t = std::size_t;

difference_t distance(position_t first, position_t last)
{
    return last - first - 1;
}

position_t next(position_t pos, difference_t n = 1)
{
    return pos + n;
}

position_t lower_bound(position_t first, position_t last, const value_t& value)
{
    while (last != first) {
        auto middle = next(first, distance(first, last) / 2);

        if (*middle < value)
            first = next(middle);
        else
            last = middle;
    }
    
    return first;
}

position_t binary_search(position_t first, position_t last, const value_t& value)
{
    first = lower_bound(first, last, value);
    return *first == value ? first : last;
}

int main() {
    value_t arr[] = { 1, 3, 4, 6, 7, 9, 12, 54, 200, 1000 };
    std::size_t len = sizeof(arr) / sizeof(value_t);

    std::cout << binary_search(arr, arr + len, 7) << '\n';
    std::cout << binary_search(arr, arr + len, 54) << '\n';
    std::cout << binary_search(arr, arr + len, 3) << '\n';
    std::cout << binary_search(arr, arr + len, 1) << '\n';
    std::cout << binary_search(arr, arr + len, 1000) << '\n';
    std::cout << binary_search(arr, arr + len, 25) << '\n';
    std::cout << binary_search(arr, arr + len, 1020) << '\n';
    std::cout << binary_search(arr, arr + len, -1) << '\n';
}
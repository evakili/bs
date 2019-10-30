#include <iostream>

using position_t = std::size_t;
using difference_t = std::size_t;

difference_t distance(position_t first, position_t last)
{
    return last - first - 1;
}

position_t next(position_t pos, difference_t n = 1)
{
    return pos + n;
}

position_t lower_bound(const int* arr, position_t first, position_t last, int value)
{
    while (last != first) {
        auto middle = next(first, distance(first, last) / 2);

        if (arr[middle] < value)
            first = next(middle);
        else
            last = middle;
    }
    
    return first;
}

position_t binary_search(const int* arr, position_t len, int value)
{
    auto first = lower_bound(arr, 0, len, value);
    return arr[first] == value ? first : len;
}

int main() {
    int arr[] = { 1, 3, 4, 6, 7, 9, 12, 54, 200, 1000 };
    std::size_t len = sizeof(arr) / sizeof(int);

    std::cout << binary_search(arr, len, 7) << '\n';
    std::cout << binary_search(arr, len, 54) << '\n';
    std::cout << binary_search(arr, len, 3) << '\n';
    std::cout << binary_search(arr, len, 1) << '\n';
    std::cout << binary_search(arr, len, 1000) << '\n';
    std::cout << binary_search(arr, len, 25) << '\n';
    std::cout << binary_search(arr, len, 1020) << '\n';
    std::cout << binary_search(arr, len, -1) << '\n';
}
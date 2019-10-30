#include <iostream>

std::size_t lower_bound(const int* arr, std::size_t first, std::size_t last, int value)
{
    while (last != first) {
        auto middle = first + (last - first - 1) / 2;

        if (arr[middle] < value)
            first = middle + 1;
        else
            last = middle;
    }
    
    return first;
}

std::size_t binary_search(const int* arr, std::size_t len, int value)
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
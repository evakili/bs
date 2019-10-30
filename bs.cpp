#include <iostream>

std::size_t binary_search(int* arr, std::size_t first, std::size_t last, int value)
{
    if (last < first)
        return -1;

    if (last == first)
        if (arr[first] != value)
            return -1;

    auto middle = (first + last) / 2;

    if (arr[middle] == value)
        return middle;

    if (arr[middle] < value)
        return binary_search(arr, middle + 1, last, value);

    if (arr[middle] > value)
        return binary_search(arr, first, middle - 1, value);

    return -1;
}

std::size_t binary_search(int* arr, std::size_t len, int value)
{
    return binary_search(arr, 0, len - 1, value);
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
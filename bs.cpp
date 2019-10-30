#include <iostream>

std::size_t binary_search(int* arr, std::size_t first, std::size_t last, int value)
{
    while (last >= first) {
        if (last == first)
            if (arr[first] != value)
                return -1;

        auto middle = first + (last - first) / 2;

        if (arr[middle] == value)
            return middle;
        else if (arr[middle] < value)
            first = middle + 1;
        else
            last = middle - 1;
    }
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
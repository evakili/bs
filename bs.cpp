#include <iostream>

using difference_t = std::size_t;

template<typename T>
difference_t distance(T* first, T* last)
{
    return last - first - 1;
}

template<typename T>
T* next(T* pos, difference_t n = 1)
{
    return pos + n;
}

template<typename T>
T* lower_bound(T* first, T* last, const T& value)
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

template<typename T>
T* binary_search(T* first, T* last, const T& value)
{
    first = lower_bound(first, last, value);
    return *first == value ? first : last;
}

int main() {
    std::cout << "ints:\n";
    {
        int arr[] = { 1, 3, 4, 6, 7, 9, 12, 54, 200, 1000 };
        std::size_t len = sizeof(arr) / sizeof(arr[0]);

        std::cout << binary_search(arr, arr + len, 7) << '\n';
        std::cout << binary_search(arr, arr + len, 54) << '\n';
        std::cout << binary_search(arr, arr + len, 3) << '\n';
        std::cout << binary_search(arr, arr + len, 1) << '\n';
        std::cout << binary_search(arr, arr + len, 1000) << '\n';
        std::cout << binary_search(arr, arr + len, 25) << '\n';
        std::cout << binary_search(arr, arr + len, 1020) << '\n';
        std::cout << binary_search(arr, arr + len, -1) << '\n';
    }
    std::cout << "doubles:\n";
    {
        double arr[] = { 1., 3., 4., 6., 7., 9., 12., 54., 200., 1000. };
        std::size_t len = sizeof(arr) / sizeof(arr[0]);

        std::cout << binary_search(arr, arr + len, 7.) << '\n';
        std::cout << binary_search(arr, arr + len, 54.) << '\n';
        std::cout << binary_search(arr, arr + len, 3.) << '\n';
        std::cout << binary_search(arr, arr + len, 1.) << '\n';
        std::cout << binary_search(arr, arr + len, 1000.) << '\n';
        std::cout << binary_search(arr, arr + len, 25.) << '\n';
        std::cout << binary_search(arr, arr + len, 1020.) << '\n';
        std::cout << binary_search(arr, arr + len, -1.) << '\n';
    }
}    
#include <iostream>

template<typename Pos>
struct pos_traits
{
    using iterator_type = Pos;
    using difference_type = decltype(iterator_type{} - iterator_type{});
};

template<typename T>
struct less_than {
    bool operator()(const T& x, const T& y) {
        return x < y;
    }
};

template<typename T>
struct greater_than {
    bool operator()(const T& x, const T& y) {
        return y < x;
    }
};

template<typename Pos>
typename pos_traits<Pos>::difference_type distance(Pos first, Pos last)
{
    return last - first - 1;
}

template<typename Pos>
Pos next(Pos pos, typename pos_traits<Pos>::difference_type n = { 1 })
{
    return pos + n;
}

template<typename T, typename Pos, typename Pred>
Pos lower_bound(Pos first, Pos last, const T& value, Pred pred)
{
    while (last != first) {
        auto middle = next(first, distance(first, last) / 2);

        if (pred(*middle, value))
            first = next(middle);
        else
            last = middle;
    }
    
    return first;
}

template<typename T, typename Pos, typename Pred>
Pos binary_search(Pos first, Pos last, const T& value, Pred pred)
{
    first = lower_bound(first, last, value, pred);
    return *first == value ? first : last;
}

template<typename T, typename Pos>
Pos binary_search(Pos first, Pos last, const T& value)
{
    return binary_search(first, last, value, less_than<T>{});
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
        double arr[] = { 1000., 200., 54., 12., 9., 7., 6., 4., 3., 1. };
        std::size_t len = sizeof(arr) / sizeof(arr[0]);

        std::cout << binary_search(arr, arr + len, 7., greater_than<double>{}) << '\n';
        std::cout << binary_search(arr, arr + len, 54., greater_than<double>{}) << '\n';
        std::cout << binary_search(arr, arr + len, 3., greater_than<double>{}) << '\n';
        std::cout << binary_search(arr, arr + len, 1., greater_than<double>{}) << '\n';
        std::cout << binary_search(arr, arr + len, 1000., greater_than<double>{}) << '\n';
        std::cout << binary_search(arr, arr + len, 25., greater_than<double>{}) << '\n';
        std::cout << binary_search(arr, arr + len, 1020., greater_than<double>{}) << '\n';
        std::cout << binary_search(arr, arr + len, -1., greater_than<double>{}) << '\n';
    }
}    
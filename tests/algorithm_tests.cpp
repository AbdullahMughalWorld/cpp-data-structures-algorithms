#include <cassert>
#include <iostream>
#include <vector>

#include "../src/algorithms.h"

int main() {
    {
        std::vector<int> values{5, 1, 4, 2, 8};
        dsa::bubbleSort(values);
        assert((values == std::vector<int>{1, 2, 4, 5, 8}));
    }

    {
        std::vector<int> values{3, -1, 3, 0, 2};
        dsa::selectionSort(values);
        assert((values == std::vector<int>{-1, 0, 2, 3, 3}));
    }

    {
        std::vector<int> values{9, 7, 5, 3, 1};
        dsa::insertionSort(values);
        assert((values == std::vector<int>{1, 3, 5, 7, 9}));
    }

    {
        const std::vector<int> values{12, 7, 5, 7};
        assert(dsa::linearSearch(values, 12) == 0);
        assert(dsa::linearSearch(values, 7) == 1);
        assert(dsa::linearSearch(values, 100) == -1);
    }

    {
        const std::vector<int> sorted{1, 3, 5, 7, 9, 11};
        assert(dsa::binarySearch(sorted, 1) == 0);
        assert(dsa::binarySearch(sorted, 7) == 3);
        assert(dsa::binarySearch(sorted, 11) == 5);
        assert(dsa::binarySearch(sorted, 4) == -1);
    }

    {
        std::vector<int> empty;
        dsa::bubbleSort(empty);
        dsa::selectionSort(empty);
        dsa::insertionSort(empty);
        assert(dsa::linearSearch(empty, 1) == -1);
        assert(dsa::binarySearch(empty, 1) == -1);
    }

    std::cout << "All algorithm tests passed!\n";
    return 0;
}

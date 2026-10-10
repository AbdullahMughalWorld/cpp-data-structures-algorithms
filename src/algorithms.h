#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

namespace dsa {

// Sorts values from smallest to largest by repeatedly swapping neighbours.
inline void bubbleSort(std::vector<int>& values) {
    for (std::size_t end = values.size(); end > 1; --end) {
        bool swapped = false;

        for (std::size_t i = 1; i < end; ++i) {
            if (values[i - 1] > values[i]) {
                int temp = values[i - 1];
                values[i - 1] = values[i];
                values[i] = temp;
                swapped = true;
            }
        }

        // If no values changed places, the vector is already sorted.
        if (!swapped) {
            break;
        }
    }
}

// Finds the smallest remaining value and puts it in the next position.
inline void selectionSort(std::vector<int>& values) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        std::size_t smallest = i;

        for (std::size_t j = i + 1; j < values.size(); ++j) {
            if (values[j] < values[smallest]) {
                smallest = j;
            }
        }

        if (smallest != i) {
            int temp = values[i];
            values[i] = values[smallest];
            values[smallest] = temp;
        }
    }
}

// Builds a sorted section one item at a time, like sorting playing cards.
inline void insertionSort(std::vector<int>& values) {
    for (std::size_t i = 1; i < values.size(); ++i) {
        int current = values[i];
        std::size_t j = i;

        while (j > 0 && values[j - 1] > current) {
            values[j] = values[j - 1];
            --j;
        }

        values[j] = current;
    }
}

// Returns the index of the first matching value, or -1 if it is not found.
inline int linearSearch(const std::vector<int>& values, int target) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (values[i] == target) {
            return static_cast<int>(i);
        }
    }

    return -1;
}

// Binary search requires values to already be sorted in ascending order.
// Returns the index of a match, or -1 if it is not found.
inline int binarySearch(const std::vector<int>& sortedValues, int target) {
    int left = 0;
    int right = static_cast<int>(sortedValues.size()) - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (sortedValues[middle] == target) {
            return middle;
        }

        if (sortedValues[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

} // namespace dsa

#endif

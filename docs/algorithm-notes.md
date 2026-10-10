# Quick Algorithm Notes

## Sorting

Sorting arranges values in a particular order. In this project, all sorting functions arrange integers in ascending order.

- **Bubble Sort:** compares neighbouring values and swaps them when they are in the wrong order. It is easy to understand, but slow for large lists.
- **Selection Sort:** finds the smallest value in the unsorted part and moves it to the next position.
- **Insertion Sort:** grows a sorted section by inserting each next value into the right place. It can be efficient for small or nearly sorted lists.

## Searching

- **Linear Search:** starts at the beginning and checks each value until it finds the target or reaches the end. The list does not need to be sorted.
- **Binary Search:** checks the middle value and discards half of the remaining range each step. The list must be sorted first.

## Data structures

- **Stack (LIFO):** Last In, First Out. The last item pushed is the first item popped. Think of a stack of plates.
- **Queue (FIFO):** First In, First Out. The first item enqueued is the first item dequeued. Think of a line of people waiting.

## Complexity

`n` means the number of values. `O(n)` grows roughly in proportion to the list size; `O(log n)` grows much more slowly; `O(n²)` can become slow as the list gets large. Big-O describes growth, not an exact time in seconds.

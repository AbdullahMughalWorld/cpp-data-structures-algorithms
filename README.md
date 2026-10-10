# C++ Data Structures & Algorithms Toolkit

A beginner-friendly, menu-driven C++17 console project for practising core Data Structures and Algorithms (DSA).

## Features

- **Bubble Sort** — repeatedly swaps neighbouring values that are out of order.
- **Selection Sort** — selects the smallest remaining value for each position.
- **Insertion Sort** — inserts each value into the correct position in a sorted section.
- **Linear Search** — checks values one by one.
- **Binary Search** — searches a sorted vector by repeatedly halving the search range.
- **Stack** — demonstrates Push, Pop, and Display (Last In, First Out / LIFO).
- **Queue** — demonstrates Enqueue, Dequeue, and Display (First In, First Out / FIFO).
- **Complexity guide** — shows basic time and extra-space complexity.
- **Input validation** — handles invalid integer input and limits list size.
- **Unit tests** — checks sorting and searching functions with sample cases.

## Built with

- C++17
- Standard Library (`vector`, `queue`, `iostream`, `sstream`)
- No external libraries required

## Project structure

```text
CppDataStructuresAlgorithmsToolkit/
├── src/
│   ├── algorithms.h
│   └── main.cpp
├── tests/
│   └── algorithm_tests.cpp
├── docs/
│   └── algorithm-notes.md
├── .gitignore
├── LICENSE
└── README.md
```

## Requirements

Install a C++ compiler that supports C++17, such as GCC (MinGW-w64 on Windows) or Clang.

Check that the compiler is available:

```bash
g++ --version
```

## Build and run

Run these commands from the project root folder.

### Windows (PowerShell)

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp -o dsa-toolkit.exe
.\dsa-toolkit.exe
```

### Linux / macOS

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp -o dsa-toolkit
./dsa-toolkit
```

## Run the tests

From the project root folder:

### Windows (PowerShell)

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic tests/algorithm_tests.cpp -o algorithm-tests.exe
.\algorithm-tests.exe
```

### Linux / macOS

```bash
g++ -std=c++17 -Wall -Wextra -pedantic tests/algorithm_tests.cpp -o algorithm-tests
./algorithm-tests
```

Expected test output:

```text
All algorithm tests passed!
```

## How to use it

1. Start the program.
2. Choose an option from the main menu.
3. For sorting or searching, enter how many values you want to use (between 1 and 100), then enter each integer.
4. For the stack and queue, select the operation you want.
5. Choose `0` to exit.

Binary search needs sorted data. This program sorts the entered values first and then runs binary search on the sorted list.

## Complexity overview

| Algorithm / Operation | Typical time complexity | Extra space |
|---|---:|---:|
| Bubble Sort | O(n²) worst case | O(1) |
| Selection Sort | O(n²) | O(1) |
| Insertion Sort | O(n²) worst case | O(1) |
| Linear Search | O(n) | O(1) |
| Binary Search | O(log n) | O(1) |
| Stack push / pop | O(1) | O(n) for stored items |
| Queue enqueue / dequeue | O(1) | O(n) for stored items |

The displayed sorting and searching complexity is for the algorithm itself. The application sorts a copy before binary search, so the complete binary-search menu option also includes sorting time.

## Learning goals

This project is intended to help practise:

- functions and header files
- vectors and queues
- loops and conditionals
- sorting and searching
- basic time and space complexity
- input validation
- writing simple tests with `assert`

## Limitations

- This is an educational console application, not a graphical application.
- The stack uses a `vector` and the queue uses `std::queue` from the C++ Standard Library.
- Binary search returns an index in the sorted list, which may differ from the original list's index.
- The algorithms are designed for learning; for production use, standard-library algorithms such as `std::sort` are usually preferred.

## Future improvements

- Add Merge Sort and Quick Sort.
- Count and compare the number of comparisons and swaps for each sorting algorithm.
- Add a graphical interface.
- Add more unit tests and edge cases.

## Author

**Abdullah Mughal**  
BS Artificial Intelligence Student  
GitHub: [@AbdullahMughalWorld](https://github.com/AbdullahMughalWorld)

---

This project is for educational and practice purposes.

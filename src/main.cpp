#include <iostream>
#include <limits>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include "algorithms.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;

// Reads a whole line and accepts it only when it contains one valid integer.
int readInt(const string& prompt) {
    while (true) {
        cout << prompt;
        string line;
        if (!std::getline(cin, line)) {
            cout << "\nInput ended. Exiting program.\n";
            std::exit(0);
        }

        std::stringstream input(line);
        int value;
        char extra;

        if (input >> value && !(input >> extra)) {
            return value;
        }

        cout << "Invalid input. Please enter a whole number.\n";
    }
}

vector<int> readNumbers() {
    int count;

    do {
        count = readInt("How many numbers (1-100)? ");
        if (count < 1 || count > 100) {
            cout << "Please enter a number from 1 to 100.\n";
        }
    } while (count < 1 || count > 100);

    vector<int> values;
    values.reserve(static_cast<std::size_t>(count));

    for (int i = 0; i < count; ++i) {
        values.push_back(readInt("Enter number " + std::to_string(i + 1) + ": "));
    }

    return values;
}

void displayVector(const vector<int>& values) {
    cout << "[ ";
    for (int value : values) {
        cout << value << ' ';
    }
    cout << "]\n";
}

void sortingMenu() {
    cout << "\n--- Sorting Algorithms ---\n";
    vector<int> original = readNumbers();

    cout << "\nOriginal values: ";
    displayVector(original);

    vector<int> bubble = original;
    dsa::bubbleSort(bubble);
    cout << "Bubble Sort:     ";
    displayVector(bubble);

    vector<int> selection = original;
    dsa::selectionSort(selection);
    cout << "Selection Sort:  ";
    displayVector(selection);

    vector<int> insertion = original;
    dsa::insertionSort(insertion);
    cout << "Insertion Sort:  ";
    displayVector(insertion);

    cout << "\nAll three algorithms sort in ascending order.\n";
}

void linearSearchMenu() {
    cout << "\n--- Linear Search ---\n";
    vector<int> values = readNumbers();
    int target = readInt("Number to find: ");
    int index = dsa::linearSearch(values, target);

    if (index == -1) {
        cout << target << " was not found.\n";
    } else {
        cout << target << " was found at index " << index
             << " (position " << index + 1 << ").\n";
    }
}

void binarySearchMenu() {
    cout << "\n--- Binary Search ---\n";
    vector<int> values = readNumbers();
    int target = readInt("Number to find: ");

    // Binary search works only on sorted values, so sort a copy first.
    dsa::insertionSort(values);

    cout << "Sorted values: ";
    displayVector(values);

    int index = dsa::binarySearch(values, target);
    if (index == -1) {
        cout << target << " was not found.\n";
    } else {
        cout << target << " was found at index " << index
             << " in the sorted list (position " << index + 1 << ").\n";
    }
}

void stackMenu() {
    vector<int> stack;
    cout << "\n--- Stack (Last In, First Out) ---\n";

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Display stack\n0. Back to main menu\n";
        int choice = readInt("Choose an option: ");

        if (choice == 0) {
            return;
        } else if (choice == 1) {
            int value = readInt("Value to push: ");
            stack.push_back(value);
            cout << value << " pushed onto the stack.\n";
        } else if (choice == 2) {
            if (stack.empty()) {
                cout << "Stack is empty; nothing to pop.\n";
            } else {
                cout << stack.back() << " popped from the stack.\n";
                stack.pop_back();
            }
        } else if (choice == 3) {
            if (stack.empty()) {
                cout << "Stack is empty.\n";
            } else {
                cout << "Top -> ";
                for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
                    cout << *it << ' ';
                }
                cout << "\n";
            }
        } else {
            cout << "Invalid option. Try again.\n";
        }
    }
}

void queueMenu() {
    std::queue<int> queue;
    cout << "\n--- Queue (First In, First Out) ---\n";

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display queue\n0. Back to main menu\n";
        int choice = readInt("Choose an option: ");

        if (choice == 0) {
            return;
        } else if (choice == 1) {
            int value = readInt("Value to enqueue: ");
            queue.push(value);
            cout << value << " added to the queue.\n";
        } else if (choice == 2) {
            if (queue.empty()) {
                cout << "Queue is empty; nothing to dequeue.\n";
            } else {
                cout << queue.front() << " removed from the queue.\n";
                queue.pop();
            }
        } else if (choice == 3) {
            if (queue.empty()) {
                cout << "Queue is empty.\n";
            } else {
                std::queue<int> copy = queue;
                cout << "Front -> ";
                while (!copy.empty()) {
                    cout << copy.front() << ' ';
                    copy.pop();
                }
                cout << "<- Rear\n";
            }
        } else {
            cout << "Invalid option. Try again.\n";
        }
    }
}

void complexityGuide() {
    cout << "\n--- Algorithm Complexity Guide ---\n";
    cout << "Algorithm       Average/Worst Time       Extra Space\n";
    cout << "Bubble Sort     O(n^2) / O(n^2)          O(1)\n";
    cout << "Selection Sort  O(n^2) / O(n^2)          O(1)\n";
    cout << "Insertion Sort  O(n^2) / O(n^2)          O(1)\n";
    cout << "Linear Search   O(n) / O(n)              O(1)\n";
    cout << "Binary Search   O(log n) / O(log n)      O(1)\n";
    cout << "\nNote: Binary search requires sorted input. The sorting functions\n"
            "modify their vector directly. The app sorts a copy before binary search.\n";
}

void showMainMenu() {
    cout << "\n============================================\n";
    cout << "  C++ Data Structures & Algorithms Toolkit\n";
    cout << "============================================\n";
    cout << "1. Compare sorting algorithms\n";
    cout << "2. Linear search\n";
    cout << "3. Binary search\n";
    cout << "4. Stack operations\n";
    cout << "5. Queue operations\n";
    cout << "6. Complexity guide\n";
    cout << "0. Exit\n";
}

int main() {
    cout << "Welcome to the C++ DSA Toolkit!\n";

    while (true) {
        showMainMenu();
        int choice = readInt("Choose an option: ");

        switch (choice) {
            case 1:
                sortingMenu();
                break;
            case 2:
                linearSearchMenu();
                break;
            case 3:
                binarySearchMenu();
                break;
            case 4:
                stackMenu();
                break;
            case 5:
                queueMenu();
                break;
            case 6:
                complexityGuide();
                break;
            case 0:
                cout << "Thank you for using the DSA Toolkit. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please choose a listed option.\n";
        }
    }
}

#include <iostream>

#include "inversion_count.hpp"

bool run_tests();

unsigned int get_random_array_number();

void fill_array(int *a, unsigned int n);

unsigned int simple_count_inversions(const int *a, unsigned int n);

int main () {
    if (run_tests()) {
        std::cout << "All tests passed!" << std::endl;
    }
    else {
        std::cout << "Something went wrong..." << std::endl;
    }

    return 0;
}

bool run_tests() {
    const unsigned int tests_number{50000};

    for (unsigned int i{0}; i < tests_number; i++) {
        const unsigned int n{get_random_array_number()};
        int a[n];
        fill_array(a, n);

        if (simple_count_inversions(a, n) != count_inversions(a, n)) {
            return false;
        }
    }

    return true;
}

unsigned int get_random_array_number() {
    const unsigned int min{1};
    const unsigned int max{1000};
    std::srand(time(0));
    return min + std::rand() % (max - min + 1);
}

void fill_array(int *a, unsigned int n) {
    const int min{-1000};
    const int max{1000};
    std::srand(time(0));

    for (unsigned int i{0}; i < n; i++) {
        a[i] = min + std::rand() % (max - min + 1);
    }
}

unsigned int simple_count_inversions(const int *a, unsigned int n) {
    unsigned int result{0};

    for (unsigned int i{0}; i < n - 1; i++) {
        for (unsigned int j{i + 1}; j < n; j++) {
            if (a[i] > a[j]) {
                result++;
            }
        }
    }

    return result;
}

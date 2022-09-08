#include <array>
#include <iostream>
#include <vector>

#include "inversion_count.hpp"

bool run_tests();

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
    const unsigned int tests_number{5};
    const std::vector<std::vector<int>> a{{2}, {1, 2, 5, 4, 3}, {1, 2, 3, 4, 5, 6, 10, 9, 8, 7}, {2, 0}, {5, 7, 8, 8, 10, 23, 60}};
    const std::array<unsigned int, tests_number> n{1, 5, 10, 2, 7};
    const std::array<unsigned int, tests_number> correct_result{0, 3, 6, 1, 0};
    unsigned int result;

    for (unsigned int i{0}; i < tests_number; i++) {
        if ((result = count_inversions(a.at(i).data(), n.at(i))) != correct_result.at(i)) {
            return false;
        }
    }

    return true;
}

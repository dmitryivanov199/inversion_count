#include "inversion_count.hpp"

static void get_array_half(const int *a, int *part, unsigned int n, half which_half);

//-----------------------------------------------------------------------------

unsigned int get_inversions_number(const int *a, unsigned int n) {
    if (n <= 1) {
        return 0;
    }

    const unsigned int left_n{n / 2};
    const unsigned int right_n{n - n / 2};

    int left_part[left_n];
    int right_part[right_n];

    get_array_half(a, left_part, n, half::LEFT);
    get_array_half(a, right_part, n, half::RIGHT);

    return 0;
}

//-----------------------------------------------------------------------------

void get_array_half(const int *a, int *part, unsigned int n, half which_half) {
    unsigned int i{(which_half == half::LEFT)? 0 : n / 2};
    unsigned int j{0};

    for (; i < n; i++) {
        part[j] = a[i];
        j++;
    }
}

#include "inversion_count.hpp"

static void copy_array(int *dst, const int *src, unsigned int n);

static unsigned int sort_and_count_inversions(int *a, unsigned int n);

static bool is_base_case(unsigned int n);

static void get_array_half(const int *a, int *part, unsigned int n, half which_half);

static unsigned int merge_and_count_inversions(int *b, unsigned int n, const int *c, unsigned int c_n, const int *d, unsigned int d_n);

//-----------------------------------------------------------------------------

unsigned int count_inversions(const int *a, unsigned int n) {
    int sorted_a[n];
    copy_array(sorted_a, a, n);
    return sort_and_count_inversions(sorted_a, n);
}

//-----------------------------------------------------------------------------

void copy_array(int *dst, const int *src, unsigned int n) {
    for (unsigned int i{0}; i < n; i++) {
        dst[i] = src[i];
    }
}

unsigned int sort_and_count_inversions(int *a, unsigned int n) {
    if (is_base_case(n)) {
        return 0;
    }

    const unsigned int c_n{n / 2};
    const unsigned int d_n{n - c_n};
    int c[c_n];
    int d[d_n];
    get_array_half(a, c, n, half::LEFT);
    get_array_half(a, d, n, half::RIGHT);

    unsigned int left_inversions_count{sort_and_count_inversions(c, c_n)};
    unsigned int right_inversions_count{sort_and_count_inversions(d, d_n)};
    unsigned int split_inversions_count{merge_and_count_inversions(a, n, c, c_n, d, d_n)};

    return left_inversions_count + right_inversions_count + split_inversions_count;
}

bool is_base_case(unsigned int n) {
    return n <= 1;
}

void get_array_half(const int *a, int *part, unsigned int n, half which_half) {
    unsigned int i{(which_half == half::LEFT)? 0 : n / 2};
    unsigned int j{0};

    for (; i < n; i++) {
        part[j] = a[i];
        j++;
    }
}

unsigned int merge_and_count_inversions(int *b, unsigned int n, const int *c, unsigned int c_n, const int *d, unsigned int d_n) {
    unsigned int i{0};
    unsigned int j{0};
    unsigned int split_inversions_count{0};

    for (unsigned int k{0}; k < n; k++) {
        if ((i < c_n) && (j < d_n)) {
            if (c[i] <= d[j]) {
                b[k] = c[i];
                i++;
            }
            else {
                b[k] = d[j];
                j++;
                split_inversions_count += c_n - i;
            }
        }
        else {
            if (i >= c_n) {
                b[k] = d[j];
                j++;
            }
            else {
                b[k] = c[i];
                i++;
            }
        }
    }

    return split_inversions_count;
}

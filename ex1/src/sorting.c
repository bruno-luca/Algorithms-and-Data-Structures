#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sorting.h"

void merge_binary_insertion_sort(void *base, size_t nitems, size_t size, size_t k, int (*compar)(const void*, const void*)) {
    if (base != NULL) {
        merge_sort(base, size, compar, 0, nitems - 1, k);
    }
}

void merge_sort(void *base, size_t size, int (*compar)(const void*, const void*), int l, int r, size_t k) {
    if (r - l < k) {
        binary_insertion_sort(base, r - l + 1, size, compar);
    } else {
        if (l < r) {
            int m = l + (r - l) / 2;
            merge_sort(base, size, compar, l, m, k);
            merge_sort(base, size, compar, m + 1, r, k);
            merge(base, size, compar, l, m, r);
        }
    }
}

void merge(void *base, size_t size, int (*compar)(const void*, const void*), int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    void *L = malloc(size * n1);
    void *R = malloc(size * n2);

    memcpy(L, base + l * size, size * n1);
    memcpy(R, base + (m + 1) * size, size * n2);

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (compar(L + i * size, R + j * size) <= 0) {
            memcpy(base + k * size, L + i * size, size);
            i++;
        } else {
            memcpy(base + k * size, R + j * size, size);
            j++;
        }
        k++;
    }

    while (i < n1) {
        memcpy(base + k * size, L + i * size, size);
        i++;
        k++;
    }

    while (j < n2) {
        memcpy(base + k * size, R + j * size, size);
        j++;
        k++;
    }

    free(L);
    free(R);
}

void binary_insertion_sort(void *base, size_t nitems, size_t size, int (*compar)(const void*, const void*)) {
    void *i, *j, *low, *high, *mid;
    void *temp = malloc(size);

    for (i = base + size; i < base + nitems * size; i += size) {
        memcpy(temp, i, size);
        low = base;
        high = i - size;

        while (low <= high) {
            mid = low + (high - low) / size / 2 * size;

            if (compar(mid, temp) < 0) {
                low = mid + size;
            } else {
                high = mid - size;
            }
        }

        for (j = i; j > low; j -= size) {
            memcpy(j, j - size, size);
        }
        memcpy(low, temp, size);
    }

    free(temp);
}

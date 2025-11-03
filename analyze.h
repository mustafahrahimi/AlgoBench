#ifndef ANALYZE_H
#define ANALYZE_H

#include "algorithm.h"
#include <stdbool.h>
#include <time.h>

#define SIZE_START 512
#define SORT_ITERATIONS 4
#define NANOSECONDS_IN_SECOND 1e9
#define MAX_RANDOM_VALUE 10000
#define SEARCH_ITERATIONS 10000
#define FP_VEC_SIZE 5

// algorithm_t defines different algorithms
typedef enum {
	bubble_sort_t,
	insertion_sort_t,
	quick_sort_t,
	linear_search_t,
	binary_search_t
} algorithm_t;

typedef enum {
	linear_search_type,
	binary_search_type
} search_t;

// case_t defines different cases
typedef enum {
	best_t,
	worst_t,
	average_t,
} case_t;

// result_t defines a timed measurement for a given array size
typedef struct {
	int size;
	double time;
} result_t;

// Function pointers for sorting algorithms and search algorithms
typedef void (*SortFunction)(int *arr, int n);
typedef bool (*SearchFunction)(const int *arr, int n, int v);

// benchmark benchmarks an algorithm a for a specific case c, writing n results
// to the result buffer buf
void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n);

#endif

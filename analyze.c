#include "analyze.h"
#include <stdio.h>

// Private --------------------------------------------------------------------------------------------------------------
static SortFunction sortingAlgorithms[FP_VEC_SIZE] = {bubble_sort, insertion_sort, quick_sort, NULL, NULL};
static SearchFunction searchingAlgorithms[FP_VEC_SIZE] = {NULL, NULL, NULL, linear_search, binary_search};

static void gen_sorted_arr(int* array, int array_size) {
    for (int j = 0; j < array_size; j++) {
        array[j] = j;
    } 
}

static void gen_reverse_sorted_arr(int* array, int array_size) {
    for (int j = 0; j < array_size; j++) {
        array[j] = (array_size - j);
    }
}

static void gen_random_arr(int* array, int array_size) {
    srand(time(0));
    for (int j = 0; j < array_size; j++) {
        array[j] = rand() % MAX_RANDOM_VALUE;
    }
}

static void bubbel_inserion_sort_data(int* array, int array_size, const case_t c) {
    switch (c) {
        case best_t:
            gen_sorted_arr(array, array_size);
            break;
        case worst_t:   
            gen_reverse_sorted_arr(array, array_size);     
            break;
        default:
            gen_random_arr(array, array_size);
            break;
    }
}

static void quicksort_data(int* array, int array_size, const case_t c) {
    switch (c) {
        case best_t:
            gen_random_arr(array, array_size);
            break;
        case worst_t:   
            gen_reverse_sorted_arr(array, array_size);
            break;
        default:
            int half = array_size >> 1;
            for (int j = 0; j < half; j++) {
                array[j] = j;
            }
            for (int j = half; j < array_size; j++) {
                array[j] = rand() % MAX_RANDOM_VALUE;
            }
            break;
    }
}

static int search_data(int* array, int array_size, const search_t s, const case_t c) {
    int search_index;
    srand(time(0));
    (s == binary_search_type) ? gen_sorted_arr(array, array_size) : gen_random_arr(array, array_size);
    switch (c) {    
        case best_t:
            search_index = (s == binary_search_type) ? array_size >> 1 : 0;         // x >> 1 <=> x / 2
            return search_index;
            break;
        case worst_t:
            search_index = array_size - 1;
            return search_index;   
            break;
        default:
            search_index = rand() % array_size;
            return search_index;
            break;
    }
    return -1;   
}

static double get_time_for_sort(SortFunction sortFunc, case_t c, int* a, int n) {
    struct timespec start, stop;
    double temptime, exexution_time;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < SORT_ITERATIONS; i++) {
        sortFunc(a, n);
        clock_gettime(CLOCK_MONOTONIC, &stop);
        
        temptime = (double)(stop.tv_sec - start.tv_sec) + ((double)(stop.tv_nsec - start.tv_nsec) / NANOSECONDS_IN_SECOND);
        exexution_time += temptime;

        // reset the array for next iteration / func call
        (sortFunc == bubble_sort || sortFunc == insertion_sort) ? bubbel_inserion_sort_data(a, n, c) : quicksort_data(a, n, c);
    }
    return (exexution_time / SORT_ITERATIONS);
}

static double get_time_for_search(SearchFunction searchFunc, int* a, int n, int v) {
    struct timespec start, stop;
    double temptime, execution_time;
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < SEARCH_ITERATIONS; i++) {
        searchFunc(a, n, v);
        clock_gettime(CLOCK_MONOTONIC, &stop); 
        
        temptime = (double)(stop.tv_sec - start.tv_sec) + ((double)(stop.tv_nsec - start.tv_nsec) / NANOSECONDS_IN_SECOND);
        execution_time += temptime;
    }
    return (execution_time / SEARCH_ITERATIONS);
}

// Public ---------------------------------------------------------------------------------------------------------------

void benchmark(const algorithm_t a, const case_t c, result_t *buf, int n) {
    int* array;
    int sizes[n];
    int search_index;
    double execution_time;

    sizes[0] = SIZE_START;
    for (int i = 1; i < n; i++) {
        sizes[i] = sizes[i-1] << 1;     // sizes[i-1] << 1 <=> sizes[i-1] * 2
    }

    // "a" ∈ [0,1,2] for algorithm_t sort and "a" ∈ [3,4] for algorithm_t search, 
    //  for ex. sortingAlgorithms[a] for a = 0 gives bubble_sort or searchingAlgorithms[a] for a = 3 gives linear_search
    if (sortingAlgorithms[a] || searchingAlgorithms[a]) {
        for (int i = 0; i < n; i++) {
            int array_size = sizes[i];
            array = (int*)malloc(array_size * sizeof(int));

            switch (a) {
                case bubble_sort_t:
                case insertion_sort_t:
                    bubbel_inserion_sort_data(array, array_size, c);
                    break;
                case quick_sort_t:
                    quicksort_data(array, array_size, c);
                    break;
                case linear_search_t:
                    search_index = search_data(array, array_size, linear_search_type, c);
                    break;
                case binary_search_t:
                    search_index = search_data(array, array_size, binary_search_type, c);
                    break;
            }

            if (a < linear_search_t) {
                execution_time = get_time_for_sort(sortingAlgorithms[a], c, array, array_size);
            }
            else {
                execution_time = get_time_for_search(searchingAlgorithms[a], array, array_size, array[search_index]);
            } 

            buf[i].size = array_size;
            buf[i].time = execution_time;
            free(array);
        }
    }
    else return;
}

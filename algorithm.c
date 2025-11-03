#include "algorithm.h"

// Private -------------------------------------------------------

// Public --------------------------------------------------------

void bubble_sort(int* a, int n) {
	int swapped = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j+1]) {
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
                swapped = 1;
			}
		}
        if (swapped == 0) {
            break;
        } 
	}
}

// --------------------------------------------------------------

void insertion_sort(int *a, int n) {
	int j, key;
	for (int i = 1; i < n; i++) {
		key = a[i];
		j =  i - 1;
		while (j >= 0 && key < a[j]) {
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
}

// --------------------------------------------------------------

static void swap_values(int* v1, int* v2) {
	int temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

static int partition(int* a, int low, int high) {
	int pivot = a[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (a[j] < pivot) {
			i = i + 1;
			swap_values(&a[i], &a[j]);
		}
	}
	swap_values(&a[i + 1], &a[high]);
	return (i + 1);
}

static void recursive_quicksort(int* a, int low, int high) {
	if (low < high) {
		int p = partition(a, low, high);
		recursive_quicksort(a, low, p - 1);
		recursive_quicksort(a, p + 1, high);
	}
}

void quick_sort(int *a, int n) {
	recursive_quicksort(a, 0, n - 1);
}

// --------------------------------------------------------------

bool linear_search(const int *a, int n, int v) {
	for (int i = 0; i < n; i++) {
		if (a[i] == v) {
			return true;
		}
	}
	return false; 
}

// --------------------------------------------------------------

bool binary_search(const int *a, int n, int v) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) >> 1;

		if (a[mid] == v) {
			return true;
		}
		if (a[mid] < v) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return false; 
}

// --------------------------------------------------------------
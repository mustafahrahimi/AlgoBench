#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "analyze.h"

#define SQUARED 2
#define CUBED 3

// read_line reads at least one and at most n-2 characters from stdin, writing a
// null-terminated result to buf; possible overflows are handled and and the
// length of buf is returned, e.g., 5 for "hello" and 0 on error.
int read_line(char *buf, int n);
void printResult(char* algorithm_and_case, result_t* buf, int n);

#endif

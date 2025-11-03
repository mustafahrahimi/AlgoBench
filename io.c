#include "io.h"

// Private --------------------------------------------------------------------------------------------------------------------------------------------------

static void empty_stream()
{
	int c;
	while ((c = getchar()) != EOF && c != '\n');
}

//
// Public
//
int read_line(char *buf, int n)
{
	int buf_size;

	if (!fgets(buf, n, stdin)) {
		empty_stream();
		return 0; // overflow
	}

	buf_size = strlen(buf);
	if (buf[buf_size-1] != '\n') {
		empty_stream();
		return 0; // overflow
	}

	// remove new line
	buf[buf_size-1] = '\0';
	return buf_size-1;
}

// Public ---------------------------------------------------------------------------------------------------------------------------------------------------

void printResult(char* algorithm_and_case, result_t* buf, int n) {
	printf("\n%s\n\n", algorithm_and_case);
	printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n\n","size", "time T(s)", "T/log(n)", "T/n", "T/nlog(n)", "T/n^2", "T/n^3");
	for (int i = 0; i < n; i++) {
		int s = buf[i].size;
        double t = buf[i].time;
        double O_logn = t / log2(s);
        double O_n = t / s;
        double O_nlogn = t / (s * log2(s));
        double O_n2 = t / pow(s, SQUARED);
        double O_n3 = t / pow(s, CUBED);

        printf("%-15d %-15lf %-15e %-15e %-15e %-15e %-15e\n", s, t, O_logn, O_n, O_nlogn, O_n2, O_n3);																		
	}
	printf("\n----------------------------------------\n");
}
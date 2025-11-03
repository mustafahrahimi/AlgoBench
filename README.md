# AlgoBench

A C program that benchmarks sorting and searching algorithms. 
This tool helps understand algorithm complexity through hands-on performance analysis.

## Features

- Interactive menu interface
- Tests sorting algorithms: Bubble Sort, Insertion Sort, Quick Sort
- Tests searching algorithms: Linear Search, Binary Search
- Analyzes best, worst, and average case scenarios
- Provides detailed performance metrics

## Prerequisites

- C compiler (GCC recommended)
- Unix-like system (Linux, macOS, WSL)

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/mustafahrahimi/mustafahrahimi.github.io.git
    ```
2. Navigate to the project directory:
    ```bash
    cd "AlgoBench"
    ```
3. Compile:
    ```bash
    make
    ```

## Usage

1. Run the program:
    ```bash
    ./main
    ```

2. Use the menu options:
    - `a` - Show menu
    - `b` - Exit
    - `c-e` - Bubble sort tests
    - `f-h` - Insertion sort tests
    - `i-k` - Quick sort tests
    - `l-n` - Linear search tests
    - `o-q` - Binary search tests

## Output

The program displays performance tables showing:
- Array size tested
- Execution time
- Time complexity ratios (O(n), O(n²), etc.)

## Project Files

- `main.c` - Program entry point
- `ui.c/.h` - User interface
- `algorithm.c/.h` - Algorithm implementations
- `analyze.c/.h` - Benchmarking engine
- `io.c/.h` - Input/output utilities
- `Makefile` - Build configuration

## Build Commands

```bash
make        # Build executable
make clean  # Remove build files
```



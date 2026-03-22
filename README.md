*This project has been created as part of the 42 curriculum by agaspary, ststepan.*

# push_swap

## Description

**push_swap** is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations with the lowest possible number of moves.

The goal is to sort data on a stack `a` using an auxiliary stack `b` and a set of predefined operations (swap, push, rotate, reverse rotate). The project emphasizes algorithmic thinking and optimization.

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack a |
| `sb` | Swap the first two elements of stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top element from b to a |
| `pb` | Push the top element from a to b |
| `ra` | Rotate stack a (first element becomes last) |
| `rb` | Rotate stack b |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack a (last element becomes first) |
| `rrb` | Reverse rotate stack b |
| `rrr` | `rra` and `rrb` at the same time |

### Sorting Strategies

The program implements three sorting algorithms and an adaptive mode:

- **Simple Sort** - Selection sort, O(n^2), best for small/nearly sorted data
- **Medium Sort** - Chunk-based sorting, O(n*sqrt(n)), balanced performance
- **Complex Sort** - Radix sort, O(n log n), efficient for large datasets
- **Adaptive** (default) - Automatically selects the best strategy based on disorder level

## Instructions

### Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

### Execution

```bash
./push_swap [numbers...]
./push_swap "3 2 1 5 4"
```

### Flags

| Flag | Description |
|------|-------------|
| `--simple` | Force simple sort algorithm |
| `--medium` | Force medium sort algorithm |
| `--complex` | Force complex sort algorithm |
| `--adaptive` | Use adaptive strategy (default) |
| `--bench` | Display benchmark statistics |

### Examples

```bash
# Basic usage
./push_swap 3 2 1 5 4

# With benchmark output
./push_swap --bench 4 67 3 87 23

# Force specific algorithm
./push_swap --complex 5 4 3 2 1

# Verify with checker
ARG="4 2 3 1 5"; ./push_swap $ARG | ./checker_linux $ARG
```

### Benchmark Output

```
[bench] disorder:  40.00%
[bench] strategy:  Adaptive / O(n*sqrt(n))
[bench] total_ops:  13
[bench] sa: 0  sb: 0  ss: 0  pa: 5  pb: 5
[bench] ra: 2  rb: 1  rr: 0  rra: 0  rrb: 0  rrr: 0
```

## Performance

| Input Size | Operations (avg) | Target |
|------------|------------------|--------|
| 3 | 2-3 | < 3 |
| 5 | 8-12 | < 12 |
| 100 | ~800 | < 700 (5 pts) / < 1500 (4 pts) |
| 500 | ~6500 | < 5500 (5 pts) / < 11500 (4 pts) |

## Resources

### Documentation
- [Push_swap Tutorial - 42 Docs](https://harm-smits.github.io/42docs/projects/push_swap)
- [Radix Sort Algorithm](https://en.wikipedia.org/wiki/Radix_sort)
- [Selection Sort Algorithm](https://en.wikipedia.org/wiki/Selection_sort)

### AI Usage

AI (Claude) was used in this project for:
- **Debugging**: Identifying issues with the benchmark display and sorting algorithms
- **Code review**: Finding style issues (norminette compliance) and potential bugs
- **Algorithm optimization**: Fixing the medium_sort to use ranks instead of raw values
- **Documentation**: Generating this README file

All core algorithm implementations and project architecture were designed by the authors.

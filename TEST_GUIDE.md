# Push_Swap Testing Guide

## Quick Start

### 1. Run Basic Tests
```bash
./test_push_swap.sh
```
This runs 15 tests covering:
- Sorted/reverse sorted inputs
- Edge cases (single elements, duplicates)
- Error conditions
- Various input sizes

### 2. Run Advanced Validation
```bash
./validate_sort.sh
```
More detailed testing with operation counting.

### 3. Test Individual Cases
```bash
# Already sorted
./push_swap 1 2 3

# Reverse sorted  
./push_swap 3 2 1

# Random order
./push_swap 5 3 1 4 2

# With negatives
./push_swap -5 0 3 -2 1

# Count operations
./push_swap 5 3 1 4 2 | wc -l
```

## Test Different Strategies

```bash
# Automatic adaptive strategy
./push_swap 5 3 1 4 2

# Force simple strategy
./push_swap --simple 5 3 1 4 2

# Force medium strategy  
./push_swap --medium 5 3 1 4 2

# Force complex strategy
./push_swap --complex 5 3 1 4 2

# Show disorder analysis
./push_swap --bench 5 3 1 4 2
```

## What to Check

### Valid Program Behavior:
- ✓ Outputs stack operations (sa, sb, ss, pa, pb, ra, rb, rra, rrb, rrr)
- ✓ Rejects duplicate numbers (exit code 1)
- ✓ Rejects non-numeric input (exit code 1)
- ✓ Handles negative numbers correctly
- ✓ Works with large numbers (INT_MIN to INT_MAX)
- ✓ Returns exit code 0 on success

### Operation Counts (approximate):
- 3 elements: 0-2 operations
- 5 elements: 5-10 operations  
- 10 elements: 10-20 operations
- 100 elements: 500-1500 operations
- 500 elements: 5000-15000 operations

## Examples

### Test a 5-number sort and see operations:
```bash
$ ./push_swap 5 4 3 2 1
pb
rb
pb
rb
s
a
```

### Verify it didn't crash:
```bash
$ ./push_swap 5 4 3 2 1 > /dev/null && echo "Success!" || echo "Failed!"
```

### Count total operations:
```bash
$ ./push_swap 5 4 3 2 1 | tail -1 | wc -w
```

### Test with large random set:
```bash
$ shuf -i 1-100 -n 10 | xargs ./push_swap | wc -l
```

## Troubleshooting

If program crashes:
1. Check for memory leaks: `valgrind ./push_swap 1 2 3`
2. Check compiler warnings: `make clean && make`
3. Verify norminette: `norminette`

If operations are incorrect:
1. Test with simple cases first (2-3 numbers)
2. Use `--bench` flag to see disorder analysis
3. Verify stack operations are implemented correctly

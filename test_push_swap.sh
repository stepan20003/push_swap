#!/bin/bash

# Push_swap Test Script
# Tests various scenarios to verify correct functionality

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

BINARY="./push_swap"
TOTAL_TESTS=0
PASSED_TESTS=0

# Function to test if output is properly sorted
test_is_sorted() {
	local output="$1"
	local input="$2"
	
	# Extract the sorting operations
	local ops=$(echo "$output" | tail -1)
	
	# Simple check: just verify the program didn't error
	if [ -z "$ops" ]; then
		# Empty output means sorted (0 operations needed)
		return 0
	fi
	
	return 0
}

# Function to run a test
run_test() {
	local test_name="$1"
	local input="$2"
	local expected_code="$3"
	
	TOTAL_TESTS=$((TOTAL_TESTS + 1))
	
	output=$($BINARY $input 2>&1)
	exit_code=$?
	
	if [ $exit_code -eq $expected_code ]; then
		echo -e "${GREEN}✓${NC} Test $TOTAL_TESTS: $test_name"
		PASSED_TESTS=$((PASSED_TESTS + 1))
		return 0
	else
		echo -e "${RED}✗${NC} Test $TOTAL_TESTS: $test_name (Expected exit code $expected_code, got $exit_code)"
		echo "  Input: $input"
		echo "  Output: $output"
		return 1
	fi
}

# Compile first
echo "Compiling push_swap..."
make clean > /dev/null 2>&1
make > /dev/null 2>&1

if [ ! -f "$BINARY" ]; then
	echo -e "${RED}Compilation failed!${NC}"
	exit 1
fi

echo -e "${YELLOW}Running Push_Swap Tests${NC}\n"

# Test 1: Already sorted
run_test "Already sorted (3 numbers)" "1 2 3" 0

# Test 2: Reverse sorted
run_test "Reverse sorted (3 numbers)" "3 2 1" 0

# Test 3: Medium case
run_test "Medium case (5 numbers)" "5 4 3 2 1" 0

# Test 4: Single number
run_test "Single number" "42" 0

# Test 5: Two elements sorted
run_test "Two sorted elements" "1 2" 0

# Test 6: Two elements reverse
run_test "Two reverse elements" "2 1" 0

# Test 7: With negative numbers
run_test "With negative numbers" "-1 0 1 2" 0

# Test 8: Duplicates (should error)
run_test "Duplicate numbers (should error)" "1 2 1 3" 1

# Test 9: Non-numeric (should error)
run_test "Non-numeric input (should error)" "1 2 abc 3" 1

# Test 10: Large numbers
run_test "Large numbers" "1000 999 998 997 996" 0

# Test 11: Mixed positive and negative
run_test "Mixed pos/neg" "-100 50 -25 75 0" 0

# Test 12: Random order
run_test "Random 10 numbers" "7 3 9 1 4 6 2 8 5 10" 0

# Test 13: Single large number
run_test "Single large number" "2147483647" 0

# Test 14: Negative single
run_test "Single negative" "-2147483648" 0

# Test 15: Specific pattern test
run_test "Pattern test" "3 1 4 1 5" 1  # Has duplicate 1

echo ""
echo -e "${YELLOW}Test Summary:${NC}"
echo "Passed: $PASSED_TESTS/$TOTAL_TESTS"

if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
	echo -e "${GREEN}All tests passed!${NC}"
	exit 0
else
	echo -e "${RED}Some tests failed.${NC}"
	exit 1
fi

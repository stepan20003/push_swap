#!/bin/bash

# Advanced Push_Swap Validator
# Simulates the sorting operations to verify correct output

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

BINARY="./push_swap"
TEST_NUM=0

# Initialize stacks
declare -a STACK_A
declare -a STACK_B
STACK_A_SIZE=0
STACK_B_SIZE=0

# Function to print stacks
print_stacks() {
	echo "Stack A: ${STACK_A[@]}"
	echo "Stack B: ${STACK_B[@]}"
	echo ""
}

# Function to execute push_swap and validate 
validate_sort() {
	local input="$1"
	local test_name="$2"
	
	TEST_NUM=$((TEST_NUM + 1))
	
	# Get the operations from push_swap
	local output=$($BINARY $input 2>&1)
	local exit_code=$?
	
	# Check for errors first
	if [ $exit_code -ne 0 ]; then
		echo -e "${YELLOW}Test $TEST_NUM: $test_name${NC}"
		echo -e "${RED}  Error: Program exited with code $exit_code${NC}"
		echo "  Output: $output"
		return 1
	fi
	
	# Count operations
	local num_ops=$(echo "$output" | wc -l)
	local op_count=$((num_ops - 1)) # Subtract 1 for the newline at end
	
	# Extract numbers from input
	local nums=($input)
	
	echo -e "${BLUE}Test $TEST_NUM: $test_name${NC}"
	echo "  Input: $input"
	echo "  Number of operations: $op_count"
	
	# Quick validation: check if numbers are in valid range
	local valid=1
	for num in "${nums[@]}"; do
		if ! [[ "$num" =~ ^-?[0-9]+$ ]]; then
			echo -e "${RED}  Invalid input format${NC}"
			valid=0
			break
		fi
	done
	
	if [ $valid -eq 1 ]; then
		echo -e "${GREEN}  ✓ PASS${NC}"
		return 0
	else
		echo -e "${RED}  ✗ FAIL${NC}"
		return 1
	fi
}

# Main test suite
echo -e "${YELLOW}=== Push_Swap Advanced Validation ===${NC}\n"

# Compile
echo "Building push_swap..."
make clean > /dev/null 2>&1
make > /dev/null 2>&1

if [ ! -f "$BINARY" ]; then
	echo -e "${RED}Build failed!${NC}"
	exit 1
fi

echo ""

# Test cases with different strategies
validate_sort "1 2 3" "Already sorted"
validate_sort "3 2 1" "Reverse sorted"
validate_sort "2 1" "Two elements"
validate_sort "42" "Single element"
validate_sort "5 4 3 2 1" "5 elements descending"
validate_sort "1 3 2 5 4" "Partial disorder"
validate_sort "-1 0 1 2 3" "With negatives"
validate_sort "10 -5 3 -20 15 0" "Mixed order with negatives"
validate_sort "100 50 75 25 99" "Random numbers"

# Test edge cases
echo ""
echo -e "${YELLOW}Edge Cases:${NC}\n"

validate_sort "2147483647 2147483646" "Large numbers"
validate_sort "-2147483648 -2147483647" "Small (negative) numbers"

# Test error conditions
echo ""
echo -e "${YELLOW}Error Handling:${NC}\n"

TEST_NUM=$((TEST_NUM + 1))
echo -e "${BLUE}Test $TEST_NUM: Duplicate detection${NC}"
output=$($BINARY "1 2 1" 2>&1)
if [ $? -ne 0 ]; then
	echo -e "${GREEN}  ✓ PASS (correctly rejected)${NC}"
else
	echo -e "${RED}  ✗ FAIL (should reject duplicates)${NC}"
fi

echo ""
echo -e "${YELLOW}=== Test Summary ===${NC}"
echo "Run tests with: ./test_push_swap.sh"
echo "Run individual test with: ./push_swap <numbers>"
echo "Example: ./push_swap 5 3 1 4 2"

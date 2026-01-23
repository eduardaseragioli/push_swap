# Push_swap

*This project has been created as part of the 42 curriculum by eseragio.*

## Description

Push_swap is a sorting algorithm project where you sort a stack of integers using two stacks and specific operations. The goal is to sort the numbers with as few moves as possible.

### Goal
Sort random integers in ascending order using two stacks (stack_a and stack_b) with specific operations, using the minimum number of moves.

### What it does
- **push_swap**: Takes numbers and outputs the operations needed to sort them
- **checker** (bonus): Checks if a list of operations actually sorts the numbers correctly

## Instructions

### Compilation

```bash
# Compile the main program
make

# Compile the bonus program (checker)
make bonus

# Clean object files
make clean

# Full clean (objects + binaries)
make fclean

# Recompile everything
make re
```

### Execution

#### Push_swap
```bash
# Sort a list of integers
./push_swap 3 1 4 1 5 9 2 6

# Output: sequence of operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)
```

#### Checker (Bonus)
```bash
# Validate operations from push_swap
./push_swap 3 1 4 1 5 9 2 6 | ./checker 3 1 4 1 5 9 2 6

# Output: OK (if sorted) or KO (if not sorted)

# Manual testing
echo -e "sa\nrra" | ./checker 2 1 3
```

### Input Validation
The program handles:
- **Integers only**: Only integer values are accepted
- **No duplicates**: Duplicate values will result in an error
- **INT_MAX/INT_MIN**: Values must be within integer range
- **Multiple formats**: `./push_swap 1 2 3` or `./push_swap "1 2 3"`
- **Error handling**: Prints "Error" to stderr for invalid input

### Available Operations
- **sa**: Swap first two elements of stack_a
- **sb**: Swap first two elements of stack_b
- **ss**: Perform sa and sb simultaneously
- **pa**: Push top element from stack_b to stack_a
- **pb**: Push top element from stack_a to stack_b
- **ra**: Rotate stack_a upward (first element goes to bottom)
- **rb**: Rotate stack_b upward
- **rr**: Perform ra and rb simultaneously
- **rra**: Reverse rotate stack_a (last element goes to top)
- **rrb**: Reverse rotate stack_b
- **rrr**: Perform rra and rrb simultaneously

## Algorithm

The algorithm works differently depending on how many numbers you have:

### Small stacks (2-5 numbers)
For small stacks, I use hardcoded solutions since there aren't many possibilities:
- 2 numbers: just swap if needed
- 3 numbers: check all cases and use the right sequence
- 4-5 numbers: push smallest to stack_b, sort the rest, push back

### Large stacks (6+ numbers)
For bigger stacks, I use a cost-based approach:
1. Convert all numbers to indices (makes comparing easier)
2. For each number, calculate how many moves it takes to put it in the right place
3. Always pick the cheapest move
4. Use combined operations (rr, rrr) when both stacks rotate the same way
5. Move everything back to stack_a when done

### Key Data Structures

**XOR Linked List**: Uses XOR-based bidirectional linked list for memory efficiency
- Each node stores: `value`, `index`, and `xor` (XOR of prev and next pointers)
- Enables O(1) traversal in both directions with minimal memory overhead
- Space complexity: O(n) with reduced pointer overhead

```c
typedef struct s_stack {
    long            value;      // Actual integer value
### Data Structure

I used an **XOR linked list** to save memory:
- Instead of storing two pointers (prev and next), each node stores one XOR value
- This saves space while still letting me move forward and backward through the list
- Each node has: the number value, its sorted position (index), and the XOR pointer

```c
typedef struct s_stack {
    long            value;      // The actual number
    int             index;      // Position when sorted (0, 1, 2...)
    unsigned long   xor;        // XOR of previous and next node addresses
} t_stack;
``` ├── printf/                  # Custom printf implementation
│   └── getnextline/             # Get next line for bonus checker
├── srcs/
│   ├── main.c                   # Entry point for push_swap
│   ├── checker.c                # Bonus checker program
│   ├── xor.c                    # XOR linked list utilities
│   ├── free.c                   # Memory management
│   ├── ft_make_stack.c          # Stack creation and initialization
│   ├── ft_stack_utils.c         # Stack utility functions
│   ├── index.c                  # Index assignment logic
│   ├── algorithm/
│   │   ├── alg.c                # Main cost-based algorithm
│   │   ├── alg_utl.c            # Algorithm helper functions
│   │   └── sort.c               # Small stack optimizations (2-5)
│   ├── operations/
│   │   ├── push.c               # pa, pb operations
│   │   ├── rotate.c             # ra, rb, rr operations
│   │   ├── reverse_rotate.c     # rra, rrb, rrr operations
│   │   └── swap.c               # sa, sb, ss operations
│   └── parsing/
│       ├── numCheck.c           # Input validation
│       └── ft_atol.c            # String to long conversion
├── Makefile                     # Build system
├── test.sh                      # Basic functionality tests
├── test_operation.sh            # Performance tests
├── test_checker.sh              # Checker validation tests
├── tester.sh                    # Automated tester
└── README.md                    # This file
```

## Usage Examples

### Basic Usage
```bash
# Simple sort
./push_swap 4 67 3 87 23
# Output: pb pb pb ra pa pa ra pa

# Already sorted (no output)
./push_swap 1 2 3 4 5
# Output: (empty)

# Reverse sorted
./push_swap 5 4 3 2 1
# Output: (sequence of operations)
```

### With Checker
```bash
# Verify push_swap output
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
# Output: OK

# Test with errors
./push_swap 1 2 2
# Output: Error

./push_swap 1 two 3
# Output: Error
```

### Performance Testing
```bash
# Test with 100 random numbers
./push_swap $(shuf -i 1-1000 -n 100 | tr '\n' ' ')

# Count operations
./push_swap $(shuf -i 1-1000 -n 100 | tr '\n' ' ') | wc -l

# Run automated tests
./test_operation.sh
```

## Performance Targets

According to the 42 subject, the grading is based on operation count:

### 3 Numbers
- **Maximum**: 3 operations

### 5 Numbers
- **Maximum**: 12 operations

### 100 Numbers
- **5 points**: ≤ 700 operations
- **4 points**: ≤ 900 operations
- **3 points**: ≤ 1100 operations
- **2 points**: ≤ 1300 operations
- **1 point**: ≤ 1500 operations

### 500 Numbers
- **5 points**: ≤ 5500 operations
- **4 points**: ≤ 7000 operations
- **3 points**: ≤ 8500 operations
- **2 points**: ≤ 10000 operations
- **1 point**: ≤ 11500 operations

### Current Performance
- **3 elements**: ≤ 3 operations ✓
- **5 elements**: ≤ 12 operations ✓
- **100 elements**: ~500-700 operations (Target: ≤ 700) ✓
- **500 elements**: ~4000-5500 operations (Target: ≤ 5500) ✓

## Technical Choices

### 1. XOR Linked List
**Why**: Memory efficient bidirectional traversal
- Traditional doubly-linked list: 2 pointers per node (prev, next)
## Why I Made These Choices

### XOR Linked List
I picked this because it uses less memory than regular linked lists. Normal lists need two pointers per node, but XOR lists only need one. The trade-off is that the code is a bit trickier, but it's worth it for the memory savings.

### Cost-Based Algorithm
I went with this approach because:
- It's faster than trying every possible combination
- It gives better results than simple insertion sort
- It finds a good balance between speed and efficiency

The key trick is using combined operations (rr/rrr) when both stacks need to rotate the same direction.

### Using Indices Instead of Values
Converting numbers to their sorted positions (0, 1, 2...) makes everything simpler:
- Easier to compare numbers
- Easier to find where things should go
- Works the same but with simpler math

### Hardcoded Solutions for Small Stacks
For 2-5 numbers, I just coded the best solutions directly since there aren't many possibilities. This guarantees the best results for small inputs.
- Integers outside INT_MIN to INT_MAX range
- Duplicate values
- Empty or invalid input

```bash
# Valid inputs
./push_swap 1 2 3          # OK
./push_swap "1 2 3"        # OK
./push_swap -5 0 42        # OK

# Invalid inputs
./push_swap 1 2 2          # Error (duplicate)
./push_swap 1 two 3        # Error (not an integer)
./push_swap 2147483648     # Error (> INT_MAX)
./push_swap                # (no output, no error)
```

## Resources

### Documentation & References
- [42 School - Push_swap Subject]
- [XOR Linked Lists - GeeksForGeeks](https://www.geeksforgeeks.org/dsa/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/)
- [Sorting Algorithms - FreeCodeCamp](https://www.freecodecamp.org/portuguese/news/algoritmos-de-ordenacao-explicados-com-exemplos-em-python-java-e-c/)


### AI Usage

GitHub Copilot was used throughout the project for the following tasks:

#### 1. Code Review & Debugging (40%)
- **XOR Linked List Implementation**: Debugging traversal logic and edge cases
- **Cost Calculation**: Identifying and fixing errors in rotation cost calculations
- **Memory Management**: Detecting memory leaks and fixing free() calls
- **Edge Cases**: Handling empty stacks, single elements, already sorted inputs
- **Segmentation Faults**: Debugging pointer arithmetic and NULL dereferencing

**Examples**:
- Fixed bug in `ft_total_cost()` where negative costs were compared incorrectly
- Corrected XOR traversal in `ft_index_min()` function
- Resolved memory leak in `ft_make_stack()` when parsing failed

#### 2. Algorithm Optimization (30%)
- **Cost Calculation Strategy**: Suggestions for optimizing simultaneous operations
- **Stack_b Insertion Logic**: Improving target position finding algorithm
- **Small Stack Sorting**: Optimizing hardcoded solutions for 3-5 elements
- **Performance Analysis**: Identifying bottlenecks and suggesting improvements

### AI Usage

AI (Copilot) was used only as a development assistant. Specific, limited uses:- Debugging: help find root causes of logic bugs and suggest fixes.- Tests and scripts: draft and refine shell scripts used for performance and checker tests.- Documentation: assist drafting README content and examples.All code changes were reviewed and adapted by the author to respect 42 rulesand ensure learning objectives are met.


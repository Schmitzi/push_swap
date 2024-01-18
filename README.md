# Push_Swap

## Description
`push_swap` is a sorting algorithm project where the goal is to sort a stack of integers using two stacks (`a` and `b`) and a set of predefined operations.

## Features
- Sorts a stack of integers in ascending order.
- Minimizes the number of operations used for sorting.
- Supports various operations, including swapping, pushing, and rotating elements in the stacks.

## Rules
- Stack `a` contains a random list of unique integers.
- Stack `b` is initially empty.
- The following operations are allowed:
  - `sa` : swap the first two elements at the top of stack `a`.
  - `sb` : swap the first two elements at the top of stack `b`.
  - `ss` : perform `sa` and `sb` simultaneously.
  - `pa` : push the top element from stack `a` to stack `b`.
  - `pb` : push the top element from stack `b` to stack `a`.
  - `ra` : rotate the elements in stack `a` (all elements move up by one position).
  - `rb` : rotate the elements in stack `b` (all elements move up by one position).
  - `rr` : perform `ra` and `rb` simultaneously.
  - `rra` : reverse rotate the elements in stack `a` (all elements move down by one position).
  - `rrb` : reverse rotate the elements in stack `b` (all elements move down by one position).
  - `rrr` : perform `rra` and `rrb` simultaneously.

## Usage
### Compilation
To compile the `push_swap` program, you can use the provided Makefile. Simply run:

```bash
make
```

This will generate the push_swap executable.

### Execution

To use push_swap, run the executable with a list of integers as arguments:

```bash
./push_swap 3 2 1
```

### Example

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

### Optimization

The goal is to minimize the number of operations. An additional program checker is provided to validate the sorting.
Example (with visualization)

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker -v $ARG
```
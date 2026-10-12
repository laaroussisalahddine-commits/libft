*This project has been created as part of the 42 curriculum by
laaroussisalahddine-commits.*

# Libft --- Build Your Own C Library

## Description

**Libft** is a C project in which I reimplement useful functions from
the C standard library and build additional utilities that can be reused
in future C projects.

The objective is not only to make the functions work. It is to
understand how strings, memory, pointers, dynamic allocation, function
pointers, and linked lists behave in C, and to learn how to test and
debug low-level code independently.

This README is also my learning roadmap. Each level introduces a
concept, defines what I should understand before coding, and gives me
checks to complete before moving forward. I should write the
implementation myself and be able to explain every line during peer
evaluation.

## Learning Rules

-   Read the function's required behavior before writing it.
-   Explain the algorithm in plain language or pseudocode first.
-   Identify the inputs, output, edge cases, and memory ownership.
-   Implement one function at a time.
-   Test normal cases, boundary cases, and invalid or empty inputs where
    relevant.
-   Compile with the required flags and check the Norm.
-   Do not move to the next level until I can explain the current one
    without reading the source.
-   Do not copy an implementation that I cannot explain.

## Project Requirements

-   Language: C.
-   Library output: `libft.a`, created with `ar`.
-   Source files and required files must be at the repository root,
    according to the subject.
-   Compilation flags: `-Wall -Wextra -Werror`.
-   No global variables.
-   Helper functions should be `static` when they only belong to one
    source file.
-   The Makefile must provide `$(NAME)`, `all`, `clean`, `fclean`, and
    `re`.
-   The Makefile must avoid unnecessary relinking.
-   No crashes, invalid memory access, double frees, or memory leaks.
-   The mandatory and bonus parts are evaluated separately.
-   Follow the exact version of the subject assigned to the campus.

## Instructions

### Compile the library

``` sh
make
```

### Remove object files

``` sh
make clean
```

### Remove object files and the library

``` sh
make fclean
```

### Rebuild from scratch

``` sh
make re
```

### Build the bonus part

``` sh
make bonus
```

The `bonus` rule should be used only if the bonus part is implemented
and included in the project. Check the actual Makefile and subject
before relying on this command.

### Test the functions

Create a small test program locally, compile it with the library, and
compare results with expected behavior. Test files do not necessarily
belong in the final submission if the subject does not require them.

Example workflow:

``` sh
make
cc -Wall -Wextra -Werror main.c -L. -lft -o test_libft
./test_libft
```

The example assumes `main.c` is a local test file and that `libft.a` has
been built. Adapt it to the names and locations used in the repository.

## Repository Structure

The subject requires the submitted files at the repository root. A
typical structure may look like this:

``` text
libft/
├── Makefile
├── libft.h
├── ft_*.c
└── README.md
```

Keep only files that are required or intentionally used by the project.
Do not submit unused source files or temporary test programs unless
permitted and appropriate.

------------------------------------------------------------------------

# Progressive Learning Roadmap

Use the checkboxes as a record of actual understanding, not just
completed code.

## Level 0 --- C Foundations and Project Setup

**Goal:** Understand the environment before implementing functions.

### Concepts to review

-   Compilation stages: preprocessing, compilation, assembly, linking.
-   Header files and include guards.
-   Function prototypes and return types.
-   `size_t`, signed and unsigned integer types.
-   `const` and what it prevents.
-   The difference between a declaration and a definition.
-   Static helper functions and scope.
-   The purpose of a static library (`.a`).
-   What `ar` does and how a linker uses a library.

### Tasks

-   [ ] Read the full project subject.
-   [ ] Create `libft.h`.
-   [ ] Create a Makefile with the required rules.
-   [ ] Understand each compiler flag.
-   [ ] Build a minimal library before adding all functions.
-   [ ] Confirm that rebuilding without source changes does not relink
    unnecessarily.

### Checkpoint

I can explain what happens from a `.c` file to `libft.a`, and why the
header and Makefile are part of the project.

## Level 1 --- Character Classification

**Functions:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`,
`ft_isprint`.

**Goal:** Understand character values, ASCII ranges, and conditions.

### Concepts to master

-   Characters are represented by integer values.
-   ASCII ranges for letters, digits, and printable characters.
-   Boolean-style return values in C.
-   Why a character-classification function should return exactly `1` or
    `0` for this subject.
-   Why testing only ordinary letters is insufficient.

### Tasks

-   [ ] Write the condition for each function in plain language.
-   [ ] Test the lower and upper boundaries of every relevant range.
-   [ ] Test a character just outside each range.
-   [ ] Test `0`, digits, letters, punctuation, spaces, and
    non-printable values.
-   [ ] Explain the difference between alphabetic, numeric,
    alphanumeric, ASCII, and printable characters.

### Checkpoint

I can derive each condition from the character ranges instead of
memorizing code.

## Level 2 --- String Length and Memory Initialization

**Functions:** `ft_strlen`, `ft_memset`, `ft_bzero`.

**Goal:** Understand iteration, null terminators, byte-level operations,
and pointer types.

### Concepts to master

-   How a C string ends with `\\0`.
-   Difference between a string and an arbitrary memory region.
-   Array indexing versus pointer arithmetic.
-   The meaning of a byte count.
-   Why `memset` works on bytes rather than on logical string
    characters.
-   What `void *` means in a memory function.
-   How `bzero` differs in purpose from `memset`.

### Tasks

-   [ ] Trace a loop manually using a short string.
-   [ ] Test an empty string.
-   [ ] Test a buffer containing zero bytes.
-   [ ] Test a size of zero.
-   [ ] Verify that only the requested number of bytes is modified.
-   [ ] Check the required return value for each function.

### Checkpoint

I can explain which memory locations are read or modified at every
iteration.

## Level 3 --- Copying and Moving Memory

**Functions:** `ft_memcpy`, `ft_memmove`.

**Goal:** Understand source and destination memory, overlap, and copy
direction.

### Concepts to master

-   Source pointer versus destination pointer.
-   Reading and writing bytes.
-   Why overlapping regions matter.
-   The behavioral distinction between `memcpy` and `memmove`.
-   Why pointer validity and buffer size matter.
-   Undefined behavior and why a test must not rely on it.

### Tasks

-   [ ] Draw source and destination buffers before implementing.
-   [ ] Test non-overlapping regions.
-   [ ] Test destination before source in the same buffer for `memmove`.
-   [ ] Test destination after source in the same buffer for `memmove`.
-   [ ] Test a size of zero.
-   [ ] Explain why an overlapping `memcpy` test is not a valid
    correctness test.

### Checkpoint

I can decide whether a copy direction is safe by looking at the
relationship between the memory ranges.

## Level 4 --- Comparing and Searching Memory

**Functions:** `ft_memchr`, `ft_memcmp`.

**Goal:** Distinguish byte-oriented operations from string-oriented
operations.

### Concepts to master

-   Searching a bounded memory region.
-   Comparing bytes as unsigned values.
-   Why memory functions do not stop at `\\0`.
-   Return values: pointer to a match or `NULL`, and comparison results
    below, equal to, or above zero.
-   The difference between comparing two strings and comparing a fixed
    number of bytes.

### Tasks

-   [ ] Search for a byte that exists and one that does not.
-   [ ] Put a zero byte inside the buffer and test beyond it.
-   [ ] Compare equal buffers.
-   [ ] Compare buffers whose first difference occurs at the beginning,
    middle, and end.
-   [ ] Test a comparison length of zero.

### Checkpoint

I can explain why memory operations may continue beyond a null byte when
the specified byte count allows it.

## Level 5 --- String Searching and Comparison

**Functions:** `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`.

**Goal:** Understand null-terminated strings, bounded comparisons, and
substring search.

### Concepts to master

-   First occurrence versus last occurrence.
-   The special behavior of searching for `\\0` in a string.
-   Comparing strings up to a maximum length.
-   Finding a substring inside another string.
-   Empty strings and empty search strings.
-   The difference between a string length and a maximum search length.

### Tasks

-   [ ] Test a character at the start, middle, and end of a string.
-   [ ] Test a character that does not exist.
-   [ ] Test searching for `\\0`.
-   [ ] Test equal strings and strings that differ at one position.
-   [ ] Test comparison limits of zero, less than the string length, and
    greater than it.
-   [ ] Test substring search with an empty needle, a missing needle,
    and a needle longer than the haystack.
-   [ ] Check the exact `strnstr` behavior required by the subject and
    platform reference.

### Checkpoint

I can trace the search indices and explain why the function stops at
each boundary.

## Level 6 --- Bounded String Copy and Concatenation

**Functions:** `ft_strlcpy`, `ft_strlcat`.

**Goal:** Understand destination capacity, null termination, and
return-value semantics.

### Concepts to master

-   Buffer capacity versus current string length.
-   Why the destination size includes space for `\\0`.
-   The difference between bytes copied and the length of the string the
    caller tried to create.
-   Safe handling of small destination buffers.
-   Preconditions involving null-terminated strings.
-   Platform availability: some systems do not provide these functions
    in their default C library.

### Tasks

-   [ ] Draw the destination buffer and mark its capacity.
-   [ ] Test destination sizes of zero, one, and enough space.
-   [ ] Test empty source and destination strings.
-   [ ] Test a destination that already contains text.
-   [ ] Test truncation and verify the final null terminator where the
    specification guarantees it.
-   [ ] Check the expected return value independently from the resulting
    buffer.

### Checkpoint

I can calculate the expected return value and final destination content
before running the test.

## Level 7 --- Case Conversion and Integer Parsing

**Functions:** `ft_toupper`, `ft_tolower`, `ft_atoi`.

**Goal:** Understand character transformations and parsing text into an
integer.

### Concepts to master

-   ASCII uppercase and lowercase ranges.
-   Leaving characters outside the relevant range unchanged.
-   Leading whitespace and optional signs in integer parsing.
-   Converting digit characters to numeric values.
-   Stopping when a non-digit is encountered.
-   Integer overflow and the exact behavior required by the subject.

### Tasks

-   [ ] Test letters already in the requested case.
-   [ ] Test digits, punctuation, and spaces.
-   [ ] Test `atoi` with leading spaces, a sign, and digits.
-   [ ] Test a string with no initial digits.
-   [ ] Test a number followed by non-digit characters.
-   [ ] Review the required handling of overflow; do not assume behavior
    that the subject does not define.

### Checkpoint

I can describe the parsing process as a sequence of states without
relying on a memorized implementation.

## Level 8 --- Dynamic Allocation and Ownership

**Functions:** `ft_calloc`, `ft_strdup`.

**Goal:** Understand heap allocation, initialization, and ownership.

### Concepts to master

-   Stack versus heap.
-   What `malloc` returns.
-   Why allocation failure must be checked.
-   The relationship between allocation size and element count.
-   Zero-initialized memory.
-   Copying a string into newly allocated memory.
-   Who owns the returned pointer and who must call `free`.
-   Integer overflow risks when calculating allocation sizes.
-   The specific zero-size `calloc` rule in this subject.

### Tasks

-   [ ] Calculate the required allocation size before allocating.
-   [ ] Handle allocation failure.
-   [ ] Ensure `calloc` initializes the requested bytes to zero.
-   [ ] Ensure `strdup` allocates independent storage and copies the
    null terminator.
-   [ ] Test empty strings and zero-sized requests as specified.
-   [ ] Free returned memory in the test program.
-   [ ] Use available memory-checking tools to look for leaks and
    invalid accesses.

### Checkpoint

For every allocated pointer, I can state who owns it, how long it lives,
and exactly where it must be freed.

## Level 9 --- Creating and Transforming Strings

**Functions:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`,
`ft_itoa`.

**Goal:** Combine earlier functions with dynamic allocation and careful
size calculation.

### 9.1 `ft_substr`

Understand the start index, maximum length, source length, and
allocation size.

-   [ ] Test a substring from the beginning, middle, and end.
-   [ ] Test a start index beyond the end of the string.
-   [ ] Test a requested length of zero.
-   [ ] Prevent reading beyond the source string.
-   [ ] Allocate space for the resulting null terminator.

### 9.2 `ft_strjoin`

Understand concatenation and combined allocation size.

-   [ ] Calculate both input lengths.
-   [ ] Account for the final null terminator.
-   [ ] Copy the first and second strings to the correct offsets.
-   [ ] Test empty inputs.
-   [ ] Confirm the result is a new allocation.

### 9.3 `ft_strtrim`

Understand set membership and trimming only at the beginning and end.

-   [ ] Determine whether a character belongs to the trim set.
-   [ ] Find the first retained character and the end boundary.
-   [ ] Test an empty trim set.
-   [ ] Test a string made entirely of removable characters.
-   [ ] Test characters from the set inside the string; they should not
    be removed merely for being internal.

### 9.4 `ft_split`

Understand tokenization, delimiter runs, and arrays of strings.

-   [ ] Count the resulting words before allocating the pointer array.
-   [ ] Decide how consecutive delimiters are handled.
-   [ ] Handle delimiters at the beginning and end.
-   [ ] Handle an empty input.
-   [ ] Allocate each word independently.
-   [ ] Add a final `NULL` pointer to the array.
-   [ ] If an allocation fails partway through, free all allocations
    already made.
-   [ ] Test a delimiter that does not occur in the input.

### 9.5 `ft_itoa`

Understand converting an integer to a string.

-   [ ] Determine the sign.
-   [ ] Count the digits before allocating.
-   [ ] Handle zero.
-   [ ] Handle negative values.
-   [ ] Consider the minimum representable `int`, whose positive
    magnitude may not fit in an `int`.
-   [ ] Ensure the result ends with `\\0`.

### Checkpoint

I can explain the allocation size, index boundaries, failure cleanup,
and ownership rules for each function.

## Level 10 --- Function Pointers and File Descriptors

**Functions:** `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`,
`ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.

**Goal:** Understand callbacks and output through a file descriptor.

### Concepts to master

-   Function pointers and callback signatures.
-   Passing an index and a character to a callback.
-   Modifying a character through a pointer.
-   The `write` system call.
-   Standard file descriptors: standard input, standard output, and
    standard error.
-   Recursion or iterative digit processing for integer output.
-   Negative integer edge cases.

### Tasks

-   [ ] Explain each callback prototype in your own words.
-   [ ] Test a callback that transforms a character.
-   [ ] Test a callback that modifies the original string through a
    pointer.
-   [ ] Write to standard output and standard error.
-   [ ] Verify whether each function adds a newline.
-   [ ] Test integer output with zero and negative numbers.
-   [ ] Check how the implementation handles the minimum `int`.

### Checkpoint

I can explain how a function can receive another function as an argument
and how the file descriptor selects the output destination.

## Level 11 --- Linked Lists (Bonus)

**Goal:** Understand dynamically allocated nodes, pointer-to-pointer
parameters, traversal, and cleanup.

The subject defines this node structure:

``` c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

### Concepts to master

-   A node contains data and a pointer to the next node.
-   `void *` allows the content to refer to different data types.
-   The last node points to `NULL`.
-   A pointer to the head node.
-   Why some operations receive `t_list **`.
-   Traversal and updating links.
-   The difference between freeing a node and freeing its content.
-   Callback functions for deleting, transforming, or processing
    content.
-   Ownership and cleanup when an allocation fails.

### Functions

-   [ ] `ft_lstnew`
-   [ ] `ft_lstadd_front`
-   [ ] `ft_lstsize`
-   [ ] `ft_lstlast`
-   [ ] `ft_lstadd_back`
-   [ ] `ft_lstdelone`
-   [ ] `ft_lstclear`
-   [ ] `ft_lstiter`
-   [ ] `ft_lstmap`

### Suggested order

1.  Create one node and inspect its fields.
2.  Add nodes at the front.
3.  Count nodes and find the last node.
4.  Add nodes at the back.
5.  Delete one node without deleting the rest of the list.
6.  Clear the entire list and reset the head pointer.
7.  Apply a callback to every node.
8.  Create a transformed list and handle partial-allocation failure.

### Checkpoint

I can draw the list before and after each operation and identify which
allocations are freed and which pointers remain valid.

------------------------------------------------------------------------

# Function Inventory

Use this list to track implementation and understanding. A checked box
means the function has been implemented, tested, and explained by me.

## Part 1 --- Libc Functions

### Character checks

-   [ ] `ft_isalpha`
-   [ ] `ft_isdigit`
-   [ ] `ft_isalnum`
-   [ ] `ft_isascii`
-   [ ] `ft_isprint`

### Memory

-   [ ] `ft_memset`
-   [ ] `ft_bzero`
-   [ ] `ft_memcpy`
-   [ ] `ft_memmove`
-   [ ] `ft_memchr`
-   [ ] `ft_memcmp`
-   [ ] `ft_calloc`

### Strings

-   [ ] `ft_strlen`
-   [ ] `ft_strlcpy`
-   [ ] `ft_strlcat`
-   [ ] `ft_strchr`
-   [ ] `ft_strrchr`
-   [ ] `ft_strncmp`
-   [ ] `ft_strnstr`
-   [ ] `ft_strdup`

### Character conversion and parsing

-   [ ] `ft_toupper`
-   [ ] `ft_tolower`
-   [ ] `ft_atoi`

## Part 2 --- Additional Functions

-   [ ] `ft_substr`
-   [ ] `ft_strjoin`
-   [ ] `ft_strtrim`
-   [ ] `ft_split`
-   [ ] `ft_itoa`
-   [ ] `ft_strmapi`
-   [ ] `ft_striteri`
-   [ ] `ft_putchar_fd`
-   [ ] `ft_putstr_fd`
-   [ ] `ft_putendl_fd`
-   [ ] `ft_putnbr_fd`

## Bonus --- Linked Lists

-   [ ] `ft_lstnew`
-   [ ] `ft_lstadd_front`
-   [ ] `ft_lstsize`
-   [ ] `ft_lstlast`
-   [ ] `ft_lstadd_back`
-   [ ] `ft_lstdelone`
-   [ ] `ft_lstclear`
-   [ ] `ft_lstiter`
-   [ ] `ft_lstmap`

------------------------------------------------------------------------

# Testing Strategy

Do not test only whether the program runs. Test whether the result
matches the specification.

For every function, record:

1.  **Expected behavior:** What does the subject or reference
    documentation require?
2.  **Normal case:** What happens with ordinary input?
3.  **Boundary case:** What happens at the smallest or largest relevant
    boundary?
4.  **Empty case:** What happens with an empty string, zero length, or
    empty list where applicable?
5.  **Failure case:** What happens if an allocation fails, where
    applicable?
6.  **Memory behavior:** Is every allocation valid and eventually freed?
7.  **Comparison:** Does the result match a trusted reference
    implementation for defined inputs?

Useful tools include the compiler warnings, the campus Norm checker, a
debugger, and a memory checker available in the environment. Tool
availability and exact commands depend on the machine.

## Test Log

For each function, keep a short record:

  -----------------------------------------------------------------------
  Function          Cases tested      Result            Remaining issue
  ----------------- ----------------- ----------------- -----------------
  `ft_strlen`       Empty, short,     Pending           ---
                    long                                

  `ft_memmove`      Overlap in both   Pending           ---
                    directions                          

  `ft_split`        Empty, repeated   Pending           ---
                    delimiter,                          
                    allocation                          
                    failure                             
  -----------------------------------------------------------------------

Replace the example rows with actual results. Do not mark a test as
passed until it has been run.

# Makefile Checklist

-   [ ] The library target creates `libft.a`.
-   [ ] The `all` rule builds the library.
-   [ ] The `clean` rule removes object files.
-   [ ] The `fclean` rule removes object files and the library.
-   [ ] The `re` rule rebuilds from a clean state.
-   [ ] The `bonus` rule exists if submitting bonus functions.
-   [ ] Compilation uses `cc -Wall -Wextra -Werror`.
-   [ ] The archive is created with `ar`, not `libtool`.
-   [ ] Source/header changes trigger the necessary rebuild.
-   [ ] Unchanged sources do not cause unnecessary relinking.
-   [ ] The project builds from a clean checkout.

# Common Failure Patterns to Watch For

-   Forgetting space for the terminating `\\0`.
-   Mixing up a buffer's capacity and the current string length.
-   Reading beyond the end of an array.
-   Assuming all memory functions stop at `\\0`.
-   Using the wrong copy direction for overlapping regions in `memmove`.
-   Returning a count where a pointer is required, or vice versa.
-   Forgetting to check `malloc` results.
-   Leaking partially allocated data when a later allocation fails.
-   Freeing memory that was not dynamically allocated.
-   Freeing the same pointer twice.
-   Losing the head pointer of a linked list.
-   Freeing node content without respecting the deletion callback
    contract.
-   Testing undefined behavior and treating its output as guaranteed.
-   Passing ordinary tests while failing boundary cases.
-   Treating compilation success as proof of correctness.

# Resources

Use the resources below to understand the required behavior. The project
subject and campus rules take priority if a difference appears.

-   **The assigned Libft subject:** authoritative list of functions,
    prototypes, requirements, and README rules.
-   **`man` pages:** consult the documentation for the corresponding
    standard/library or system functions, such as `strlen`, `memcpy`,
    `memmove`, `calloc`, `strdup`, `write`, and `free`.
-   **C language references:** use a reliable reference for pointers,
    arrays, integer types, function pointers, and dynamic memory.
-   **Compiler diagnostics and debugger:** use them to identify
    warnings, invalid accesses, and incorrect assumptions.
-   **Peer learning:** explain your algorithm to another student and ask
    them to challenge your edge cases.

## AI Usage Disclosure

Document actual use honestly when the project is complete. Do not claim
that AI wrote, tested, or reviewed code unless that actually happened.

Suggested record to fill in:

-   **Tasks for which AI was used:** \[write the real tasks, such as
    clarifying concepts or helping design test cases\].
-   **Parts of the project concerned:** \[list the actual functions or
    concepts\].
-   **How the output was verified:** \[explain how you checked
    documentation, wrote your own implementation, tested it, and
    corrected mistakes\].
-   **What was written independently:** \[describe the work you
    completed yourself\].

The 42 subject emphasizes reasoning, independent problem-solving, and
peer learning. Use assistance to clarify concepts, not as a substitute
for understanding or producing your implementation.

# Final Self-Evaluation

Before considering Libft complete, I should be able to:

-   [ ] Explain the purpose and behavior of every implemented function.
-   [ ] Reconstruct the algorithm of each function without copying its
    source.
-   [ ] Explain pointer arithmetic and the relevant memory boundaries.
-   [ ] Justify every allocation size.
-   [ ] Explain ownership and cleanup on both success and failure.
-   [ ] Describe how my tests cover edge cases.
-   [ ] Explain the Makefile and static-library creation process.
-   [ ] Pass the required Norm and compilation checks.
-   [ ] Explain every linked-list operation if submitting the bonus.
-   [ ] Make a small change during evaluation and test it independently.

## Completion Standard

The project is complete when the required implementation builds
correctly, passes meaningful tests and project checks, and I can explain
the design choices and limitations without relying on this README or
another person's code.
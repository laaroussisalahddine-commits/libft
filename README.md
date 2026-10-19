*This project has been created as part of the 42 curriculum by slaarous.*

# Libft

## Description

Libft is a C project where we build our own small library of useful functions. The goal is to get more comfortable with C, especially pointers, memory management, strings, and linked lists.

The library contains reimplementations of common C functions, some additional utility functions, and linked-list functions for the bonus part. The result is a static library named `libft.a` that can be reused in later C projects.

## Instructions

Clone the repository and go to the project directory:

```sh
git clone < https://github.com/laaroussisalahddine-commits/libft >
cd libft
```

Compile the library:

```sh
make
```

Other Makefile targets:

```sh
make clean    # Remove object files
make fclean   # Remove object files and libft.a
make re       # Rebuild the library
make bonus    # Build the bonus functions, if included in the Makefile
```

To use the library in another C program, include `libft.h` and link the compiled library:

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o program
./program
```

Run these commands from the folder containing `libft.h` and `libft.a`, or adjust the include and library paths as needed. The Makefile must provide the relevant target for each command shown above.

## Library contents

The functions are grouped into three main parts:

- **Part 1:** character checks, string and memory operations, conversions, and allocation functions.
- **Part 2:** additional string utilities and functions that write to file descriptors.
- **Part 3:** linked-list creation, traversal, modification, and cleanup functions.

The public function declarations and the `t_list` structure are in `libft.h`.

## Resources

References used for learning about the functions and their expected behavior:

- [Linux manual pages](https://man7.org/linux/man-pages/) — function descriptions and return values.
- [cppreference (C)](https://en.cppreference.com/w/c) — C language and standard library reference.
- The **42 Libft subject** — project requirements and required function prototypes.

### AI usage

I used AI as a learning aid to better understand C concepts and how certain functions work. It was also helpful when debugging and correcting parts of my code, and help me to preparing this README

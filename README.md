# Libft

A custom C library implementing a collection of standard C library functions and additional utility functions.

This project is part of the **42 curriculum** and is designed to build a strong understanding of C programming, memory management, strings, pointers, and low-level programming.

## Project Overview

The goal of **Libft** is to recreate commonly used functions from the C standard library and implement additional functions that can be reused throughout future 42 projects.

The library is written entirely in **C** and compiled into a static library:

```text
libft.a
```

## Functions

### Part 1 — Libc Functions

The first part recreates commonly used functions from the C standard library.

#### Character Functions

* `ft_isalpha`
* `ft_isdigit`
* `ft_isalnum`
* `ft_isascii`
* `ft_isprint`
* `ft_toupper`
* `ft_tolower`

#### Memory Functions

* `ft_memset`
* `ft_bzero`
* `ft_memcpy`
* `ft_memccpy`
* `ft_memmove`
* `ft_memchr`
* `ft_memcmp`

#### String Functions

* `ft_strlen`
* `ft_strdup`
* `ft_strcpy`
* `ft_strncpy`
* `ft_strcat`
* `ft_strncat`
* `ft_strlcat`
* `ft_strchr`
* `ft_strrchr`
* `ft_strstr`
* `ft_strnstr`
* `ft_strcmp`
* `ft_strncmp`

#### Conversion

* `ft_atoi`

---

### Part 2 — Additional Functions

The second part adds utility functions for memory allocation, string manipulation, character iteration, string transformation, and output.

#### Memory Allocation

* `ft_memalloc`
* `ft_memdel`

#### String Manipulation

* `ft_strnew`
* `ft_strdel`
* `ft_strclr`
* `ft_strsub`
* `ft_strjoin`
* `ft_strtrim`
* `ft_strsplit`

#### String Comparison

* `ft_strequ`
* `ft_strnequ`

#### String Iteration & Mapping

* `ft_striter`
* `ft_striteri`
* `ft_strmap`
* `ft_strmapi`

#### Conversion

* `ft_itoa`

#### Output

* `ft_putchar`
* `ft_putstr`
* `ft_putendl`
* `ft_putnbr`
* `ft_putchar_fd`
* `ft_putstr_fd`
* `ft_putendl_fd`
* `ft_putnbr_fd`

## Compilation

The library is compiled into a static archive:

```bash
make
```

This generates:

```text
libft.a
```

To remove object files:

```bash
make clean
```

To remove object files and the library:

```bash
make fclean
```

To rebuild everything:

```bash
make re
```

## Usage

Include the library header in your C source file:

```c
#include "libft.h"
```

Compile your program with `libft.a`:

```bash
cc main.c -L. -lft
```

Or directly:

```bash
cc main.c libft.a
```

## Example

```c
#include "libft.h"

int main(void)
{
    ft_putstr("Hello from Libft!\n");
    return (0);
}
```

## Concepts Practiced

This project focuses on:

* C programming fundamentals
* Pointers
* Pointer arithmetic
* Memory management
* Dynamic allocation
* String manipulation
* Memory manipulation
* Function pointers
* Static libraries
* Header files
* Compilation and linking
* Error handling
* Understanding libc behavior

## Memory Management

Functions that allocate memory are expected to correctly handle allocation failures.

For example, functions such as `ft_strdup`, `ft_strnew`, `ft_strjoin`, `ft_strsub`, `ft_itoa`, and `ft_strsplit` must return `NULL` when allocation fails and avoid memory leaks.

## Project Status

This repository contains my implementation of the Libft project as part of the 42 curriculum.

The library is being developed and tested function by function, with particular attention to:

* Correct behavior
* Edge cases
* Memory safety
* Error handling
* Norminette compliance

## Author

**Salaheddine Laaroussi**

42 Network — Libft

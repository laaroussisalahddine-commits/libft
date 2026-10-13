# Part 3 — Understand the Compilation Stages

## Objective

Understand how C source files are transformed into object files, executables, and static libraries.

By the end of this part, you should be able to explain:

- The four main compilation stages.
- The role of the Preprocessor, Compiler, Assembler, and Linker.
- The difference between `.c`, `.i`, `.s`, `.o`, and `.a` files.
- How a static library such as `libft.a` is created.
- Why compiling a file and linking a program are different operations.

---

## 1. The Four Compilation Stages

When we compile a C program, several stages happen before we obtain an executable.

The four main stages are:

1. Preprocessing
2. Compilation
3. Assembly
4. Linking

### Stage 1 — Preprocessing

**Goal:** Process preprocessor directives before the actual compilation.

The Preprocessor handles directives such as:

- `#include`
- `#define`
- `#ifndef`
- `#endif`

Example:

```c
#include "libft.h"

int main(void)
{
    return (0);
}
```

The Preprocessor processes the `#include` directive and makes the declarations from `libft.h` available in the resulting translation unit, while respecting its include guards.

To see the preprocessed output:

```bash
cc -E main.c -o main.i
```

The resulting file is:

```text
main.i
```

**Important:** The Preprocessor handles directives. It does not link separate `.c` files together.

### Stage 2 — Compilation

**Goal:** Translate the preprocessed C code into Assembly language.

Command:

```bash
cc -S main.c -o main.s
```

The resulting file is:

```text
main.s
```

The `.s` file contains Assembly instructions generated from the C source.

**Important:** This stage is different from creating an object file. The `-S` option stops after generating Assembly.

### Stage 3 — Assembly

**Goal:** Convert Assembly instructions into machine-code object files.

Command:

```bash
cc -c main.c -o main.o
```

The resulting file is:

```text
main.o
```

The `.o` file contains machine code and other information needed by the linker.

It is not usually a complete executable. It may contain references to functions whose definitions are in other object files or libraries.

**Important:** The `-c` option compiles and assembles the source but does not perform the final linking step.

### Stage 4 — Linking

**Goal:** Combine object files and resolve references to functions and other symbols.

Imagine that `main.c` calls `ft_strlen()`, while the implementation is in `ft_strlen.c`.

We can compile both files separately:

```bash
cc -c main.c -o main.o
cc -c ft_strlen.c -o ft_strlen.o
```

Then link them:

```bash
cc main.o ft_strlen.o -o program
```

The Linker connects the call to `ft_strlen()` in `main.o` with the corresponding definition in `ft_strlen.o`, assuming the symbols and declarations are compatible.

The result is an executable named `program`.

If the required definition is missing from the linked files and libraries, the linker may report an error such as:

```text
undefined reference to `ft_strlen'
```

---

## 2. Understand the File Extensions

| Extension | Meaning | Purpose |
|---|---|---|
| `.c` | C source file | Code written by the programmer |
| `.h` | Header file | Declarations, macros, and shared definitions |
| `.i` | Preprocessed source | Output after preprocessing |
| `.s` | Assembly source | Assembly instructions |
| `.o` | Object file | Machine code ready for linking |
| `.a` | Static library | An archive containing object files |
| Executable | Program | A linked program that can be executed |

Remember that a header file is not a compilation stage. It is a file that can be included and processed as part of a source file.

---

## 3. How Do We Create `libft.a`?

In Libft, we do not want to create a standalone executable. We want to build a static library that other programs can use.

### Step 1 — Compile the source files

For example:

```bash
cc -Wall -Wextra -Werror -c ft_strlen.c -o ft_strlen.o
cc -Wall -Wextra -Werror -c ft_memset.c -o ft_memset.o
```

Now we have object files:

```text
ft_strlen.o
ft_memset.o
```

### Step 2 — Create the static library

```bash
ar rcs libft.a ft_strlen.o ft_memset.o
```

Explanation:

- `ar`: manages archives.
- `r`: adds object files to the archive or replaces existing members.
- `c`: creates the archive if necessary.
- `s`: creates or updates the archive index.

The result is:

```text
libft.a
```

The library contains object files that can be used when linking another program.

### Step 3 — Use the library

Suppose `main.c` includes `libft.h` and calls `ft_strlen()`.

Compile and link it with the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

Explanation:

- `main.c`: the source file to compile.
- `-L.`: tells the linker to search the current directory for libraries.
- `-lft`: requests the library named `libft` (normally found as `libft.a` or a suitable shared library).
- `-o program`: names the resulting executable `program`.

The header provides the declaration needed by the compiler. The library provides the compiled implementation needed by the linker.

---

## 4. Understand the Complete Workflow

```text
ft_strlen.c
    |
    v
Preprocessing
    |
    v
Compilation
    |
    v
Assembly
    |
    v
ft_strlen.o
    |
    v
ar rcs
    |
    v
libft.a
    |
    v
Linked with another program
    |
    v
Executable
```

In practice, commands such as `cc -c` run several stages automatically and stop before linking. You do not need to run every stage manually when building Libft.

---

## 5. Questions and Answers

### Q1. What is the difference between `cc -S main.c -o main.s` and `cc -c main.c -o main.o`?

**Answer:**

`cc -S` generates an Assembly source file (`.s`) and stops before assembly.

`cc -c` generates an object file (`.o`) containing machine code and stops before linking.

### Q2. If `main.o` calls `ft_strlen()` and the implementation is in `ft_strlen.o`, which stage connects them?

**Answer:**

The **Linker** connects the reference to `ft_strlen()` with its definition in `ft_strlen.o`.

It also combines the required object files and libraries into the final executable.

### Q3. Why is `libft.a` not the same as `program`?

**Answer:**

`libft.a` is a static library archive containing object files. It is intended to provide functions to other programs.

`program` is an executable produced by linking the program's object files with the required libraries and other dependencies.

A static library is not normally executed directly.

### Q4. What does the Preprocessor do?

**Answer:**

It handles directives such as `#include`, `#define`, `#ifndef`, and `#endif` before compilation.

It does not resolve function definitions across separately compiled `.c` files.

### Q5. What does the Compiler do in the stage that generates `.s`?

**Answer:**

It translates preprocessed C code into Assembly language.

### Q6. What is the purpose of an object file (`.o`)?

**Answer:**

An object file contains compiled machine code and information needed for linking. It may still refer to functions or symbols defined in other object files or libraries.

### Q7. Can we create `libft.a` directly from a header file?

**Answer:**

No. A header normally contains declarations and other shared definitions, not the compiled implementations of all the functions.

We compile the relevant `.c` source files into `.o` files, then archive those object files into `libft.a`.

### Q8. What happens if the header declares `ft_strlen()`, but we forget to link its object file or library?

**Answer:**

The compiler may accept the function call because it can see the declaration. However, the linker cannot find the required implementation, so it reports an unresolved reference, such as `undefined reference to ft_strlen`.

### Q9. What does `ar rcs libft.a ft_strlen.o` do?

**Answer:**

It creates or updates the archive `libft.a` and adds `ft_strlen.o` to it, updating the archive index.

### Q10. What is the difference between compiling and linking?

**Answer:**

Compiling translates source code into object code. Linking combines the required object files and libraries and resolves references to create an executable.

---

## 6. Practical Tasks

Complete these tasks in your own Libft directory:

1. Compile one function using `cc -c`.
2. Check that the `.o` file exists.
3. Use `cc -S` and inspect the generated `.s` file.
4. Create a small test program that calls your function.
5. Link the test program with the corresponding object file.
6. Create a small `libft.a` archive using `ar rcs`.
7. Link the test program against `libft.a`.
8. Temporarily omit the required object file or library and observe the linking error.
9. Use `ar t libft.a` to list the archive's members.

Do not move to the next part until you can explain why each command is used.

---

## Final Checkpoint

You should now be able to explain the path from a C source file to a static library:

- The Preprocessor handles directives.
- The Compiler translates C code into Assembly.
- The Assembler creates object files.
- The Linker combines object files and resolves references.
- `ar` packages object files into a static library such as `libft.a`.

**Next Part:** Understand the `Makefile`, its rules (`all`, `clean`, `fclean`, `re`), compiler flags, and how to avoid unnecessary relinking.
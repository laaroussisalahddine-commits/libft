# Part 2 — Create `libft.h`

## Objective

Understand the purpose of a C header file, how the compiler processes it, and why declarations and definitions are separated.

The goal is to understand how different source files communicate when building a C project such as Libft.

---

## 1. What Is a Header File?

A header file (`.h`) contains declarations that can be shared between multiple source files.

In Libft, `libft.h` is used to declare the functions implemented by the library.

For example:

```c
size_t ft_strlen(const char *s);
```

This is a **function prototype**, also called a function declaration.

It tells the compiler:

- **Return type:** `size_t`
- **Function name:** `ft_strlen`
- **Parameter:** `const char *s`

However, this declaration does not contain the actual implementation of the function.

### Declaration vs. Definition

A declaration informs the compiler about a function's interface.

```c
size_t ft_strlen(const char *s);
```

A definition contains the actual implementation.

```c
size_t ft_strlen(const char *s)
{
    /* Implementation goes here */
}
```

The second example is only a structural illustration; it is not a complete implementation.

**Key idea:** A declaration describes the function, while a definition implements it.

---

## 2. Why Do We Need `libft.h`?

Imagine that our project contains three files:

```text
libft/
├── libft.h
├── ft_strlen.c
└── main.c
```

Each file has a different responsibility.

| File | Responsibility |
|---|---|
| `libft.h` | Contains shared function declarations. |
| `ft_strlen.c` | Contains the implementation of `ft_strlen()`. |
| `main.c` | Contains the program that calls `ft_strlen()`. |

Suppose `main.c` wants to use `ft_strlen()`.

Without the appropriate declaration, the compiler may not know the function's interface when processing `main.c`.

We solve this by including the header:

```c
#include "libft.h"
```

Now, the declarations in `libft.h` become available to the source file after preprocessing.

This allows the compiler to check function calls against the declared interface.

### Why Not Put Everything in `main.c`?

A project can contain many functions spread across many source files.

Repeating prototypes in different files makes maintenance harder and can lead to inconsistencies.

A shared header provides a central place for the public declarations of our library.

**Key idea:** The header makes function declarations available to the source files that need them.

---

## 3. What Happens When We Include a Header?

Consider the following code:

```c
#include "libft.h"

int main(void)
{
    size_t len = ft_strlen("hello");
    return (0);
}
```

Before normal compilation, the **preprocessor** handles directives such as `#include`.

Conceptually, it incorporates the contents of `libft.h` into the source being processed, subject to the header's preprocessing directives.

For example, if `libft.h` contains:

```c
size_t ft_strlen(const char *s);
```

The resulting source can be understood conceptually as:

```c
size_t ft_strlen(const char *s);

int main(void)
{
    size_t len = ft_strlen("hello");
    return (0);
}
```

This is a simplified illustration of the result after preprocessing.

The compiler can now see the declaration before encountering the function call.

### Important Distinction

The preprocessor does not search through every `.c` file to retrieve function implementations.

Its role includes processing directives such as:

- `#include`
- `#define`
- `#ifndef`
- `#endif`

The compiler then processes the resulting translation unit.

**Key idea:** Including a header makes its declarations available; it does not automatically compile or link the implementations in other source files.

---

## 4. The Difference Between Compilation and Linking

These are separate stages of building a C program.

### Compilation

Each source file is processed independently.

For example:

```text
main.c       → main.o
ft_strlen.c  → ft_strlen.o
```

The object files contain compiled code and information that the linker can use.

The compiler can process `main.c` using the declaration of `ft_strlen()` without having its implementation inside that same source file.

### Linking

The linker combines the required compiled code and resolves references between object files and libraries.

For example:

```text
main.o + ft_strlen.o → executable
```

If `main.o` refers to `ft_strlen()` but the linker cannot find a suitable definition, linking will generally fail with an error such as:

```text
undefined reference to `ft_strlen'
```

The exact diagnostic depends on the toolchain.

### Comparison

| Concept | Main responsibility |
|---|---|
| Preprocessor | Processes directives and includes header contents. |
| Compiler | Compiles the processed source and checks its correctness. |
| Linker | Resolves references and combines compiled code. |
| Header file | Provides declarations shared by source files. |
| Source file | Contains function definitions and other C code. |
| Object file | Contains compiled code and linking information. |

---

## 5. What Happens If We Remove `#include "libft.h"`?

Suppose `main.c` contains:

```c
int main(void)
{
    size_t len = ft_strlen("hello");
    return (0);
}
```

There are two potential problems:

1. `size_t` must be declared through an appropriate header.
2. `ft_strlen()` has no visible prototype in this translation unit.

With a modern C compiler and strict flags such as `-Wall -Wextra -Werror`, the missing declaration can cause compilation to fail.

This does not necessarily mean that `ft_strlen()` is absent from the project.

The implementation may exist in `ft_strlen.c`, but `main.c` still needs the appropriate declaration to compile correctly.

**Important:** Having an implementation in another source file does not automatically make its declaration visible to every source file.

---

## 6. What If the Prototype Exists but the Definition Is Not Linked?

Consider this situation:

- `libft.h` declares `ft_strlen()`.
- `main.c` includes `libft.h` and calls `ft_strlen()`.
- The compiled implementation of `ft_strlen()` is not included in the linking step.

The source may compile successfully, but the linker generally cannot resolve the reference to `ft_strlen()`.

This produces a **linker error**.

Compare the two situations:

| Situation | Possible result |
|---|---|
| Declaration is missing | Compilation error or diagnostic, depending on the code and compiler. |
| Declaration exists, but definition is unavailable during linking | Linker error, such as an undefined reference. |
| Declaration and definition are both available and linked correctly | The program can be built, assuming there are no other errors. |

The declaration and definition solve different problems.

- The declaration describes the function's interface.
- The definition provides its implementation.
- Linking connects references to the corresponding definitions.

---

## 7. What Is a Translation Unit?

A **translation unit** is the source file after preprocessing, including the contents incorporated through its headers and the effects of preprocessing directives.

For example, `main.c` and `ft_strlen.c` are normally processed as separate translation units.

Each can be compiled independently.

This is part of **separate compilation**, a common approach in C projects.

### Why Is This Useful?

Separate compilation allows us to:

- Organize functions into multiple source files.
- Compile files independently.
- Recompile only the files affected by changes when using a correctly configured build system.
- Reuse compiled code through object files and libraries.

---

## 8. Public Functions and `static` Helper Functions

In C, a function defined with `static` at file scope has **internal linkage**.

For example:

```c
static int helper_function(void)
{
    return (0);
}
```

This function is intended to be used only within its own translation unit.

A public library function, such as `ft_strlen()`, is normally defined without `static` so other files can link against it.

The distinction is useful when designing libraries:

- **Public function:** intended to be accessible to other source files.
- **Static helper:** an implementation detail restricted to one translation unit.

A header should generally expose the public interfaces required by users of the library rather than every internal helper.

---

## 9. Include Guards

An include guard prevents a header's contents from being processed repeatedly within the same translation unit.

A typical structure is:

```c
#ifndef LIBFT_H
# define LIBFT_H

/* Function declarations */

#endif
```

How it works:

1. `#ifndef LIBFT_H` checks whether the macro is already defined.
2. `# define LIBFT_H` defines the macro if it was not already defined.
3. The declarations are processed.
4. `#endif` closes the conditional block.

If the header is included again in the same translation unit, its contents inside the guard are skipped.

Include guards help prevent problems caused by repeated declarations and, especially, repeated definitions of header-level constructs.

---

## 10. Practical Tasks

Complete these tasks before moving on to the next part.

- [ ] Review the required function prototypes in the Libft subject.
- [ ] Create `libft.h` with an include guard.
- [ ] Add the required public function declarations as specified by the subject.
- [ ] Include `libft.h` in the appropriate source files.
- [ ] Identify which source file contains each function definition.
- [ ] Explain the difference between compilation and linking.
- [ ] Build a small test program using one implemented function.
- [ ] Observe the result when a required object file is omitted from linking.
- [ ] Explain why a missing declaration and a missing definition can cause different errors.

Follow the actual Libft subject and your school's rules when deciding which declarations and files are required.

---

## 11. Questions and Answers

### Q1. Why must we read the project subject before implementing functions?

**Answer:**

We need to understand the requirements before coding.

The subject specifies the mandatory functions, their prototypes, their expected behavior, the restrictions, and the submission requirements.

Reading it first helps us avoid implementing the wrong behavior or violating the project rules.

### Q2. What is the difference between a function prototype and its expected behavior?

**Answer:**

A function prototype describes the function's interface, including its name, parameters, and return type.

Expected behavior describes what the function must do and what result it should produce for given inputs.

For example:

```c
size_t ft_strlen(const char *s);
```

This is a prototype. For the input `"hello"`, the expected result is `5`.

### Q3. What is the return type of `ft_strlen()`, and what does it return for `"hello"`?

**Answer:**

The return type is `size_t`, and the expected result is `5`.

The terminating null character `'\0'` is not counted as part of the string length.

### Q4. Why is `libft.h` necessary if `ft_strlen()` is implemented in `ft_strlen.c`?

**Answer:**

The header provides the function declaration to other source files that need to call it.

The implementation in `ft_strlen.c` provides the actual code, but its existence does not automatically make its prototype visible in `main.c`.

The declaration helps the compiler check the function call, while the linker resolves the reference to the compiled definition.

### Q5. Which component processes `#include "libft.h"` first?

**Answer:**

The preprocessor processes the `#include` directive before the normal compilation stage. It incorporates the header's contents into the preprocessed source, subject to its directives.

### Q6. Is the header sufficient to build an executable that uses `ft_strlen()`?

**Answer:**

No. The header provides the declaration, but the implementation must also be available during linking.

The relevant compiled object file or library must be included in the linking process.

### Q7. What is the difference between a compilation error and a linker error?

**Answer:**

A compilation error occurs when the compiler cannot successfully process the source code.

A linker error occurs when the linker cannot resolve a required reference or encounters another problem while combining compiled code.

For example, a missing declaration may cause a compilation diagnostic, while a missing linked definition may cause an undefined-reference error.

### Q8. What is a translation unit?

**Answer:**

A translation unit is a source file after preprocessing, including the material incorporated through its headers.

Each `.c` file is normally compiled as a separate translation unit.

### Q9. Why do we use include guards?

**Answer:**

Include guards prevent the same header contents from being processed repeatedly within a single translation unit.

They help avoid problems caused by repeated inclusion.

### Q10. What is the difference between a public function and a static helper?

**Answer:**

A public function is normally defined without `static` so other source files can link against it.

A function declared `static` at file scope has internal linkage and is intended for use only within its own translation unit.

---

## 12. Final Checkpoint

Before proceeding, make sure you can explain these concepts without memorizing the answers word for word:

- [ ] What a header file does.
- [ ] The difference between a declaration and a definition.
- [ ] How the preprocessor handles `#include`.
- [ ] Why each source file needs access to the declarations it uses.
- [ ] The difference between compilation and linking.
- [ ] Why a missing declaration differs from a missing linked definition.
- [ ] What a translation unit is.
- [ ] Why include guards are useful.
- [ ] The difference between public functions and static helpers.

**Completion criterion:** You can explain how `main.c` uses the declaration in `libft.h`, how `ft_strlen.c` provides the implementation, and how compilation and linking work together to produce an executable.

Next: **Part 3 — Compilation Stages: Preprocessing, Compilation, Assembly, and Linking.**
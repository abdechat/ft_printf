*This project has been created as part of the 42 curriculum by achancha.*

# ft_printf

## Description

The **ft_printf** project consists of recreating the behavior of the standard C library function `printf()`.

The goal is to understand variadic functions in C and learn how to handle different data types using format specifiers.

## Supported Conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal. |
| `%d` | Prints a decimal integer. |
| `%i` | Prints an integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints a lowercase hexadecimal number. |
| `%X` | Prints an uppercase hexadecimal number. |
| `%%` | Prints a percent sign. |

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This generates `libftprintf.a`.

### Cleaning

- `make clean`: Removes object files.
- `make fclean`: Removes object files and the library.
- `make re`: Rebuilds the library.

### Usage

Include the header in your source file:

```c
#include "ft_printf.h"
```

Compile your program using:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
```

## Algorithm Justification

The algorithm iterates through the format string character by character. When it encounters `%`, it identifies the conversion specifier and calls the corresponding helper function. A counter keeps track of the total number of characters printed.

## Data Structure

The project uses `va_list` to handle variable arguments and an integer counter to track the number of characters printed.

## Resources

- `man 3 printf` — printf documentation.
- `man 3 stdarg` — Variadic functions documentation.
- `man 2 write` — write system call documentation.
- [cppreference - Variadic arguments](https://en.cppreference.com/w/c/variadic)
- [GNU C Library - Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)

### AI Usage

AI was used to help understand variadic functions, format specifiers, review code, identify potential errors, and improve project documentation.

The implementation and testing were carried out by the project author.

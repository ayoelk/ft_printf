*This project has been created as part of the 42 curriculum by ayelkadi*

# Description

ft_printf is a project of the 42 common core. The goal is to recode the
`printf()` function from the C standard library, as a static library named
`libftprintf.a`.

The function reproduces the behaviour of the real `printf()` for the
following conversions: `c s p d i u x X %`. It reads a format string, prints
each argument in the right way, and returns the total number of characters
printed, exactly like the original. The buffer management of the real
`printf()` is not reproduced, as asked by the subject.

# Instructions

*Compiling the library*

Run `make` at the root of the repository. It builds `libftprintf.a`, a static
library made from all the `.c` files, compiled with `cc` and the flags
`-Wall -Wextra -Werror`.

*Makefile rules*

- `make` → default rule, same as `make all`
- `make libftprintf.a` → turns each `.c` into an object file, thereturn (count);n archives
  them all into `libftprintf.a` using `ar`
- `make clean` → deletes the `.o` object files but keeps `libftprintf.a`
- `make fclean` → deletes the `.o` files **and** `libftprintf.a`
- `make re` → runs `fclean`, then rebuilds everything from scratch

*Using the library in a program*

Include the header in your code:

    #include "ft_printf.h"

Then link `libftprintf.a` when compiling:

    cc main.c -L. -lftprintf -o my_program

# Algorithm

`ft_printf` reads the format string character by character. A normal character
is written directly to the output. When a `%` is found, the character right
after it is passed to `ft_format`, which acts as a dispatcher: it looks at the
conversion letter and calls the matching helper function with the right
argument type (`va_arg`), then returns how many characters were printed.

Numbers (`d i u x X p`) are printed with recursion: the number is divided by
its base, the function calls itself on the quotient, then prints the last
digit. This naturally prints the digits in the correct order (left to right).

For hexadecimal, a lookup string `"0123456789abcdef"` is used: the remainder
of the division (a value from 0 to 15) is used directly as an index into this
string, which gives the right symbol for both digits and letters in a single
step.

The chosen types matter:
- `%d`/`%i` use a `long` internally, to safely negate `INT_MIN` (which would
  overflow as an `int`).
- `%u`/`%x`/`%X` use `unsigned int` (always positive, full range).
- `%p` uses `unsigned long`, because a memory address is 64 bits and would be
  truncated in an `unsigned int`. It prints the `0x` prefix, or `(nil)` when
  the pointer is `NULL`.

Each helper returns its own count, and `ft_printf` adds them up to return the
total, like the real `printf()`. No complex data structure is used: only the
variadic `va_list` to walk through the arguments, and a constant string as the
base for hexadecimal conversion.

# Resources

*Documentation*

- The `man` pages from the terminal (`man 3 printf`, `man stdarg`), to match
  the exact behaviour of the real function and understand variadic arguments
- The `man` pages for `write` and for the `va_start` / `va_arg` / `va_end`
  macros

*Use of AI*

- AI (Claude) was used to re-explain the concepts needed for this project:
  variadic functions (`va_list`), number bases and hexadecimal, and recursion.
- It was also used to review my code and point out my mistakes through
  questions.
-------------------------------------------------------------
#  README.md
### `_printf` – Custom implementation of the C printf function

-------------------------------------------------------------
## 1. Description

### This project is a custom recreation of the C standard library
function: `printf`.
Our implementation handles formatted output, using variadic functions,
recursion and specific conversion specifiers.
Its purpose is to understand how such a function works internally/

We describe here:
- What the `_printf` function supports.
- What it does not support.
- The internal logic of how the function processes a format string.

-------------------------------------------------------------
## 2. Compilation

To compile all source files:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

-------------------------------------------------------------
## 3. Requirements

- Ubuntu 20.04 LTS
- GCC (GNU Compiler Collection)
- Git / GitHub
- Collaboration workflow with branches (`main`, `Felix`, `Pawnee`)
- Allowed editors: vi, vim, emacs
- No global variables are used
- No more than 5 functions per file
- No use of the `switch` keyword
- Use of variadic functions (`stdarg.h`)
- The code follows the Betty coding style
- Project written in C following the Holberton School style guidelines

-------------------------------------------------------------
## 4. Supported Conversion Specifiers

Our implementation currently supports:

- %c
- %s
- %%
- %d
- %i

-------------------------------------------------------------
## 5. Flags, Field Width and Precision

List of **supported flags**:

- At this step, the function does not support flags. 

List of **unsupported flags**:

- flag characters (+, -, 0, space, #, etc.)
- field width (e.g. %5d) 
- precision (e.g. %.3s)
- length modifiers (h, l, etc.)
Any of these appearing in the format string are not interpreted.

-------------------------------------------------------------
## 6. Examples

Example usages of `_printf`:

```c
_printf("Character: %c\n", 'A');
_printf("String: %s\n", "Hello!");
_printf("Integer: %d, %i\n", 98, -98765);
_printf("Percent sign: %%\n");
```

The return values and the overall behaviour of _printf should match
the standard printf function whenever it is possible.

Expected output:
```bash
Character: A
String: Hello!
Integer: 98, -98765
Percent sign: %
```

-------------------------------------------------------------
## 7. Testing

We test the function by comparing our output with the standard printf:
- Visual comparison of stdout
- Comparison of return value (number of printed chars)
- Edge cases handling
- Memory safety checked with Valgrind

Example:
- `valgrind --leak-check=full ./a.out`

-------------------------------------------------------------
## 8. Flowchart

![Flowchart of _printf](Project_printf.drawio.svg)
```Mermaid
flowchart TD

    %% --- Entry & declarations ---

    A([Start]) --> B["int _printf(const char *format, ...);"]
    B --> C["Declare: index, index_2, found, count = 0, va_list args"]
    C --> D{format == NULL ?}

    D -->|YES| E[/"return (-1)"/]
    D -->|NO| F["va_start(args, format); index = 0"]

    %% --- Main loop on format[index] ---

    F --> G{format[index] == '\0' ?}

    G -->|YES| H["va_end(args)"]
    H --> I[/"return (count)"/]

    G -->|NO| J["found = 0"]

    J --> K{format[index] == '%' ?}

    %% --- Case: normal character (not '%') ---

    K -->|NO| L["_putchar(format[index])"]
    L --> M["count++"]
    M --> N["index++"]
    N --> G

    %% --- Case: '%' found ---

    K -->|YES| O{format[index+1] == '%' ?}

    %% --- Case: '%%' ---

    O -->|YES| P["_putchar('%')"]
    P --> Q["found = 1"]
    Q --> R["count++"]
    R --> S["index++"]
    S --> G

    %% --- Case: '%' + potential specifier ---

    O -->|NO| T["index_2 = 0"]

    T --> U{"format[index+1] == specifier[index_2]<br/>AND found == 0 ?"}
    U -->|YES| V["call _print_to_what for specifier[index_2]"]
    V --> W["count += printed_elements"]
    W --> X["found = 1"]
    X --> AA["index_2++"]
    AA --> U

    %% --- No match yet: reached end of specifier list? ---

    U -->|NO| Y{"specifier[index_2] == '\\0'<br/>AND found == 0 ?"}
    Y -->|NO| AA

    %% --- No specifier matched: invalid sequence after '%' ---

    Y -->|YES| Z{"format[index+1] == '\\0' ?"}
    Z -->|YES| E2[/"return (-1)"/]
    Z -->|NO| L2["_putchar(format[index])"]
    L2 --> M2["count++"]
    M2 --> N2["index++"]
    N2 --> G
```

-------------------------------------------------------------
## 9. Man Page

- A man page is available with the project:
```bash
man ./_printf.3
```

-------------------------------------------------------------
## 10. Authors

- **Pawnee Defize**
  GitHub: https://github.com/Pawnee33
- **Felix Besancon**
  Github: https://github.com/FelixBesancon

-------------------------------------------------------------
## 11. Date

November 2025

-------------------------------------------------------------

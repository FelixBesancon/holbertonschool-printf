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

    %% --- Entry & setup ---
    A([Start]) --> B[_printf(const char *format, ...)]
    B --> C[Declare:<br/>int index, index_2, found<br/>int count = 0<br/>va_list args]
    C --> D{format == NULL ?}
    D -- Yes --> E[[return -1]]
    D -- No --> F[va_start(args, format)<br/>index = 0]

    %% --- Main loop on format string ---
    F --> G{format[index] == '\\0' ?}
    G -- Yes --> H[va_end(args)]
    H --> I[[return count]]

    G -- No --> J[found = 0]
    J --> K{format[index] == '%' ?}

    %% --- Normal character (not a '%') ---
    K -- No --> L[_putchar(format[index])]
    L --> M[count++]
    M --> N[index++]
    N --> G

    %% --- '%' found: check specifier table ---
    K -- Yes --> O[index_2 = 0]

    %% Loop over specifier table
    O --> P{format[index + 1] ==<br/>specifier[index_2].type<br/>&& found == 0 ?}

    %% Matching specifier
    P -- Yes --> Q[Call specifier[index_2].print_format(args)]
    Q --> R[count += number of<br/>printed characters<br/>found = 1]
    R --> S[index++<br/>(skip specifier char)]
    S --> T[index++<br/>(for loop increment)]
    T --> G

    %% No match yet: move to next specifier
    P -- No --> U{specifier[index_2].type == 0<br/>&& found == 0 ?}

    %% Still specifiers left: continue loop
    U -- No --> V[index_2++]
    V --> P

    %% End of specifier table and none matched
    U -- Yes --> W{format[index + 1] == '\\0' ?}

    %% Error: '%' is last character
    W -- Yes --> H1[va_end(args)]
    H1 --> E1[[return -1]]

    %% Print '%' literally if next char exists
    W -- No --> X[_putchar(format[index])]
    X --> Y[count++]
    Y --> N

    %% --- Legend: specifier table content ---
    subgraph Specifier_Table [Specifier table (conceptual)]
        ST1[specifier[0] = 'c' → print_char]
        ST2[specifier[1] = 's' → print_string]
        ST3[specifier[2] = 'd' → print_int]
        ST4[specifier[3] = 'i' → print_int]
        ST5[specifier[4] = '%' → print_percent]
        ST6[specifier[5].type = 0 → end marker]
    end
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

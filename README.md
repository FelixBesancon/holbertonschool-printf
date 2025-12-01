-------------------------------------------------------------
#  README.md
### `_printf` – Custom implementation of the C printf function

-------------------------------------------------------------
## 1. Description

### This project is a custom recreation of the C standard library
function: `printf`.
Our implementation handles formatted output, using variadic functions,
recursion and specific conversion specifiers.
Its purpose is to understand how such a function works internally.

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

Our implementation currently supports the following specifiers.
These conversion specifiers are mapped internally through the 
`get_spec_function` lookup table:

| Specifier | Handler function | Description                                                                                                |
| --------- | ---------------- | ---------------------------------------------------------------------------------------------------------- |
| %c        | print_char       | Prints a single character                                                                                  |
| %s        | print_string     | Prints a null-terminated C string                                                                          |
| %%        | print_percent    | Prints the literal '%' character                                                                           |
| %d        | print_int        | Prints a signed integer (base 10)                                                                          |
| %i        | print_int        | Alias of %d (signed integer)                                                                               |
| %b        | print_binary     | Prints an unsigned int converted to binary                                                                 |
| %u        | print_uint       | Prints an unsigned int (base 10)                                                                           |
| %o        | print_octal      | Prints an unsigned int converted to octal                                                                  |
| %x        | print_hexa       | Prints an unsigned int in lowercase hexadecimal                                                            |
| %X        | print_HEXA       | Prints an unsigned int in UPPERCASE hexadecimal                                                            |
| %S        | print_STRING     | Prints a string; non-printable chars are replaced by their uppercase hexadecimal ASCII code (format: \xNN) |
| %p        | print_pointer    | Prints the memory address of a pointer in hexadecimal                                                      |
| %r        | print_rev        | Prints a reversed string                                                                                   |
| %R        | print_rot13      | Prints a string encoded with the ROT13 cipher                                                              |


-------------------------------------------------------------
## 5. Flags, Field Width and Precision

List of **supported flags**:

- At this step, the function does not support flags. 

List of **unsupported flags**:

- flag characters (+, -, 0, space, #, etc.)
- field width (e.g. %5d) 
- precision (e.g. %.3s)
- length modifiers (h, l, etc.)
Any of these flags, width or precision fields will be printed as
literal characters and will not be interpreted.

-------------------------------------------------------------
## 6. Examples

Example usages of `_printf`:

```c
_printf("Character: %c\n", 'A');
_printf("String: %s\n", "Hello!");
_printf("Integer: %d, %i\n", 98, -98765);
_printf("Percent sign: %%\n");
```

Expected output:
```bash
Character: A
String: Hello!
Integer: 98, -98765
Percent sign: %
```

Examples with additional specifiers provided by this project:
```c
_printf("Binary: %b\n", 17);
_printf("Unsigned: %u\n", 4294967295);
_printf("Octal: %o\n", 255);
_printf("Hex (lower): %x\n", 255);
_printf("Hex (upper): %X\n", 255);

_printf("Special string: %S\n", "Best\nSchool");
_printf("Pointer: %p\n", (void *)&main);
_printf("Reversed: %r\n", "Holberton");
_printf("ROT13: %R\n", "Hello, World!");
```

Expected output:
```
Binary: 10001
Unsigned: 4294967295
Octal: 377
Hex (lower): ff
Hex (upper): FF
Special string: Best\nSchool   (non-printable chars shown as \xNN)
Pointer: 0x7ffe...
Reversed: notrebloH
ROT13: Uryyb, Jbeyq!
```
The exact return value of _printf (number of printed characters) 
should match the standard printf whenever the format string 
and arguments are supported by both functions.

-------------------------------------------------------------
## 7. Testing

We test the function by comparing our output with the standard printf:
- Visual comparison of stdout
- Comparison of return value (number of printed chars)
- Edge cases handling (NULL pointers, unsupported specifiers, '%'
  at end of string, etc.)
- Memory safety checked with Valgrind:
  `valgrind --leak-check=full ./a.out`

Example test pattern:
```c
int a, b;

a = _printf("Let's try to printf a %%!\n");
b = printf("Let's try to printf a %%!\n");
printf("_printf: %d, printf: %d\n\n", a, b);

a = _printf("Text is string: %s\n", "this is a string.");
b = printf("Text is string: %s\n", "this is a string.");
printf("_printf: %d, printf: %d\n\n", a, b);

a = _printf("Signed int: %d, %i\n", 12345, -98765);
b = printf("Signed int: %d, %i\n", 12345, -98765);
printf("_printf: %d, printf: %d\n\n", a, b);
```

-------------------------------------------------------------
## 8. Flowchart

![Flowchart of _printf](holberton-printf.svg)

### a. flowchart of _printf function:
```Mermaid
    %% --- Entry & setup ---
    A([Start]) --> B[Call _printf(format, ...)]
    B --> C[Declare and initialize variables:<br/>index = 0, count = 0,<br/>add = 0, buffer[1024], args,<br/>get_function]
    C --> D{Is format NULL?}
    
    D -- Yes --> E[[return -1<br/>(error, nothing printed)]]
    
    D -- No --> F[Start variadic arguments:<br/>va_start(args, format)]
    
    %% --- Main loop over format string ---
    F --> G{format[index] == '\0'?}
    
    %% End of string: flush and exit successfully
    G -- Yes --> H[Flush buffer to stdout:<br/>write(1, buffer, add)]
    H --> I[End variadic arguments:<br/>va_end(args)]
    I --> J[[return count<br/>(total printed characters)]]
    
    %% Still characters left
    G -- No --> K{Is format[index] == '%' ?}
    
    %% --- Normal character (no '%') ---
    K -- No --> L[Store current char:<br/>print_buffer(format[index], buffer, &add)]
    L --> M[count++<br/>(one more printed char)]
    M --> N[index++<br/>(move to next char)]
    N --> G
    
    %% --- '%' found: handle specifier / error cases ---
    K -- Yes --> O{Is format[index + 1] == '\0'?}
    
    %% Error: '%' is last character in string
    O -- Yes --> P[End variadic arguments:<br/>va_end(args)]
    P --> Q[[return -1<br/>(error: lone '%')]]
    
    %% There is at least one char after '%'
    O -- No --> R[Get conversion function:<br/>get_function = get_spec_function(format[index + 1])]
    
    R --> S{Is get_function != NULL?}
    
    %% --- Valid specifier: call handler ---
    S -- Yes --> T[Call handler:<br/>get_function(args, buffer, &add)]
    T --> U[count += number of characters printed<br/>by the conversion function]
    U --> V[index += 1<br/>(skip specifier char)]
    V --> N
    
    %% --- Unknown specifier: print '%' and spec literally ---
    S -- No --> W[Store '%' in buffer:<br/>print_buffer('%', buffer, &add)]
    W --> X[Store specifier literally:<br/>print_buffer(format[index + 1], buffer, &add)]
    X --> Y[count += 2<br/>(two characters printed)]
    Y --> V
    end
```
### b. flowchart of get_spec_function:
```Mermaid
A([Start get_spec_function]) --> B[Receive specifier character sp]
B --> C[Initialize index = 0]
C --> D[Access specifier table:<br/>array of {type, print_function} pairs<br/>ending with {0, NULL}]
D --> E{print_table[index].type == 0?}

%% End of table, no match
E -- Yes --> F[[return NULL<br/>(no matching function)]]

%% Still entries available
E -- No --> G{sp == print_table[index].type?}

G -- Yes --> H[[return print_table[index].print_format<br/>(matching handler found)]]

G -- No --> I[index++]
I --> D
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

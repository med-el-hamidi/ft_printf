# ft_printf

## Description

`ft_printf` is a custom implementation of the standard `printf` function. It handles various format specifiers and supports additional functionalities as per the 42 Network's project requirements.

## Features

- Supports mandatory format specifiers:
  - `%c` (character)
  - `%s` (string)
  - `%p` (pointer)
  - `%d` and `%i` (integers)
  - `%u` (unsigned integer)
  - `%x` and `%X` (hexadecimal)
  - `%%` (percentage sign)
- Bonus features:
  - Support for `#`, `0`, `-`, ` ` (space), and `+` flags
  - Field width and precision
  - Length modifiers

## Usage

Include `ft_printf.h` in your project and compile it with:

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
```

After making libftprintf.a with:

```sh
make && make clean
```

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/med-el-hamidi/ft_printf/LICENSE.md)

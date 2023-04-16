# [ft_printf](https://github.com/zakelhajoui/ft_printf/blob/main/ft_printf.c)

## ℹ️ About
ft_printf is a custom implementation of the printf() function in C. The function provides similar functionality to the standard printf() function, but with some additional features and improvements.

For detailed information, refer to the [subject of this project](https://github.com/zakelhajoui/ft_printf/blob/main/en.subject.pdf).

## ⚙️ Variadic functions
  Variadic functions are functions that take a variable number of arguments. We typically use variadic function when we don’t know the total number of arguments that will be used for a function. Basically one single function could potentially have n number of arguments.

  ```c 
  int ft_printf(char* format, ...);
  ```
- What is this ellipsis '...'? 
  - It’s a special token which marks the function as variadic, so, int a_function ( int x, ... ); would tell the compiler the function should accept however many arguments that the programmer uses, as long as it is equal to at least one, the one being the first, x

- How do we access the extra arguments passed in the call? 
  - We'll need to use some macros from the ```stdarg.h``` header file to extract the values stored in the variable argument list.
  - To process the variable argument list, four macros are used:
    - `va_list`
    - `va_start()`
    - `va_arg()`
    - `va_end()`
1. **`va_list`** : Create a list of arguments
    - *`va_list`* is used in situations in which we need to access optional parameters and it is an argument list. So, our list will contain some data that will be accessed after we declare our *`va_list`*
    - *`va_list`* is like any other type. It’s effectively a pointer to an arguments in the var-args array. After calling *`va_start`*, argp points at the first var-argument.
3. *`va_start`* is a macro which accepts two arguments, is used to initialize a va_list with the address of the first argument after the fixed arguments.
    ```c
      int ft_printf(char* format, ...)
      {
        va_list argp;
        va_start(argp, format);
        // ...
      }
    ```
2. ```va_arg``` You call it with a va_list and a type, and it takes value pointed at by the ```va_list``` as a value of the given type, then increment the pointer by the size of that pointer. For example, ```va_arg(argp, int)``` will return ```(int) *argp```, and increment the pointer, so ```argp += sizeof int```.
3. At the point that we’ve stopped consuming arguments, we must call ```va_end(argp)``` cleaning up whatever memory was used when the va_end variable was declared.



## 🗒 Notes
- ### Variable Argument Lists
  Some otherwise portable C programs depend on the argument passing scheme, implicitly assuming that all arguments are passed on the stack, and arguments appear in increasing order on the stack. Programs that make these assumptions never have been portable, but they have worked on many implementations. However, they do not work on the AMD64 architecture because some arguments are passed in registers. Portable C programs must use the header file `<stdarg.h>` in order to handle variable argument lists. When a function taking variable-arguments is called, %al must be set to the total number of floating point parameters passed to the function in vector register.<br>
  When __m256 or __m512 is passed as variable-argument, it should always be passed on stack. Only named __m256 and __m512 arguments may be passed in register as specified in section <br>

- ### The Register Save Area : <br>
  The prologue of a function taking a variable argument list and known to call the macro `va_start` is expected to save the argument registers to the *register save area* Each argument register has a fixed offset in the register save area.<br>
  Only registers that might be used to pass arguments need to be saved. Other registers are not accessed and can be used for other purposes.
- ### The `va_list` Type : <br>
  The va_list type is an array containing a single element of one structure containing the necessary information to implement the va_arg macro.
  ```c
  typedef struct {
    unsigned int gp_offset;
    unsigned int fp_offset;
    void *overflow_arg_area;
    void *reg_save_area;
  } va_list[1];
  ```
- ### The `va_start` Macro : <br>
  The va_start macro initializes the structure as follows: <br>

  `reg_save_area` The element points to the start of the register save area. <br>

  `overflow_arg_area` This pointer is used to fetch arguments passed on the stack. It is initialized with the address of the first argument passed on the stack, if any, and then always updated to point to the start of the next argument on
  the stack. <br>

  `gp_offset` The element holds the offset in bytes from reg_save_area to the place where the next available general purpose argument register is saved. <br>

  `fp_offset` The element holds the offset in bytes from reg_save_area to the place where the next available floating point argument register is saved. <br>

- ### The `va_arg` Macro : <br>
  The va_arg macro is usually implemented as a compiler builtin and expanded in simplified forms for each particular type.

## 📌 Useful Links
- [c-varargs](https://jameshfisher.com/2016/11/23/c-varargs/)
- [Variable Argument Lists in C using va_list](https://www.cprogramming.com/tutorial/c/lesson17.html)
- [C Variadic Function](https://www.thegeekstuff.com/2017/05/c-variadic-functions/)
- [Variable Argument Lists](https://c-for-dummies.com/blog/?p=3398)
- [System V Application Binary Interface (PDF)](https://github.com/zakelhajoui/ft_printf/blob/main/x86-64-psABI-1.0.pdf)
- [Secrets of “printf” (PDF)](https://quizgen.doncolton.com/tut/q11.printf.p6.pdf)
- [printf](https://cplusplus.com/reference/cstdio/printf/)

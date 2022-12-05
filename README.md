# [ft_printf](https://github.com/zakelhajoui/ft_printf/blob/main/ft_printf.c)

## 🗣️ About
>_Because ft_putnbr() and ft_putstr() aren’t enough, the goal of this project is to recode the printf function. You will mainly learn about using a variable number of arguments._

For detailed information, refer to the [subject of this project](https://github.com/zakelhajoui/ft_printf/blob/main/en.subject.pdf).

## 🗒 Notes
Variadic functions are functions that take a variable number of arguments.
```c 
int ft_printf(char* format, ...);
```
- What is this ellipsis '...'? 
  - It’s a special token which marks the function as variadic, so, int a_function ( int x, ... ); would tell the compiler the function should accept however many arguments that the programmer uses, as long as it is equal to at least one, the one being the first, x

- How do we access the extra arguments passed in the call? 
  - We'll need to use some macros (which work much like functions, and you can treat them as such) from the ```stdarg.h``` header file to extract the values stored in the variable argument list--`va_start`, which initializes the list, `va_arg`, which returns the next argument in the list, and `va_end`, which cleans up the variable argument list.
1. `va_start` is a macro which accepts two arguments, a va_list and the name of the variable that directly precedes the ellipsis ("..."). So in the function a_function, to initialize a_list with va_start, you would write va_start ( a_list, x );
```c
int ft_printf(char* format, ...)
{
  va_list argp;
  va_start(argp, format);
  // ...
}
```
  - What is this `va_list`? 
    - To use these functions, we need a variable capable of storing a variable-length argument list--this variable will be of type va_list.
    - `va_list` is like any other type. It’s effectively a pointer to an arguments in the var-args array. After calling ```va_start```, argp points at the first var-argument.
2. ```va_arg``` You call it with a va_list and a type, and it takes value pointed at by the ```va_list``` as a value of the given type, then increment the pointer by the size of that pointer. For example, ```va_arg(argp, int)``` will return ```(int) *argp```, and increment the pointer, so ```argp += sizeof int```.
3. At the point that we’ve stopped consuming arguments, we must call ```va_end(argp)```.

## 📌 Useful Links
- [c-varargs](https://jameshfisher.com/2016/11/23/c-varargs/)

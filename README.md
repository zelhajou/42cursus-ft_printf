# [ft_printf](https://github.com/zakelhajoui/ft_printf/blob/main/ft_printf.c)

## 🗣️ About
>_Because ft_putnbr() and ft_putstr() aren’t enough, the goal of this project is to recode the printf function. You will mainly learn about using a variable number of arguments._

For detailed information, refer to the [subject of this project](https://github.com/zakelhajoui/ft_printf/blob/main/en.subject.pdf).

## 🗒 Notes
Variadic functions are functions that take a variable number of arguments.
```c 
int ft_printf(char* format, ...);
```
- What is this ...? 
  - It’s a special token which marks the function as variadic, meaning that call sites can pass an arbitrary list of values following the named parameters.
- How do we access the extra arguments passed in the call?
  - With three “special macros” in ```stdarg.h```. 
1. ``` va_start ``` (read: variable-arguments start):
```c
int ft_printf(char* format, ...)
{
  va_list argp;
  va_start(argp, format);
  // ...
}
```
  - What is this ```va_list```? It’s effectively a pointer to an arguments in the var-args array. After calling ```va_start```, argp points at the first var-argument.
2. ```va_arg``` You call it with a va_list and a type, and it takes value pointed at by the ```va_list``` as a value of the given type, then increment the pointer by the size of that pointer. For example, ```va_arg(argp, int)``` will return ```(int) *argp```, and increment the pointer, so ```argp += sizeof int```.
3. At the point that we’ve stopped consuming arguments, we must call ```va_end(argp)```.

## 📌 Useful Links
- [c-varargs](https://jameshfisher.com/2016/11/23/c-varargs/)

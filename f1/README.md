# Ex 2
## b)
The variable `a` is a integer array with 10 elements. Therefore, `sizeof` returns the total amount of memory used by the array: _#elements_*_size of each element (type)_.
It's important to be aware that an array variable has an implicit convertion to pointer type, and on some circunstances you might be expecting the full array size but you get the pointer size.
```C
int main() {
    ...
    int values[10];
    ...
    example(values);
    ...
}

void example(int a[]) {
    // The function doesn't get a copy of the array, it receives a pointer to the first element of the array. 
    // Hence, a is just a pointer on this function scope
    printf("%d", sizeof(a)); // Outputs 4 or 8 bytes (pointer size)
}
```

Regarding the struct, the `sizeof` function returns the total memory reserved for the struct, which in theory should match the size used by the variables within the struct. On the example, the struct has two `double` type variables, therefore the returned size by `sizeof` is 16, because each `double` takes 8 bytes. 
There are some cases where the return of `sizeof` won't be what you are expecting, due compiler optimizations.
```C
struct {
    char c;
    double re;
} a1;
struct {
    double re;
    char c;
    char a;
} a2;
```
`sizeof(a1)` and `sizeof(a2)` return 16 bytes. This is due *data alignment*, that consists of putting data at a memory offset multiple of the word size, increasing memory access performance because of the way CPU handles memory. The word size usually refers to CPU registers size. Therefore, a word on 32-bit CPU means 4 bytes, and on 64-bit CPU means 8 bytes. 
Depending on the C standard, compiler and compiler flags, the results may vary. You can, on some compilers, disable data alignment. On that case, `sizeof(a1)` and `sizeof(a2)` would return 9 and 10 bytes respectively. [Learn more]('https://wr.informatik.uni-hamburg.de/_media/teaching/wintersemester_2013_2014/epc-14-haase-svenhendrik-alignmentinc-paper.pdf')

Finally, the `sizeof` of `hello`. The variable was declared as a char pointer, therefore the returned size is either 4 or 8 bytes. If you declared the string as `char[] = "Hello, World!"` the returned size would be 14 bytes (don't forget counting the null-terminator `\0`).

## c)
On both cases, the sizeof is getting an element of the array. `a` is an array of integers, so any element uses 4 bytes. `hello` is a pointer to an array of chars (C-string), `*hello` is accessing the first character, therefore `sizeof` returns 1 byte.

# Ex 4
`atoi` and `strtol` try to achieve the same thing: converting a number represented as string to an int/long data type.

The difference is how they handle strings that not represent a number at all.

## atoi
If you give a string which the initial portion is a number, atoi returns that number.
`atoi("123sdafeger") => 123`
However, if the string doesn't have a number at all, it returns 0.
`atoi("asfsfsf") => 0.` and `atoi("0") => 0`. So, how you distinguish? You don't ¯\\_(ツ)_/¯. Unless, you do some extra verification. Oh,what about a number between alfa-characters? Also returns zero.
## strtol
`strtol` is fancier. Well, it also returns zero if things go wrong... but there's an extra parameter, `char **endptr`, that stores the address of the first invalid character. If you do some comparations here and there you can know if the input is invalid or not. Moreover, you can reach digits between characters with succesive calls, using the `endptr`. And finally, `strtol` supports errors. You can detect overflows, underflows and if there's no coversion at all (not working for me, ¯\\_(ツ)_/¯, but it's mentiond on the standard documentation. There's a note saying this is not valid on C99, but doesn't say anything about more recent standards).
>  The implementation may also set errno to EINVAL in case no conversion was performed (no  digits  seen,  and  0 returned).

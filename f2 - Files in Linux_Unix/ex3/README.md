# Memory alignment

To simplify the problem, I am writing the binary file using the struct `test_t`. However, that can be dangerous if the file is meant to be shared. This is, depending on the architecture where the program is compiled, the compiler will most likely perform memory alignments on the structure. The result is that the same structure `test_t` can have different sizes on different operating systems and computers, and the members of the structure might be at different locations than expected. A solution is to use compiler flags such `__attribute__((packed))` for **GCC**.

Another possible approach is to perform individual `write` and `read` statements for each structure member, thus ensuring that:
- The first 30 bytes are a name
- The following 4 bytes are the first grade
- The next 4 bytes are the second grade
- More 4 bytes for the third and last grade

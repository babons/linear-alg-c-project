# Linear Algebra C Tool

This is an interactive command-line tool for experimenting with linear algebra in 3D, written entirely in C. It serves both as a study aid for *Essence of Linear Algebra* by 3Blue1Brown and as a systems-level learning project.

## Operations Supported

- [x] Create and store vectors and matrices
- [x] Vector addition
- [x] Scalar multiplication (vectors & matrices)
- [x] Dot product
- [x] Cross product (3D only)
- [x] Matrix-vector multiplication
- [x] Matrix-matrix multiplication
- [x] Determinant (3x3)
- [x] Cofactor matrix
- [x] Matrix transpose
- [x] Matrix inverse (via adjugate method)
- [x] Eigenvalue calculation (2x2)
- [x] View and delete vector/matrix history

## C Techniques and Concepts Used

- **Manual memory allocation** via a fixed-size buffer (`mem.c`)
- **Tagged type allocator**: All memory is drawn from a fixed-size buffer using a custom `alloc(size, type)` function. Types (vector or matrix) are tracked via an `enum EntryType` and stored in a history array, allowing precise undo/delete functionality without dynamic memory management or malloc/free.
- **History tracking** for vectors and matrices (no dynamic memory)
- **Modular structure** with `main`, `ops`, `lin_math`, `io`, and `mem` modules
- **Custom matrix and vector types** using `struct`
- **Pointer management** and error checking on buffer limits
- **Command-based user interface** with numeric input control

## Build Instructions

```bash
gcc *.c -o lin_tool -lm
./lin_tool
```

## Notes

- The tool operates entirely in 3D (vectors with 3 components, 3×3 matrices).
- All input is manual via terminal.

- Intended for educational use — emphasizes understanding over performance.


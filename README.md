### Right, an actual description of what I am doing
This repo is for notes and projects I have taken/made while learning linear alg.

Edit: I am going through the course below, but I am also learning the "technical" side not covered within the course below. It is an excellent course, and he intentionally strays away from some computing, so I would like to fill in the blank.

I am going through the online course "Essence of linear algebra" by 3blue1brown here: https://youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab&si=0ELJJx5L6hInWr1Y
This is also serving as an extension of my C learning journey.
I am building an interactive linear alg calculator of sorts. It is proving to be very *fun*.
Anyway, hope the notes are useful and that this code is helpful. Please reach out if the code sucks.


### SECTION 1 - Essence of linear algebra

Vector - building block of linear alg
	Three ideas
	Physics student -> arrows pointing in space; length and direction
	CS student -> Ordered lists of numbers; house prices, pairing sq ft and price [sq, $]
	Math student -> Generalizes these; anything where there is a notion of adding a vector and multiplying a vector

	New ideas with vectors, think like this
		Think about an arrow inside of a coord system, with tail at origin
		Translate it to a list of numbers, considering coordinates of vector

	Vectors are written in the square bracket [x, y] whereas points are (x, y)
		Each pair only gives one vector, and each vector one pair

	Vector addition
		[3, -5] + [2, 1] = [3 + 2, -5 + 1]
		When adding two vectors, take the second and move the tail to tip of the 1st
		New vector from A.tail to B.tip is the result
		[3, -5] + [2, 1]
			Step 3 to the right, move down 5. Step 2 to the right, and up 1
	Vector multiplication
		Multiplying a vector by a number just stretches it out in that multiple
		Negatives flip it and then stretch it
		Scaling
		This is scalar
		Multiplying a vector by 2 multiplies each component by 2.

### SECTION 2 - Linear combinations, span, and basis vectors
Two special vectors
	right with length 1, i-hat
	up with length 1, j-hat
	[3, -2]
		3 scales i-hat
		-2 scales j-hat
		Sum of two scaled vectors
	"basis vectors" of xy coord system
	think about scaling with different basis vectors...
Scaling and adding two vectors is considered a linear combination of two vectors
	a(v) + b(w); a and b are scalars
The span is the set of all possible linear combinations of two basis vectors.
	Most basis vectors can span all vectors of 2D space (if 2D) except for
		Line up
		Origin
Linear algebra revolves around these concepts

3D vector span
	Collection of all possible linear combinations of the two vectors
	Think of the span of two 3D vectors as a sheet -- while they -- eurika moment
	2 vector linear combo in 3d creates a 2d plane

	3 vector linear combos in 3d spans the 3d plane
		if third vector is on the span of the first two, spane doesnt change
		third vector "moves the sheet through space"

If the third vector is on the span of the first two, or two vectors line up, there is redundancy. At least one vector is. When you can remove one without reducing span, they are linearly dependent. One vector can be seen as a linear combination of the others.
If the third, fourth, fifth, whatever vector adds to the span, it is linearly independent

### SECTION 3 - Linear transformations and matrices
"Unfortunately, no one can be told what the Matrix is. You have to see it for yourself" - Morpheus

Linear transformation
	Transformation is a fancy word for function
		Input vector, output vector
		Suggest you think in terms of movement
	Linear
		Is linear if
			Lines remain lines
			The origin remains fixed in place
		Keeps grid lines parallel and evenly spaced
		
Describing trnasformations numerically
	Need to record where base vectors lie
		v = [-1, 2] = -1i + 2j
		Transformed v = -1(Transformed i) + 2(Transformed j)
	Allows you to know where v is with knowing where i-hat and j-hat are
		Transformed i = [1, -2]; transformed j = [3, 0]
		Transformed v = -1[1, -2] + 2[3, 0]
		Transformed v = [-1, 2] + [6, 0] = [5, 2]
Linear transformations are described by four numbers:
	Two coordinates for where i-hat lands [3, -2]
	Two cooredinates for where j-hat lands [2, 1]
	[3, -2 | 2, 1]
	Vector [5, 7]
		5[3, -2] + 7[2, 1]

	Can be defined as matrix-vector multiplication
		[3, -2 | 2, 1] * [3, 5] = 3[3, -2] + 5[2, 1] = [19, -1]

Fun example
	If all of space is rotated by 90 degrees
		i-hat becomes [0, 1]
		j-hate becomes [-1, 0]
		If we had a vector, [x, y]
		We can apply the transformed i-hat and j-hat
		[0, 1 | -1, 0] [x, y] = [0, x] + [-y, 0] = [-y, x]
		
Shear example
	i-hat = [1, 0] j-hat = [1, 1]

Other way around
	Start with matrix [1, 2 | 3, 1]
	Vector [2, 3] = [11, 8]

### SECTION 4 – Matrix Multiplication as Composition

Matrix multiplication represents **chaining transformations**.  
If you apply `M1` then `M2`, the overall effect is the same as applying the single matrix `M2 * M1`.

Think of it like function composition:
- `f(g(x))` = do `g` first, then `f`
- In matrix form: `M2(M1(v)) = (M2 * M1) * v`

Matrix multiplication is **associative** but not **commutative**:
- `(M3 * M2) * M1 = M3 * (M2 * M1)`
- But `M1 * M2 ≠ M2 * M1`

Each column of the composed matrix shows where the **transformed basis vectors** land after applying the full sequence.

### SECTION 5 – 3D Linear Transformations

Linear transformations in 3D follow the same rules:
- Each vector transformed by a matrix is a linear combination of its **columns** (i-hat, j-hat, k-hat)

If you apply a 3×3 matrix to a vector `[x, y, z]`, it gives:
```
x·(î transformed) + y·(ĵ transformed) + z·(k̂ transformed)
```

Each transformation:
- Can rotate, scale, shear, or reflect space in 3D
- Changes the basis of space itself
- Still preserves linearity (lines stay lines, origin stays fixed)

### SECTION 6 – The Determinant

The **determinant** of a matrix measures how a transformation **scales space**:

- **2D:** it gives the **area scaling factor**
- **3D:** it gives the **volume scaling factor**

Important interpretations:
- `det = 0`: Transformation **collapses space** (e.g. to a line or point); not invertible
- `det < 0`: Transformation **flips** orientation (reflection)
- `det > 0`: Orientation is **preserved**

For 2×2 matrices:
```
|a  b|
|c  d| → det = ad - bc
```

The determinant gives deep insight into the **effect of a matrix on space** — especially when composing transformations.

### Section 7 - Inverse matricies, column space, and null space
-- Gaussian Elimination and Row Echelon Form are not covered. Will do a seperate section on those after.
Linear system of equations -- totally haven't seen this before. But wait, it's neat.
3x + 1y + 4z = 1
5x + 9y + 2z = 6
5x + 3y + 5z = 8

    A	   x   v
[ 3 1 4 ] [x] [1]
[ 5 9 2 ] [y] [6]
[ 5 3 5 ] [z] [8]

AX = v
A - Matrix
X - Vector
v - Output / Transformed Vector

To solve, consider a couple things
Does the answer lower a dimension (i.e. 2D transforming into squashed line)

Playing the transformation in reverse helps us when looking for the answer

Inverse of A denoted by

A^-1

Result of (A^-1)*(A) = [], or, the identity transformation. Columns are 1,0 and 0,1

AX = v
(A^-1)*A*X = (A^-1)v

When the determinant is 0, there is no inverse, in the function sense.

When the output of a transformation is a line, the transformation has a rank of one.

If vectors land on a 2D plane, then it is Rank 2.

Rank is the number of dimensions in an output.

All possible outputs of Av = column space of A.

Span of base columns = column space

Rank is the number of dimensions in the column space.
When rank equals the number of columns in the column space, the matrix is Full Rank.

When a 3D transformation squishes all of space into a line, there is an entire plane which lands on the origin.

Set of vectors which land on the origin are considered "Null Space" or the "Kernel" of the matrix

Ax = v
When v is the "zero vector" i.e. [0,0], null space gives all possible solutions.

Column space lets us know when a solution exists, null space helps us understand what the set of all possible solutions look like.

### Row Echelon Form notes
I learned this at some point in my academic career, definitely not for this context, though.

Row Echelon Form (REF)

If a matrix is in REF there are a set of properties:
Zero Rows at the buttom - If any rows are all zeros, they should be at the bottom

Leading 1s - First entry of a non-zero row (leading entry) can be any non-zero numner

Staggered Leading 1s - Leading entry in a row must be to the right of the leading entry in the row above it.


Reduced Row Echelon Form (RREF)
- Zero Rows at the bottom - Any rows with all zeros must be at the bottom
- Leading entries - First non-zero must be 1
- Staggered Leading Entries - Leading 1 in each row must be to the right of the leading 1
- Column of Leading 1s - Each leading 1 is the only non-zero entry.

### Guassian Elimination
Row reduction algorithm for solving linear systems
Operations on the augmented matrix (coefficients and constants) to simplify it into REF/RREF
Obj are to help determine rank, determinant, and the inverse of matrices.

Back to this matrix for a system of linear equations.
[a1, b1, c1 | d1]
[a2, b2, c2 | d2]
[a3, b3, c3 | d3]

Goal is to make it
[0, a, b | d]
[0, 1, c | e]
[0, 0, 1 | f]

High level steps:
	Swap two rows
	Multiply a row by a scalar
	Adding a scalar multiple of one row to another

Example
1. 3x + 2y = 4
2. x + 4y = 8

[3, 2 | 4]
[1, 4 | 8]

1/3r1 = [1, 2/3 | 4/3]

2r = [1, 4 | 8] - [1, 2/3, | 4/3] = [0, 10/3, 20/3]

2r/(3/10) = [0, 1, 2]

[1, 2/3 | 4/3]
[0, 1   | 2]

r1 = x + 2/3*2 = 4/3; x=0
r2 = 0x + y = 2; y = 2;

3x3 example:
1. x + y + z = 6
2. 2x + 3y + z = 14
3. z + 2y + 3z = 14

[1, 1, 1 | 6]
[2, 3, 1 | 14]
[1, 2, 3 | 14]

r1 = [1, 1, 1 | 6]
r2 = [0, 1, -1 | 2]
r3 = [0, 0, 3 | 6]

z = 2
y = 4
x = 0

### Section 8 -- Nonsquare matrices as transformations between dimensions
Square matrices (2x2, 3x3) transforms their respective dimension to the other

Non-square matrices (2x3(m), 3x2(n)) changes the rank (n -> m)
Number of columns is the input dimension
Number of rows is the output dimension
Cannot be inverted traditionally

Ex.
3x2
[1 0]
[0 1]
[0 0]

R2 -> R3
Creates a 2D plane through 3D space.

Ex.
2x3
[1 0 0]
[0 1 0]
Maps R3->R2
"Projects" 3D vectors onto the 2D plane.

Non-square matrices squash or embed space.
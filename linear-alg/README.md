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

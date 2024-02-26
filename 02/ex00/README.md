Orthodox Canonical Form

- Default constructor

- Copy constructor
	Receiving a reference to an object of the same class type as a factor and initialize itself with that reference.\
	If it's not defined, a default constructor will be created.
	The default constructor does "Shallow copy" that is copying the address of the reference.\
	Copy constructor copies the contents of the origianal object and create a new object. It's "Deep copy".

- Copy assignment operator
	Overloading the assignment operator.
	Redefining the default operator(=).
	Because the default operator does "Shallow copy".
	Only when both objects are created and initialized and the corresponding type of object is entered to the right.

- Destructor

	- Shallow Copy
		The copied object's instance variable is referencing the memory of the original object's instance variable.
	- Deep Copy
		Copying the object and instance variables. 
		When dynamic allocation is made within the creator, "delete" will be executed repeatly during destroying the object. Then the memory pointer will be lost and it occurs memory leak.
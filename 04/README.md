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


Polymorphism
	Polymorphism means "many forms", and it occurs when we have many classes that are related to each other by inheritance.
	- Inheritance
		Inherit attributes and methods from another class.
	- Polymorphism
		Polymorphism uses those methods to perform different tasks. This allows us to perform a single action in different ways.

Pure Virtual Functions and Abstract Class
	Sometimes implementation of all functions cannot be provided in a base class because we don’t know the implementation. Such a class is called an abstract class.
	An Animal class doesn’t have the implementation of move() (assuming that all animals move), but all animals must know how to move. We cannot create objects of abstract classes.
	A pure virtual function (or abstract function) in C++ is a virtual function for which we can have an implementation, But we must override that function in the derived class, otherwise, the derived class will also become an abstract class. A pure virtual function is declared by assigning 0 in the declaration.
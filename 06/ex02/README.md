dynamic_cast

- dynamic_cast
	Dynamic_cast is mainly used for downcasting, in which a pointer to a parent is changed to point to a child. If the parent class is an abstract class with a virtual function, downcasting is possible because the child's address is stored separately.

	However, if the child's constructor is not called (if the parent class pointer is called to the parent class constructor), dynamic casting is impossible because there is no address to refer to. If it is not an abstract class, static_cast rather than dynamic_cast should be used. (However, safety is not guaranteed in this case.)

	If dynamic_cast fails, it returns NULL if it is a pointer, but if it is a reference (because it cannot use NULL), an exception occurs.

	dynamic_cast provides RTTI(Run Time Type Information). RTTI identifies if the class is in the correct type form depending on the type_info of the class at runtime.

	* One condition to use dynamic_cast *
	: Using virtual function.
	Because of RTTI type_info.
	If a virtual function is used, a v-table will be created on a class.
	this v-table has an address that is able to point an overrided child class's function and it has the type_info of the class. Therefore, with using dynamic_cast, type casting can be happened in safer way. 
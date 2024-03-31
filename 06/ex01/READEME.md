Serialization

- reinterpret_cast
	Reinterpret_cast is a casting mainly used in pointers, and is responsible for pointer→pointer, variable→pointer, and pointer→ variable.

- Serialization
	When sending information in the network, it should be sent streamed, it can only be sent in the basic data type. (unintptr_t) Therefore, in order to send information on objects or pointers in the structure or class in use, the information must be converted into a basic data type, which is called serialization.

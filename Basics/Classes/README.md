The fundamental ideas behind `classes` are `data abstraction` and `encapsulation`. Data abstraction is a programming (and design) technique that relies on the separation of `interface` and `implementation`.

The interface of a class consists of the operations that users of the class can execute. The implementation includes the class’ data members, the bodies of the functions that constitute the interface, and any functions needed to define the class that are not intended for general use.

Encapsulation enforces the separation of a class’ interface and implementation. A class that is encapsulated hides its implementation—users of the class can use the interface but have no access to the implementation.

# Defining Abstract Data Type

A class that uses data abstraction and encapsulation defines an `abstract data type`.

To make Sales_data an abstract type, we need to define operations for users
of Sales_data to use. Once Sales_data defines its own operations, we can
encapsulate (that is, hide) its data members.

The functions that do addition and IO will not be members of `Sales_data`. Instead, we’ll define those functions as ordinary functions. The
function that handles compound assignment will be a member. Our class doesn’t need to define assignment.

Thus, the interface to `Sales_data` consists of the following operations:
• An `isbn` member function to return the object’s ISBN
• A `combine` member function to add one `Sales_data` object into another
• A function named `add` to add two `Sales_data` objects
• A read function to read data from an istream into a Sales_data object
• A print function to print the value of a Sales_data object on an ostream

# this

`this` is a hidden pointer inside all non-static member functions.
It points to the object the function was called on.
It's how a member function knows which object’s data to access.
Because this is intended to always refer to “this” object, this is a const
pointer. We cannot change the address that this holds.

# Introducing const Member Functions



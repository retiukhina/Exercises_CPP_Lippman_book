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

`this` is a hidden pointer inside all non-static member functions. It points to the object the function was called on.
It's how a member function knows which object’s data to access. Because this is intended to always refer to “this” object, this is a const pointer. We cannot change the address that this holds.

If you have:

class Sales_data {
public:
    void print();
};

Then inside print(), you can imagine:

void print(Sales_data* this);

(You don’t write this — the compiler handles it.)

2. What does Sales_data *const mean?


    Sales_data* → pointer to a Sales_data object
    const (after the *) → the pointer itself cannot be changed

So:

Sales_data *const this;
means:

    "this is a pointer that cannot point to a different object, but the object it points to can be changed."

regular member function:	Sales_data *const this	-> pointer can't change, object can
const member function:	const Sales_data *const this ->	pointer can't change, object can't either

# Introducing const Member Functions

`std::string isbn() const { return bookNo; }`

    Function definition:

        isbn() is a member function of class Sales_data. It returns a std::string, which is the book number (bookNo).

    What does const mean after the function?

        The const after the parameter list tells the compiler:
        "This function does not modify the object it is called on."

    How does this work internally?

        In a non-const member function, the this pointer is of type:

ClassName* const this;

This means:

    The pointer itself (this) is constant (you can't reassign it).
    But the object it points to is not const, so the function can modify the object.

When you declare a function like isbn() const, it changes the type of this to:

    const ClassName* const this;

    So:

        The pointer is still constant.
        But now it points to a const object.
        Therefore, you cannot modify any member variables inside this function (unless they are marked mutable).

Why is this useful?

    It allows you to call isbn() on const objects:

        const Sales_data sd;
        std::string s = sd.isbn();  // This is allowed because isbn() is a const member function

        If isbn() were not marked const, this call would result in a compiler error, because a non-const method cannot be called on a const object.

Summary:

Adding const after a member function ensures:

    The function doesn't (and can't) modify the object.
    It can be safely called on const instances of the class.

# Class Scope and Member Functions

 How C++ processes a class

C++ compiles a class in two phases:
🔹 Step 1: Process member declarations (signatures)

C++ reads the entire list of member names and types — it builds a "map" of what's inside the class.

So it already knows:

    There is a member variable bookNo of type std::string
    There is a member function isbn() returning std::string

It doesn't care about the order of these declarations at this point.
🔹 Step 2: Compile function bodies

Now C++ starts reading the code inside the functions like isbn().

When it sees return bookNo;, it says:

    “Ah, I know what bookNo is — it's a member variable of this class.”

So it’s valid, even if bookNo was declared later in the class definition.
🧠 Summary

    A class is its own scope, so members can refer to each other.
    C++ processes class declarations before it looks at function bodies.
    Because of that, member functions can use any member of the class, regardless of order.

# Defining a Member Function outside the Class

✅ Key Rule #1: Definition must match declaration

If you declared a function inside the class like this:

class Sales_data {
public:
    double avg_price() const;  // declaration
};

Then when you define it outside the class:

double Sales_data::avg_price() const {
    // body
}

It must match the declaration:

    Same return type → double
    Same name → avg_price
    Same parameters → here, none
    If it was const in the class declaration, it must also be const in the definition

✅ Key Rule #2: Use the scope resolution operator ::

double Sales_data::avg_price() const {
    // ...
}

This line says:

    “I'm defining the avg_price function from the class Sales_data.”

That’s what Sales_data::avg_price means — it "reconnects" the definition to the class it belongs to.

✅ Key Rule #3: The body is interpreted in class scope

Once the compiler sees:

double Sales_data::avg_price() const

…it knows you’re inside Sales_data. So it lets you refer to member variables like revenue or units_sold directly — without writing this->revenue.

# Constructor 

A constructor is a special member function in a class that is automatically called when you create an object of that class.

Its main job is to initialize the data members (variables inside the object).
📌 Key Points:

    It has the same name as the class.
    It has no return type (not even void).
    You can define multiple constructors with different parameters (called constructor overloading).
    If you don’t write any constructor, C++ provides a default constructor for you.
    Constructors have the same name as the class.
    Unlike other functions, constructors have no return type. Like other functions, constructors have a (possibly
    empty) parameter list and a (possibly empty) function body. 
    A class can have multiple constructors. Like any other overloaded function, the constructors must differ from each other in the number or types of their parameters.
    Unlike other member functions, constructors may not be declared as const. When we create a const object of a class type, the object does not assume its “constness” until after the constructor completes the object’s initialization. Thus, constructors can write to const objects during their construction.


# Access Control and Encapsulation

In C++ we use access specifiers to enforce encapsulation:

• Members defined after a public specifier are accessible to all part of the program. The public members define the interface to the class.

• Members defined after a private specifier are accessible only to the member functions of the same class. 
Code outside the class cannot access it directly. The private sections encapsulate (i.e., hide) the implementation.


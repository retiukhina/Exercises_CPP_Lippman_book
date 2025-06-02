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

   • It has the same name as the class.
   • It has no return type (not even void).
   • You can define multiple constructors with different parameters (called constructor overloading).
   • If you don’t write any constructor, C++ provides a default constructor for you.
   • Constructors have the same name as the class.
   • Unlike other functions, constructors have no return type.
   • Like other functions, constructors have a (possibly empty) parameter list and a (possibly empty) function body.
   • A class can have multiple constructors. Like any other overloaded function, the constructors must differ from each other in the number or types of their parameters.
   • Unlike other member functions, constructors may not be declared as const. When we create a const object of a class type, the object does not assume its “constness” until after the constructor completes the object’s initialization. Thus, constructors can write to const objects during their construction.

   We often define several constructors — that is, several ways to create an object — to make the class flexible, easy to use, and suitable for different situations.

✅ Use cases for each constructor

1. `Sales_data()`
Use when you want an empty/default object:

`Sales_data d;`  // All values start at zero/default

2. `Sales_data(const std::string &s)`
Use when you only know the book’s ISBN, but not sales data yet:

`Sales_data d("ISBN123");`

3. `Sales_data(const std::string &s, unsigned n, double p)`
Use when you want to create an object with full sales info:

`Sales_data d("ISBN123", 10, 12.99);`  // 10 books sold at $12.99

4. `Sales_data(std::istream &)`
Use when you want to read data from the user or a file:

`Sales_data d(std::cin);`  // Reads ISBN, quantity, and price

## Default constructor

A default constructor is automatically called in various situations when no explicit initialization is provided. This helps ensure all members are properly initialized even if the programmer doesn’t manually specify values.
Default initialization happens when:

1. When we define nonstatic variables or arrays at block scope without initializers.

`int main() {`
    `MyClass a;`       // ✅ default constructor is automatically called
    `MyClass arr[3];`  // ✅ default constructor is called for each element
`}`

No initializer is given, so the compiler calls the default constructor automatically.

2. Synthesized Default Constructor in a Class with Member Objects

class Engine {
public:
    Engine() { std::cout << "Engine default constructor\n"; }
};

class Car {
    Engine e;  // class-type member
};

int main() {
    Car c;  // ✅ default constructor of `Car` calls default constructor of `Engine`
}

3. Members Not Explicitly Initialized in Constructor Initializer List

class Engine {
public:
    Engine() { std::cout << "Engine default constructor\n"; }
};

class Car {
    Engine e;
public:
    Car() { std::cout << "Car constructor body\n"; }  // e is default-initialized
};

int main() {
    Car c;
}

The constructor body does not initialize e. So e is default-initialized using its class's default constructor. If a member like Engine does not have a default constructor, the compiler will give an error unless you explicitly initialize it in the initializer list.

Value initialization is a type of initialization in C++ that ensures an object is initialized to a "zero" or default value in a way that depends on the type. For built-in types (like int, double), value initialization means they get zeroed (e.g., 0 for int, 0.0 for double).For class types, value initialization means the default constructor is called (if any).

Value initialization happens when:
1. During array initialization when fewer initializers than the array size are provided: `int arr[5] = {1, 2};` Here, the first two elements are initialized to 1 and 2. The remaining elements (arr[2], arr[3], arr[4]) are value initialized, so they become 0.
2. When defining a local static object without an initializer
`static int x;  // x is value-initialized to 0`
3. When you explicitly request value initialization with T()
`int x = int();`            // x is zero-initialized to 0
`std::vector<int> v(10);`  // constructs a vector with 10 value-initialized `ints (all zeros)`

## Constructor Initializer List

`Sales_data(const std::string &s): bookNo(s) { }`
`Sales_data(const std::string &s, unsigned n, double p):`
`bookNo(s), units_sold(n), revenue(p*n) { }`

A constructor initializer list specifies initial values for one or more data members of the
object being created. The constructor initializer is a list of member names, each of
which is followed by that member’s initial value in parentheses (or inside curly braces). Multiple member initializations are separated by commas.

When a member is omitted from the constructor initializer list, it is implicitly initialized using the same process as is used by the synthesized default constructor. The compiler uses their in-class initializersor or their default initialization if no in-class initializer is provided.

An in-class initializer is a way to give default values to data members directly at the point of their declaration inside a class. This feature was introduced in C++11 and makes class definitions cleaner and constructors simpler.

When we define variables, we typically initialize them immediately rather than defining them and then assigning to them.

`Definition:`		When a variable is declared	`string foo;`	Allocates memory for the variable
`Initialization:`	At the point of definition	`string foo = "Hi";`	Gives the variable its first value
`Assignment:`		After a variable is already defined	`foo = "Hello";`	Replaces the current value with a new one

When we create an object, its data members should ideally be initialized using a constructor initializer list, not assigned inside the constructor body.

🧱 Example from the Text:

// Sloppier way: no constructor initializer list
Sales_data::Sales_data(const string &s, unsigned cnt, double price) {
    bookNo = s;
    units_sold = cnt;
    revenue = cnt * price;
}

This code assigns values to the data members after they have already been default-initialized.

🔁 Compared to Proper Initialization:

// Better: use constructor initializer list
Sales_data::Sales_data(const string &s, unsigned cnt, double price)
    : bookNo(s), units_sold(cnt), revenue(cnt * price) { }

This code initializes the members directly, which is:

- More efficient (avoids default init + assignment),
- Necessary for const, reference, or non-copyable members,
- Better style in general.

## Constructor Initializers Are Sometimes Required

Members that are const or references must be initialized. Similarly, members that are of a class type that does not define a default constructor also must be initialized.

If a data member is of a class type (i.e., it's an object of another class) and that class does not have a default constructor, then we must explicitly initialize it using the constructor initializer list.

// error: ci and ri must be initialized
ConstRef::ConstRef(int ii)
{
    // assignments:
    i = ii;
    // ok
    ci = ii; // error: cannot assign to a const
    ri = i;
    // error: ri was never initialized
}

A default constructor can and often should use a constructor initializer list to initialize members, especially for:

built-in types (to avoid garbage values),
const members (which must be initialized),
reference members (also must be initialized),
and class types (to explicitly control how they’re initialized).

## Copy, Assignment, and Destruction

The classes also control what happens when we copy, assign, or destroy objects of the class type.
Objects are copied in several contexts, such as when we initialize a variable or when we pass or return an object by value. Objects are assigned when we use the assignment operator. Objects
are destroyed when they cease to exist, such as when a local object is destroyed on exit from the block in which it was created. Objects stored in a vector (or an array) are destroyed when that vector (or array) is destroyed. If we do not define these operations, the compiler will synthesize them for us.

## Copy Constructors

### Shallow Copy and Deep Copy

Depending upon the resources like dynamic memory held by the object, either we need to perform Shallow Copy or Deep Copy in order to create a replica of the object. In general, if the variables of an object have been dynamically allocated, then it is required to do a Deep Copy in order to create a copy of the object.

In shallow copy, an object is created by simply copying the data of all variables of the original object. This works well if none of the variables of the object are defined in the heap section of memory but if some variables are dynamically allocated memory from heap section, then the copied object variable will also reference the same memory location.

This will create ambiguity and run-time errors, dangling pointer. Since both objects will reference to the same memory location, then change made by one will reflect those change in another object as well. Since we wanted to create a replica of the object, this purpose will not be filled by Shallow copy.

Example:

class Example {
public:
    int* data;

    Example(int value) {
        data = new int(value);
    }

    // Default copy constructor: performs shallow copy
    Example(const Example& other) {
        data = other.data;  // Just copy the pointer, both objects now point to the same memory!
    }

    ~Example() {
        delete data;  // dangerous: double delete if shallow copy is used
    }
};

int main() {
    Example a(10);
    Example b = a;  // shallow copy
}

Both a and b point to the same memory. When either is destroyed, the memory is deleted. The other object now holds a dangling pointer — leads to undefined behavior, especially double deletion or memory corruption.

In Deep copy, an object is created by copying data of all variables, and it also allocates similar memory resources with the same value to the object. In order to perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory as well, if required. Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.

// Deep copy constructor
Example(const Example& other) {
    data = new int(*other.data);  // allocate new memory and copy the the pointed-to data 
}

## Delegating Constructors

The new standard extends the use of constructor initializers to let us define so called delegating constructors. A delegating constructor uses another constructor from its own class to perform its initialization. It is said to “delegate” some (or all) of its work to this other constructor.

Like other member initializers, the name of the class is followed by a parenthesized list of arguments. The argument list must match another constructor in the class.

class Sales_data {
	public:
		// nondelegating constructor initializes members from corresponding arguments
		Sales_data(std::string s, unsigned cnt, double price):
		bookNo(s), units_sold(cnt), revenue(cnt*price) { }
		// remaining constructors all delegate to another constructor
		Sales_data(): Sales_data("", 0, 0) {}
		Sales_data(std::string s): Sales_data(s, 0,0) {}
		Sales_data(std::istream &is): Sales_data()
		{ read(is, *this); }
		// other members as before
};

Constructor `Sales_data(std::istream &is)` delegates to the default constructor `Sales_data()` to initializes `bookNo` to `"" (default std::string)`, initializes `units_sold` to `0`, initializes `revenue` to `0.0`. After that, the body of the delegating constructor runs `read(is, *this);` This function reads data from the input stream into `*this` (i.e., the current object).

# Access Control and Encapsulation

In C++ we use access specifiers to enforce encapsulation:

• Members defined after a public specifier are accessible to all part of the program. The public members define the interface to the class.

• Members defined after a private specifier are accessible only to the member functions of the same class.
Code outside the class cannot access it directly. The private sections encapsulate (i.e., hide) the implementation.


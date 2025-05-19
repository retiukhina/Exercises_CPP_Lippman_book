# Data types

Data types determine the meaning of the data and operations in our programs.

C++ defines a set of primitive types that include the `arithmetic types` and a special type named `void`. The arithmetic types represent `characters`, `integers`, `boolean` values, and `floating-point numbers`. The `void` type has no associated values and can be used in only a few circumstances, most commonly as the return type for functions that do not return a value.

The arithmetic types are divided into two categories: `integral types` (which include character and boolean types) and `floating-point types`.

The `floating-point` types represent single-, double-, and extended-precision values. The standard specifies a minimum number of significant digits. Most compilers provide more precision than the specified minimum. Typically, `floats` are represented in one word (32 bits), `doubles` in two words (64 bits), and `long doubles` in either three or four words (96 or 128 bits). The `float` and `double` types typically yield about 7 and 16 significant digits, respectively. The type `long double` is often used as a way to accommodate special-purpose floating-point hardware; its precision is more likely to vary from one implementation to another.

C++, like C, is designed to let programs get close to the hardware when necessary. The arithmetic types are defined to cater to the peculiarities of various kinds of hardware. Accordingly, the number of arithmetic types in C++ can be bewildering. Most programmers can (and should) ignore these complexities by restricting the types they
use. A few rules of thumb can be useful in deciding which type to use:
• Use an `unsigned` type when you know that the values cannot be negative.
• Use `int` for integer arithmetic. `short` is usually too small and, in practice, `long` often has the same size as `int`. If your data values are larger than the minimum guaranteed size of an int, then use `long long`.
• Do not use plain `char` or `bool` in arithmetic expressions. Use them only to hold characters or truth values. Computations using char are especially problematic because `char` is `signed` on some machines and `unsigned ` on others. If you need a tiny integer, explicitly specify either `signed char` or `unsigned char`.
• Use `double` for floating-point computations; `float` usually does not have enough precision, and the cost of double-precision calculations versus single-precision is negligible. In fact, on some machines, double-precision operations are faster than single. The precision offered by `long double` usually is unnecessary and often entails considerable run-time cost.


• When we assign one of the non`bool` arithmetic types to a `bool` object, the result is false if the value is 0 and true otherwise.
• When we assign a `bool` to one of the other arithmetic types, the resulting value is 1 if the `bool` is `true` and 0 if the bool is `false`.
• When we assign a floating-point value to an object of integral type, the value is truncated. The value that is stored is the part before the decimal point.
• When we assign an integral value to an object of floating-point type, the fractional part is zero. Precision may be lost if the integer has more bits than the floating-point object can accommodate.
• If we assign an out-of-range value to an object of `unsigned` type, the result is the remainder of the value modulo the number of values the target type can hold. For example, an 8-bit `u`nsigned char` can hold values from 0 through
255, inclusive. If we assign a value outside this range, the compiler assigns the remainder of that value modulo 256. Therefore, assigning –1 to an 8-bit `unsigned char` gives that object the value 255.
• If we assign an out-of-range value to an object of signed type, the result is undefined. The program might appear to work, it might crash, or it might produce garbage values.

Programs usually should avoid implementation-defined behavior, such as assuming that the size of an `int` is a fixed and known value. Such programs are said to be nonportable. When the program is moved to another machine, code that
relied on implementation-defined behavior may fail. Tracking down these sorts of problems in previously working programs is, mildly put, unpleasant.

# Initialization

Initialization and assignment are different operations in C++. Initialization is not assignment. Initialization happens when a variable is given a value when it is created. Assignment obliterates an object’s current value and replaces that value with a new one.

## List initialization

From C++ 11 we can use any of the following four different ways to define an int variable named units_sold and initialize it to 0:

`int units_sold = 0;`
`int units_sold = {0};`
`int units_sold{0};`
`int units_sold(0);`

The generalized use of curly braces for initialization was introduced as part of the new standard. This form of initialization previously had been allowed only in more restricted ways. This form of initialization is referred to as `list initialization`. Braced lists of initializers can now be used whenever we initialize an object and in some cases when we assign a new value to an object.

When used with variables of built-in type, this form of initialization has one important property: The compiler will not let us list initialize variables of built-in type if the initializer might lead to the loss of information:
`long double ld = 3.1415926536;`
`int a{ld}, b = {ld};` // error: narrowing conversion required
`int c(ld), d = ld;` // ok: but value will be truncated
The compiler rejects the initializations of a and b because using a long double to
initialize an int is likely to lose data. At a minimum, the fractional part of ld will
be truncated. In addition, the integer part in ld might be too large to fit in an int.

## Default initialization

Uninitialized objects of built-in type defined inside a function body have undefined value, outside - initiaized to 0. Objects of class type that we do not explicitly initialize have a value that is defined by the class.

# Static typing

C++ is a statically typed language, which means that types are checked at compile time. The process by which types are checked is referred to as type checking. In C++, the compiler checks whether the operations we write are supported by the types we use. If we try to do things that the type does not support, the compiler generates an error message and does not produce an executable file. Static type checking can help
find bugs.

# Identifiers

The identifiers we define in our own programs may not contain two consecutive underscores, nor can an identifier begin with an underscore followed immediately by an uppercase letter. In addition, identifiers defined outside a function may not begin with an underscore.

# Scope of a name

The global scope is a scope of accessability outside of the function. The block scope is a scope of accessability within a block of a function or statement (for example for loop).

int reused = 42;
// reused has global scope

int main()
{
    int unique = 0; // unique has block scope
    // output #1: uses global reused; prints 42 0
    std::cout << reused << " " << unique << std::endl;
    int reused = 0; // new, local object named reused hides global reused
    // output #2: uses local reused; prints 0 0
    std::cout << reused << " " << unique << std::endl;
    // output #3: explicitly requests the global reused; prints 42 0
    std::cout << ::reused << " " << unique << std::endl;
    return 0;
}

`::` scope operator (§ 1.2, p. 8) used to override the default scoping rules. The global scope has no name. Hence, when the scope operator has an empty left-hand side, it is a request to fetch the name on the right-hand side from the global scope.

# Compound types

A compound type is a type that is defined in terms of another type. C++ has several compound types, two of which—references and pointers.

`A declaration` is a base type followed by a list of declarators. Each declarator names a variable and gives the variable a type that is related to the base type.

## References

The C++11 standard introduced a new kind of reference: an `“rvalue reference”`. These references are primarily intended for use inside classes. Technically speaking, when we use the term reference, we mean `“lvalue reference.”`

A `reference` defines an alternative name for an object. A reference type “refers to” another type. We define a `reference type` by writing a declarator of the form &d, where d is the name being declared:

int ival = 1024;
int &refVal = ival; // refVal refers to (is another name for) ival
int &refVal2; // error: a reference must be initialized

Ordinarily, when we initialize a variable, the value of the initializer is copied into the object we are creating. When we define a reference, instead of copying the initializer’s value, we bind the reference to its initializer. Once initialized, a reference remains bound to its initial object. There is no way to rebind a reference to refer to
a different object. Because there is no way to rebind a reference, references must be initialized.

!! A `reference` is not an object. Instead, a `reference` is just another name for an already existing object.
After a `reference` has been defined, all operations on that `reference` are actually operations on the object to which the reference is bound.

!! Because references are not objects, we may not define a reference to a reference.

### Reference Definitions

We can define multiple references in a single definition. Each identifier that is a reference must be preceded by the & symbol:

`int i = 1024, i2 = 2048;`// i and i2 are both ints
`int &r = i, r2 = i2;` // r is a reference bound to i; r2 is an int
`int i3 = 1024, &ri = i3;` // i3 is an int; ri is a reference bound to i3
`int &r3 = i3, &r4 = i2;`// both r3 and r4 are references

With two exceptions, the type of a reference and the object to which the reference refers must match exactly.
Moreover, a reference may be bound only to an object, not to a literal or to the result of a more general expression.

# Pointers

A pointer is a compound type that “points to” another type. Like references, pointers are used for indirect access to other objects. Unlike a reference, a pointer is an object in its own right. Pointers can be assigned and copied; a single pointer can point to several different objects over its lifetime. Unlike a reference, a pointer
need not be initialized at the time it is defined. Like other built-in types, pointers defined at block scope have undefined value if they are not initialized.

We define a pointer type by writing a declarator of the form *d, where d is the name being defined. The * must be repeated for each pointer variable:
`int *ip1, *ip2;` // both ip1 and ip2 are pointers to int
`double dp, *dp2; `// dp2 is a pointer to double; dp is a double

## Taking the Address of an Object

A pointer holds the address of another object. We get the address of an object by using the address-of operator (the & operator):

`int ival = 42;` // p holds the address of ival;
`int *p = &ival;` // p is a pointer to ival;

The second statement defines p as a pointer to int and initializes p to point to the int object named ival. Because references are not objects, they don’t have addresses. Hence, we may not define a pointer to a reference. With two exceptions, the types of the pointer and the object to which it points must match:

`double dval;`
`double *pd = &dval;` // ok: initializer is the address of a double
`double *pd2 = pd;` // ok: initializer is a pointer to double
`int *pi = pd;` // error: types of pi and pd differ
`pi = &dval;` // error: assigning the address of a double to a pointer to int

The types must match because the type of the pointer is used to infer the type of the object to which the pointer points. If a pointer addressed an object of another type, operations performed on the underlying object would fail.

A pointer holds a memory address, and its value can be:

1. Valid (points to an object) – it refers to actual data.
2. One-past-the-end – it points just beyond an array or object (safe for comparison, not dereferencing).
3. Null – it points to nothing (used to signal "no object").
4. Invalid – it has a garbage or deleted address; using it leads to undefined behavior.

### One-past-the-end Pointer
In C++, a pointer is allowed to point to one element past the end of an array, but you must not dereference it (i.e., you cannot access the value at that address). This is mainly useful for loops and comparisons, especially with iterators.

This feature helps in implementing generic algorithms like loops and iterators without needing special cases for the last element.

✅ Example: Safe usage (comparison only)

`#include <iostream>

int main() {
    int numbers[3] = {10, 20, 30};
    int* begin = numbers;
    int* end = numbers + 3; // one-past-the-end pointer

    for (int* ptr = begin; ptr != end; ++ptr) {
        std::cout << *ptr << std::endl;
    }

    return 0;
}`

## Using a Pointer to Access an Object

When a pointer points to an object, we can use the dereference operator (the * operator) to access that object:

`int &r2 = *p;` // r2 becomes an alias for the int value pointed to by p.

## Null Pointers

A null pointer does not point to any object. There are several ways to obtain a null pointer:

`int *p1 = nullptr;` // equivalent to int *p1 = 0; (since C++11)
`int *p2 = 0;` // directly initializes p2 from the literal constant 0
// must #include cstdlib
`int *p3 = NULL;` // equivalent to int *p3 = 0;

nullptr is a literal that has a special type that can be converted to any other pointer type.


Older programs sometimes use a preprocessor variable named NULL, which
the cstdlib header defines as 0. Preprocessor variables are managed by the preprocessor, and are not part of the std namespace. As a result, we refer to them directly without the `std:: prefix.`
When we use a preprocessor variable, the preprocessor automatically replaces the variable by its value. Hence, initializing a pointer to NULL is equivalent to initializing it to 0. Modern C++ programs generally should avoid using NULL and use nullptr instead.

It is illegal to assign an int variable to a pointer, even if the variable’s value happens to be 0.

int zero = 0;
int* pi;
pi = zero;  // ❌ ERROR: cannot assign int to int*

! Under most compilers, when we use an uninitialized pointer, the bits in the memory in which the pointer resides are used as an address. Using an uninitialized pointer is a request to access a supposed object at that supposed location. There is no way to distinguish a valid address from an invalid one formed from the bits that happen to
be in the memory in which the pointer was allocated.
Our recommendation to initialize all variables is particularly important for pointers. If possible, define a pointer only after the object to which it should point has been defined. If there is no object to bind to a pointer, then initialize the pointer to nullptr or zero. That way, the program can detect that the pointer does not point to
an object.

## Pointers to Pointers

We can store the address of a pointer in another pointer.
We indicate each pointer level by its own *. That is, we write ** for a pointer to a pointer, *** for a pointer to a pointer to a pointer, and so on:

`int ival = 1024;`
`int *pi = &ival;` // pi points to an int
`int **ppi = &pi;` // ppi points to a pointer to an int

## References to Pointers

A reference is not an object. Hence, we may not have a pointer to a reference.
However, because a pointer is an object, we can define a reference to a pointer:
`int i = 42;`
`int *p;` // p is a pointer to int
`int *&r = p;` // r is a reference to the pointer p
`r = &i;` // r refers to a pointer; assigning &i to r makes p point to i
`*r = 0;` // dereferencing r yields i, the object to which p points; changes i to 0

It can be easier to understand complicated pointer or reference declara-
tions if you read them from right to left.

# const qualifier

We can make a variable unchangeable by deﬁning the variable’s type as const:

`const int bufSize = 512;` // input buffer size

Because we can’t change the value of a const object after we create it, it must be initialized. As usual, the initializer may be an arbitrarily complicated expression:

`const int i = get_size();` // ok: initialized at run time
`const int j = 42;` // ok: initialized at compile time
`const int k;` // error: k is uninitialized const

## Ininitialization and const

A const type can use most but not all of the same operations as its nonconst version. The one restriction is that we may use only those operations that cannot change an object. So, for example, we can use a
const int in arithmetic expressions in exactly the same way as a plain, nonconst int. A const int converts to bool the same way as a plain int, and so on.
Among the operations that don’t change the value of an object is initialization — when we use an object to initialize another object, it doesn’t matter whether either or both of the objects are consts:
`int i = 42;`
`const int ci = i;` // ok: the value in i is copied into ci
`int j = ci;` // ok: the value in ci is copied into j

## By Default, const Objects Are Local to a File

In C++, a const variable has internal linkage by default. That means:

It is only visible within the file where it is defined.
It is not accessible from other .cpp files, even if you declare it in a header.
(!It's only applied to variables, not to return types of functions and not to function parameters)

If you write:

// file1.cpp
`const int bufSize = 512;`

And then in another file:

// file2.cpp
`extern const int bufSize;`  // ❌ will cause linker error if bufSize is not defined here too

This fails, because bufSize was only defined in file1.cpp, and by default, const variables are not shared between files (internal linkage).

## extern and const

Sometimes we have a const variable that we want to share across multiple files but whose initializer is not a constant expression.

A constant expression is a value that the compiler can fully evaluate at compile time — it is known and fixed before the program runs.

Examples of constant expressions:

`const int x = 10;` // ✅ constant expression: 10 is known at compile time
`const int y = 2 + 3 * 4;` // ✅ still a constant expression: math is resolved at compile time

In these cases, the compiler knows exactly what x and y are, so it can:

Replace every use of x or y with their actual values,
Avoid creating real variables in memory — it just hardcodes the values.

🔸 What is an initializer?
An initializer is the value or expression you assign to a variable when you define it.

`const int size = 512;` // "512" is the initializer

If the initializer is a constant expression, the compiler treats size as a compile-time constant.

🔸 Why is this important for const variables?
When the initializer is a constant expression, like 512, the compiler can optimize your code and give the variable internal linkage by default. That means:

The variable stays private to its file.
If you use it in other files, you must define it again in each file (with the same value).
But if the initializer is not a constant expression, like:

`const int bufSize = fcn();` // ❌ not a constant expression — depends on a function at runtime

Then:

The compiler cannot replace bufSize with a value during compilation. The variable must actually exist at runtime.

You must use **extern** to make sure only one instance exists across files.

// file_1.cc defines and initializes a const that is accessible to other files
`extern const int bufSize = fcn();`
// file_1.h
`extern const int bufSize;` // same bufSize as defined in file_1.cc

What not to do:

// file_1.h
`const int bufSize = 512;`  // This defines a separate const in every file that includes this header!

This leads to multiple definitions and linker errors because each .cpp file gets its own bufSize.

# References to const

We can bind a reference to an object of a const type. To do so we use a reference to const, which is a reference that refers to a const type. Unlike an ordinary reference, a reference to const cannot be used to change the object to which the reference is bound:

`const int ci = 1024;`
`const int &r1 = ci;` // ok: both reference and underlying object are const
`r1 = 42;` // error: r1 is a reference to const
`int &r2 = ci;` // error: nonconst reference to a const object

## Initialization and References to const

# Dealing with types

## Type Aliases

A type alias is a name that is a synonym for another type. Type aliases let us simplify complicated type definitions, making those types easier to use. Type aliases also let us emphasize the purpose for which a type is used.

We can define a type alias in one of two ways. Traditionally, we use a `typedef`:

`typedef double wages;` // wages is a synonym for double
`typedef wages base, *p;` // base is a synonym for double, p for double*

The keyword typedef may appear as part of the base type of a declaration. This means that you can write a declaration where the base type includes the typedef keyword, and instead of creating variables, you are defining a new name (alias) for an existing type.

Example:

`typedef unsigned int uint;`

Now uint can be used anywhere you’d use unsigned int.

If a declaration starts with typedef, it's not creating variables, it's creating new type names.

Example:

`typedef int* IntPtr;`

This does not create a pointer. It defines IntPtr as a new name for the type int*.

As in any other declaration, the declarators can include `type modifiers`  (like *, &, []) that define `compound types` built from the `base type` of the definition.

Example:

`typedef int* IntPtr;`

    Base type: int
    Declarator (*IntPtr) applies the pointer modifier
    Result: IntPtr is an alias for int*

Another example:

`typedef char name[20];`

    Base type: char
    Declarator: name[20]
    Result: name is a synonym for char[20]

The C++11 standard introduced a second way to define a type alias, via an alias declaration:
`using SI = Sales_item;` // SI is a synonym for Sales_item
An alias declaration starts with the keyword `using` followed by the alias name and an =. The alias declaration defines the name on the left-hand side of the = as an alias for the type that appears on the right-hand side.

### Pointers, const, and Type Aliases

Declarations that use type aliases that represent compound types and const can yield surprising results.

`typedef char *pstring;`
`const pstring cstr = 0;` // cstr is a constant pointer to char
`const pstring *ps;` // ps is a pointer to a constant pointer to char

! `const pstring cstr = 0;` IS NOT equuiavelnt to `const char* cstr = 0;`


`const char *` is a pointer to a const char, while `char * const` is a constant pointer to a char.

The first, the value being pointed to can't be changed but the pointer can be. The second, the value being pointed at can change but the pointer can't (similar to a reference).

When you write const pstring cstr, you're saying:
    `cstr` is a `const` pstring → cstr is a `char* const`

Thus:

`const pstring cstr = 0;`
→ is the same as:
`char* const cstr = 0;`

There is also a

`const char * const`

which is a constant pointer to a constant char (so nothing about it can be changed).

Note:

The following two forms are equivalent:

`const char *`

and

`char const *`

## The auto Type Specifier

When we write a program, it can be surprisingly difficult—and sometimes even impossible—to determine the type of an expression. Under the C++11 standard, we can let the compiler figure out the type for us by using the auto type specifier. Unlike type specifiers, such as double, that name a specific type, auto tells the compiler to deduce the type from the initializer.

By implication, a variable that uses auto as its type specifier must have an initializer:
// the type of item is deduced from the type of the result of adding val1 and val2
`auto item = val1 + val2;` // item initialized to the result of val1 + val2

Because a declaration can involve only a single base type, the initializers for all the variables in the declaration must have types that are onsistent with each other:
`auto i = 0, *p = &i;` // ok: i is int and p is a pointer to int
`auto sz = 0, pi = 3.14;` // error: inconsistent types for sz and pi

When we use a reference as an initializer, the initializer is the corresponding object. The compiler uses that object’s type for auto’s type deduction:
`int i = 0, &r = i;`
`auto a = r;` // a is an int (r is an alias for i, which has type int)

`auto` ordinarily ignores top-level consts. As usual in initializations, low-level consts, such as when an initializer is a pointer to const, are kept:

const int ci = i, &cr = ci;
auto b = ci; // b is an int (top-level const in ci is dropped)
auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
auto d = &i; // d is an int* (& of an int object is int*)
auto e = &ci; // e is const int* (& of a const object is low-level const)

If we want the deduced type to have a top-level const, we must say so explicitly:

`const auto f = ci;` // deduced type of ci is int; f has type const int

We can also specify that we want a reference to the auto-deduced type. Normal initialization rules still apply:

`const int ci = 42;`

🔹 `auto &g = ci;`

	✅ This works fine
    ci is a const int
    auto &g says: “g is a reference to ci”
    So, g becomes a const int& (because auto deduces const int from ci)

🧠 Key rule: When using auto with a reference, auto deduces the base type including const if the reference is initialized from a const.

🔹 `auto &h = 42;`

    ❌ Error — can't bind a non-const reference to a literal (like 42)
    Why? Because:
        auto deduces the type as int
        So auto &h becomes int&
        But you can't bind an int& (non-const) to a temporary literal like 42

🛑 C++ doesn't allow binding a non-const reference to a temporary value.

🔹 `const auto &j = 42;`

    ✅ This is valid
    auto deduces int
    So const auto& becomes const int&
    You can bind a const reference to a temporary (like 42), and it extends the lifetime of the temporary

When we define several variables in the same statement, it is important to remember that a reference or pointer is part of a particular declarator and not part of the base type for the declaration. As usual, the initializers must provide consistent auto-deduced types:
`auto k = ci, &l = i;` // k is int; l is int&
`auto &m = ci, *p = &ci;` // m is a const int&; p is a pointer to const int
`auto &n = i, *p2 = &ci;` // error: type deduced from i is int; type deduced from &ci is const int

## The decltype Type Specifier

The C++11 introduced a second type specifier, `decltype`, which returns the type of its operand.

The compiler analyzes the expression to determine its type but does not evaluate the expression:
`decltype(f()) sum = x; `// sum has whatever type f returns

The way `decltype`handles top-level const and references differs subtly from the way `auto` does. When the expression to which we apply decltype is a variable, decltype returns the type of that variable, including top-level const and references:

`const int ci = 0, &cj = ci;`
`decltype(ci) x = 0;` // `x` has type `const int`
`decltype(cj) y = x;` // `y` has type `const int&` and is bound to `x`
`decltype(cj) z;` // error: z is a reference and must be initialized

### decltype and References

Some expressions will cause `decltype` to yield a reference type. Generally speaking, `decltype` returns a reference type for expressions that yield objects that can stand on the left-hand side of the assignment:

// decltype of an expression can be a reference type
`int i = 42, *p = &i, &r = i;`
`decltype(r + 0) b;` // ok: addition yields an int; b is an (uninitialized) int
`decltype(*p) c;` // error: c is `int&` and must be initialized

When we dereference the pointer p using *p, you are accessing the value stored at the memory location that p is pointing to. Here’s the key part: *p doesn't give you an int value directly. It gives you the lvalue that p points to. Since p is a pointer to int, *p is of type int&, a reference to int, not just an int.

When we apply decltype to a variable without any parentheses, we get the type of that variable. If we wrap the variable’s name in one or more sets of parentheses, the compiler will evaluate the operand as an expression.

// decltype of a parenthesized variable is always a reference
`decltype((i)) d;` // error: d is int& and must be initialized
`decltype(i) e;` // ok: e is an (uninitialized) int

!! Remember that decltype((variable)) (note, double parentheses) is always a reference type, but decltype(variable) is a reference type only if variable is a reference.

# Defining our own data strustures

We’ll define our class as follows:

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

The names defined inside the class must be unique within the class but can reuse names defined outside the class.

! Bad practice:  defining a variable immediately after the class, like this:

class MyClass {
    // class members
} myObject;  // ← defining an object at the same time

myObject is an instance of MyClass, declared as part of the class sstatement. This can confuse readers, making them think that `myObject` is part of the class, when it's just a global variable defined right after it.

## Class Data Members

The class body defines the members of the class. Our class has only `data members`.

The data members of a class define the contents of the objects of that class type. Each object has its own copy of the class data members. Modifying the data members of one object does not change the data in any other Sales_data object. We define data members the same way that we define normal variables: We specify a base type followed by a list of one or more declarators.

Under C++11 we can supply an `in-class initializer` for a data member. It is a way to give a data member of a class a default value directly in its declaration inside the class definition.

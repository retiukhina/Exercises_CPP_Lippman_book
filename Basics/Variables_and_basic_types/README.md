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

Initialization and assignment are different operations in C++. Initialization is not assignment. Initialization happens when a variable
is given a value when it is created. Assignment obliterates an object’s current value and replaces that value with a new one.

## List initialization

From C++ 11 we can use any of the following four different ways to define an int variable named units_sold and
initialize it to 0:

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

C++ is a statically typed language, which means that types are checked at compile time. The process by which types are checked is referred to as type checking. In C++, the compiler checks whether the operations we write are supported
by the types we use. If we try to do things that the type does not support, the compiler
generates an error message and does not produce an executable file. Static type checking can help
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

`A declaration` is a base type followed by a list of declarators. Each declarator names a variable and gives the
variable a type that is related to the base type.

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

With two exceptions, the type of a reference and the object to which the reference refers must match exactly.
Moreover, a reference may be bound only to an object, not to a literal or to the result of a more general expression.


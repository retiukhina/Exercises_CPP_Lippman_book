# Basics

Operator overloading lets us define the meaning of an operator when ap-plied to operand(s) of a class type.

Overloaded operators are functions with special names: the keyword operator
followed by the symbol for the operator being defined. Like any other function, an overloaded operator has a return type, a parameter list, and a body.

An overloaded operator function has the same number of parameters as the
operator has operands. A unary operator has one parameter; a binary operator
has two. In a binary operator, the left-hand operand is passed to the first parameter and the right-hand operand to the second.

When an overloaded operator is a member function, `*this` is bound to
the left-hand operand.Member operator functions have one less (explicit) parameter than the number of operands. Non-member function takes two parameters explicitly:

``class MyClass {`
`public:`
    `MyClass operator+(const MyClass& rhs) const;`
`};`

`MyClass operator+(const MyClass& lhs, const MyClass& rhs)`

An operator function must either be a member of a class or have at least one
parameter of class type:

`// error: cannot redefine the built-in operator for ints`
`int operator+(int, int);`

This restriction means that we cannot change the meaning of an operator when
applied to operands of built-in type.

Four symbols (`+,` `-,` `*,` and `&`) serve as both unary and binary operators. Either or both of these operators can be overloaded. The number of parameters determines which operator is being defined.

An overloaded operator has the same precedence and associativity as the corresponding built-in operator. Regardless of the operand types

`x == y + z;` is always equivalent to `x == (y + z)`.

## Calling an Overloaded Operator Function Directly

1. Non-member functions:
We “call” an overloaded operator function indirectly by using the operator on arguments of the appropriate type. We can also call an overloaded operator function directly in the same way that we call an ordinary function. We name the function and pass an appropriate number of arguments of the appropriate type:

`// equivalent calls to a nonmember operator function`
`data1 + data2;` // normal expression
`operator+(data1, data2);` // equivalent function call

Both functions call the nonmember function `operator+`, passing `data1` as the first argument and `data2` as the second.

2. Member functions:

We call a member operator function explicitly in the same way that we call
any other member function. We name an object (or pointer) on which to run the
function and use the dot (or arrow) operator to fetch the function we wish to call:

`data1 += data2;` // expression-based ‘‘call’’
`data1.operator+=(data2);` // equivalent call to a member operator function

Each of these statements calls the member function operator+=, binding this
to the address of data1 and passing data2 as an argument.

## Operators That Cannot Be Overloaded

`::`   `.*`   `.`   `?:`

It is generally a bad idea to overload certain C++ operators:

`&& (logical AND)`
`|| (logical OR)`
`, (comma)`
`& (address-of)`

Here’s a breakdown of the key reasons, with technical clarity:

1. Overloaded Operators Are Just Function Calls
When you overload an operator like `&&` or `,`, you're actually writing a function. For example:

`bool operator&&(const MyClass& lhs, const MyClass& rhs);`
This means both operands must be evaluated before the function can be called—because the function needs values for both `lhs` and `rhs`.

2. No Short-Circuit Evaluation
The built-in logical operators (`&&, ||`) use short-circuit evaluation:

`a && b evaluates b only if a is true.`
`a || b evaluates b only if a is false.`

Overloaded versions cannot replicate this behavior, because the compiler must evaluate both operands to pass them into the function.

So this code:

`if (obj1 && obj2) { ... }`

will evaluate `obj2` even if `obj1` is false, which can break expectations and logic.

3. Breaking Built-in Semantics and Expectations
The comma operator (`,`) and the address-of operator (`&`) already have built-in behavior:

`a, b:` evaluates a, discards result, evaluates and returns b.

`&a:` returns the memory address of a.

These are used commonly and naturally in C++ code. If you overload them, you change how they behave, possibly leading to unexpected or confusing behavior.

For example:

`MyClass a, b;`
`auto result = a , b;` // could do something totally unrelated to evaluating 'a' then 'b'

Same with:

`MyClass obj;`
`MyClass* p = &obj;` // might not give the address if & is overloaded

## Use Definitions That Are Consistent with the Built-in Meaning

When you design a class, you should always think first about what operations
the class will provide. Only after you know what operations are needed should
you think about whether to define each operation as an ordinary function or as an overloaded operator.

• If the class does IO, define the shift operators to be consistent with how IO is done for the built-in types.
• If the class has an operation to test for equality, define `operator==`. If the class has `operator==`, it should usually have `operator!=` as well.
• If the class has a single, natural ordering operation, define `operator<`. If the class has `operator<`, it should probably have all of the relational operators.
• The return type of an overloaded operator usually should be compatible with
the return from the built-in version of the operator: The logical and relational operators should return `bool`, the arithmetic operators should return a value of the class type, and assignment and

# Assignment and Compound Assignment Operators

Assignment operators should behave analogously to the synthesized operators:
After an assignment, the values in the left-hand and right-hand operands should have the same value, and the operator should return a reference to its left-hand operand.

*Synthesized operators (also called implicitly-defined operators) are operators that the compiler automatically generates for a class in C++ if you don’t explicitly define them yourself. Copy assignment operator (T& operator=(const T&))

! Overloaded assignment should generalize the built-in meaning of assignment, not circumvent it. What does it mean?

For built-in types (like int, float, or structs with only basic types), assignment does the following:

1. Replaces the left-hand side's contents with the right-hand side's.
2. Cleans up the old contents (if necessary).
3. Returns a reference to the left-hand side so chained assignments work: a = b = c;

Example: Proper operator=

class MyClass {
    int* data;
public:
    MyClass& operator=(const MyClass& other) {
        if (this != &other) { // check for self-assignment
            delete data; // clean up current resource
            data = new int(*other.data); // deep copy
        }
        return *this; // support chained assignment
    }
};

When we overload an arithmetic or bitwise operator, then its usually good idea to overload compound-assignment operators like +=, -=, *=, etc., which combine an operation and assignment, because developers expect them behave the same way.

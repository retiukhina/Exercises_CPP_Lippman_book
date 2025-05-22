Arguments are the initializers for a function’s parameters. The first argument initializes the first parameter, the second argument initializes the second parameter, and so on.

The return type of a function may not be an array type or a function type. However, a function may return a pointer to an array or a function.

Objects defined outside any function exist throughout the program’s execution. Such objects are created when the program starts and are not destroyed until the program ends. The lifetime of a local variable depends on how it is defined.

Objects that exist only while a block is executing are known as `automatic objects`. After execution exits a block, the values of the automatic objects created in that block are undefined.

`local static object` is a local variable declared with the static keyword and whose lifetime continues across calls to the function.

`Best practice` The header that declares a function should be included in the source file that defines that function.

# Using References to Avoid Copies

It can be inefficient to copy objects of large class types or large containers. Moreover, some class types (including the IO types) cannot be copied. Functions must use reference parameters to operate on objects of a type that cannot be copied.

`Best practice` Reference parameters that are not changed inside a function should be references to const.

# Overloaded Functions

Functions that have the same name but different parameter lists and that appear in the same scope are overloaded.

The main function may not be overloaded.

## Defining Overloaded Functions

Overloaded functions must differ in the number or the type(s) of their parameters. Each of the functions above takes a single parameter, but the parameters have different types.

It is an error for two functions to differ only in terms of their return types. If the parameter lists of two functions match but the return types differ, then the second declaration is an error:
`Record lookup(const Account&);`
`bool lookup(const Account&);` // error: only the return type is different

## Determining Whether Two Parameter Types Differ

Two parameter lists can be identical, even if they don’t look the same:
// each pair declares the same function
`Record lookup(const Account &acct);`
`Record lookup(const Account&);` // parameter names are ignored

`typedef Phone Telno;`
`Record lookup(const Phone&);`
`Record lookup(const Telno&); `// Telno and Phone are the same type

## Overloading and const Parameters

top-level const has no effect on the objects that can be passed to the function. A parameter that has a top-level const is indistinguishable from one without a top-level const:

`Record lookup(Phone);`
`Record lookup(const Phone);` // redeclares Record lookup(Phone)

`Record lookup(Phone*);`
`Record lookup(Phone* const);` // redeclares Record lookup(Phone*)

These are the same functions — the top-level const has no effect on overload resolution.

On the other hand, we can overload based on whether the parameter is a reference (or pointer) to the const or nonconst version of a given type; such consts are low-level:
// functions taking const and nonconst references or pointers have different parameters declarations for four independent, overloaded functions
`Record lookup(Account&);` // function that takes a reference to Account
`Record lookup(const Account&); `// new function that takes a const reference

`Record lookup(Account*);` // new function, takes a pointer to Account
`Record lookup(const Account*);` // new function, takes a pointer to const

✅ Key Rules to Remember
1. Low-level const matters (inside pointers or references):

T& vs const T& → different
T* vs const T* → different

2. Top-level const doesn't matter (on values or pointer variables):

T vs const T → same
T* vs T* const → same

3. Const objects/pointers can only be passed to const versions:

const T → only matches const T& or const T*
Non-const objects/pointers can match both, but:

4. Compiler prefers non-const overloads when we pass a nonconst object or pointer to nonconst.

## const_cast and Overloading

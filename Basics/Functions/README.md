Arguments are the initializers for a function’s parameters. The first argument initializes the first parameter, the second argument initializes the second parameter, and so on.

The return type of a function may not be an array type or a function type. However, a function may return a pointer to an array or a function.

Objects defined outside any function exist throughout the program’s execution. Such objects are created when the program starts and are not destroyed until the program ends. The lifetime of a local variable depends on how it is defined.

Objects that exist only while a block is executing are known as `automatic objects`. After execution exits a block, the values of the automatic objects created in that block are undefined.

`local static object` is a local variable declared with the static keyword and whose lifetime continues across calls to the function.

`Best practice` The header that declares a function should be included in the source file that defines that function.

# Using References to Avoid Copies

It can be inefficient to copy objects of large class types or large containers. Moreover, some class types (including the IO types) cannot be copied. Functions must use reference parameters to operate on objects of a type that cannot be copied.

`Best practice` Reference parameters that are not changed inside a function should be references to const.

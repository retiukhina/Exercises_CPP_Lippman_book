# Writing to a Stream

In C++ an expression yields a result and is composed of one or more operands and (usually) an operator.

The `<<` operator takes two operands:

the left-hand operand must be an ostream object (`std::cout`);
the right-hand operand is a value to print.

The operator `<<` writes the given value on the given ostream. It returns
its left-hand operand, so the result of the first operator becomes the left-hand operand of the next one. As a result, we can chain together output requests. Thus, expression `std::cout << "Enter two numbers:" << std::endl;` is equivalent to `(std::cout << "Enter two numbers:") << std::endl;`

`endl` is a special value called a manipulator. Writing endl has the effect of ending the current line and flushing the buffer associated with that device. Flushing the buffer ensures that all the output the program has generated so far is actually written to the output stream, rather than
sitting in memory waiting to be written.

The prefix `std::` indicates that the names `cout` and `endl` are defined inside the namespace named std. Namespaces allow us to avoid inadvertent collisions between the names we define and uses of those same names inside a library. All the names defined by the standard library are in the
std namespace.

# Reading from a Stream

The input operator (the `»` operator) behaves analogously to the output operator. It takes an istream as its left-hand operand and an object as its
right-hand operand. It reads data from the given istream and stores what was
read in the given object.


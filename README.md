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

## Exercise 1.3:
Write a program to print Hello, World on the standard output.
## Exercise 1.4:
Our program used the addition operator, +, to add two numbers. Write
a program that uses the multiplication operator, *, to print the product instead.
## Exercise 1.5:
We wrote the output in one large statement. Rewrite the program to use
a separate statement to print each operand.
## Exercise 1.6:
Explain whether the following program fragment is legal.
`std::cout << "The sum of " << v1;`
`<< " and " << v2;`
`<< " is " << v1 + v2 << std::endl;`
If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?

--> No, it's not a legal code as expressions can't start with operator.

## Exercise 1.11:

Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

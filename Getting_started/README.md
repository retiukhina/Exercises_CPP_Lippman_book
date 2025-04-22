# Writing to a Stream

In C++ an expression yields a result and is composed of one or more operands and (usually) an operator.

The `<<` operator takes two operands:

the left-hand operand must be an ostream object (`std::cout`);
the right-hand operand is a value to print.

The operator `<<` writes the given value on the given ostream. It returns its left-hand operand, so the result of the first operator becomes the left-hand operand of the next one. As a result, we can chain together output requests. Thus, expression `std::cout << "Enter two numbers:" << std::endl;` is equivalent to `(std::cout << "Enter two numbers:") << std::endl;`

`endl` is a special value called a manipulator. Writing endl has the effect of ending the current line and flushing the buffer associated with that device. Flushing the buffer ensures that all the output the program has generated so far is actually written to the output stream, rather than sitting in memory waiting to be written.

The prefix `std::` indicates that the names `cout` and `endl` are defined inside the namespace named std. Namespaces allow us to avoid inadvertent collisions between the names we define and uses of those same names inside a library. All the names defined by the standard library are in the std namespace.

# Reading from a Stream

The input operator (the `»` operator) behaves analogously to the output operator. It takes an istream as its left-hand operand and an object as its right-hand operand. It reads data from the given istream and stores what was read in the given object.

# Introducing Classes

In C++ we define our own data structures by defining a class. A class defines a type along with a collection of operations that are related to that type.

To use a class, we need not care about how it is implemented. Instead, what we need to know is what operations objects of that type can perform. Every class defines a type. The type name is the same as the name of the class.

## The Sales_item Class

When we write `Sales_item item;` we are saying that `item` is an object of type `Sales_item`. We often contract the phrase `“an object of type Sales_item”` to `“a Sales_item object”` or even more simply to `“a Sales_item.”`

In addition to being able to define variables of type Sales_item, we can:

• Call a function named isbn to fetch the ISBN from a Sales_item object.
• Use the input (>>) and output (<<) operators to read and write objects of
type Sales_item.
• Use the assignment operator (=) to assign one Sales_item object to another.
• Use the addition operator (+) to add two Sales_item objects. The two objects must refer to the same ISBN. The result is a new Sales_item object whose ISBN is that of its operands and whose number sold and revenue are the sum of the corresponding values in its operands.
• Use the compound assignment operator (+=) to add one Sales_item object into another.

## What Is a Member Function?

A member function is a function that is defined as part of a class. Member functions are sometimes referred to as methods. Ordinarily, we call a member function on behalf of an object. For example, the first part of the left-hand operand of the equality expression `item1.isbn` uses the dot operator (the “.” operator) to say that we want “the isbn member of the object named item1.”



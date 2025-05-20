# Library string Type

A string is a variable-length sequence of characters. String is defined in the std namespace.

## Defining and Initializing strings

Each class defines how objects of its type can be initialized.

1. Default Initialization (Empty String)
Creates an empty string; that is, a string with no characters.

    `std::string s1;`  // default initialization

2. Copy initialization
Characters from the string literal (excluding the null terminator) are copied into the string.

    `string s5 = "hiya";`

3. Direct initialization
When we omit the =, we use direct initialization.

   `string s6("hiya");`

4. Direct initialization
When the string have to contain the given number of copies of the specified character, we use direct initialization.

   `string s7(10, ’c’);`

Ways to Initialize a string:

string s1           		Default initialization; s1 is the empty string.
string s2(s1)       		s2 is a copy of s1.
string s2 = s1      		Equivalent to s2(s1), s2 is a copy of s1.
string s3("value")  		s3 is a copy of the string literal, not including the null.
string s3 = "value" 		Equivalent to s3("value"), s3 is a copy of the string literal.
string s4(n, ’c’)   		Initialize s4 with n copies of the character ’c’.
string s8 = string(10, ’c’)	Copy initialization; s8 is cccccccccc

## Operations on strings

Along with defining how objects are created and initialized, a class also defines the operations that objects of the class type can perform. A class can define operations that are called by name, such as the isbn function of our Sales_item class. A class also can define what various operator symbols, such as << or +, mean when applied to objects of the class’ type. Table 3.2 (overleaf) lists the most common string operations.

### Reading and Writing strings

os << s			Writes s onto output stream os. Returns os.
is >> s			Reads whitespace-separated string from is into s. Returns is.
getline(is, s)	Reads a line of input from is into s. Returns is.
s.empty()		Returns true if s is empty; otherwise returns false.
s.size()		Returns the number of characters in s.
s[n]			Returns a reference to the char at position n in s; positions start at 0.
s1 + s2			Returns a string that is the concatenation of s1 and s2.
s1 = s2			Replaces characters in s1 with a copy of s2.
s1 == s2		The strings s1 and s2 are equal if they contain the same characters.
s1 != s2		Equality is case-sensitive.
<, <=, >, >=	Comparisons are case-sensitive and use dictionary ordering.

### Reading an Unknown Number of strings

int main()
{
	string word;
	while (cin >> word) // read until end-of-file
		cout << word << endl; // write each word followed by a new line
	return 0;
}

### Using getline to Read an Entire Line

Sometimes we do not want to ignore the whitespace in our input. In such cases,
we can use the getline function instead of the >> operator. The getline function takes an input stream and a string. This function reads the given stream up to and including the first newline and stores what it read—not including the newline—in its string argument. After getline sees a newline, even if it is the first character in the input, it stops reading and returns. If the first character in the input is a newline, then the resulting string is the empty string.

Like the input operator, getline returns its istream argument. As a result,
we can use getline as a condition just as we can use the input operator as a
condition: while (getline(cin, line)).

The newline that causes getline to return is discarded; the newline is
not stored in the string.

### The string empty and size Operations

The empty function returns a bool indicating whether the string is empty.
Funciton empty is a member function of string. To call this function, we use
the dot operator to specify the object on which we want to run the empty function.

`if (!line.empty())`

The size member returns the length of a string (i.e., the number of charac-
ters in it).

// to print only lines longer than 80 characters:
`if (line.size() > 80)`

### The string::size_type Type

size returns a string::size_type value.

The string class—and most other library types—defines several compan-
ion types. These companion types make it possible to use the library types in a machine-independent manner. The type size_type is one of these companion
types. To use the size_type defined by string, we use the scope operator to
say that the name size_type is defined in the string class.
Although we don’t know the precise type of string::size_type, we do
know that it is an unsigned type big enough to hold the size of any string. Any variable used to store the result from the string size operation should be of type string::size_type.
Admittedly, it can be tedious to type string::size_type. Under the new
standard, we can ask the compiler to provide the appropriate type by using auto or decltype:

`auto len = line.size();` // len has type string::size_type

Because size returns an unsigned type, it is essential to remember that expressions that mix signed and unsigned data can have surprising results.
For example, if n is an int that holds a negative value, then `s.size() < n` will almost surely evaluate as true. It yields true because the negative value in n will convert to a large unsigned value.
You can avoid problems due to conversion between unsigned and int by not using ints in expressions that use size().

### Comparing strings

1. If two strings have different lengths and if every character in the shorter
string is equal to the corresponding character of the longer string, then the shorter string is less than the longer one.
2. If any characters at corresponding positions in the two strings differ, then the result of the string comparison is the result of comparing the first character at which the strings differ.

As an example, consider the following strings:

string str = "Hello";
string phrase = "Hello World";
string slang = "Hiya";

Using rule 1, we see that str is less than phrase. By applying rule 2, we see that slang is greater than both str and phrase.

### Assignment for strings

string st1(10, ’c’), st2; // st1 is cccccccccc; st2 is an empty string
st1 = st2; // assignment: replace contents of st1 with a copy of st2
			// both st1 and st2 are now the empty string

### Adding Two strings

string s1 = "hello, ", s2 = "world\n";
string s3 = s1 + s2; // s3 is hello, world\n
s1 += s2; // equivalent to s1 = s1 + s2

### Adding Literals and strings

The string library lets us convert both character literals and character string literals to strings. Because we can use these literals where a string is expected, we can rewrite the previous program as follows:
string s1 = "hello", s2 = "world";
string s3 = s1 + ", " + s2 + ’\n’;

C++ allows string concatenation only if at least one operand is an actual std::string object.

This is fine:

string s6 = s1 + ", " + "world"; // ✅

Why?
s1 is a std::string, so "s1 + ', '" is a std::string
Then you're doing: std::string + const char* → still valid

This is error:

string s7 = "hello" + ", " + s2; // ❌ Error

Why is this wrong?
In C++98, both "hello" and ", " are string literals, which are of type:

const char[6] // for "hello"
const char[3] // for ", "

You're not concatenating strings. Instead, this is pointer arithmetic!

🔥 What actually happens:
"hello" decays to a pointer to const char (const char*).

Then you try to add ", " (which is also a const char*).

This is not valid:

const char* + const char* // ❌ invalid
You're essentially asking the compiler:

"Can I add one memory address to another?"

## Dealing with the Characters in a string

### Processing Every Character? Use Range-Based for

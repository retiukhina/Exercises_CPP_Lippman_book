
# Additional string Operations

Additional Ways to Construct strings n, len2 and pos2 are all unsigned values

// s is a copy of the first n characters in the array to which cp points. That array must have at least n characters.
`string s(cp, n);`

// s is a copy of the characters in the string s2 starting at
the index pos2. Undefined if pos2 > s2.size().
`string s(s2, pos2);`

// s is a copy of len2 characters from s2 starting at the index pos2. Undefined if pos2 > s2.size(). Regardless of the value of len2, copies at most
s2.size() - pos2 characters.
`string s(s2, pos2, len2);`

## Other Ways to Change a string

In addition to the versions of insert and erase that take iterators, string provides versions that take an index. The index indicates the starting element to erase or the position before which to insert the given values:

`s.insert(s.size(), 5, ’!’);` // insert five exclamation points at the end of s
`s.erase(s.size() - 5, 5);` // erase 5 characters starting from the position s.size() - 5.

The string library also provides versions of insert and assign that take C-style character arrays. For example, we can use a null-terminated character array as the value to insert or assign into a string:

const char *cp = "Stately, plump Buck";
`s.assign(cp, 7);` // s == "Stately"
`s.insert(s.size(), cp + 7);` // s == "Stately, plump Buck"

assign() copies 7 chars starting from the pointer of cp array points to.
insert() starts copying characters from the 8th character of cp and adds them to the end of the string.

std::string::insert() can take either:

a whole string, or
a substring from another string,

and insert it at a specific position in another string.

`string s = "some string";`
`string s2 = "some other string";`

1. s.insert(0, s2);
What it does:
Inserts the entire string s2 at the beginning of s.
Result:
s == "some other stringsome string"

2. s.insert(0, s2, 0, s2.size());
This does exactly the same thing — but in a more explicit way.
s.insert(pos, source_string, source_pos, count);

! insert() does not overwrite any part of the string. It inserts new characters at the specified position and shifts the existing characters to the right.

## The append and replace Functions

The string class defines two additional members, append and replace, that
can change the contents of a string. Table 9.13 summarizes these functions. The append operation is a shorthand way of inserting at the end:

string s("C++ Primer"), s2 = s; // initialize s and s2 to "C++ Primer"
s.insert(s.size(), " 4th Ed."); // s == "C++ Primer 4th Ed."
s2.append(" 4th Ed."); // equivalent: appends " 4th Ed." to s2; s == s2

The replace operations are a shorthand way of calling erase and insert:
// equivalent way to replace "4th" by "5th"
s.erase(11, 3); // s == "C++ Primer Ed."
s.insert(11, "5th"); // s == "C++ Primer 5th Ed."

// starting at position 11, erase three characters and then insert "5th"
s2.replace(11, 3, "5th"); // equivalent: s == s2

In the call to replace, the text we inserted happens to be the same size as the text we removed. We can insert a larger or smaller string:
s.replace(11, 3, "Fifth");
// s == "C++ Primer Fifth Ed."
In this call we remove three characters but insert five in their place.

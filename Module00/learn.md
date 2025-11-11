# Module 00 — Learning Guide

## Overview

Module 00 introduces fundamental C++ concepts: basic I/O, command-line arguments, classes, encapsulation, and static members. Each exercise builds toward understanding Object-Oriented Programming principles within C++98 constraints.

---

## Core Concepts

### 1. Command-Line Arguments

**Summary:** Programs receive arguments via `argc` and `argv` parameters in `main()`.

**OOP Principle:** Not directly OOP-related, but demonstrates program entry points and input handling.

**C++98 Mapping:**

- `int main(int argc, char **argv)` or `int main(int argc, char *argv[])`
- `argc`: count of arguments (program name counts as 1)
- `argv`: array of C-style strings (`char*`)
- Access arguments: `argv[1]` through `argv[argc-1]`

**Pitfalls:**

- Forgetting that `argv[0]` is the program name
- Not checking `argc` before accessing `argv[i]` (risk of out-of-bounds)
- Treating `argv` elements as `std::string` directly (need conversion)

**Micro-Exercise:** Write a program that prints each command-line argument on a separate line, numbered from 1.

**Checklist:**

- [ ] Understand `argc` and `argv` relationship
- [ ] Can safely iterate through arguments
- [ ] Know how to check for empty argument list

**English Glossary:**

- **argc**: Argument count; number of command-line arguments plus program name
- **argv**: Argument vector; array of C-style strings containing arguments
- **Command-line**: Interface where users type commands and arguments

---

### 2. Character Manipulation

**Summary:** Transform characters using standard library functions like `std::toupper`.

**OOP Principle:** Abstraction — hide implementation details of character encoding behind a simple function interface.

**C++98 Mapping:**

- Include `<cctype>` for character classification/conversion
- `std::toupper(int c)`: converts lowercase to uppercase
- Cast to `unsigned char` to avoid undefined behavior with negative values
- Iterate through `std::string` using index or iterator (C++98 compatible)

**Pitfalls:**

- Passing negative values to `std::toupper` (undefined behavior)
- Not casting `char` to `unsigned char` before conversion
- Modifying characters in-place without proper bounds checking

**Micro-Exercise:** Write a function that takes a `std::string` and returns a new string with all lowercase letters converted to uppercase, preserving non-alphabetic characters.

**Checklist:**

- [ ] Know when to use `<cctype>` functions
- [ ] Understand unsigned char casting for safety
- [ ] Can iterate through string characters

**English Glossary:**

- **toupper**: Function converting lowercase to uppercase
- **unsigned char**: Character type guaranteed to represent values 0-255
- **Character encoding**: System mapping characters to numeric values

---

### 3. Classes and Encapsulation (ex01)

**Summary:** Encapsulation keeps data private and exposes only necessary operations through a public interface.

**OOP Principle:** **Encapsulation** — bundle data and methods together; control access to internal state.

**C++98 Mapping:**

- `class Contact { private: ... public: ... };`
- Private members: data fields (name, phone, etc.)
- Public members: constructors, getters, setters (when needed)
- Access control: `private`, `public`, `protected`
- Getters return `const` references when possible to avoid copies

**Pitfalls:**

- Making data members `public` (breaks encapsulation)
- Providing setters that don't validate input
- Returning non-const references from getters (allows external modification)
- Forgetting to mark getters as `const` when they don't modify state

**Micro-Exercise:** Design a `Contact` class with private fields for first name, last name, and phone number. Provide a constructor that validates non-empty strings and const getters for each field.

**Checklist:**

- [ ] All data members are private
- [ ] Public interface is minimal and well-defined
- [ ] Getters are const when appropriate
- [ ] Constructor enforces invariants

**English Glossary:**

- **Encapsulation**: Bundling data and methods; hiding implementation details
- **Access control**: Keywords (`private`, `public`) controlling member visibility
- **Getter**: Method returning a value of a private member
- **Setter**: Method modifying a private member (use sparingly)
- **Invariant**: Condition that must always be true for a valid object state

---

### 4. Fixed Arrays and Ring Buffers (ex01)

**Summary:** Use fixed-size arrays to store objects; implement circular overwrite behavior when capacity is reached.

**OOP Principle:** **Abstraction** — hide the ring buffer implementation behind a simple `addContact()` interface.

**C++98 Mapping:**

- Fixed array: `Contact contacts[8];` (no dynamic allocation)
- Track insertion index: `int _insertIndex;` (wraps around using modulo)
- Track count: `int _count;` (capped at 8)
- Modulo arithmetic: `_insertIndex = (_insertIndex + 1) % 8;`

**Pitfalls:**

- Using dynamic allocation (`new Contact[8]`) when fixed array suffices
- Forgetting to wrap the insertion index (causes out-of-bounds)
- Not tracking count separately from insertion index
- Confusing when to overwrite vs. append

**Micro-Exercise:** Design a `RingBuffer` class that stores up to 5 integers. When full, overwrite the oldest element. Provide `add(int)` and `get(int index)` methods.

**Checklist:**

- [ ] Understand modulo for wrapping indices
- [ ] Can distinguish between count and insertion index
- [ ] Know when overwrite occurs vs. append

**English Glossary:**

- **Ring buffer**: Circular data structure overwriting oldest elements when full
- **Modulo**: Arithmetic operation (`%`) returning remainder of division
- **Fixed array**: Array with compile-time known size
- **Insertion index**: Position where next element will be added

---

### 5. Stream I/O and Formatting (ex01)

**Summary:** Use C++ streams (`std::cin`, `std::cout`) and manipulators (`<iomanip>`) for formatted output.

**OOP Principle:** **Abstraction** — streams hide low-level I/O details behind a uniform interface.

**C++98 Mapping:**

- Input: `std::cin >> variable;` or `std::getline(std::cin, stringVar);`
- Output: `std::cout << value << std::endl;`
- Formatting: `#include <iomanip>`
- Width: `std::setw(10)` sets minimum field width
- Alignment: `std::right` (default for numbers), `std::left` (default for strings)
- Reset: `std::setw(0)` or width applies only to next insertion

**Pitfalls:**

- Mixing `>>` and `getline()` without clearing buffer (leaves newline)
- Forgetting that `setw()` applies only to the next insertion
- Not resetting alignment/width when switching output styles
- Using `printf` (forbidden in 42 modules)

**Micro-Exercise:** Print a table with three columns (name, age, score) each 15 characters wide, right-aligned, separated by `|`.

**Checklist:**

- [ ] Can read input using `std::cin` and `std::getline`
- [ ] Understand `std::setw()` behavior (applies once)
- [ ] Know how to control alignment
- [ ] Avoid mixing C and C++ I/O

**English Glossary:**

- **Stream**: Abstraction for input/output operations
- **Manipulator**: Function-like object controlling stream behavior (`setw`, `endl`)
- **Field width**: Minimum number of characters for next output
- **Alignment**: Positioning text within a field (left, right, internal)

---

### 6. Static Members (ex02)

**Summary:** Static members belong to the class, not instances; shared across all objects of that class.

**OOP Principle:** **Abstraction** — static members represent class-level state and operations, separate from instance data.

**C++98 Mapping:**

- Declaration in class: `static int _nbAccounts;`
- Definition in `.cpp`: `int Account::_nbAccounts = 0;` (ODR requirement)
- Static methods: `static void displayAccountsInfos();` (no `this` pointer)
- Access: `Account::_nbAccounts` or `obj._nbAccounts` (but prefer class scope)

**Pitfalls:**

- Forgetting to define static members in `.cpp` (linker error)
- Accessing static members through instance (works but misleading)
- Modifying static members without thread safety (not a concern in Module 00)
- Confusing static members with global variables

**Micro-Exercise:** Design a `Counter` class with a static member `_totalCount` tracking all instances created. Increment it in the constructor and decrement in the destructor. Provide a static method to retrieve the total.

**Checklist:**

- [ ] Understand static members are shared across instances
- [ ] Know declaration vs. definition requirement
- [ ] Can call static methods without an object
- [ ] Understand when to use static vs. instance members

**English Glossary:**

- **Static member**: Class-level variable or function shared by all instances
- **ODR (One Definition Rule)**: Requirement that entities be defined exactly once
- **Class scope**: Belonging to the class itself, not individual objects
- **Instance member**: Variable or function belonging to a specific object

---

### 7. Constructors and Destructors (ex02)

**Summary:** Constructors initialize objects; destructors clean up resources when objects are destroyed.

**OOP Principle:** **Encapsulation** — constructors establish invariants; destructors maintain resource safety (RAII).

**C++98 Mapping:**

- Constructor: `Account(int initialAmount);` (same name as class, no return type)
- Destructor: `~Account();` (prefixed with `~`, no parameters, no return type)
- Initialization: prefer initializer lists `: _amount(initialAmount)` over assignment in body
- Order: destructors called in reverse order of construction (typically)

**Pitfalls:**

- Forgetting initializer lists (default-constructs then assigns, less efficient)
- Not initializing all members (undefined values)
- Destructor order assumptions (implementation-dependent for globals)
- Missing destructor when resources need cleanup

**Micro-Exercise:** Write a `Resource` class with a constructor that prints "Resource created" and a destructor that prints "Resource destroyed". Create three instances and observe destruction order.

**Checklist:**

- [ ] Constructor name matches class name
- [ ] Destructor prefixed with `~`
- [ ] Prefer initializer lists over assignment
- [ ] Understand destruction order (reverse construction)

**English Glossary:**

- **Constructor**: Special member function initializing objects
- **Destructor**: Special member function cleaning up objects
- **Initializer list**: Syntax `: member(value)` for efficient initialization
- **RAII (Resource Acquisition Is Initialization)**: Pattern tying resource lifetime to object lifetime

---

## Exercise-Specific Learning Points

### ex00 — Megaphone

**Key Concepts:**

- Command-line argument handling
- Character transformation (`std::toupper`)
- String iteration and concatenation
- Conditional output (arguments vs. default message)

**Design Approach:**

- No classes needed (procedural is acceptable for simple I/O)
- Focus on correct argument parsing and character handling
- Ensure exact output matching (spaces, newlines)

**Test Strategy:**

- Test with no arguments (default message)
- Test with single argument
- Test with multiple arguments
- Test with special characters and spaces

---

### ex01 — PhoneBook

**Key Concepts:**

- Class design (`Contact`, `PhoneBook`)
- Encapsulation (private data, public interface)
- Fixed arrays (no dynamic allocation)
- Ring buffer pattern
- Stream I/O and formatting (`<iomanip>`)
- Input validation

**Design Approach:**

- **Contact**: Encapsulate five string fields; validate in constructor/setter
- **PhoneBook**: Manage fixed array; track insertion index and count; provide `addContact()`, `list()`, `display(index)`
- **Main loop**: Read commands (`ADD`, `SEARCH`, `EXIT`); dispatch to appropriate methods

**Invariants:**

- `Contact`: All fields non-empty when saved
- `PhoneBook`: `_count` between 0 and 8; `_insertIndex` between 0 and 7

**Test Strategy:**

- Add 8 contacts, verify all saved
- Add 9th contact, verify oldest overwritten
- Search with valid/invalid indices
- Test table formatting (width, alignment, truncation)
- Test empty input rejection

---

### ex02 — Account

**Key Concepts:**

- Static members (class-level state)
- Static methods
- Constructor/destructor with logging
- Timestamp formatting
- Aggregation across instances

**Design Approach:**

- Static members track totals across all accounts
- Instance members track per-account state
- Constructor increments static counters; destructor decrements
- Methods update both instance and static state
- Match log format exactly (timestamps, field order, separators)

**Invariants:**

- Static totals always reflect sum of all instances
- `_accountIndex` unique per instance
- `_amount` non-negative (or handle negative if allowed)

**Test Strategy:**

- Compare output with provided log (byte-for-byte except timestamps)
- Verify static totals update correctly
- Test deposit/withdrawal edge cases (insufficient funds)
- Verify constructor/destructor logging

---

## Common Pitfalls Across Module 00

1. **Using `using namespace std;`** — Forbidden; qualify names explicitly (`std::cout`, `std::string`)
2. **Mixing C and C++ I/O** — Use `std::cout`/`std::cin`, not `printf`/`scanf`
3. **Forgetting include guards** — Always use `#ifndef`/`#define`/`#endif` in headers
4. **Implementing functions in headers** — Put implementations in `.cpp` files (except templates)
5. **Not checking compilation flags** — Must compile with `-Wall -Wextra -Werror -std=c++98`
6. **Memory leaks** — If using `new`, always `delete` (though Module 00 ex01 forbids dynamic allocation)
7. **Public data members** — Keep data private; use getters/setters when needed
8. **Missing const correctness** — Mark getters and parameters as `const` when appropriate

---

## Module 00 Checklist

Before submitting, verify:

- [ ] All code compiles with `c++ -Wall -Wextra -Werror -std=c++98`
- [ ] No `using namespace std;` anywhere
- [ ] No `printf`, `malloc`, `free` (use C++ alternatives)
- [ ] All headers have include guards
- [ ] Function implementations are in `.cpp` files (not headers)
- [ ] Classes use proper encapsulation (private data, public interface)
- [ ] Static members are defined in `.cpp` files
- [ ] Output matches requirements exactly (spaces, newlines, formatting)
- [ ] No memory leaks (use tools like `valgrind` if dynamic allocation used)
- [ ] Makefile has correct targets and flags

---

## English Glossary — Module 00

- **Class**: User-defined type bundling data and functions
- **Encapsulation**: Hiding implementation details behind a public interface
- **Access control**: `private`, `public`, `protected` keywords controlling member visibility
- **Constructor**: Special function initializing objects (same name as class)
- **Destructor**: Special function cleaning up objects (`~ClassName`)
- **Static member**: Class-level variable or function shared by all instances
- **Getter**: Method returning a private member's value
- **Setter**: Method modifying a private member
- **Invariant**: Condition that must always be true for valid object state
- **Stream**: Abstraction for input/output (`std::cin`, `std::cout`)
- **Manipulator**: Function controlling stream behavior (`std::setw`, `std::endl`)
- **Ring buffer**: Circular data structure overwriting oldest elements when full
- **RAII**: Resource Acquisition Is Initialization; tying resource lifetime to object lifetime
- **ODR**: One Definition Rule; entities must be defined exactly once
- **Include guard**: Preprocessor directives preventing multiple inclusion (`#ifndef`/`#define`/`#endif`)

---

## Next Steps

After completing Module 00:

- Understand the difference between stack and heap allocation (Module 01)
- Learn about pointers and references (Module 01)
- Prepare for Orthodox Canonical Form (Module 02)
- Review when to use classes vs. free functions

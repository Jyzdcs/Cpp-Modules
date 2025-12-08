# Module 01 — Learning Guide

## Overview

Module 01 introduces memory management and resource handling in C++: stack vs. heap allocation, pointers vs. references, dynamic memory with `new`/`delete`, RAII principles, and practical applications like file I/O and pointer-to-member functions. Each exercise builds toward understanding ownership, lifetime, and safe resource management within C++98 constraints.

---

## Core Concepts

### 1. Stack vs. Heap Allocation

**Summary:** Objects can be allocated on the stack (automatic lifetime) or heap (manual lifetime management).

**OOP Principle:** **Encapsulation of Lifetime** — choose allocation strategy based on ownership and lifetime requirements.

**C++98 Mapping:**

- **Stack allocation**: `Zombie z("Bob");` — object destroyed when scope exits
- **Heap allocation**: `Zombie* z = new Zombie("Alice");` — manual `delete z;` required
- Stack is automatic, fast, limited size; heap is manual, slower, larger capacity
- Stack objects destroyed in reverse order of construction (LIFO)

**Pitfalls:**

- Using heap when stack suffices (unnecessary complexity)
- Forgetting to `delete` heap objects (memory leak)
- Accessing stack objects after scope exit (dangling reference)
- Using `delete` on stack objects (undefined behavior)

**Micro-Exercise:** Create two zombies: one on the stack in a helper function that announces immediately, and one on the heap that you return to main, announce, then delete.

**Checklist:**

- [ ] Understand when objects are automatically destroyed
- [ ] Know when to choose stack vs. heap
- [ ] Can identify ownership transfer scenarios
- [ ] Remember to `delete` heap objects

**English Glossary:**

- **Stack allocation**: Automatic memory management; object lifetime tied to scope
- **Heap allocation**: Manual memory management using `new`/`delete`
- **Scope**: Region of code where a variable is accessible
- **Lifetime**: Duration between object construction and destruction
- **Memory leak**: Failure to deallocate heap memory, causing resource waste

---

### 2. Pointers and References

**Summary:** Pointers hold addresses and can be null/reassigned; references are aliases and must be initialized.

**OOP Principle:** **Abstraction** — choose the right level of indirection for expressing relationships and ownership.

**C++98 Mapping:**

- **Pointer**: `std::string* ptr = &str;` — can be null, reassigned, requires `*` to dereference
- **Reference**: `std::string& ref = str;` — must be initialized, cannot be reseated, no special syntax to use
- Address-of: `&variable` gives address
- Dereference: `*ptr` accesses value
- Null pointer: `ptr = NULL;` (C++98) or `ptr = 0;`

**Pitfalls:**

- Dereferencing null pointers (undefined behavior)
- Confusing `&` in declaration (reference) vs. expression (address-of)
- Thinking references can be reseated (they cannot)
- Forgetting to check pointer validity before dereferencing
- Creating references to temporary objects (dangling reference)

**Micro-Exercise:** Write a function that takes a reference parameter and modifies the original variable. Write another that takes a pointer and safely modifies the value only if the pointer is not null.

**Checklist:**

- [ ] Understand pointer syntax (`*`, `&`, `->`)
- [ ] Know when references are mandatory (can't be null/reseated)
- [ ] Can check pointers for null before use
- [ ] Understand address vs. value distinction

**English Glossary:**

- **Pointer**: Variable storing a memory address; can be null or reassigned
- **Reference**: Alias for another variable; must be initialized; cannot be reseated
- **Dereference**: Accessing the value a pointer points to (using `*`)
- **Address-of operator**: `&` in expression; returns memory address
- **Null pointer**: Pointer pointing to nothing (address 0 or `NULL`)
- **Dangling pointer/reference**: Pointer/reference to memory that has been freed or gone out of scope

---

### 3. Dynamic Memory Management (new/delete)

**Summary:** Use `new` to allocate objects on the heap; use `delete` to free them. Use `new[]` for arrays with matching `delete[]`.

**OOP Principle:** **RAII (Resource Acquisition Is Initialization)** — tie resource lifetime to object lifetime; acquire in constructor, release in destructor.

**C++98 Mapping:**

- Single object: `Zombie* z = new Zombie("Bob");` then `delete z;`
- Array: `Zombie* horde = new Zombie[10];` then `delete[] horde;`
- Never mix: `delete` with `new[]` or `delete[]` with `new` (undefined behavior)
- Placement: prefer stack when possible; use heap for large objects or dynamic lifetimes

**Pitfalls:**

- Forgetting to `delete` (memory leak)
- Double-delete (undefined behavior)
- Mixing `delete` and `delete[]` (undefined behavior)
- Deleting stack objects (crash)
- Accessing memory after `delete` (use-after-free)
- Not initializing array elements (default constructor must exist)

**Micro-Exercise:** Allocate an array of 5 zombies using `new[]`, set their names individually, make each announce, then properly deallocate the array. Use a debugger or Valgrind to verify no leaks.

**Checklist:**

- [ ] Use `new[]` and `delete[]` together
- [ ] Use `new` and `delete` together
- [ ] Never mix array and non-array forms
- [ ] Check for leaks with tools (Valgrind, `leaks` on macOS)
- [ ] Understand when heap allocation is necessary

**English Glossary:**

- **new**: Operator allocating memory on heap; calls constructor
- **delete**: Operator deallocating memory; calls destructor
- **new[]**: Array allocation operator
- **delete[]**: Array deallocation operator
- **Memory leak**: Allocated memory never freed
- **Double-delete**: Attempting to free memory twice (undefined behavior)
- **Use-after-free**: Accessing memory after it's been deallocated

---

### 4. RAII (Resource Acquisition Is Initialization)

**Summary:** Acquire resources in constructors; release them in destructors. Ensures resources are cleaned up automatically.

**OOP Principle:** **Encapsulation of Resource Management** — tie resource lifetime to object lifetime; no manual cleanup needed.

**C++98 Mapping:**

- Constructor acquires: `File(const std::string& name) : _stream(name.c_str()) { }`
- Destructor releases: `~File() { if (_stream.is_open()) _stream.close(); }`
- Stack objects automatically call destructor when scope exits
- Heap objects call destructor when `delete`d

**Pitfalls:**

- Acquiring resources without a destructor to release them
- Exceptions thrown during constructor (resource leak if not careful)
- Not following RAII when managing heap memory (prefer smart pointers in modern C++, unavailable in C++98)
- Relying on manual cleanup instead of automatic scope-based cleanup

**Micro-Exercise:** Design a `FileHandle` class that opens a file in the constructor and closes it in the destructor. Print a message in each. Create an instance in a function and observe automatic cleanup when the function returns.

**Checklist:**

- [ ] Acquire resources in constructor
- [ ] Release resources in destructor
- [ ] Prefer stack allocation for automatic cleanup
- [ ] Understand exception safety (not required in Module 01 but good to know)

**English Glossary:**

- **RAII**: Resource Acquisition Is Initialization; pattern tying resource lifetime to object lifetime
- **Resource**: Any limited asset (memory, file handles, sockets, etc.)
- **Acquisition**: Obtaining or allocating a resource
- **Release**: Freeing or closing a resource
- **Automatic cleanup**: Destructor called when object goes out of scope
- **Exception safety**: Ensuring resources are released even if exceptions occur

---

### 5. References in Class Members

**Summary:** Store references as members when the object always needs a valid, unchanging external object.

**OOP Principle:** **Encapsulation of Dependencies** — express mandatory, permanent relationships via reference members.

**C++98 Mapping:**

- **Reference member**: `class HumanA { Weapon& _weapon; };`
- **Initialization**: Must use initializer list: `HumanA(Weapon& w) : _weapon(w) { }`
- **Lifetime**: Referenced object must outlive the referring object
- **Immutability**: Cannot reseat; always refers to the same object

**Pitfalls:**

- Forgetting initializer list (reference must be initialized at construction)
- Storing reference to temporary object (dangling reference)
- Assuming reference member can be changed later (it cannot)
- Not ensuring referenced object outlives the referencing object

**Micro-Exercise:** Design a `Student` class with a reference to a `School` object. The student is always associated with the same school. Provide a method that prints the school's name via the reference.

**Checklist:**

- [ ] Initialize reference members in initializer list
- [ ] Ensure referenced object lifetime exceeds referencing object
- [ ] Understand reference members cannot be reseated
- [ ] Know when to use reference vs. pointer members

**English Glossary:**

- **Member reference**: Reference stored as a class member variable
- **Initializer list**: Syntax after constructor signature for initializing members
- **Reseat**: Change what a reference refers to (impossible for references)
- **Outlive**: Exist longer than another object
- **Mandatory relationship**: Association that must always exist (use reference)

---

### 6. Pointers in Class Members

**Summary:** Store pointers as members when the object may or may not have an associated external object, or when the association can change.

**OOP Principle:** **Encapsulation of Optional Dependencies** — express optional or changeable relationships via pointer members.

**C++98 Mapping:**

- **Pointer member**: `class HumanB { Weapon* _weapon; };`
- **Initialization**: Can be null: `HumanB() : _weapon(NULL) { }`
- **Setter**: Allow changing: `void setWeapon(Weapon& w) { _weapon = &w; }`
- **Null checks**: Always check before dereferencing: `if (_weapon) { _weapon->getType(); }`

**Pitfalls:**

- Dereferencing null pointer without checking (crash)
- Forgetting to initialize pointer to null (undefined value)
- Assuming pointer is always valid (may be null)
- Not updating pointer when referenced object is destroyed

**Micro-Exercise:** Design an `Employee` class with an optional pointer to a `Manager`. Provide a `setManager()` method and a `hasManager()` method. In a `report()` method, check if a manager exists before accessing it.

**Checklist:**

- [ ] Initialize pointer members (to null or valid address)
- [ ] Always check for null before dereferencing
- [ ] Understand when to use pointer vs. reference members
- [ ] Provide setters if association can change

**English Glossary:**

- **Member pointer**: Pointer stored as a class member variable
- **Optional relationship**: Association that may or may not exist (use pointer)
- **Null check**: Testing if a pointer is null before dereferencing
- **Setter method**: Function allowing modification of a member
- **Dangling pointer**: Pointer to memory that has been freed

---

### 7. File I/O with Streams

**Summary:** Use `std::ifstream` to read files and `std::ofstream` to write files; prefer C++ streams over C file APIs.

**OOP Principle:** **Abstraction** — streams hide low-level file operations behind a uniform interface.

**C++98 Mapping:**

- **Input**: `std::ifstream ifs("input.txt");` — open for reading
- **Output**: `std::ofstream ofs("output.txt");` — open for writing
- **Check**: `if (!ifs)` or `if (!ifs.is_open())` to verify open success
- **Read**: `std::getline(ifs, line);` or `ifs >> word;`
- **Write**: `ofs << "text" << std::endl;`
- **Close**: automatic on destruction, or explicit `ifs.close();`

**Pitfalls:**

- Not checking if file opened successfully (reading/writing invalid stream)
- Using C APIs (`fopen`, `fclose`, `fprintf`) — forbidden
- Forgetting to close files (typically automatic but good practice to be explicit)
- Not handling read/write errors
- Mixing `>>` and `getline` without handling leftover newlines

**Micro-Exercise:** Write a program that reads a file line-by-line and writes each line to a new file with line numbers prepended. Handle file open failures gracefully.

**Checklist:**

- [ ] Include `<fstream>` for file streams
- [ ] Check if file opened successfully
- [ ] Use `std::getline()` for line-based reading
- [ ] Close files explicitly or rely on RAII
- [ ] Avoid C file APIs

**English Glossary:**

- **ifstream**: Input file stream; for reading files
- **ofstream**: Output file stream; for writing files
- **fstream**: File stream supporting both read and write
- **Stream state**: Condition indicating success/failure of operations
- **RAII**: File automatically closed when stream object destroyed

---

### 8. String Manipulation (find, substr)

**Summary:** Use `std::string` methods for searching and extracting substrings; avoid `std::string::replace()` when forbidden.

**OOP Principle:** **Abstraction** — string class hides complexity of character array manipulation.

**C++98 Mapping:**

- **Find**: `size_t pos = str.find(substr);` — returns position or `std::string::npos` if not found
- **Substring**: `std::string sub = str.substr(start, length);` — extract portion
- **Concatenation**: `str1 + str2` or `str += str2;`
- **Length**: `str.length()` or `str.size()`
- **Manual replace**: Loop with `find()`, build new string with `substr()` and concatenation

**Pitfalls:**

- Using forbidden `std::string::replace()` (ex04 constraint)
- Not checking for `std::string::npos` before using find result
- Off-by-one errors in substring indices
- Infinite loop when search string is empty
- Forgetting to update search position after replacement

**Micro-Exercise:** Write a function that takes a string and replaces all occurrences of `"old"` with `"new"` using only `find()`, `substr()`, and concatenation. Handle edge cases (empty search string, no matches).

**Checklist:**

- [ ] Understand `find()` returns position or `npos`
- [ ] Can extract substrings with `substr(start, length)`
- [ ] Know how to build replacement manually
- [ ] Handle edge cases (empty string, no matches)

**English Glossary:**

- **find()**: Method returning position of substring or `npos`
- **substr()**: Method extracting portion of string
- **npos**: Special constant meaning "not found" (`std::string::npos`)
- **Concatenation**: Joining strings together
- **Position**: Zero-based index into string

---

### 9. Pointers to Member Functions

**Summary:** Store addresses of member functions in variables; invoke them on objects to avoid if/else chains.

**OOP Principle:** **Polymorphism via Dispatch Table** — map data (strings) to behavior (functions) for extensible design.

**C++98 Mapping:**

- **Type**: `void (Harl::*funcPtr)()` — pointer to member function of `Harl` returning `void`
- **Assignment**: `funcPtr = &Harl::debug;` — take address of member function
- **Invocation**: `(this->*funcPtr)();` or `(obj.*funcPtr)();` — call via object
- **Array of pointers**: `void (Harl::*funcs[])() = { &Harl::debug, &Harl::info, ... };`
- **Dispatch table**: Map strings to function pointers; lookup and invoke

**Pitfalls:**

- Confusing syntax (`.*` vs. `->*`) for invoking pointers to member functions
- Forgetting to take address (`&Harl::debug` not `Harl::debug`)
- Using regular function pointers for member functions (won't work)
- Not handling invalid lookup (string not in table)

**Micro-Exercise:** Create a `Calculator` class with methods `add()`, `subtract()`, `multiply()`, `divide()`. Implement a `compute(std::string op)` method using a dispatch table of pointers to member functions.

**Checklist:**

- [ ] Understand pointer-to-member-function syntax
- [ ] Can declare and assign pointers to member functions
- [ ] Know how to invoke via `.*` or `->*`
- [ ] Can build dispatch table for extensible design

**English Glossary:**

- **Pointer to member function**: Variable storing address of a class member function
- **Dispatch table**: Array or map associating keys with function pointers
- **.***: Operator invoking pointer to member function on object
- **->***: Operator invoking pointer to member function via pointer to object
- **Extensibility**: Ease of adding new behavior without changing existing code

---

### 10. Switch Statements and Fall-Through

**Summary:** Use `switch` for multi-way branching on integral values; intentional fall-through executes multiple cases.

**OOP Principle:** **Control Flow Abstraction** — express hierarchical filtering logic clearly with fall-through.

**C++98 Mapping:**

- **Syntax**: `switch (value) { case 0: /* code */ break; case 1: /* code */ break; default: /* code */ }`
- **Fall-through**: Omit `break` to continue executing next case(s)
- **Default**: Catches all unmatched values
- **Integral types**: `int`, `char`, `enum` (not `std::string`)

**Pitfalls:**

- Forgetting `break` when fall-through is unintended
- Trying to switch on non-integral types (use if/else or map)
- Not providing `default` case (may miss unexpected values)
- Confusing fall-through behavior (document it clearly)

**Micro-Exercise:** Write a `switch` that maps severity levels (0=debug, 1=info, 2=warning, 3=error) and prints messages for that level and all higher levels using fall-through.

**Checklist:**

- [ ] Understand `switch` syntax and `case` labels
- [ ] Know when to use `break` vs. fall-through
- [ ] Provide `default` case for safety
- [ ] Document intentional fall-through

**English Glossary:**

- **Switch statement**: Multi-way branch based on value
- **Case label**: Marker for a specific value in switch
- **Fall-through**: Execution continuing into next case without `break`
- **Default case**: Catches all values not explicitly handled
- **Integral type**: Integer-like type (int, char, enum)

---

## Exercise-Specific Learning Points

### ex00 — BraiiiiiiinnnzzzZ

**Key Concepts:**

- Stack vs. heap allocation
- Object lifetime and scope
- Factory functions (`newZombie`) vs. temporary objects (`randomChump`)
- Destructor logging for debugging

**Design Approach:**

- **Zombie class**: Private `std::string name`; constructor initializes; `announce()` prints message; destructor logs name
- **newZombie**: Allocates on heap, returns pointer (caller must `delete`)
- **randomChump**: Allocates on stack, announces, destructs automatically
- **Main**: Demonstrate both allocation strategies; clean up heap zombie

**Invariants:**

- `Zombie`: `name` is always initialized
- Heap zombies must be explicitly deleted

**Test Strategy:**

- Create stack zombie in function; observe automatic destruction on return
- Create heap zombie; announce; delete; observe destruction
- Verify destructor messages include zombie names
- Check for memory leaks with Valgrind

---

### ex01 — Moar brainz!

**Key Concepts:**

- Dynamic array allocation (`new[]` / `delete[]`)
- Array initialization (default constructor + setter or parameterized constructor)
- Single allocation for multiple objects
- Proper deallocation of arrays

**Design Approach:**

- **Zombie class**: Needs default constructor (for `new Zombie[N]`) and setter or name-accepting constructor
- **zombieHorde function**: `Zombie* horde = new Zombie[N];` — single allocation; loop to set names; return pointer
- **Main**: Call `zombieHorde`, iterate and announce, then `delete[] horde;`

**Invariants:**

- Horde is a single allocation (not N separate `new` calls)
- All zombies initialized with names
- Matching `delete[]` for `new[]`

**Test Strategy:**

- Allocate horde of 10; verify all names set
- Check `announce()` for each zombie
- Verify proper destruction order (reverse)
- Use Valgrind to confirm no leaks

---

### ex02 — HI THIS IS BRAIN

**Key Concepts:**

- Pointer vs. reference syntax
- Address-of operator (`&`)
- Understanding memory addresses
- Demonstrating pointer/reference equivalence

**Design Approach:**

- Declare `std::string brain = "HI THIS IS BRAIN";`
- `std::string* stringPTR = &brain;`
- `std::string& stringREF = brain;`
- Print addresses: `&brain`, `stringPTR`, `&stringREF`
- Print values: `brain`, `*stringPTR`, `stringREF`

**Invariants:**

- All three addresses are identical
- All three values are identical

**Test Strategy:**

- Run program; verify addresses match
- Verify values match
- Understand why reference has same address as original

---

### ex03 — Unnecessary violence

**Key Concepts:**

- Member references vs. member pointers
- Mandatory vs. optional associations
- Initializer list for references
- Null checking for pointers
- Shared mutable state (`Weapon` changed externally)

**Design Approach:**

- **Weapon class**: Private `std::string _type`; `getType()` returns const reference; `setType()` modifies
- **HumanA**: Reference member `Weapon& _weapon`; constructor takes weapon; always armed
- **HumanB**: Pointer member `Weapon* _weapon`; may start unarmed (null); `setWeapon()` setter; check null in `attack()`
- **Main**: Create weapons, humans, attack before/after weapon change

**Invariants:**

- `HumanA` always has a valid weapon (reference)
- `HumanB` may not have a weapon (pointer can be null)
- Weapon changes reflected in both humans

**Test Strategy:**

- Test `HumanA` with weapon; change weapon type; attack again
- Test `HumanB` without weapon (handle null); set weapon; attack
- Verify both humans see weapon type changes
- Ensure no crashes from null dereference

---

### ex04 — Sed is for losers

**Key Concepts:**

- File I/O (`ifstream`, `ofstream`)
- String searching (`find()`)
- String extraction (`substr()`)
- Manual string replacement (forbidden to use `std::string::replace()`)
- Command-line argument validation

**Design Approach:**

- Validate arguments: `argc == 4`
- Open input file; check success
- Open output file `<filename>.replace`; check success
- Read content (line-by-line or entire file)
- Loop: find `s1`; if found, append substring before + `s2`; continue after `s1`
- Handle edge cases: empty `s1` (error or no-op), no matches (copy as-is)

**Invariants:**

- Input file unchanged
- Output file created with correct name
- All occurrences of `s1` replaced with `s2`

**Test Strategy:**

- Test with simple replacement (single occurrence)
- Test with multiple occurrences (verify all replaced)
- Test with no matches (output identical to input)
- Test with `s1` == `s2` (no change)
- Test error cases (missing arguments, file not found, empty `s1`)
- Use diff to compare expected vs. actual output

---

### ex05 — Harl 2.0

**Key Concepts:**

- Pointers to member functions
- Dispatch table (array of function pointers)
- Avoiding if/else chains
- Encapsulation of dispatch logic

**Design Approach:**

- **Harl class**: Four private methods (`debug`, `info`, `warning`, `error`); public `complain(std::string level)`
- **Dispatch table**: Array of strings (levels) and corresponding function pointers
- **Lookup**: Loop through table; match string; invoke via `(this->*funcPtr)()`
- **Main**: Create `Harl` instance; call `complain()` with various levels

**Invariants:**

- Level strings are case-sensitive (document expected format)
- Invalid level either silent or prints error (your choice)

**Test Strategy:**

- Call `complain("DEBUG")`, verify debug message
- Call `complain("INFO")`, verify info message
- Call `complain("WARNING")`, verify warning message
- Call `complain("ERROR")`, verify error message
- Call `complain("INVALID")`, handle gracefully
- Verify no if/else chains (code review)

---

### ex06 — Harl filter

**Key Concepts:**

- Switch statement with fall-through
- Severity hierarchy (debug < info < warning < error)
- Command-line argument for level filtering
- Formatted output with level labels

**Design Approach:**

- Take command-line argument (level)
- Map level string to integer (0=DEBUG, 1=INFO, 2=WARNING, 3=ERROR, default=-1)
- Use switch on integer:
  - `case 0:` print `[ DEBUG ]` message; fall-through
  - `case 1:` print `[ INFO ]` message; fall-through
  - `case 2:` print `[ WARNING ]` message; fall-through
  - `case 3:` print `[ ERROR ]` message; break
  - `default:` print insignificant problems message
- Each case prints its level and falls through to higher levels

**Invariants:**

- Lower severity levels include all higher severity messages
- Unknown level prints single default message

**Test Strategy:**

- `./harlFilter DEBUG` — prints all four levels
- `./harlFilter INFO` — prints info, warning, error
- `./harlFilter WARNING` — prints warning, error
- `./harlFilter ERROR` — prints only error
- `./harlFilter XYZ` — prints default message
- Verify output formatting matches requirements

---

## Common Pitfalls Across Module 01

1. **Forgetting to delete heap objects** — Use Valgrind; prefer stack when possible
2. **Mixing new/delete with new[]/delete[]** — Arrays need `delete[]`
3. **Dereferencing null pointers** — Always check before use
4. **Dangling pointers/references** — Ensure referenced object outlives reference
5. **Not initializing reference members in initializer list** — References must be initialized at construction
6. **Using C file APIs (fopen, fclose)** — Use C++ streams (`ifstream`, `ofstream`)
7. **Not checking file open success** — Verify stream state before reading/writing
8. **Using std::string::replace()** — Forbidden in ex04; implement manually
9. **Infinite loops in string replacement** — Handle empty search string
10. **Confusing pointer-to-member-function syntax** — Review `.*` and `->*` operators

---

## Module 01 Checklist

Before submitting, verify:

- [ ] All code compiles with `c++ -Wall -Wextra -Werror -std=c++98`
- [ ] No memory leaks (use Valgrind or `leaks` on macOS)
- [ ] Correct use of `new`/`delete` and `new[]`/`delete[]`
- [ ] Pointers checked for null before dereferencing
- [ ] Reference members initialized in initializer list
- [ ] File streams checked for open success
- [ ] No forbidden functions used (no C file APIs, no `std::string::replace()` in ex04)
- [ ] Destructors print messages for debugging (ex00, ex01)
- [ ] Pointer-to-member-function syntax correct (ex05)
- [ ] Switch statement uses fall-through correctly (ex06)
- [ ] Makefile has correct targets and flags

---

## English Glossary — Module 01

- **Stack allocation**: Automatic memory management; object lifetime tied to scope
- **Heap allocation**: Manual memory management using `new`/`delete`
- **Pointer**: Variable storing a memory address; can be null or reassigned
- **Reference**: Alias for another variable; must be initialized; cannot be reseated
- **new**: Operator allocating memory on heap; calls constructor
- **delete**: Operator deallocating memory; calls destructor
- **new[]**: Array allocation operator
- **delete[]**: Array deallocation operator
- **Memory leak**: Allocated memory never freed
- **RAII**: Resource Acquisition Is Initialization; tying resource lifetime to object lifetime
- **Dereference**: Accessing the value a pointer points to (using `*`)
- **Null pointer**: Pointer pointing to nothing (address 0 or `NULL`)
- **Dangling pointer/reference**: Pointer/reference to memory that has been freed or gone out of scope
- **Member reference**: Reference stored as a class member variable
- **Member pointer**: Pointer stored as a class member variable
- **Initializer list**: Syntax after constructor signature for initializing members
- **ifstream**: Input file stream; for reading files
- **ofstream**: Output file stream; for writing files
- **find()**: Method returning position of substring or `npos`
- **substr()**: Method extracting portion of string
- **npos**: Special constant meaning "not found" (`std::string::npos`)
- **Pointer to member function**: Variable storing address of a class member function
- **Dispatch table**: Array or map associating keys with function pointers
- **.***: Operator invoking pointer to member function on object
- **->***: Operator invoking pointer to member function via pointer to object
- **Switch statement**: Multi-way branch based on value
- **Fall-through**: Execution continuing into next case without `break`

---

## Next Steps

After completing Module 01:

- Understand Orthodox Canonical Form (Module 02)
- Learn about copy constructors and assignment operators (Module 02)
- Explore fixed-point numbers and operator overloading (Module 02)
- Review deep vs. shallow copying
- Prepare for inheritance and polymorphism (Module 03+)


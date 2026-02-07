# C++ Object-Oriented Programming (OOP) Examples

---

This repository contains a collection of C++ programs demonstrating key Object-Oriented Programming (OOP) concepts. Each file focuses on a specific OOP principle or technique, providing clear and concise examples to help learners understand and implement these concepts effectively.


## Table of Contents

- [Project Overview](#project-overview)
- [Files and Descriptions](#files-and-descriptions)
- [Prerequisites](#prerequisites)
- [How to Run](#how-to-run)
- [Key OOP Concepts Covered](#key-oop-concepts-covered)
- [Contributing](#contributing)


## Project Overview
This project serves as an educational resource for students and developers learning OOP using C++. The code examples cover fundamental OOP principles such as encapsulation, inheritance, polymorphism, and abstraction, along with related concepts like constructors, destructors, deep/shallow copying, and the `static` keyword. Each program is well-commented and structured to illustrate a single concept clearly.


## Files and Descriptions
Below is a list of the C++ source files in this repository, each focusing on a specific OOP concept:

| File Name                     | Description                                                                 |
|-------------------------------|-----------------------------------------------------------------------------|
| `abstraction.cpp`             | Demonstrates abstraction using an abstract class with a pure virtual function. |
| `constructor.cpp`             | Shows different types of constructors (non-parameterized, parameterized, and copy) and the use of the `this` keyword. |
| `destructor.cpp`              | Illustrates the use of a destructor to clean up dynamically allocated memory. |
| `encapsulation.cpp`           | Explains encapsulation by wrapping data and methods in a class, using getters and setters. |
| `inheritance.cpp`             | Covers inheritance, including modes (public, private, protected) and types (single, multiple, multilevel, hierarchical, hybrid). |
| `oops.cpp`                    | Introduces basic OOP concepts with a simple `Teacher` class, demonstrating attributes and methods. |
| `polymorphism.cpp`            | Explores compile-time polymorphism (constructor overloading) and introduces virtual functions for runtime polymorphism. |
| `shallow&deepCopy.cpp`        | Compares shallow and deep copying in a class with dynamically allocated memory. |
| `staticKeyword.cpp`           | Demonstrates the use of the `static` keyword for variables and objects, showing their lifetime and scope. |

## Prerequisites
To compile and run the programs in this repository, you need:
- A C++ compiler (e.g., `g++`, part of GCC)
- A development environment (e.g., VS Code, CLion, or any IDE supporting C++)
- Basic knowledge of C++ syntax and OOP concepts

## How to Run
1. **Clone the Repository**: This will clone the complete DSA file
   ```bash
   git clone https://github.com/Sanju-1114/DSA.git

   ```

### Key OOP Concepts Covered
- **Encapsulation:** Bundling data and methods into a class, with access control using private/public modifiers [encapsulation.cpp].
- **Abstraction:** Hiding unnecessary details using abstract classes and pure virtual functions [abstraction.cpp].
- **Inheritance:** Passing properties and methods from a base class to a derived class, with different modes and types [inheritance.cpp].
- **Polymorphism:** Implementing compile-time (constructor overloading) and runtime (virtual functions) polymorphism [polymorphism.cpp].
- **Constructors and Destructors:** Initializing objects with constructors and cleaning up with destructors [constructor.cpp,] [destructor.cpp].
- **Shallow vs. Deep Copy:** Managing dynamic memory during object copying [shallow&deepCopy.cpp].
Static Keyword: Using static for variables and objects to control lifetime and scope [staticKeyword.cpp].   

## Contributing
Contributions are welcome! If you have suggestions for improving the code, adding new examples, or enhancing the documentation, please:

1. Fork the repository.
2. Create a new branch (git checkout -b feature-branch).
3. Make your changes and commit (git commit -m "Add feature").
4. Push to the branch (git push origin feature-branch).
5. Open a pull request.

# AdvCalc Interpreter
Made by:

- Arınç Demir
- Dağlar Eren Tekşen

For our Cmpe230 (Systems Programming) course project 3.

## Purpose
To create a classic memory game which includes matching the cards having the same colors. 

## Usage
In QT Creator, we run the C++ code and game starts. 

## Implementation
We wrote this project in multiple files with one file serving only one purpose to make it easier to understand and debug.

#### colorbutton.h
Declerations and protocoles has been written in that.

#### mygrid.h
The variables about the layout of the grid is included in 

#### colorbutton.cpp
The entry program of the project. Here, our `variableList` is initialized. Inside an infinite while loop, input is taken and fed through `lexer.c` to get the token representation. After that, errors in the expression are checked by feeding the tokens to `error.c`. Then, the variables in the tokens are changed into their respected integer values with `changeVariables(tokens)` in `evaluator.c`. Whether the expression is an assignment or not is checked with `isAssignment(tokens)` in also `evaluator.c`. Finally if it is an assignment it is fed through `assign(tokens)` or else, `evaluate(tokens)`, again, both in `evaluator.c`.

#### main.cpp
In this file, the main function is `getTokens(expr)`. The expression is looped through characterwise in a loop, and tokens are created with the characters' respected tokenTypes. The precedences of the tokens are set if the tokens are operators. Also values of the integers and the names of the variables are taken here, and assigned to their respectful tokens. There are two additional functions `isReservedKeyword(str)`, and `getKeywordType(str)` for determining if a string represents one of the functions such as `lr` and `not`.

#### mygrid.cpp
This file is used to check if the given expression is erronous. If an error exists, the program doesn't terminate, but prints `Error!` There are plenty of error types. Inorder to visualize, there are else-if and the functions that checks whether there is that spesific error type or not.

## Difficulties Encountered
Doing this project, we had to overcome many dificulties, mainly caused by our inexperience with the C language. Here are some dificulties we encountered and how we solved them:
- Memory management: This was our first time that we wrote in a programming language without an included garbage collector. Our first problem occured when we realized that we cannot return variables that we just declared in a function, as it is stored in the stack memory and it is deleted after the function ends. So we got introduced the world of `malloc` and `free`. Now we acted much more careful what we wanted to store in the heap, and remembered to free it.
- Unavailability of OOP: As an oop fan myself, i found it really hard to work with a programming language that did not have objects and the dot notation to call methods. However, after a while I got used to the "C way of doing things", which is passing data as arguments to functions. Now that I am used to that, I actually find it an OK way of doing things.
- Unavailability of basic data types in C: As previous python and java programmers, we were used to finding the data types that we are looking for to be included in the standart libraries. However, it is not the case in C, and we had to write our own data structures. We needed two extra data types for this project:
  - Stack and queue: We implemented a data structure that can be used both as a stack and a queue using a doubly linked list.
  - Table for storing variables: The intuition here is to use a hashmap for O(1) operation cost. However, we found it to be overkill and just opted for an arraylist.
- Using git: We knew that using git to collaboratively develop a project the way to go. However, we did not know the best practices to use it. First, we were commiting into the main branch. After dealing with a few merge problems, we learned to always work on different branches. It worked fine for us, and we were able to complete the project with minimum number of conflicts.
- Error types are really hard to discover. We encounter a new type everyday and add that into our code.

## Conclusion
The AdvCalc Interpreter project is a Python-like interpreter written in C language for the Systems Programming course project. The project is implemented in multiple files, with each file having a specific purpose to make it easier to debug and understand. We created a token structure with three attributes tokenType, value, and name, an array list implementation to match variable names and values, and a hybrid of queue and stack data structure to hold tokens. Additionally, the project includes an error checker to identify erroneous expressions and a series of functions to evaluate expressions.  While implementing the project, we encountered several challenges, such as memory management, the absence of object-oriented programming, and the unavailability of basic data types in C. However, they overcame these challenges by using dynamic memory allocation, passing data as arguments to functions, and careful implementation of data types. Overall, it was a great project that thought us compiler design, working with C and working with a group.

# Memory Game
Made by:

- Arınç Demir
- Dağlar Eren Tekşen

For our Cmpe230 (Systems Programming) course project 3.

## Purpose
To create a classic memory game which includes matching the cards having the same colors. 

## Usage
Open the project in QT Creator and run it. 

## Implementation
We wrote this project in multiple files with one file serving only one purpose to make it easier to understand and debug.

#### colorbutton.h
Declerations and protocoles has been written in that.

#### mygrid.h
The variables about the layout of the grid is included in this file.

#### colorbutton.cpp
There is *pressed()* function. It behaves by the information that how many cards are open.
We chose 15 distinct colors to match. We wrote them in RGB form.

#### main.cpp
We initialized all buttons, text, layout etc. 

#### mygrid.cpp
We checked whether the color match or not in here. Also, the *reset()* function which enables us start all over again is in here.

## Difficulties Encountered
- It was hard to discover the QT library in general. The documentation is hard to understand, and it is hard to find what you are looking for.
- The ui programming prodigm is quite different than the coding we were used to. It took some time to understand and adapt to it.

## Conclusion
It was a fun but challenging project. It was not challenging because it took a long time, but it was hard to understand the ui design concept and it was hard to find how to do things in QT. Overall, we learned a lot about ui creation and game making.

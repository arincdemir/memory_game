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
We created the function declarations and the following data fields:
- `id` for determining the color of the button, and to be able to match them.
- `identifier` that is random to be able to distinguish the buttons.
- `open` to determine if back side of the card is shown.
- `grid` as a reference to the actual game manager object MyGrid

#### mygrid.h
We created the function declarations and the following data fields:
- `score` to hold how many cards have been matched yet.
- `tries` to hold how many tries the player has left.
- `firstShownIdentifier` to determine which button is shown first.
- `secondShownIdentifier` to determine which button is shown second.
- `timerId` to be able to kill the timer that is created.
- `scoreLabel` to hold and be able to make changes on the score label.
- `triesLabel` to hold and be able to make changes on the tries label.

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

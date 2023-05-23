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
- `state` holding how many cards are open right now
- `tries` to hold how many tries the player has left.
- `firstShownIdentifier` to determine which button is shown first.
- `secondShownIdentifier` to determine which button is shown second.
- `timerId` to be able to kill the timer that is created.
- `scoreLabel` to hold and be able to make changes on the score label.
- `triesLabel` to hold and be able to make changes on the tries label.

#### colorbutton.cpp
- `pressed()` updates the cards and grid depending on `state` of the grid. Calls `processTwoShown()` if two cards are shown.
- `showDefaultColor()` shows the card in the default color, which is black
- `showColor()` shows the card in the color defined by its `id`, call this when card is opened.

#### mygrid.cpp
- `reset()` resets the game states. Called in the program beginning and when the reset button is pressed.
- `processTwoShown()` called when two buttons are opened on the screen. Gets the two buttons, and checks if they are the same. If not, a timer is created.
- `loseGame()` called when the player runs out of tries. Pops up a message box and resets the game.
- `winGame()` called when all cards are open. Pops up a message box and resets the game.
- `timerEvent()` is called by the timer created in processTwoShown. Closes the cards.
#### main.cpp
We initialized all buttons, text, layout and connected them here. After that, `app.exec()` is called for the main ui loop. 

## Difficulties Encountered
- It was hard to discover the QT library in general. The documentation is hard to understand, and it is hard to find what you are looking for.
- The ui programming prodigm is quite different than the coding we were used to. It took some time to understand and adapt to it.

## Conclusion
It was a fun but challenging project. It was not challenging because it took a long time, but it was hard to understand the ui design concept and it was hard to find how to do things in QT. Overall, we learned a lot about ui creation and game making.

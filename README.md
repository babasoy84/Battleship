# Battleship

![alt text](https://github.com/babasoy84/Battleship/blob/main/battleship_title.png?raw=true)

A simple battleship game implemented in less than 2000 lines of C++.

# Installation
Just clone this repo and you are ready to rumble.
```sh
~ git clone https://github.com/babasoy84/Battleship.git
```
# Usage
You can now start the game by running:
```sh
~ c++ Source.cpp
```

The gameplay is straightforward. Each player hides ships on a grid containing vertical and horizontal space coordinates. Players take turns calling out row and column coordinates on the other player's grid in an attempt to identify a square that contains a ship. 

The game board each player gets has two grids: an upper and lower grid. The upper grid is used by the player to "hide" the location of his own ships, while the lower grid is used to record the shots fired toward the opponent and to document whether those shots were hits or misses.


| Color            | Meaning        |
|------------------|----------------|
| Black/ white     | Empty Field    |
| Green            | Ship Hit       |
| RED              | Miss           |
| Yellow Rectangle | Cursor         |
| Yellow Circle    | Ship           |


# Notes
If you want to start "hiding" the location of your own ships again, just press the spacebar.You can move the cursor with the arrow keys and you want to select the coordinate on the cursor, you just need to press the enter key.If you manage to hit an enemy ship you get a chance to hit again but otherwise it's the enemy's turn.

| Type of Ship     | Count          |
|------------------|----------------|
| 4 cell           | 2              |
| 3 cell           | 3              |
| 2 cell           | 4              |
| 1 cell           | 5              |

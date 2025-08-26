# Tennis-game-Graphics-and-multimedia


A simple classic Pong game implemented in C using the Turbo C graphics library (graphics.h).
Control the paddles and try to beat your opponent!

Features

Two-player gameplay (left paddle: W/S keys, right paddle: Up/Down arrow keys)

Real-time ball movement with bouncing physics

Score tracking for both players

Simple and clean graphical interface with basic shapes and text

ESC key to quit the game

Controls
Player	Controls
Left Paddle	W (up), S (down)
Right Paddle	Up Arrow, Down Arrow
Quit Game	ESC
How to Run

Make sure you have Turbo C installed or any compatible environment supporting graphics.h.

Compile the pong.c file using Turbo C or a compatible IDE.

Run the compiled executable.

Use the controls to play the game.

Code Overview

The game uses the BGI graphics library for rendering shapes and text.

Paddle positions are updated based on user input.

Ball movement is updated every frame with collision detection against paddles and screen edges.

Scores are incremented when the ball passes a paddle.

Dependencies

Turbo C or any compiler supporting graphics.h

conio.h, stdlib.h, and dos.h for input handling and timing functions

Limitations

Works best in Turbo C environment on Windows.

Not compatible with modern compilers like GCC without modification (due to graphics.h and DOS-specific headers).

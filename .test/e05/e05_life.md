*  Can you help me with "Game of Life" project at 42 School?

---

- Files to turn in: `*.c`, `*.h`
- Allowed functions: atoi, read, putchar, malloc, calloc, realloc, free

Prototype of program: ./life width height iterations
---

Width and height are the dimensions of the board and iterations is the number of generations to simulate.

The initial configuration of the board will be drawn by a sequence of commands in the standard input.

Imagine a pen starting in the top left corner of the board.
Easch command is one of these characters:
  - w a s d -> move the pen up, left, down, right by one cell
  - x -> lift or lower the pen in order to start or stop drawing

- pen no move outside board and stays still if a command ask for it
- pen do nothing in case of invalid command

once end of file is reached, your program must simulate a game of life on board and print the result in stdout (each cell alive will be represented by the '0' character and each dead cell will be represented by a space ' ' character).

- each cell outside of the array will be considered dead

Examples:


```
$> echo 'sdxddssaaww' | ./a.out 5 5 0 | cat -e
     $
 000 $
 0 0 $
 000 $
     $
$> echo 'sdxssdswdxdddxsaddawxwdxwaa' | ./a.out 10 6 0 | cat -e
          $
 0   000  $
 0     0  $
 000  0   $
  0  000  $
          $
$> echo 'dxss' | ./a.out 3 3 0 | cat -e
 0 $
 0 $
 0 $
$> echo 'dxss' | ./a.out 3 3 1 | cat -e
   $
000$
   $
$> echo 'dxss' | ./a.out 3 3 2 | cat -e
 0 $
 0 $
 0 $

```


---

*  Please put comments in the code and give me explanations of what and why is done.


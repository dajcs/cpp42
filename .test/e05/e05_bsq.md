*  Can you help me with "Biggest Square" project at 42 School?

---

- Assignment name: bsq
- Files to turn in: `*.c`, `*.h`
- Allowed functions: `malloc`, `calloc`, ` realloc`, `free`, `fopen`, `fclose`, `getline`, `fscanf`, `fputs`, `fprintf`, `stderr`, `stdout`, `stdin`, `errno`

---

The aim of this program is to find the biggest square on a map, avoiding obstacles.

A file containing the map will be passed as a parameter to your program.
The first line of the file contains:
  - the number of lines of the map,
  - the 'empty' character,
  - the 'obstacle' character,
  - the 'full' character.
The map is made up of 'empty' and 'obstacle' characters only.
The aim of the program is to find the biggest square made up of 'empty' characters and to fill it with the 'full' character.
In the case that more than one solution exists, we'll take the one closest to the top of the map, then to the left of the map.
When the program receives more than one map in arguments, it must solve each one of them in order. Each solution or "map error" must be followed by a newline.
Should there be no passed argument, the program must read from the standard input.

Definition of a valid map:
  - all lines must have the same length
  - there's at least one line of at least one character
  - at each end of line there's a newline character
  - the characters used in the map are only those defined in the first line
  - the map is invalid if a character is missing from the first line, or if two characters (of empty, full and obstacle) are identical.
  - the characters can be any printable characters, even digits.
  - in case of invalid map, the program should display "map error" followed by a newline on the standard output. The program will move then to the next map.


Examples:

```bash
%>cat example_file
9 . o x
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
%>./bsq example_file
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxxo..............
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxx...o...........
.....xxxxxxx...............
......o..............o.....
..o.......o................
%>
```


---

- Please put comments in the code and give me explanations of what and why is done
- Please implement my naive algorithm describeb below:
The struct:

```c
typedef struct s_map
{
    int     rows;           // Total rows defined in header
    int     cols;           // Length of a line
    char    empty;          // Character for empty space
    char    obs;            // Character for obstacle
    char    full;           // Character to fill the square
    char    **grid;         // The 2D map
    int     x0;            // X coordinate of the top-left corner of the biggest square found
    int     y0;            // Y coordinate of the top-left corner of the biggest square found
    int     size;           // Size of the biggest square found
} t_map;
```

The naive algorithm:
1. go to each cell of the map starting from (0,0)
2. for each cell that is empty:
   - record x0, y0, set size to 1
   - loop increasing i from 1 to min(rows - y0, cols - x0)
     - check if map[y0+i][x0+i] is empty
     - check if the new row (y0+i) from x0 to x0+i is empty
     - check if the new column (x0+i) from y0 to y0+i is empty
     - if all checks are ok, set size to i+1
     - if new size is bigger than the recorded size in t_map, update t_map's x0, y0, size
3. after checking all cells, fill the square in the map from (x0, y0) with size 'size' with the 'full' character
4. print the map


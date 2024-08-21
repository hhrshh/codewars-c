#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#define ERR_BUFF_SIZE 4096


// That's terrible! Some evil korrigans have abducted you during your sleep and threw you into a maze of thorns in the scrubland D:
// But have no worry, as long as you're asleep your mind is floating freely in the sky above your body.

// Seeing the whole maze from above in your sleep, can you remember the list of movements you'll have to do to get out when you awake?

// Input
// You are given the whole maze maze as a 2D grid, more specifically in your language:

// a Maze* (a struct with three fields: unsigned height, unsigned width, char **grid) Each line is '\0' terminated,
// but the array of lines is not.
// maze->grid[0][0] is the top left-hand corner.

// maze->grid[maze->height - 1][maze->width - 1] is the bottom right-hand corner.

// Inside this 2D grid:

// ' ' is some walkable space
// '#' is a thorn bush (you can't pass through)
// '^', '<', 'v' or '>' is your sleeping body facing respectively the top, left, bottom or right side of the map.
// Output
// Write the function escape that returns the list/array of moves you need to do relatively to the direction you're
// facing in order to escape the maze (you won't be able to see the map when you wake up). as an array of the following instructions:

// 'F' move one step forward
// 'L' turn left
// 'R' turn right
// 'B' turn back
// Note: 'L','R', and 'B' ONLY perform a rotation and will not move your body

// If the maze has no exit, return NULL.

// This is a real maze, there is no "escape" point. Just reach the edge of the map and you're free!
// You don't explicitely HAVE to find the shortest possible route, but you're quite likely to timeout if you don't ;P
// Aside from having no escape route the mazes will all be valid (they all contain one and only one "body"
// character and no other characters than the body, "#" and " ". Besides, the map will always be rectangular, you don't have to check that either)


/*
** @param maze a valid Maze* (see description) with consistent height, width and grid.
** Note: maze->grid[0][0] is the top left-hand corner and maze->grid[maze->height - 1][maze->width - 1] is the bottom right-hand corner.
** @return a heap-allocated string composed of the instructions 'F', 'R', 'B' and 'L'. NULL if no exit is reachable.
** Note: It is not strictly necessary to null terminate that array of char, but  I recommend doing so,
** both for good practice and to avoid a segfault in my validator if your solution doesn't reach the exit.
*/

typedef struct s_Maze
{
    unsigned height, width;
    char** grid;
}   Maze;


char *escape(const Maze *maze)
{
  char *path;
  const char *my_answer = "FLFRFBFFFF";

  if(maze->grid == NULL) 
    return NULL;
  
  printf("Maze(w: %u, h: %u):\n", maze->width, maze->height);
  for (unsigned int i = 0; i < maze->height; ++i)
    printf("\"%s\"\n", maze->grid[i]);
  printf("\n");
  // Remember that path must be heap-allocated (otherwise you can't safely return it)
  path = (char*)calloc(strlen(my_answer) + 1, sizeof(char));
  if (path == NULL)
    return NULL;
  return strcpy(path, my_answer);
}



int main(void)
{
    return 0;
}
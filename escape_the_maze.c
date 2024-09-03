#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#define HEIGHT 9
#define WIDTH 9

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
  unsigned height; // Высота лабиринта
  unsigned width;  // Ширина лабиринта
  char **grid;     // Двумерный массив для хранения символов лабиринта
} Maze;

// Функция для создания лабиринта
Maze *createMaze(unsigned height, unsigned width)
{
  Maze *maze = malloc(sizeof(Maze)); // Выделяем память под структуру
  if (!maze)
  {
    fprintf(stderr, "Ошибка выделения памяти под лабиринт\n");
    return NULL;
  }

  maze->height = height;
  maze->width = width;

  // Выделение памяти для строк (высоты) массива grid
  maze->grid = malloc(height * sizeof(char *));
  if (!maze->grid)
  {
    fprintf(stderr, "Ошибка выделения памяти под строки лабиринта\n");
    free(maze); // Освобождаем память под структуру, если не удалось выделить память под grid
    return NULL;
  }
//
  // Выделение памяти для каждого столбца (ширины) массива grid
  for (unsigned i = 0; i < height; i++)
  {
    maze->grid[i] = malloc(width * sizeof(char));
    if (!maze->grid[i])
    {
      fprintf(stderr, "Ошибка выделения памяти под столбцы лабиринта\n");
      // Освобождаем ранее выделенную память
      for (unsigned j = 0; j < i; j++)
        free(maze->grid[j]);
      free(maze->grid);
      free(maze);
      return NULL;
    }
  }

  return maze;
}

// Функция для заполнения лабиринта
void fillMaze(Maze *maze, char fillChar[HEIGHT][WIDTH])
{
  for (unsigned i = 0; i < maze->height; ++i)
    for (unsigned j = 0; j < maze->width; ++j)
      maze->grid[i][j] = fillChar[i][j]; // Заполняем лабиринт символом fillChar
}

// Функция для вывода лабиринта на экран
void printMaze(Maze *maze)
{
  printf("Maze(w: %u, h: %u):\n", maze->width, maze->height);
  for (unsigned int i = 0; i < maze->height; ++i)
    printf("\"%s\"\n", maze->grid[i]);
  printf("\n");
}

//----------------------------------------------------------------------------------------------------------------------------- Рекурсивная функция

char *go(const Maze *maze, int x, int y, char z, char *way)
{
  char *path = NULL;
  path = (char*)malloc(254 * sizeof(char));
  // идем вперед
  if(maze->grid[x][++y] == ' ')
    go();
  // идем назад
  if(maze->grid[x][--y] == ' ')
    go();
  // идем вверх
  if(maze->grid[++x][y] == ' ')
    go();
  // идем вниз
  if(maze->grid[--x][y] == ' ')
    go();
}




//---------------------------------------------------------------------------------------------------------------------------- Функция показывает выход из лабиринта
char *escape(const Maze *maze)
{
  int pos_x = -1, pos_y = -1; // начальные координаты
  char pos_z = 'z'; // положение
  char *path = NULL;
  char way[maze->height][maze->width];

  char *my_answer = "FLFRFBFFFF";

  if(maze->grid == NULL)
    return NULL;

  // Ищем положение и копирем лабиринт из структуры во временный буфер way[][]
  for (unsigned i = 0; i < maze->height; ++i)
    for (unsigned j = 0; j < maze->width; ++j)
    {
      way[i][j] = maze->grid[i][j];
      if(maze->grid[i][j] == '^' || maze->grid[i][j] == '>' || maze->grid[i][j] == 'v' || maze->grid[i][j] == '<')
      {
        pos_x = i;
        pos_y = j;
        pos_z = maze->grid[i][j];
        printf("X = %d Y = %d\n", i, j);
      }
    }

  // идем вперед
  for (unsigned i = pos_x; i < maze->height; ++i)
  {
    //
  }

  // идем назад
  for (unsigned i = pos_x; i >= 0; --i)
  {
    //
  }

  // идем вверх
  for (unsigned j = pos_y; j < maze->width; ++j)
  {
    //
  }

  // идем вниз
  for (unsigned j = 0; j >= 0; --j)
  {
    //
  }



  // Remember that path must be heap-allocated (otherwise you can't safely return it)
  path = (char*)calloc(strlen(my_answer) + 1, sizeof(char));
  if(path == NULL)
    return NULL;
  return strcpy(path, my_answer);
}
//---------------------------------------------------------------------------------------------------------------------------- Функция показывает выход из лабиринта

// Функция для освобождения памяти
void freeMaze(Maze *maze)
{
  for (unsigned i = 0; i < maze->height; i++)
    free(maze->grid[i]); // Освобождаем память под каждый столбец
  free(maze->grid); // Освобождаем память под массив grid
  free(maze);       // Освобождаем память под саму структуру Maze
}



int main(void)
{
  unsigned height = HEIGHT, width = WIDTH;
  char fillChar[HEIGHT][WIDTH] = {{' ',' ','#','#','#','#','#',' ',' '},
                                  {' ','#',' ',' ',' ',' ',' ','#',' '},
                                  {'#',' ',' ',' ',' ',' ',' ',' ','#'},
                                  {'#',' ',' ',' ',' ',' ',' ',' ','#'},
                                  {'#',' ',' ',' ','^',' ',' ',' ','#'},
                                  {' ','#',' ',' ',' ',' ',' ','#',' '},
                                  {' ',' ','#',' ',' ',' ','#',' ',' '},
                                  {' ',' ',' ','#',' ','#',' ',' ',' '},
                                  {' ',' ',' ',' ','#',' ',' ',' ',' '}};

  Maze *maze = createMaze(height, width); // Создаем лабиринт
  if (!maze)
    return 1; // Выход в случае ошибки создания лабиринта

  fillMaze(maze, fillChar); // Заполняем лабиринт
  printMaze(maze);     // Выводим лабиринт на экран
  printf("%s\n", escape(maze)); // Выводим выход из лабиринта
  freeMaze(maze); // Освобождаем память
  return 0;
}



// {{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
//                                   {'#','<',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#'},
//                                   {'#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#'},
//                                   {'#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#'},
//                                   {'#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#','#','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#'},
//                                   {'#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#'},
//                                   {'#','#','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#','#','#','#','#'},
//                                   {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#'},
//                                   {'#',' ','#',' ','#','#','#','#','#','#','#',' ','#','#','#',' ','#','#','#',' ','#','#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#','#','#','#','#',' ','#'},
//                                   {'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#'},
//                                   {'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','#',' ','#','#','#','#','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#'},
//                                   {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#'},
//                                   {'#','#','#','#','#',' ','#','#','#','#','#','#','#',' ','#',' ','#','#','#','#','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#','#','#'},
//                                   {'#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#'},
//                                   {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#','#','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#'},
//                                   {'#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#'},
//                                   {'#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#','#','#','#','#','#','#',' ','#',' ','#'},
//                                   {'#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#'},
//                                   {'#',' ','#','#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#'},
//                                   {'#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' '},
//                                   {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
// #define HEIGHT 21
// #define WIDTH 41


// {{'#',' ','#'}, // Карта лабиринта
//                                   {' ','>',' '},
//                                   {'#',' ','#'}};
// #define HEIGHT 3
// #define WIDTH 3




// {{' ',' ','#','#','#','#','#',' ',' '},
//                                   {' ','#',' ',' ',' ',' ',' ','#',' '},
//                                   {'#',' ',' ',' ',' ',' ',' ',' ','#'},
//                                   {'#',' ',' ',' ',' ',' ',' ',' ','#'},
//                                   {'#',' ',' ',' ','^',' ',' ',' ','#'},
//                                   {' ','#',' ',' ',' ',' ',' ','#',' '},
//                                   {' ',' ','#',' ',' ',' ','#',' ',' '},
//                                   {' ',' ',' ','#',' ','#',' ',' ',' '},
//                                   {' ',' ',' ',' ','#',' ',' ',' ',' '}};

// #define HEIGHT 9
// #define WIDTH 9
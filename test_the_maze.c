#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

#define HEIGHT 8
#define WIDTH 10



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
typedef struct {
    unsigned height; // Высота лабиринта
    unsigned width;  // Ширина лабиринта
    char **grid;     // Сетка лабиринта
} Maze;

typedef struct {
    int x, y; // Текущая позиция
    int dir;  // Текущее направление (0: вверх, 1: вправо, 2: вниз, 3: влево)
    char *moves; // Движения, сделанные для достижения этой позиции
} State;

// Массив направлений
const int directions[4][2] = {
    {-1, 0}, // Вверх
    {0, 1},  // Вправо
    {1, 0},  // Вниз
    {0, -1}  // Влево
};


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

// Функция для побега из лабиринта
char* escape(Maze *maze) {
    // Находим начальную позицию и направление
    int startX, startY, startDir;
    for (unsigned i = 0; i < maze->height; i++) {
        for (unsigned j = 0; j < maze->width; j++) {
            if (maze->grid[i][j] == '^') {
                startX = i; startY = j; startDir = 0; // Вверх
            } else if (maze->grid[i][j] == '>') {
                startX = i; startY = j; startDir = 1; // Вправо
            } else if (maze->grid[i][j] == 'v') {
                startX = i; startY = j; startDir = 2; // Вниз
            } else if (maze->grid[i][j] == '<') {
                startX = i; startY = j; startDir = 3; // Влево
            }
        }
    }

    // Настройка BFS
    State *queue = malloc(maze->height * maze->width * 4 * sizeof(State));
    int front = 0, back = 0;
    char **visited = malloc(maze->height * sizeof(char*));
    for (unsigned i = 0; i < maze->height; i++) {
        visited[i] = calloc(maze->width * 4, sizeof(char)); // 4 направления
    }

    // Начальное состояние
    queue[back++] = (State){startX, startY, startDir, ""};
    visited[startX][startY * 4 + startDir] = 1;

    // Основной цикл BFS
    while (front < back) {
        State current = queue[front++];
        
        // Проверяем, находимся ли мы на краю лабиринта
        if (current.x == 0 || current.x == maze->height - 1 || current.y == 0 || current.y == maze->width - 1) {
            return strdup(current.moves); // Возвращаем последовательность движений
        }

        // Двигаемся вперед
        int newX = current.x + directions[current.dir][0];
        int newY = current.y + directions[current.dir][1];
        if (newX >= 0 && newX < maze->height && newY >= 0 && newY < maze->width && maze->grid[newX][newY] == ' ' && !visited[newX][newY * 4 + current.dir]) {
            visited[newX][newY * 4 + current.dir] = 1;
            char *newMoves = malloc(strlen(current.moves) + 2);
            sprintf(newMoves, "%sF", current.moves);
            queue[back++] = (State){newX, newY, current.dir, newMoves};
        }

        // Поворот налево
        int leftDir = (current.dir + 3) % 4;
        if (!visited[current.x][current.y * 4 + leftDir]) {
            visited[current.x][current.y * 4 + leftDir] = 1;
            char *newMoves = malloc(strlen(current.moves) + 2);
            sprintf(newMoves, "%sL", current.moves);
            queue[back++] = (State){current.x, current.y, leftDir, newMoves};
        }

        // Поворот направо
        int rightDir = (current.dir + 1) % 4;
        if (!visited[current.x][current.y * 4 + rightDir]) {
            visited[current.x][current.y * 4 + rightDir] = 1;
            char *newMoves = malloc(strlen(current.moves) + 2);
            sprintf(newMoves, "%sR", current.moves);
            queue[back++] = (State){current.x, current.y, rightDir, newMoves};
        }

        // Поворот назад
        int backDir = (current.dir + 2) % 4;
        if (!visited[current.x][current.y * 4 + backDir]) {
            visited[current.x][current.y * 4 + backDir] = 1;
            char *newMoves = malloc(strlen(current.moves) + 2);
            sprintf(newMoves, "%sB", current.moves);
            queue[back++] = (State){current.x, current.y, backDir, newMoves};
        }
    }

    // Освобождаем память
    for (unsigned i = 0; i < maze->height; i++) {
        free(visited[i]);
    }
    free(visited);
    free(queue);
    return NULL; // Выход не найден
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
  char fillChar[HEIGHT][WIDTH] = {{'#','#','#','#','#','#','#','#','#','#'},
                                  {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                                  {'#',' ',' ','#','#','#','#','#',' ','#'},
                                  {'#',' ',' ','#',' ',' ',' ','#',' ','#'},
                                  {'#',' ',' ','#','^','#',' ','#',' ','#'},
                                  {'#',' ',' ','#','#','#',' ','#',' ','#'},
                                  {'#',' ',' ',' ',' ',' ',' ','#',' ','#'},
                                  {'#','#','#','#','#','#','#','#',' ','#'}};






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

// {{'#','#','#','#','#','#','#','#','#','#'},
//                                   {'#','>',' ',' ',' ',' ',' ',' ',' ','#'},
//                                   {'#','#','#','#','#','#','#','#',' ','#'}};
// #define HEIGHT 3
// #define WIDTH 10
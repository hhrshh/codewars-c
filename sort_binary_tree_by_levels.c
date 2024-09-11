#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <malloc.h>

// You are given a binary tree:

// typedef struct Tree {
//     struct Tree *left, *right;
//     int value;
// } Tree;
// Your task is to return the list with elements from tree sorted by levels, which means the root element goes first,
// then root children (from left to right) are second and third, and so on.

// Set tree_size to 0 if root is NULL.

// Example 1 - following tree:

//                  2
//             8        9
//           1  3     4   5
// Should return following list:

// [2,8,9,1,3,4,5]
// Example 2 - following tree:

//                  1
//             8        4
//               3        5
//                          7
// Should return following list:

// [1,8,4,3,5,7]



typedef struct Tree
{
    struct Tree *left,
        *right;
    int value;
} Tree;




/* ========================TESTS======================= */

//Создание узла
Tree* create_root(int value)
{
    Tree* node = NULL;
    node = (Tree*)malloc(sizeof(Tree));
    if(node == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
        node->left = NULL;
        node->right = NULL;
        node->value = value;
        return node;

}
//Вставка узла
Tree* insert_node(Tree* node, int value)
{
    if(node == NULL)
    {
        return create_root(value);
    }
    if(value < node->value)
    {
        node->left = insert_node(node->left, value);
    }
    else
    {
        node->right = insert_node(node->right, value);
    }
    return node;   
}
//Удаление дерева
Tree* free_tree(Tree* node)
{
    if(node != NULL)
    {
        free(node->left);
        free(node->right);
    }
    free(node);
}
/* ==================================================== */



// void CurrentLevel(Tree* node, int level)
// {
//     if(node == NULL)
//         return;
//     if(level == 1)
//         printf("%d ", node->value);
//     else if (level > 1)
//     {
//         CurrentLevel(node -> left, level - 1);
//         CurrentLevel(node -> right, level - 1);
//     }
// }

// int height(Tree* node)
// {
//   if (node == NULL)
//     return 0;
//   else {
//     int lheight = height(node->left);
//     int rheight = height(node -> right);
//     if (lheight > rheight)
//       return (lheight + 1);
//     else return (rheight + 1);
//   }
// }

// void LevelOrder(Tree* node)
// {
//     int h = height(node);
//     int i;
//     for (i = 1; i <= h; i++)
//         CurrentLevel(node, i);
// }


// Функция для обхода бинарного дерева в уровне с использованием массива
void levelOrder(Tree* root) {
    if (root == NULL) {
        return;
    }

    // Максимальный размер дерева (можно увеличить при необходимости)
    int capacity = 100;
    Tree** queue = (Tree**)malloc(capacity * sizeof(Tree*));
    int front = 0;
    int rear = 0;

    // Добавляем корень в очередь
    queue[rear++] = root;

    while (front < rear) {
        Tree* current = queue[front++]; // Извлекаем узел из очереди
        printf("%d ", current->value);

        // Добавляем левое поддерево в очередь
        if (current->left != NULL) {
            if (rear >= capacity) {
                // Увеличиваем размер массива, если необходимо
                capacity *= 2;
                queue = (Tree**)realloc(queue, capacity * sizeof(Tree*));
            }
            queue[rear++] = current->left;
        }

        // Добавляем правое поддерево в очередь
        if (current->right != NULL) {
            if (rear >= capacity) {
                // Увеличиваем размер массива, если необходимо
                capacity *= 2;
                queue = (Tree**)realloc(queue, capacity * sizeof(Tree*));
            }
            queue[rear++] = current->right;
        }
    }

    // Освобождение памяти для очереди
    free(queue);
}



// int *tree_by_levels(const Tree *tree, size_t *tree_size)
// {
//     int* answer = NULL;
//     answer = (int*)malloc(*tree_size * sizeof(int));
//         if(answer == NULL)
//         {
//             fprintf(stderr, "Memory allocation error!");
//             exit(EXIT_FAILURE);
//         }
    
//     *tree_size = *tree_size; // report the tree size
//     return NULL; // return a heap-allocated array, it will be freed
// }



int main(void)
{
    Tree* node = NULL;
    size_t tree_size = 8;
    node = insert_node(node, 2);
    insert_node(node, 8);
    insert_node(node, 9);
    insert_node(node, 4);
    insert_node(node, 3);
    insert_node(node, 1);
    insert_node(node, 5);
    levelOrder(node);
    free_tree(node);


    return 0;
}
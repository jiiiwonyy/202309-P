#include <time.h>
#define MAX_TASKS 20
#define CHAR_NUM 100
#define DATE_LENGTH 11

struct Todo {
    char task[CHAR_NUM];
    char date[DATE_LENGTH];
};

void manageTodoList();
void addTodo(struct Todo tasks[MAX_TASKS], int* taskCount);
void deleteTodo(struct Todo tasks[MAX_TASKS], int* taskCount);
void modifyTodo(struct Todo tasks[MAX_TASKS], int* taskCount);
void displayTodo(char tasks[MAX_TASKS][CHAR_NUM], int taskCount);
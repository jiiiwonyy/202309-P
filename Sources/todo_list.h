#include <time.h>
#define MAX_TASKS 20
#define CHAR_NUM 100
#define DATE_LENGTH 11

struct Todo {
    char task[CHAR_NUM];
    char deadline[DATE_LENGTH];
};

void manageTodoList();
void addTodo(struct Todo tasks[MAX_TASKS], int* taskCount);
void deleteTodo(struct Todo tasks[MAX_TASKS], int* taskCount);
void modifyTodo(struct Todo tasks[MAX_TASKS], int* taskCount);
void displayTodo(struct Todo tasks[MAX_TASKS], int taskCount);
int calculateDday(const char* deadline);
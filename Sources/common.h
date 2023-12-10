#define MAX_LENGTH 50
#define MAX_ASSIGNMENTS 10

struct Todo {
    char todoName[MAX_LENGTH];
    int dueDate;
};

struct Course {
    char className[MAX_LENGTH];
    char professorName[MAX_LENGTH];
    char classPlace[MAX_LENGTH];
    double grade;
};
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50
#define MAX_ASSIGNMENTS 10

struct Assignment {
    char assignmentName[MAX_LENGTH];
    int dueDate;
};

struct Course {
    char className[MAX_LENGTH];
    char professorName[MAX_LENGTH];
    char classPlace[MAX_LENGTH];
    double grade;
    struct Assignment* assignments;
    int assignmentCount;
};

void manageTimetable(struct Course** timetable, int* hakjum);
void manageGrades(struct Course* timetable, int hakjum, double* goalGrade);
void displayTimetable(struct Course* timetable, int hakjum);
void displayGradeTimetable(struct Course* timetable, int hakjum);
void displayAssignment(struct Course* timetable, int hakjum);
void manageAssignments(struct Course* timetable, int hakjum);



#include "todo_list.h"
#include "common.h"
#include <stdio.h>

void manageTodoList(struct Course* timetable, int hakjum) {

    int index = 0;

    printf("\n���� ����Ʈ �Դϴ�.\n");
    printf("----------------------------------\n");
    printf("�ؾ��� ���� �߰�/���� �ϼ���.\n");

    int menu=0;

    do {
        printf("\n-------------------------------\n");
        printf("1. �ؾ��� �� �߰��ϱ�\n");
        printf("2. �ؾ��� �� �����ϱ�\n");
        printf("3. ��������\n");
        scanf_s("%d", &menu);


        switch (menu) {
        case 1:
            // �ؾ��� �� �߰�
            

        case 2:
            // �ؾ��� �� ����
           
        }
    
        displayTodo(timetable, hakjum);
    } while (menu != 3);


}

void addTodo(struct Course* timetable) {
    
}

void deleteTodo(struct Course* timetable) {
    
}


void displayTodo(struct Course* timetable, int hakjum) {
    
}


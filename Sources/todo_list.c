#include "todo_list.h"
#include "common.h"
#include <stdio.h>

void manageTodoList(struct Todo** todoList) {

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
    
        displayTodo();
    } while (menu != 3);


}

void addTodo() {
    
}

void deleteTodo() {
    
}


void displayTodo() {
    
}


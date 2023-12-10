#include "todo_list.h"
#include "common.h"
#include <stdio.h>

void manageTodoList(struct Todo** todoList) {

    int index = 0;

    printf("\n투두 리스트 입니다.\n");
    printf("----------------------------------\n");
    printf("해야할 일을 추가/삭제 하세요.\n");

    int menu=0;

    do {
        printf("\n-------------------------------\n");
        printf("1. 해야할 일 추가하기\n");
        printf("2. 해야할 일 삭제하기\n");
        printf("3. 이전으로\n");
        scanf_s("%d", &menu);


        switch (menu) {
        case 1:
            // 해야할 일 추가
            

        case 2:
            // 해야할 일 삭제
           
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


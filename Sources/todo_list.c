#include "todo_list.h"
#include "common.h"
#include <stdio.h>
#include <time.h>

void manageTodoList() {
    char tasks[MAX_TASKS][CHAR_NUM] = { "" };
    int taskCount = 0;

    printf("\n투두 리스트 입니다.\n");
    printf("----------------------------------\n");
    printf("할 일을 추가/삭제 하세요.\n");

    int menu = -1;
    while (1) {

        int terminate = 0;

        printf("\n-------------------------------\n");
        printf("1. 할 일 추가하기\n");
        printf("2. 할 일 삭제하기\n");
        printf("3. 할 일 수정\n");
        printf("4. 이전으로\n");
        scanf_s("%d", &menu);

        switch (menu) {
        case 1:
            addTodo(tasks, &taskCount);
            break;

        case 2:
            deleteTodo(tasks, &taskCount);
            break;

        case 3:
            modifyTodo(tasks, &taskCount);
            break;

        case 4:
            terminate = 1;
            break;

        default:
            printf("잘못된 범위입니다.\n");
            break;
        }

        displayTodo(tasks, taskCount);

        if (terminate == 1) {
            break;
        }
    }
}

void addTodo(struct Todo tasks[MAX_TASKS], int* taskCount) {
    printf("할 일을 입력하세요: ");
    scanf_s("%s", tasks[*taskCount].task, (int)sizeof(tasks[*taskCount].task));
    printf("할 일 \"%s\" 가 저장 되었습니다.\n\n", tasks[*taskCount].task);
    (*taskCount)++;
}

void deleteTodo(struct Todo tasks[MAX_TASKS], int* taskCount) {
    int delIndex = -1;

    printf("삭제할 할 일의 번호를 입력하세요(1부터 시작): ");
    scanf_s("%d", &delIndex);

    if (delIndex > *taskCount || delIndex <= 0) {
        printf("삭제 범위가 벗어났습니다.\n");
    }
    else {
        printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1].task);
        for (int i = delIndex; i < *taskCount; i++) {
            tasks[i - 1] = tasks[i];
        }
        (*taskCount)--;
    }
}

void modifyTodo(struct Todo tasks[MAX_TASKS], int* taskCount) {
    int changeIndex = -1;

    printf("수정할 할 일의 번호를 입력하세요. (1부터 시작): ");
    scanf_s("%d", &changeIndex);

    if (changeIndex > *taskCount || changeIndex <= 0) {
        printf("수정 범위가 벗어났습니다.\n");
    }
    else {
        printf("%d. %s : 할 일을 수정합니다.\n", changeIndex, tasks[changeIndex - 1].task);
        printf("수정할 내용을 입력하세요\n");
        scanf_s("%s", tasks[changeIndex - 1].task, (int)sizeof(tasks[changeIndex - 1].task));
        printf("%d번 할 일이 %s으로 수정되었습니다.\n", changeIndex, tasks[changeIndex - 1].task);
    }
}

void displayTodo(char tasks[MAX_TASKS][CHAR_NUM], int taskCount) {
    printf("\n투두 리스트 입니다.\n");
    printf("----------------------------------\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
    printf("\n");
}





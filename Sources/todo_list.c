#include "todo_list.h"
#include "common.h"
#include <stdio.h>
#include <time.h>

void manageTodoList() {
    char tasks[MAX_TASKS][CHAR_NUM] = { "" };
    int taskCount = 0;

    printf("\n���� ����Ʈ �Դϴ�.\n");
    printf("----------------------------------\n");
    printf("�� ���� �߰�/���� �ϼ���.\n");

    int menu = -1;
    while (1) {

        int terminate = 0;

        printf("\n-------------------------------\n");
        printf("1. �� �� �߰��ϱ�\n");
        printf("2. �� �� �����ϱ�\n");
        printf("3. �� �� ����\n");
        printf("4. ��������\n");
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
            printf("�߸��� �����Դϴ�.\n");
            break;
        }

        displayTodo(tasks, taskCount);

        if (terminate == 1) {
            break;
        }
    }
}

void addTodo(struct Todo tasks[MAX_TASKS], int* taskCount) {
    printf("�� ���� �Է��ϼ���: ");
    scanf_s("%s", tasks[*taskCount].task, (int)sizeof(tasks[*taskCount].task));
    printf("�� �� \"%s\" �� ���� �Ǿ����ϴ�.\n\n", tasks[*taskCount].task);
    (*taskCount)++;
}

void deleteTodo(struct Todo tasks[MAX_TASKS], int* taskCount) {
    int delIndex = -1;

    printf("������ �� ���� ��ȣ�� �Է��ϼ���(1���� ����): ");
    scanf_s("%d", &delIndex);

    if (delIndex > *taskCount || delIndex <= 0) {
        printf("���� ������ ������ϴ�.\n");
    }
    else {
        printf("%d. %s : �� ���� �����մϴ�.\n", delIndex, tasks[delIndex - 1].task);
        for (int i = delIndex; i < *taskCount; i++) {
            tasks[i - 1] = tasks[i];
        }
        (*taskCount)--;
    }
}

void modifyTodo(struct Todo tasks[MAX_TASKS], int* taskCount) {
    int changeIndex = -1;

    printf("������ �� ���� ��ȣ�� �Է��ϼ���. (1���� ����): ");
    scanf_s("%d", &changeIndex);

    if (changeIndex > *taskCount || changeIndex <= 0) {
        printf("���� ������ ������ϴ�.\n");
    }
    else {
        printf("%d. %s : �� ���� �����մϴ�.\n", changeIndex, tasks[changeIndex - 1].task);
        printf("������ ������ �Է��ϼ���\n");
        scanf_s("%s", tasks[changeIndex - 1].task, (int)sizeof(tasks[changeIndex - 1].task));
        printf("%d�� �� ���� %s���� �����Ǿ����ϴ�.\n", changeIndex, tasks[changeIndex - 1].task);
    }
}

void displayTodo(char tasks[MAX_TASKS][CHAR_NUM], int taskCount) {
    printf("\n���� ����Ʈ �Դϴ�.\n");
    printf("----------------------------------\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
    printf("\n");
}





#include "todo_list.h"
#include "common.h"
#include <stdio.h>
#include <time.h>

struct tm current_tm;

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
    fflush(stdin);


    printf("�� ���� �Է��ϼ���: ");
    scanf_s("%s", tasks[*taskCount].task, (int)sizeof(tasks[*taskCount].task));

    printf("���� ��¥�� �Է��ϼ���(yyyy-mm-dd): ");
    scanf_s("%s", tasks[*taskCount].deadline, (int)sizeof(tasks[*taskCount].deadline));

    int year, month, day;
    if (sscanf_s(tasks[*taskCount].deadline, "%d-%d-%d", &year, &month, &day) != 3) {
        printf("��¥ ������ �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���.\n\n");
        return;
    }

    printf("�� �� \"%s\" �� ����Ǿ����ϴ�.\n\n", tasks[*taskCount].task);

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

        for (int i = delIndex - 1; i < *taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
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

void displayTodo(struct Todo tasks[MAX_TASKS], int taskCount) {
    printf("\n���� ����Ʈ �Դϴ�.\n");
    printf("----------------------------------\n");

    for (int i = 0; i < taskCount; i++) {
        int dday = calculateDday(tasks[i].deadline);

        if (dday > 0) {
            printf("%d. %s (����: %d��)\n", i + 1, tasks[i].task, dday);
        }
        else if (dday == 0) {
            printf("%d. %s (���ñ����Դϴ�!)\n", i + 1, tasks[i].task);
        }
        else {
            printf("%d. %s (�������� �������ϴ�.)\n", i + 1, tasks[i].task);
        }
    }
    printf("\n");
}

int calculateDday(const char* deadline) {
    struct tm current_tm = { 0 };
    time_t current_time = time(NULL);
    localtime_s(&current_tm, &current_time);

    // ���� ��¥�� �ð� ���� �ʱ�ȭ
    current_tm.tm_hour = 0;
    current_tm.tm_min = 0;
    current_tm.tm_sec = 0;

    // ���� ��¥ ����
    struct tm deadline_tm = { 0 };
    int year, month, day;
    if (sscanf_s(deadline, "%d-%d-%d", &year, &month, &day) == 3) {
        deadline_tm.tm_year = year - 1900; // tm_year�� 1900���� �������� �ϹǷ� 1900�� ���ݴϴ�.
        deadline_tm.tm_mon = month - 1;    // tm_mon�� 0���� �����ϹǷ� 1�� ���ݴϴ�.
        deadline_tm.tm_mday = day;
    }

    // ���� ��¥�� �ð� ���� �ʱ�ȭ
    deadline_tm.tm_hour = 0;
    deadline_tm.tm_min = 0;
    deadline_tm.tm_sec = 0;

    time_t current_day_start = mktime(&current_tm);
    time_t deadline_day_start = mktime(&deadline_tm);

    // ���� ���
    double dday_seconds = difftime(deadline_day_start, current_day_start);
    int dday_days = (int)(dday_seconds / (60 * 60 * 24));

    return dday_days;
}





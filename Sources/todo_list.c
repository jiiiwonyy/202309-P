#include "todo_list.h"
#include "common.h"
#include <stdio.h>
#include <time.h>

struct tm current_tm;

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
    fflush(stdin);


    printf("할 일을 입력하세요: ");
    scanf_s("%s", tasks[*taskCount].task, (int)sizeof(tasks[*taskCount].task));

    printf("마감 날짜를 입력하세요(yyyy-mm-dd): ");
    scanf_s("%s", tasks[*taskCount].deadline, (int)sizeof(tasks[*taskCount].deadline));

    int year, month, day;
    if (sscanf_s(tasks[*taskCount].deadline, "%d-%d-%d", &year, &month, &day) != 3) {
        printf("날짜 형식이 잘못되었습니다. 다시 입력해주세요.\n\n");
        return;
    }

    printf("할 일 \"%s\" 가 저장되었습니다.\n\n", tasks[*taskCount].task);

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

        for (int i = delIndex - 1; i < *taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
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

void displayTodo(struct Todo tasks[MAX_TASKS], int taskCount) {
    printf("\n투두 리스트 입니다.\n");
    printf("----------------------------------\n");

    for (int i = 0; i < taskCount; i++) {
        int dday = calculateDday(tasks[i].deadline);

        if (dday > 0) {
            printf("%d. %s (디데이: %d일)\n", i + 1, tasks[i].task, dday);
        }
        else if (dday == 0) {
            printf("%d. %s (오늘까지입니다!)\n", i + 1, tasks[i].task);
        }
        else {
            printf("%d. %s (마감일이 지났습니다.)\n", i + 1, tasks[i].task);
        }
    }
    printf("\n");
}

int calculateDday(const char* deadline) {
    struct tm current_tm = { 0 };
    time_t current_time = time(NULL);
    localtime_s(&current_tm, &current_time);

    // 현재 날짜의 시간 정보 초기화
    current_tm.tm_hour = 0;
    current_tm.tm_min = 0;
    current_tm.tm_sec = 0;

    // 마감 날짜 설정
    struct tm deadline_tm = { 0 };
    int year, month, day;
    if (sscanf_s(deadline, "%d-%d-%d", &year, &month, &day) == 3) {
        deadline_tm.tm_year = year - 1900; // tm_year는 1900년을 기준으로 하므로 1900을 빼줍니다.
        deadline_tm.tm_mon = month - 1;    // tm_mon은 0부터 시작하므로 1을 빼줍니다.
        deadline_tm.tm_mday = day;
    }

    // 마감 날짜의 시간 정보 초기화
    deadline_tm.tm_hour = 0;
    deadline_tm.tm_min = 0;
    deadline_tm.tm_sec = 0;

    time_t current_day_start = mktime(&current_tm);
    time_t deadline_day_start = mktime(&deadline_tm);

    // 디데이 계산
    double dday_seconds = difftime(deadline_day_start, current_day_start);
    int dday_days = (int)(dday_seconds / (60 * 60 * 24));

    return dday_days;
}





#include "function.h"
#include <stdlib.h>
#include <stdio.h>


//시간표 관리 함수
void manageTimetable(struct Course** timetable, int* hakjum) {

    // 시간표 출력
    displayTimetable(*timetable, *hakjum);

    // 시간표 수정
    printf("\n1. 수업 추가\n2. 수업 삭제\n3. 이전으로\n");
    printf("원하는 번호를 입력하세요.\n");

    int option = 0;
    scanf_s("%d", &option);

    if (option == 1) {
        // 수업 추가
        printf("추가할 수업의 수업명, 교수명, 장소명을 차례대로 입력하세요. (띄어쓰기로 구분)\n");
        scanf_s("%s %s %s", (*timetable)[*hakjum].className, MAX_LENGTH, (*timetable)[*hakjum].professorName, MAX_LENGTH, (*timetable)[*hakjum].classPlace, MAX_LENGTH);
        (*hakjum)++;
        printf("수업이 추가되었습니다.\n");
    }
    else if (option == 2) {
        // 수업 삭제
        if (*hakjum > 0) {
            printf("삭제할 수업의 번호를 입력하세요 (1부터 시작)\n");
            int courseNumber = 0;
            scanf_s("%d", &courseNumber);

            if (courseNumber >= 1 && courseNumber <= *hakjum) {
                for (int i = courseNumber - 1; i < *hakjum - 1; i++) {
                    (*timetable)[i] = (*timetable)[i + 1];
                }
                (*hakjum)--;
                printf("수업이 삭제되었습니다.\n");
            }
            else {
                printf("잘못된 번호입니다.\n");
            }
        }
        else {
            printf("현재 수업이 없어 삭제할 수 없습니다.\n");
        }
    }
    else if (option == 3) {
        // 다시 메인메뉴 보이게 함
    }
    else {
        printf("잘못된 번호입니다.\n");
    }
}

//성적 관리 함수
void manageGrades(struct Course* timetable, int hakjum, double* goalGrade) {
    int setGrade = 0;
    int option = 0;

    while (1) {
        printf("\n\n성적관리 프로그램\n---------------------\n");
        printf("1. 목표성적 입력 및 수정\n2. 각 수업 별 성적 입력 및 수정\n3. 성적분석\n4. 이전으로\n");
        scanf_s("%d", &option);

        // 목표 성적 입력 및 수정
        if (option == 1) {
            if (!setGrade) {
                printf("목표 성적을 입력하세요: ");
                scanf_s("%lf", goalGrade);
                printf("당신의 목표 성적은 %.2lf 입니다.", *goalGrade);
                setGrade = 1;
            }
            else {
                printf("수정할 목표 성적을 입력하세요.\n");
                scanf_s("%lf", goalGrade);
                printf("수정한 당신의 목표 성적은 %.2lf입니다.", *goalGrade);
            }
        }

        // 각 과목 별 목표 성적 입력 및 수정
        else if (option == 2) {
            for (int i = 0; i < hakjum; i++) {
                printf("%s 과목의 성적을 입력하세요: \n", timetable[i].className);
                scanf_s("%lf", &timetable[i].grade);
            }
            displayGradeTimetable(timetable, hakjum);
        }

        // 목표 성적과 현재 성적 비교
        else if (option == 3) {
            printf("목표 성적: %.2lf\n", *goalGrade);
            double currentGrade = 0.0;
            double sum = 0.0;

            for (int i = 0; i < hakjum; i++) {
                sum += timetable[i].grade;
            }

            currentGrade = sum / hakjum;

            if (sum != 0.0) {
                printf("현재 당신의 성적: %.2lf\n", currentGrade);

                if (*goalGrade > currentGrade) {
                    printf("목표 성적까지 %.2lf만큼 남았습니다.\n", *goalGrade - currentGrade);
                    printf("조금 더 열심히 공부하세요!\n");
                }
                else if (*goalGrade < currentGrade) {
                    printf("목표 성적보다 %.2lf만큼 높습니다.\n", currentGrade - *goalGrade);
                    printf("멋집니다!\n");
                }
                else {
                    printf("목표성적과 현재 성적이 같습니다.\n");
                }
            }
            else {
                printf("현재 성적을 입력해주세요.\n");
            }
        }
        else {
            break;
        }
    }
}

// 과제 관리 함수
void manageAssignments(struct Course* timetable, int hakjum) {
    int index = 0;

    displayAssignment(timetable, hakjum);

    printf("\n과제 관리 프로그램입니다.\n");
    printf("----------------------------------\n");
    printf("과제를 추가/삭제 할 과목을 선택하세요.\n");

    for (int i = 0; i < hakjum; i++) {
        printf("%d. %s\n", i + 1, timetable[i].className);
    }

    scanf_s("%d", &index);

    int menu;

    printf("\n-------------------------------\n");
    printf("1. 과제 추가하기\n");
    printf("2. 과제 삭제하기\n");
    printf("3. 이전으로\n");
    scanf_s("%d", &menu);

    switch (menu) {
    case 1:
        // 추가된 부분: assignments를 동적으로 할당
        if (timetable[index - 1].assignmentCount < MAX_ASSIGNMENTS) {
            timetable[index - 1].assignments = (struct Assignment*)malloc(MAX_ASSIGNMENTS * sizeof(struct Assignment));
            if (timetable[index - 1].assignments == NULL) {
                printf("메모리 할당 오류\n");
                return;
            }

            printf("%s 과목의 과제를 입력하세요: \n", timetable[index - 1].className);
            scanf_s("%s", timetable[index - 1].assignments[timetable[index - 1].assignmentCount].assignmentName, MAX_LENGTH);
            printf("%s 과목의 마감기한를 입력하세요: \n", timetable[index - 1].className);
            scanf_s("%d", &timetable[index - 1].assignments[timetable[index - 1].assignmentCount].dueDate);
            timetable[index - 1].assignmentCount++; // 추가된 과제 개수 증가
        }
        else {
            printf("최대 과제 개수를 초과하여 추가할 수 없습니다.\n");
        }
        break;
    case 2:
        if (timetable[index - 1].assignmentCount > 0) {
            printf("삭제할 과제의 번호를 입력하세요 (1부터 시작)\n");
            int delete = 0;
            scanf_s("%d", &delete);

            if (delete >= 1 && delete <= timetable[index - 1].assignmentCount) {
                // 변경된 부분: 할당된 메모리를 해제하고 NULL로 초기화
                free(timetable[index - 1].assignments);
                timetable[index - 1].assignments = NULL;
                timetable[index - 1].assignmentCount = 0;
                printf("과제가 삭제되었습니다.\n");
            }
            else {
                printf("잘못된 번호입니다.\n");
            }
        }
        else {
            printf("현재 과제가 없어 삭제할 수 없습니다.\n");
        }
        break;
    case 3:
        break;
    default:
        printf("잘못된 번호입니다. 다시 입력하세요.\n");
    }
}

//시간표 보여주는 함수
void displayTimetable(struct Course* timetable, int hakjum) {
    printf("\n시간표:\n-----------------------\n");
    for (int i = 0; i < hakjum; i++) {
        printf("%s | %s | %s\n", timetable[i].className, timetable[i].professorName, timetable[i].classPlace);
    }
}

//과목별 성적 보여주는 함수
void displayGradeTimetable(struct Course* timetable, int hakjum) {
    printf("\n수업 별 성적:\n-----------------------\n");
    for (int i = 0; i < hakjum; i++) {
        printf("%s | 성적: %.2lf\n", timetable[i].className, timetable[i].grade);
    }
}

//과제목록 보여주는 함수
void displayAssignment(struct Course* timetable, int hakjum) {
    printf("\n수업 별 과제:\n-----------------------\n");

    for (int i = 0; i < hakjum; i++) {
        printf("%s:\n", timetable[i].className);

        if (timetable[i].assignmentCount == 0) {
            printf("해당 과목에 등록된 과제가 없습니다.\n");
        }
        else {
            for (int j = 0; j < timetable[i].assignmentCount; j++) {
                printf("과제 이름: %s, 마감 기한: %d\n", timetable[i].assignments[j].assignmentName, timetable[i].assignments[j].dueDate);
            }
        }

        printf("\n");
    }
}



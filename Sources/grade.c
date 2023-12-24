#include "grade.h"
#include "common.h"
#include <stdio.h>

//성적 관리 프로그램 함수
void manageGrades(struct Course* timetable, int hakjum, double* goalGrade,int check) {
    int setGrade = (*goalGrade == 0.0) ? 0 : 1;
    int option = 0;
    int allGrade = 0;

    while (1) {
        printf("\n\n성적관리 프로그램\n---------------------\n");
        printf("1. 목표성적 입력 및 수정\n2. 각 수업 별 성적 입력 및 수정\n3. 성적분석\n4. 이전으로\n");
        scanf_s("%d", &option);

        switch (option) {
        //목표 설정
        case 1:
            setGoalGrade(goalGrade);
            setGrade = 1;
            break;
        //과목별 성적 추가 및 수정
        case 2:
            if (setGrade) {
                if (!check) {
                    setSubjectGrades(timetable, hakjum);
                    check = 1;
                }
                else {
                    modifySubjectGrade(timetable, hakjum);
                }
                displayGradeTimetable(timetable, hakjum);
            }
            else {
                printf("목표 성적을 먼저 입력하세요.\n");
            }
            break;
        //성적 분석
        case 3:
            if (setGrade) {
                analyzeGrade(timetable, hakjum, *goalGrade);
            }
            else {
                printf("목표 성적을 먼저 입력하세요.\n");
            }
            break;

        case 4:
            return;

        default:
            printf("잘못된 번호입니다.\n");
            break;
        }
    }
}

//목표 성적 입력 및 수정
void setGoalGrade(double* goalGrade) {
    if (*goalGrade == 0.0) {
        printf("목표 성적을 입력하세요: ");
        scanf_s("%lf", goalGrade);
        printf("당신의 목표 성적은 %.2lf 입니다.", *goalGrade);
    }
    else {
        printf("수정할 목표 성적을 입력하세요.\n");
        scanf_s("%lf", goalGrade);
        printf("수정한 당신의 목표 성적은 %.2lf입니다.", *goalGrade);
    }
}

//과목별 성적 입력
void setSubjectGrades(struct Course* timetable, int hakjum) {
    if (hakjum > 0) {
        for (int i = 0; i < hakjum; i++) {
            printf("%s 과목의 성적을 입력하세요: \n", timetable[i].className);
            scanf_s("%lf", &timetable[i].grade);
        }
    }
    else {
        printf("현재 수업이 없어 성적을 입력할 수 없습니다.\n");
    }
}

//과목 별 성적 수정
void modifySubjectGrade(struct Course* timetable, int hakjum) {
    if (hakjum > 0) {
        int subNum = 0;
        printf("성적을 수정할 과목의 번호를 입력하세요.\n");
        for (int i = 0; i < hakjum; i++) {
            printf("%d. %s\n", i + 1, timetable[i].className);
        }
        scanf_s("%d", &subNum);

        if (subNum >= 1 && subNum <= hakjum) {
            printf("%s 과목의 성적을 수정하세요.\n", timetable[subNum - 1].className);
            scanf_s("%lf", &timetable[subNum - 1].grade);
            printf("성적이 수정 되었습니다.\n");
        }
        else {
            printf("잘못된 번호입니다.\n");
        }
    }
    else {
        printf("현재 수업이 없어 성적을 수정할 수 없습니다.\n");
    }
}

//성적 분석
void analyzeGrade(struct Course* timetable, int hakjum, double goalGrade) {
    printf("목표 성적: %.2lf\n", goalGrade);

    double currentGrade = 0.0;
    double sum = 0.0;

    for (int i = 0; i < hakjum; i++) {
        sum += timetable[i].grade;
    }

    currentGrade = sum / hakjum;

    if (sum != 0.0) {
        printf("현재 당신의 성적: %.2lf\n", currentGrade);

        if (goalGrade > currentGrade) {
            printf("목표 성적까지 %.2lf만큼 남았습니다.\n", goalGrade - currentGrade);
            printf("조금 더 열심히 공부하세요!\n");
        }
        else if (goalGrade < currentGrade) {
            printf("목표 성적보다 %.2lf만큼 높습니다.\n", currentGrade - goalGrade);
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

//과목 별 성적 보여주기
void displayGradeTimetable(struct Course* timetable, int hakjum) {
    printf("\n수업 별 성적:\n-----------------------\n");
    for (int i = 0; i < hakjum; i++) {
        printf("%s | 성적: %.2lf\n", timetable[i].className, timetable[i].grade);
    }
}
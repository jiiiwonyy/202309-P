#include <stdio.h>
#include <stdlib.h>
#include "timetable.h"
#include "grade.h"
#include "todo_list.h"
#include "common.h"


void clrscr() {
    system("cls");
}

int main() {

    struct Course* timetable = NULL;
    struct Todo* todoList = NULL;

    int timetableCreated = 0;
    int hakjum = 0;
    double grade = 0.0;
    double* goalGrade = &grade;
    int check = 0;
    

    while (1) {
        clrscr();

        printf("\n대학생활 도우미 프로그램입니다.\n 무엇을 도와드릴까요?\n");
        printf("1. 시간표 관리\n2. 성적 관리\n3. 투두 리스트\n4. 프로그램 종료\n");
        printf("-------------------------------------------------\n");
        printf("원하는 번호를 입력하세요.\n");

        int num = 0;
        scanf_s("%d", &num);

        if (num == 1)
        {
            clrscr();
            if (!timetableCreated) {
                int grade = 0;
                int semester = 0;

                printf("시간표 관리 메뉴입니다.\n");
                printf("몇학년 몇학기 수업인가요? (띄어쓰기로 구분해서 학년,학기 작성)\n");
                scanf_s("%d %d", &grade, &semester);
                printf("총 몇개의 수업을 들으시나요?");
                scanf_s("%d", &hakjum);

                timetable = (struct Course*)malloc(hakjum * sizeof(struct Course));

                if (timetable == NULL) {
                    printf("메모리 할당 오류\n");
                    return;
                }

                printf("듣는 수업의 수업명, 교수명, 장소명을 차례대로 입력하세요. (띄어쓰기로 구분)\n");

                for (int i = 0; i < hakjum; i++) {
                    scanf_s("%49s %49s %49s", timetable[i].className, MAX_LENGTH, timetable[i].professorName, MAX_LENGTH, timetable[i].classPlace, MAX_LENGTH);
                }

                timetableCreated = 1;
            }
            manageTimetable(&timetable, &hakjum);
        }

        else if (num == 2) {
            clrscr();
            if (*goalGrade != 0.0) {
                printf("당신의 목표 성적은 %.2lf 입니다.\n\n", *goalGrade);
            }
            else {
                printf("아직 목표 성적이 입력되지 않았습니다.\n1번을 눌러 목표 성적을 입력하세요.\n");
            }

            manageGrades(timetable, hakjum, goalGrade, check);
            check = 1;
        }
        //투두리스트 프로그램 작성
        else if (num == 3) {
            clrscr();
            manageTodoList(todoList);
        }

        else if (num == 4) { //프로그램 종료
            printf("프로그램을 종료합니다.");
            free(timetable);
            return 0;
        }
        else
            printf("잘못된 번호입니다. 다시 입력하세요\n\n");

    }
    
    return 0;
    
}


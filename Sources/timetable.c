#include "timetable.h"
#include "common.h"
#include <stdlib.h>
#include <stdio.h>

// 시간표 관리 함수
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
        addCourse(*timetable, hakjum);
        // 수업 추가 후 시간표 출력
        displayTimetable(*timetable, *hakjum);
    }
    else if (option == 2) {
        // 수업 삭제
        deleteCourse(*timetable, hakjum);

        // 수업 삭제 후 시간표 출력
        displayTimetable(*timetable, *hakjum);
    }
    else if (option == 3) {
        // 다시 메인메뉴 보이게 함
    }
    else {
        printf("잘못된 번호입니다.\n");
    }
}

// 수업 추가 함수
void addCourse(struct Course* timetable, int* hakjum) {
    printf("추가할 수업의 수업명, 교수명, 장소명을 차례대로 입력하세요. (띄어쓰기로 구분)\n");
    scanf_s("%s %s %s", timetable[*hakjum].className, MAX_LENGTH, timetable[*hakjum].professorName, MAX_LENGTH, timetable[*hakjum].classPlace, MAX_LENGTH);

    (*hakjum)++;
    printf("수업이 추가되었습니다.\n");
}

// 수업 삭제 함수
void deleteCourse(struct Course* timetable, int* hakjum) {
    if (*hakjum > 0) {
        printf("삭제할 수업의 번호를 입력하세요 (1부터 시작)\n");
        int courseNumber = 0;
        scanf_s("%d", &courseNumber);

        if (courseNumber >= 1 && courseNumber <= *hakjum) {
            for (int i = courseNumber - 1; i < *hakjum - 1; i++) {
                timetable[i] = timetable[i + 1];
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

// 시간표 보여주는 함수
void displayTimetable(struct Course* timetable, int hakjum) {
    printf("\n시간표:\n-----------------------\n");
    for (int i = 0; i < hakjum; i++) {
        printf("%s | %s | %s\n", timetable[i].className, timetable[i].professorName, timetable[i].classPlace);
    }
}

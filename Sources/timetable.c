#include "timetable.h"
#include "common.h"
#include <stdlib.h>
#include <stdio.h>

// �ð�ǥ ���� �Լ�
void manageTimetable(struct Course** timetable, int* hakjum) {
    // �ð�ǥ ���
    displayTimetable(*timetable, *hakjum);

    // �ð�ǥ ����
    printf("\n1. ���� �߰�\n2. ���� ����\n3. ��������\n");
    printf("���ϴ� ��ȣ�� �Է��ϼ���.\n");

    int option = 0;
    scanf_s("%d", &option);

    if (option == 1) {
        // ���� �߰�
        addCourse(*timetable, hakjum);
        // ���� �߰� �� �ð�ǥ ���
        displayTimetable(*timetable, *hakjum);
    }
    else if (option == 2) {
        // ���� ����
        deleteCourse(*timetable, hakjum);

        // ���� ���� �� �ð�ǥ ���
        displayTimetable(*timetable, *hakjum);
    }
    else if (option == 3) {
        // �ٽ� ���θ޴� ���̰� ��
    }
    else {
        printf("�߸��� ��ȣ�Դϴ�.\n");
    }
}

// ���� �߰� �Լ�
void addCourse(struct Course* timetable, int* hakjum) {
    printf("�߰��� ������ ������, ������, ��Ҹ��� ���ʴ�� �Է��ϼ���. (����� ����)\n");
    scanf_s("%s %s %s", timetable[*hakjum].className, MAX_LENGTH, timetable[*hakjum].professorName, MAX_LENGTH, timetable[*hakjum].classPlace, MAX_LENGTH);

    (*hakjum)++;
    printf("������ �߰��Ǿ����ϴ�.\n");
}

// ���� ���� �Լ�
void deleteCourse(struct Course* timetable, int* hakjum) {
    if (*hakjum > 0) {
        printf("������ ������ ��ȣ�� �Է��ϼ��� (1���� ����)\n");
        int courseNumber = 0;
        scanf_s("%d", &courseNumber);

        if (courseNumber >= 1 && courseNumber <= *hakjum) {
            for (int i = courseNumber - 1; i < *hakjum - 1; i++) {
                timetable[i] = timetable[i + 1];
            }
            (*hakjum)--;
            printf("������ �����Ǿ����ϴ�.\n");
        }
        else {
            printf("�߸��� ��ȣ�Դϴ�.\n");
        }
    }
    else {
        printf("���� ������ ���� ������ �� �����ϴ�.\n");
    }
}

// �ð�ǥ �����ִ� �Լ�
void displayTimetable(struct Course* timetable, int hakjum) {
    printf("\n�ð�ǥ:\n-----------------------\n");
    for (int i = 0; i < hakjum; i++) {
        printf("%s | %s | %s\n", timetable[i].className, timetable[i].professorName, timetable[i].classPlace);
    }
}

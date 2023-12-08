#include "function.h"
#include <stdlib.h>
#include <stdio.h>


//�ð�ǥ ���� �Լ�
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
        printf("�߰��� ������ ������, ������, ��Ҹ��� ���ʴ�� �Է��ϼ���. (����� ����)\n");
        scanf_s("%s %s %s", (*timetable)[*hakjum].className, MAX_LENGTH, (*timetable)[*hakjum].professorName, MAX_LENGTH, (*timetable)[*hakjum].classPlace, MAX_LENGTH);
        (*hakjum)++;
        printf("������ �߰��Ǿ����ϴ�.\n");
    }
    else if (option == 2) {
        // ���� ����
        if (*hakjum > 0) {
            printf("������ ������ ��ȣ�� �Է��ϼ��� (1���� ����)\n");
            int courseNumber = 0;
            scanf_s("%d", &courseNumber);

            if (courseNumber >= 1 && courseNumber <= *hakjum) {
                for (int i = courseNumber - 1; i < *hakjum - 1; i++) {
                    (*timetable)[i] = (*timetable)[i + 1];
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
    else if (option == 3) {
        // �ٽ� ���θ޴� ���̰� ��
    }
    else {
        printf("�߸��� ��ȣ�Դϴ�.\n");
    }
}

//���� ���� �Լ�
void manageGrades(struct Course* timetable, int hakjum, double* goalGrade) {
    int setGrade = 0;
    int option = 0;

    while (1) {
        printf("\n\n�������� ���α׷�\n---------------------\n");
        printf("1. ��ǥ���� �Է� �� ����\n2. �� ���� �� ���� �Է� �� ����\n3. �����м�\n4. ��������\n");
        scanf_s("%d", &option);

        // ��ǥ ���� �Է� �� ����
        if (option == 1) {
            if (!setGrade) {
                printf("��ǥ ������ �Է��ϼ���: ");
                scanf_s("%lf", goalGrade);
                printf("����� ��ǥ ������ %.2lf �Դϴ�.", *goalGrade);
                setGrade = 1;
            }
            else {
                printf("������ ��ǥ ������ �Է��ϼ���.\n");
                scanf_s("%lf", goalGrade);
                printf("������ ����� ��ǥ ������ %.2lf�Դϴ�.", *goalGrade);
            }
        }

        // �� ���� �� ��ǥ ���� �Է� �� ����
        else if (option == 2) {
            for (int i = 0; i < hakjum; i++) {
                printf("%s ������ ������ �Է��ϼ���: \n", timetable[i].className);
                scanf_s("%lf", &timetable[i].grade);
            }
            displayGradeTimetable(timetable, hakjum);
        }

        // ��ǥ ������ ���� ���� ��
        else if (option == 3) {
            printf("��ǥ ����: %.2lf\n", *goalGrade);
            double currentGrade = 0.0;
            double sum = 0.0;

            for (int i = 0; i < hakjum; i++) {
                sum += timetable[i].grade;
            }

            currentGrade = sum / hakjum;

            if (sum != 0.0) {
                printf("���� ����� ����: %.2lf\n", currentGrade);

                if (*goalGrade > currentGrade) {
                    printf("��ǥ �������� %.2lf��ŭ ���ҽ��ϴ�.\n", *goalGrade - currentGrade);
                    printf("���� �� ������ �����ϼ���!\n");
                }
                else if (*goalGrade < currentGrade) {
                    printf("��ǥ �������� %.2lf��ŭ �����ϴ�.\n", currentGrade - *goalGrade);
                    printf("�����ϴ�!\n");
                }
                else {
                    printf("��ǥ������ ���� ������ �����ϴ�.\n");
                }
            }
            else {
                printf("���� ������ �Է����ּ���.\n");
            }
        }
        else {
            break;
        }
    }
}

// ���� ���� �Լ�
void manageAssignments(struct Course* timetable, int hakjum) {
    int index = 0;

    displayAssignment(timetable, hakjum);

    printf("\n���� ���� ���α׷��Դϴ�.\n");
    printf("----------------------------------\n");
    printf("������ �߰�/���� �� ������ �����ϼ���.\n");

    for (int i = 0; i < hakjum; i++) {
        printf("%d. %s\n", i + 1, timetable[i].className);
    }

    scanf_s("%d", &index);

    int menu;

    printf("\n-------------------------------\n");
    printf("1. ���� �߰��ϱ�\n");
    printf("2. ���� �����ϱ�\n");
    printf("3. ��������\n");
    scanf_s("%d", &menu);

    switch (menu) {
    case 1:
        // �߰��� �κ�: assignments�� �������� �Ҵ�
        if (timetable[index - 1].assignmentCount < MAX_ASSIGNMENTS) {
            timetable[index - 1].assignments = (struct Assignment*)malloc(MAX_ASSIGNMENTS * sizeof(struct Assignment));
            if (timetable[index - 1].assignments == NULL) {
                printf("�޸� �Ҵ� ����\n");
                return;
            }

            printf("%s ������ ������ �Է��ϼ���: \n", timetable[index - 1].className);
            scanf_s("%s", timetable[index - 1].assignments[timetable[index - 1].assignmentCount].assignmentName, MAX_LENGTH);
            printf("%s ������ �������Ѹ� �Է��ϼ���: \n", timetable[index - 1].className);
            scanf_s("%d", &timetable[index - 1].assignments[timetable[index - 1].assignmentCount].dueDate);
            timetable[index - 1].assignmentCount++; // �߰��� ���� ���� ����
        }
        else {
            printf("�ִ� ���� ������ �ʰ��Ͽ� �߰��� �� �����ϴ�.\n");
        }
        break;
    case 2:
        if (timetable[index - 1].assignmentCount > 0) {
            printf("������ ������ ��ȣ�� �Է��ϼ��� (1���� ����)\n");
            int delete = 0;
            scanf_s("%d", &delete);

            if (delete >= 1 && delete <= timetable[index - 1].assignmentCount) {
                // ����� �κ�: �Ҵ�� �޸𸮸� �����ϰ� NULL�� �ʱ�ȭ
                free(timetable[index - 1].assignments);
                timetable[index - 1].assignments = NULL;
                timetable[index - 1].assignmentCount = 0;
                printf("������ �����Ǿ����ϴ�.\n");
            }
            else {
                printf("�߸��� ��ȣ�Դϴ�.\n");
            }
        }
        else {
            printf("���� ������ ���� ������ �� �����ϴ�.\n");
        }
        break;
    case 3:
        break;
    default:
        printf("�߸��� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���.\n");
    }
}

//�ð�ǥ �����ִ� �Լ�
void displayTimetable(struct Course* timetable, int hakjum) {
    printf("\n�ð�ǥ:\n-----------------------\n");
    for (int i = 0; i < hakjum; i++) {
        printf("%s | %s | %s\n", timetable[i].className, timetable[i].professorName, timetable[i].classPlace);
    }
}

//���� ���� �����ִ� �Լ�
void displayGradeTimetable(struct Course* timetable, int hakjum) {
    printf("\n���� �� ����:\n-----------------------\n");
    for (int i = 0; i < hakjum; i++) {
        printf("%s | ����: %.2lf\n", timetable[i].className, timetable[i].grade);
    }
}

//������� �����ִ� �Լ�
void displayAssignment(struct Course* timetable, int hakjum) {
    printf("\n���� �� ����:\n-----------------------\n");

    for (int i = 0; i < hakjum; i++) {
        printf("%s:\n", timetable[i].className);

        if (timetable[i].assignmentCount == 0) {
            printf("�ش� ���� ��ϵ� ������ �����ϴ�.\n");
        }
        else {
            for (int j = 0; j < timetable[i].assignmentCount; j++) {
                printf("���� �̸�: %s, ���� ����: %d\n", timetable[i].assignments[j].assignmentName, timetable[i].assignments[j].dueDate);
            }
        }

        printf("\n");
    }
}



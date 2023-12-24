#include "grade.h"
#include "common.h"
#include <stdio.h>

//���� ���� ���α׷� �Լ�
void manageGrades(struct Course* timetable, int hakjum, double* goalGrade,int check) {
    int setGrade = (*goalGrade == 0.0) ? 0 : 1;
    int option = 0;
    int allGrade = 0;

    while (1) {
        printf("\n\n�������� ���α׷�\n---------------------\n");
        printf("1. ��ǥ���� �Է� �� ����\n2. �� ���� �� ���� �Է� �� ����\n3. �����м�\n4. ��������\n");
        scanf_s("%d", &option);

        switch (option) {
        //��ǥ ����
        case 1:
            setGoalGrade(goalGrade);
            setGrade = 1;
            break;
        //���� ���� �߰� �� ����
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
                printf("��ǥ ������ ���� �Է��ϼ���.\n");
            }
            break;
        //���� �м�
        case 3:
            if (setGrade) {
                analyzeGrade(timetable, hakjum, *goalGrade);
            }
            else {
                printf("��ǥ ������ ���� �Է��ϼ���.\n");
            }
            break;

        case 4:
            return;

        default:
            printf("�߸��� ��ȣ�Դϴ�.\n");
            break;
        }
    }
}

//��ǥ ���� �Է� �� ����
void setGoalGrade(double* goalGrade) {
    if (*goalGrade == 0.0) {
        printf("��ǥ ������ �Է��ϼ���: ");
        scanf_s("%lf", goalGrade);
        printf("����� ��ǥ ������ %.2lf �Դϴ�.", *goalGrade);
    }
    else {
        printf("������ ��ǥ ������ �Է��ϼ���.\n");
        scanf_s("%lf", goalGrade);
        printf("������ ����� ��ǥ ������ %.2lf�Դϴ�.", *goalGrade);
    }
}

//���� ���� �Է�
void setSubjectGrades(struct Course* timetable, int hakjum) {
    if (hakjum > 0) {
        for (int i = 0; i < hakjum; i++) {
            printf("%s ������ ������ �Է��ϼ���: \n", timetable[i].className);
            scanf_s("%lf", &timetable[i].grade);
        }
    }
    else {
        printf("���� ������ ���� ������ �Է��� �� �����ϴ�.\n");
    }
}

//���� �� ���� ����
void modifySubjectGrade(struct Course* timetable, int hakjum) {
    if (hakjum > 0) {
        int subNum = 0;
        printf("������ ������ ������ ��ȣ�� �Է��ϼ���.\n");
        for (int i = 0; i < hakjum; i++) {
            printf("%d. %s\n", i + 1, timetable[i].className);
        }
        scanf_s("%d", &subNum);

        if (subNum >= 1 && subNum <= hakjum) {
            printf("%s ������ ������ �����ϼ���.\n", timetable[subNum - 1].className);
            scanf_s("%lf", &timetable[subNum - 1].grade);
            printf("������ ���� �Ǿ����ϴ�.\n");
        }
        else {
            printf("�߸��� ��ȣ�Դϴ�.\n");
        }
    }
    else {
        printf("���� ������ ���� ������ ������ �� �����ϴ�.\n");
    }
}

//���� �м�
void analyzeGrade(struct Course* timetable, int hakjum, double goalGrade) {
    printf("��ǥ ����: %.2lf\n", goalGrade);

    double currentGrade = 0.0;
    double sum = 0.0;

    for (int i = 0; i < hakjum; i++) {
        sum += timetable[i].grade;
    }

    currentGrade = sum / hakjum;

    if (sum != 0.0) {
        printf("���� ����� ����: %.2lf\n", currentGrade);

        if (goalGrade > currentGrade) {
            printf("��ǥ �������� %.2lf��ŭ ���ҽ��ϴ�.\n", goalGrade - currentGrade);
            printf("���� �� ������ �����ϼ���!\n");
        }
        else if (goalGrade < currentGrade) {
            printf("��ǥ �������� %.2lf��ŭ �����ϴ�.\n", currentGrade - goalGrade);
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

//���� �� ���� �����ֱ�
void displayGradeTimetable(struct Course* timetable, int hakjum) {
    printf("\n���� �� ����:\n-----------------------\n");
    for (int i = 0; i < hakjum; i++) {
        printf("%s | ����: %.2lf\n", timetable[i].className, timetable[i].grade);
    }
}
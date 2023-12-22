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

        printf("\n���л�Ȱ ����� ���α׷��Դϴ�.\n ������ ���͵帱���?\n");
        printf("1. �ð�ǥ ����\n2. ���� ����\n3. ���� ����Ʈ\n4. ���α׷� ����\n");
        printf("-------------------------------------------------\n");
        printf("���ϴ� ��ȣ�� �Է��ϼ���.\n");

        int num = 0;
        scanf_s("%d", &num);

        if (num == 1)
        {
            clrscr();
            if (!timetableCreated) {
                int grade = 0;
                int semester = 0;

                printf("�ð�ǥ ���� �޴��Դϴ�.\n");
                printf("���г� ���б� �����ΰ���? (����� �����ؼ� �г�,�б� �ۼ�)\n");
                scanf_s("%d %d", &grade, &semester);
                printf("�� ��� ������ �����ó���?");
                scanf_s("%d", &hakjum);

                timetable = (struct Course*)malloc(hakjum * sizeof(struct Course));

                if (timetable == NULL) {
                    printf("�޸� �Ҵ� ����\n");
                    return;
                }

                printf("��� ������ ������, ������, ��Ҹ��� ���ʴ�� �Է��ϼ���. (����� ����)\n");

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
                printf("����� ��ǥ ������ %.2lf �Դϴ�.\n\n", *goalGrade);
            }
            else {
                printf("���� ��ǥ ������ �Էµ��� �ʾҽ��ϴ�.\n1���� ���� ��ǥ ������ �Է��ϼ���.\n");
            }

            manageGrades(timetable, hakjum, goalGrade, check);
            check = 1;
        }
        //���θ���Ʈ ���α׷� �ۼ�
        else if (num == 3) {
            clrscr();
            manageTodoList(todoList);
        }

        else if (num == 4) { //���α׷� ����
            printf("���α׷��� �����մϴ�.");
            free(timetable);
            return 0;
        }
        else
            printf("�߸��� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���\n\n");

    }
    
    return 0;
    
}


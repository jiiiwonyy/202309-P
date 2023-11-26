#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 50

struct Course {
    char className[MAX_LENGTH];
    char professorName[MAX_LENGTH];
    char classPlace[MAX_LENGTH];
    double grade;
    struct Admission* admissionTable;
};

struct Admission {
    char admissionName[MAX_LENGTH];
    int year;
    int month;
    int day;
};

void displayTimetable(struct Course* timetable, int hakjum);
void displayGradeTimetable(struct Course* timetable, int hakjum);

int main() {
    struct Course* timetable = NULL;
    struct Admission* admissionTable = NULL;

    int timetableCreated = 0;
    int hakjum = 0;
    double grade = 0.0;
    double* goalGrade = &grade;

    while (1) {
        printf("\n\n���л�Ȱ ����� ���α׷��Դϴ�.\n ������ ���͵帱���?\n");
        printf("1. �ð�ǥ ����\n2. ���� ����\n3. ���� ����\n4. ���α׷� ����\n");
        printf("-------------------------------------------------\n");
        printf("���ϴ� ��ȣ�� �Է��ϼ���.\n");

        int num = 0;
        scanf_s("%d", &num);

        if (num == 1) {
            if (!timetableCreated) {
                // �ð�ǥ�� �Է¹޴� �κ�
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
                    return -1;
                }

                printf("��� ������ ������, ������, ��Ҹ��� ���ʴ�� �Է��ϼ���. (����� ����)\n");

                for (int i = 0; i < hakjum; i++) {
                    scanf_s("%49s %49s %49s", timetable[i].className, MAX_LENGTH, timetable[i].professorName, MAX_LENGTH, timetable[i].classPlace, MAX_LENGTH);
                }

                timetableCreated = 1; 
            }

            // �ð�ǥ ���
            displayTimetable(timetable, hakjum);

            // �ð�ǥ ����
            printf("\n1. ���� �߰�\n2. ���� ����\n3. ��������\n");
            printf("���ϴ� ��ȣ�� �Է��ϼ���.\n");

            int option = 0;
            scanf_s("%d", &option);

            if (option == 1) {
                // ���� �߰�
                    printf("�߰��� ������ ������, ������, ��Ҹ��� ���ʴ�� �Է��ϼ���. (����� ����)\n");
                    scanf_s("%s %s %s", timetable[hakjum].className, MAX_LENGTH, timetable[hakjum].professorName, MAX_LENGTH, timetable[hakjum].classPlace, MAX_LENGTH);
                    hakjum++;
                    printf("������ �߰��Ǿ����ϴ�.\n");
            }
            else if (option == 2) {
                // ���� ����
                if (hakjum > 0) {
                    printf("������ ������ ��ȣ�� �Է��ϼ��� (1���� ����)\n");
                    int courseNumber = 0;
                    scanf_s("%d", &courseNumber);

                    if (courseNumber >= 1 && courseNumber <= hakjum) {
                        for (int i = courseNumber - 1; i < hakjum - 1; i++) {
                            timetable[i] = timetable[i + 1];
                        }
                        hakjum--;
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

        else if (num == 2) {
            //���� ���� ���α׷� �ۼ�
            displayTimetable(timetable, hakjum);

            if (*goalGrade != 0.0) {
                printf("����� ��ǥ ������ %.2lf �Դϴ�.\n\n", *goalGrade);
            }
            else {
                printf("���� ��ǥ ������ �Էµ��� �ʾҽ��ϴ�.\n1���� ���� ��ǥ ������ �Է��ϼ���.\n");
            }

            int setGrade = 0;
            int option = 0;
            while (1) {
                printf("\n\n�������� ���α׷�\n---------------------\n");
                printf("1. ��ǥ���� �Է� �� ����\n2. �� ���� �� ���� �Է� �� ����\n3. �����м�\n4. ��������\n");
                scanf_s("%d", &option);

                //��ǥ ���� �Է� �� ����
                if (option == 1) {
                    if (!setGrade) { //��ǥ ������ �ԷµǾ� ���� ���� ���
                        printf("��ǥ ������ �Է��ϼ���: ");
                        scanf_s("%lf", goalGrade);
                        printf("����� ��ǥ ������ %.2lf �Դϴ�.", *goalGrade);
                        setGrade = 1;
                    }
                    else { //��ǥ ���� ����
                        printf("������ ��ǥ ������ �Է��ϼ���.\n");
                        scanf_s("%lf", goalGrade);
                        printf("������ ����� ��ǥ ������ %.2lf�Դϴ�.", *goalGrade);
                    }
                }

                //�� ���� �� ��ǥ ���� �Է� �� ����
                else if (option == 2) {
                    for (int i = 0; i < hakjum; i++) {
                        printf("%s ������ ������ �Է��ϼ���: \n", timetable[i].className);
                        scanf_s("%lf", &timetable[i].grade);
                    }
                    displayGradeTimetable(timetable, hakjum);
                }

                //��ǥ ������ ���� ���� ��
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
                    else
                    {
                        printf("���� ������ �Է����ּ���.\n");
                    }
                    
                }
                else {
                    break;
                }
            }
            

		}
        //���� ���� ���α׷� �ۼ�
		else if (num == 3) {
            int index = 0;
            if (hakjum==0) {
                printf("���� �ð�ǥ�� �Էµ��� �ʾҽ��ϴ�.\n�ð�ǥ�� ���� �Է����ּ���.\n");
            }
            printf("\n���� ���� ���α׷��Դϴ�.\n");
            printf("----------------------------------\n");
            printf("������ �Է� �� ������ �����ϼ���.\n");
            for (int i = 0; i < hakjum; i++) {
                printf("%d. %s\n", i + 1, timetable[i].className);
            }
            scanf_s("%d",&index);
            

			
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

void displayTimetable(struct Course* timetable, int hakjum) {
    printf("\n�ð�ǥ:\n-----------------------\n");
    for (int i = 0; i < hakjum; i++) {
        printf("%s | %s | %s\n", timetable[i].className, timetable[i].professorName, timetable[i].classPlace);
    }
}

void displayGradeTimetable(struct Course* timetable, int hakjum) {
    printf("\n���� �� ����:\n-----------------------\n");
    for (int i = 0; i < hakjum; i++) {
        printf("%s | ����: %.2lf\n", timetable[i].className, timetable[i].grade);
    }
}


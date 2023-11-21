#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 50

struct Course {
    char className[MAX_LENGTH];
    char professorName[MAX_LENGTH];
    char classPlace[MAX_LENGTH];
};

void displayTimetable(struct Course* timetable, int hakjum) {
    printf("\n�ð�ǥ:\n-----------------------\n");
    for (int i = 0; i < hakjum; i++) {
        printf("%s | %s | %s\n", timetable[i].className, timetable[i].professorName, timetable[i].classPlace);
    }
}

int main() {
    struct Course* timetable = NULL;
    int timetableCreated = 0;
    int hakjum = 0;

    while (1) {
        printf("���л�Ȱ ����� ���α׷��Դϴ�.\n ������ ���͵帱���?\n");
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
                    scanf_s("%s %s %s", timetable[i].className, MAX_LENGTH, timetable[i].professorName, MAX_LENGTH, timetable[i].classPlace, MAX_LENGTH);
                }

                timetableCreated = 1; // Set the flag to indicate that the timetable has been created.
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
		}
		else if (num == 3) {
			//���� ���� ���α׷� �ۼ�
		}
		else if (num == 4) { //���α׷� ����
            free(timetable);
            return 0;
		}

		else
			printf("�߸��� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���\n\n");
	}

	return 0;
}
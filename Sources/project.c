#include <stdio.h>


int main() {

	while (1) {
		printf("���л�Ȱ ����� ���α׷��Դϴ�.\n ������ ���͵帱���?\n");
		printf("1. �ð�ǥ ����\n2. ���� ����\n3. ���� ����\n4. ���α׷� ����\n");
		printf("-------------------------------------------------\n");
		printf("���ϴ� ��ȣ�� �Է��ϼ���.\n");

		int num = 0;
		scanf_s("%d", &num);
		if (num == 1) {
			//�ð�ǥ ���� ���α׷� �ۼ�

			int grade = 0;
			int semester = 0;
			int hakjum = 0;
			char* timetable = { "" };
			
			printf("�ð�ǥ ���� �޴��Դϴ�.\n");
			printf("���г� ���б� �����ΰ���? (����� �����ؼ� �г�,�б� �ۼ�)\n");
			scanf_s("%d %d", &grade, &semester);
			printf("�� ��� ������ �����ó���?");
			scanf_s("%d", &hakjum);

			/*
			timetable = (char*)malloc(hakjum * sizeof(int));

			if (timetable == NULL) {
				printf("�޸� �Ҵ� ����\n");
				continue;
			}
			*/
			printf("��� ������ ������, ������, ��Ҹ��� ���ʴ�� �Է��ϼ���. (����� ����)\n");
			
		}
		else if (num == 2) {
			//���� ���� ���α׷� �ۼ�
		}
		else if (num == 3) {
			//���� ���� ���α׷� �ۼ�
		}
		else if (num == 4) { //���α׷� ����
			return 1;
		}

		else
			printf("�߸��� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���\n\n");
	}

	return 0;
}
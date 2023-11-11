#include <stdio.h>


int main() {

	while (1) {
		printf("대학생활 도우미 프로그램입니다.\n 무엇을 도와드릴까요?\n");
		printf("1. 시간표 관리\n2. 성적 관리\n3. 과제 관리\n4. 프로그램 종료\n");
		printf("-------------------------------------------------\n");
		printf("원하는 번호를 입력하세요.\n");

		int num = 0;
		scanf_s("%d", &num);
		if (num == 1) {
			//시간표 관리 프로그램 작성

			int grade = 0;
			int semester = 0;
			int hakjum = 0;
			char* timetable = { "" };
			
			printf("시간표 관리 메뉴입니다.\n");
			printf("몇학년 몇학기 수업인가요? (띄어쓰기로 구분해서 학년,학기 작성)\n");
			scanf_s("%d %d", &grade, &semester);
			printf("총 몇개의 수업을 들으시나요?");
			scanf_s("%d", &hakjum);

			/*
			timetable = (char*)malloc(hakjum * sizeof(int));

			if (timetable == NULL) {
				printf("메모리 할당 오류\n");
				continue;
			}
			*/
			printf("듣는 수업의 수업명, 교수명, 장소명을 차례대로 입력하세요. (띄어쓰기로 구분)\n");
			
		}
		else if (num == 2) {
			//성적 관리 프로그램 작성
		}
		else if (num == 3) {
			//과제 관리 프로그램 작성
		}
		else if (num == 4) { //프로그램 종료
			return 1;
		}

		else
			printf("잘못된 번호입니다. 다시 입력하세요\n\n");
	}

	return 0;
}
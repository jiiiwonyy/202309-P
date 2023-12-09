//성적 관리 프로그램 함수
void manageGrades(struct Course* timetable, int hakjum, double* goalGrade,int check);

//목표 성적 입력 및 수정
void setGoalGrade(double* goalGrade);

//과목별 성적 입력
void setSubjectGrades(struct Course* timetable, int hakjum);

//과목 별 성적 수정
void modifySubjectGrade(struct Course* timetable, int hakjum);

//성적 분석
void analyzeGrade(struct Course* timetable, int hakjum, double goalGrade);

//과목 별 성적 보여주기
void displayGradeTimetable(struct Course* timetable, int hakjum);

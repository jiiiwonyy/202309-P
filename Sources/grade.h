//���� ���� ���α׷� �Լ�
void manageGrades(struct Course* timetable, int hakjum, double* goalGrade,int check);

//��ǥ ���� �Է� �� ����
void setGoalGrade(double* goalGrade);

//���� ���� �Է�
void setSubjectGrades(struct Course* timetable, int hakjum);

//���� �� ���� ����
void modifySubjectGrade(struct Course* timetable, int hakjum);

//���� �м�
void analyzeGrade(struct Course* timetable, int hakjum, double goalGrade);

//���� �� ���� �����ֱ�
void displayGradeTimetable(struct Course* timetable, int hakjum);

/*
Purpose of program
Assumption: What domain of data you are restricting
Input: variables with data types
Output: variables to display
Algorithm: how to reach output from input
Programmer
*/

#include <stdio.h>
#include <string.h>

#define TOTAL_QUESTIONS 29
#define MAX_STUDENTS 100

struct student_rec {
	char id[7];
	char name[21];
	double gpa;
}; // struct student_rec

typedef struct student_rec studentRec;


// fucntion prototype
int getInput(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS]);
void skipNchar(int n);
void skipALine(void);
void output(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count);
void getKey(int key[TOTAL_QUESTIONS]);
void outputKey(int key[TOTAL_QUESTIONS]);
void getID(char id[7]);
void outputID(char id[]);
void getName(char name[20]);
void outputName(char name[20]);
void getAnswers(int answer[][TOTAL_QUESTIONS]);
void outputAnswers(int answer[][TOTAL_QUESTIONS]);
void findGrade(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, double grade[], int miss[][TOTAL_QUESTIONS]);

const int MAX_CHOICES = 5;

int main(void){
	
	int answer[MAX_STUDENTS][TOTAL_QUESTIONS]; // answers for all 29 questions
	int key[TOTAL_QUESTIONS]; // the correct answers
	char id[7];
	char name[20];
	int miss[MAX_STUDENTS][TOTAL_QUESTIONS]; // stores the question number of what was missed
	double grade[MAX_STUDENTS]; // a grade for each student
	int correct[TOTAL_QUESTIONS]; // stores the number of students that are correct for each question
	int response[TOTAL_QUESTIONS][MAX_CHOICES+1]; // stores the number of student that have each response
	double uniqueGrade[MAX_STUDENTS]; // stores unique grades
	int frequency[MAX_STUDENTS]; // stores frequency of unique grades
	int i = 0;
	char c;

	studentRec student[50];
	int numStudent = 0;

	while(scanf("%c", &c) != EOF){
		getID(id);
		outputID(id);
	} // while

	return 0;

} // main

/*
 * skipNchar: skip n characters for read
 * input from main: n(int) (#of characters skipped for read
 * output to main: none
 * */

void skipNchar(int n) {
	char c;
	int i;
		     
	for (i=0; i<n; i++) {
		scanf("%c", &c);
	}
} // skipNchar

/* Purpose: skip reading a whole line
 *  * Input: : none
 *   * Output: none
 *   */

void skipALine (void) {
	char c;

	scanf("%c",&c);
	while (c != '\n')
		scanf("%c",&c);
} // skipALine

void getID(char id[7]){

	char garbage[1000];

	scanf("%39c", garbage);
	scanf("%15c", id);

	id[15] = '\0';
} // getID

void outputID(char id[]){
	printf("%s", id);
} // outputID

void getData(studentRec student[50], int *iPtr) {
	const char SENTINEL[] = "sentin";
	   

	while ( getID(student[*iPtr].id), 
			strcmp(student[*iPtr].id, SENTINEL) != 0){

		// getName(student[*iPtr].name);
		// scanf("%lf", & (student[*iPtr].gpa));
					    
		 (*iPtr)++;
	} // while
} // getData

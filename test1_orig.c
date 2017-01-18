/*
Purpose (of Program)

Assumption: What domain of data you are restricting

Input: variables(with data types) available

Output: variables to display

Algorithm (or processing logic): How to reach output from input

programmer
*/


#include <stdio.h>

#define TOTAL_QUESTIONS 29
#define MAX_STUDENTS 100

void getID(char id[7]);
void outputID(char id[]);
void getName(char name[21]);
void outputName(char name[21]);
void getKey(int key[TOTAL_QUESTIONS]);
void getAnswer(int answer[MAX_STUDENTS][TOTAL_QUESTIONS]);
int getInput(int key[TOTAL_QUESTIONS], int answer[MAX_STUDENTS][TOTAL_QUESTIONS]);
void findGrade(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, double grade[], int miss[][TOTAL_QUESTIONS]);
double findAvg(double grade[], int count);
double findMedian(double grade[], int n);
char convertChar (int ans);

const int MAX_CHOICES = 5;	


int main(void) {
   char id[7];
   char name[21];
   char c;
   int answer[MAX_STUDENTS][TOTAL_QUESTIONS];
   int key[TOTAL_QUESTIONS];
   double grade[MAX_STUDENTS];
   //double testGrade[5] = {95.8, 78.4, 90.0, 66.6, 89.9};
   //int testCount = 5;
   int miss[MAX_STUDENTS][TOTAL_QUESTIONS];
   int count = 29;

   // debugging
   
   //printf("%C", convertChar(1));
   
   
   // debugging
   
   
//	getKey(key);
//	getAnswer(answer);
//findGrade(key, answer, count, grade, miss);
   while (scanf("%c", &c) != EOF) {
//      getID(id);
//	  outputID(id);
//      getName(name);
//      outputName(name);
	  getAnswer(answer);
//	  findGrade(key, answer, count, grade, miss);
//      getInput(key, answer);
   } // while

   return 0;
} // main

int getInput(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS]){
	char garbage[1000];
	int i;
	char c;

	scanf("%40c", garbage);
	scanf("%15c", key);
	printf("%s\n", key);
	

} // getInput

void getID(char id[7]) {
   int i;
   char garbage[1000]; // dumpster

   scanf("%39c",garbage);
   scanf("%15c",id);

/*
   for (i=0;i<6;i++) {
      scanf("%c", &id[i]);
   } // for
*/
   id[15] = '\0'; // end with null character

} // getID


void outputID(char id[]) {
   printf("%s", id);

} //outputID


void getName(char name[21]) {
   char first[9]; // max 8 char. in firstname
   char last[13]; // max 12 in lastname
   char c;
   char garbage[1000];

//   scanf("%s", first);
//   scanf("%s", last);

     scanf("%19c", name);
     scanf("%[^\n]", garbage);




   // more secured line
//   snprintf(name, 20, "%s %s",last, first);
//   sprintf(name, "%s %s",last, first);
   scanf("%c", &c); // skip newline character
   
} // getName


void outputName(char name[21]) {
   printf(" %s\n", name);

} // outputName

void getKey(int key[TOTAL_QUESTIONS]){
	char garbage[1000];
	char c;
	int i;

//	scanf("%75c", garbage);
	//scanf("%28c", c);
	for(i=0; i<TOTAL_QUESTIONS; ++i){
		scanf("%c", &c);
		key[i] = c - '\0';
//		printf("%i", key[i]);
	} // for
	
} // getKey

void getAnswer(int answer[MAX_STUDENTS][TOTAL_QUESTIONS]){
	char garbage[1000];
	char c;
	int i = 0;
	int j;

	scanf("%5c, garbage");
	for(i=0; i<MAX_STUDENTS; ++i){
		for(j=0; i<TOTAL_QUESTIONS; ++j){
			scanf("%c", &c);
			answer[i][j] = c - '\0';
			++i;
			printf("%i", answer[i][j]);
		}
	}
} // getAnswer

void findGrade(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, double grade[], int miss[][TOTAL_QUESTIONS]){
	int i;
	int j;
	int correct = 0;
	int incorrect = 0;
	count = 0;
	
	for(i=0; i<MAX_STUDENTS; ++i){
		for(j=0; j<TOTAL_QUESTIONS; ++j){
			if(key[i] != answer[i][j]){
				count++;
				miss[i][j] = j;
				++incorrect;
				//printf("%i", miss[i][j]);
			}
			else{
				++correct;
				count++;
			}
			
			grade[i] = (correct/TOTAL_QUESTIONS);
			printf("%lf", &grade);
		}
	}
	//printf("%s", &miss);
}

double findAvg(double grade[], int count){
	double classAvg = 0;
	double totalGrade = 0;
	int i;
	
	for(i=0; i<MAX_STUDENTS; ++i){
		totalGrade += grade[i];
	}
	classAvg = (totalGrade/count);
	
	return classAvg;
}

double findMedian(double grade[], int n) {

	if (n%2 == 1) // n is odd
		return grade[(n+1)/2-1];
	else
		return (grade[n/2-1]+grade[n/2])/2;

}

char convertChar (int ans) {

	switch (ans) {

		case 1:
			return 'A';
			break;
		case 2:
			return 'B';
			break;
		case 3:
			return 'C';
			break;
		case 4:
			return 'D';
			break;
		case 5:
			return 'E';
			break;
		default:

		return ' ';

	}

}

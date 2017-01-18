/*
To find each student’s grade, list those questions that are wrong for each students, print out all answers and find the class average.

Assumption: The program reads a .txt with student information and parses it into answers and a key to do difference forms of analysis on the data.

Input: The test1_data.txt file is read in from scanf. 

Output: Text is outputted in the window with student scores, answers, the key, wrong questions, question frequencies, and sorted grades. 

Algorithm (or processing logic): The .txt is read into the program via scanf where the answer key and individual answers are put into separate arrays. The functions then loop through the answer and answer key arrays; 

programmer: Sam Harrison
*/


#include <stdio.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 29
#define MAX_STUDENTS 100
const int MAX_CHOICES = 5;

// function prototype
void skipNchar(int n);
void skipALine(void);

void getID(char id[7]); // gets the ID of a student
void outputID(char id[]); // outputs student ID
void getName(char name[21]); // gets the students name
void outputName(char name[21]); // output the student's name
void getKey(int key[TOTAL_QUESTIONS]); // gets the answer key
void getAnswer(int answer[MAX_STUDENTS][TOTAL_QUESTIONS]); // gets the answers for each student
int getInput(int key[TOTAL_QUESTIONS], int answer[MAX_STUDENTS][TOTAL_QUESTIONS]); // gets the key and answer input
void findGrade(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, double grade[], int miss[][TOTAL_QUESTIONS]);
double findAvg(double grade[], int count);
void printHeading(void);
void outputResult(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, double grade[], int miss[][TOTAL_QUESTIONS]);
void findQuestion(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, int question_response[][MAX_CHOICES+1], int question_correct[TOTAL_QUESTIONS]);
void outputQuestionResult(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int question_correct[], int question_response[][MAX_CHOICES+1], int count);
void sortGrade(double grade[], int n);
double findMedian(double grade[], int n);
int findFrequency(double grade[], double unique_grade[], int frequency[], int count);
char convertChar (int ans);
void swap(double *a, double *b);



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
   int question_response[TOTAL_QUESTIONS][MAX_CHOICES+1];
   int question_correct[TOTAL_QUESTIONS];
   double unique_grade[MAX_STUDENTS];
   int frequency[MAX_STUDENTS];
   int count = 29;

   // debugging
   
   //printf("%C", convertChar(1));
   
   
   // debugging
   
   
	getKey(key);
//findGrade(key, answer, count, grade, miss);
//   while (scanf("%c", &c) != EOF) {
      getID(id);
//	  outputID(id);
      getName(name);
//      outputName(name);
	  getAnswer(answer);
//	  findGrade(key, answer, count, grade, miss);
//      getInput(key, answer);
//   } // while
	findGrade(key, answer, count, grade, miss);
	outputResult(key, answer, count, grade, miss);
	findQuestion(key, answer, count, question_response, question_correct);
	outputQuestionResult(key, answer, question_correct, question_response, count);
	sortGrade(grade, MAX_STUDENTS);
	findFrequency(grade, unique_grade, frequency, count);

   return 0;
} // main

/*
skipNchar: skip n characters for read
input from main: n(int) (#of characters skipped for read
output to main: none
*/

void skipNchar(int n) {
   char c;
   int i;
   
   for (i=0; i<n; i++) {
      scanf("%c", &c);
   } // for
} // skipNchar


/*
skipALine: skip reading a whole line
input from main: none
output to main: none
*/

void skipALine(void) {
   char c;

   scanf("%c", &c);
   while (c != '\n') {
      scanf("%c", &c);
   } // while

} // skipALine


/*
reads in data from keyboard and convert them to integer using c- ‘0’, and then store them into a 2D array.
input: int key[TOTAL_QUESTIONS] (key array), int answer[][TOTAL_QUESTIONS] (answer array)
ouput: # of lines read
*/ 

int getInput(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS]){
	char garbage[1000];
	int i;
	char c;

	scanf("%40c", garbage);
	scanf("%15c", key);
	printf("%s\n", key);
	

} // getInput

/*
Gets the ID of a student and stores it in the id array
input: id[7] (id array)
output: none
*/

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

/*
Loops through and outputs the student id
input: id[7] (id array)
output: none
*/
void outputID(char id[]) {
   printf("%s", id);

} //outputID

/*
Gets the name of a student and stores it in the name array
input: name[21] (name array)
output: none
*/

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

/*
Loops through and outputs student name
input: name[21] (name array)
output: none
*/

void outputName(char name[21]) {
   printf(" %s\n", name);

} // outputName

/*
Gets the answer key and stores it in the key array
input: key(TOTAL_QUESTIONS] (key array)
output: none
*/
void getKey(int key[TOTAL_QUESTIONS]){
	char garbage[1000];
	char c;
	int i;

//	scanf("%75c", garbage);
	//scanf("%28c", c);
   skipNchar(75);

	for(i=0; i<TOTAL_QUESTIONS; ++i){
		scanf("%c", &c);
		key[i] = c - '0';
		//printf("%i", key[i]);
	} // for
   //printf("\n");
   //skipALine();
	
} // getKey

/*
Gets the answer for each student and stores them in the 2D answer array
input: answer[MAX_STUDENTS][TOTAL_QUESTIONS] (answer array)
output: none
*/

void getAnswer(int answer[MAX_STUDENTS][TOTAL_QUESTIONS]){
	char garbage[1000];
	char c;
	int i = 0;
	int j;

//	scanf("%5c, garbage");
   while (scanf("%c", &c) != EOF) {
      skipNchar(74);
//	for(i=0; i<MAX_STUDENTS; ++i){
		for(j=0; j<TOTAL_QUESTIONS; ++j){
			scanf("%c", &c);
         if (isdigit(c))
			   answer[i][j] = c - '0';
         else
			   answer[i][j] = 0;
//			++i;
		//	printf("%i", answer[i][j]);
		} // for
    //  printf("\n");
      skipALine();
		++i;
	}
} // getAnswer

/*
compare answers with the key, stores the incorrect question numbers in miss[][TOTAL_QUESTIONS] and find the grade[i] for the student.
input: int key[TOTAL_QUESTIONS] (key array), int answer[][TOTAL_QUESTIONS] (answer array), int count (number of lines), double grade[] (array of student grades, int miss[][TOTAL_QUESTIONS] (array of questions missed)
output: none
*/
void findGrade(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, double grade[], int miss[][TOTAL_QUESTIONS]){
	int i;
	int j;
	double correct = 0;
	int incorrect = 0;
	count = 0;
	char c;
	
	for(i=0; i<MAX_STUDENTS; ++i){
		for(j=0; j<TOTAL_QUESTIONS; ++j){
			if(key[j] != answer[i][j]){
				count++;
				miss[i][j] = j+1;
				++incorrect;
			} // if
			else if(key[j] == answer[i][j]){
				++correct;
			} // else
			grade[i] = (correct/TOTAL_QUESTIONS);
		} // for j
		correct = 0;
		//printf("%lf\n", grade[i]);
	} // for i
	//printf("%i", count);
} // findGrade
 /*
 returns the class average
 input: double grade[] (array of student grades), int count (number of students)
 output: double classAvg (the class average)
 */
 
double findAvg(double grade[], int count){
	double classAvg = 0;
	double totalGrade = 0;
	int i;
	
	for(i=0; i<MAX_STUDENTS; ++i){
		totalGrade += grade[i];
	} // for
	classAvg = (totalGrade/count);
	
	return classAvg;
} // findAvg

/*
to print all necessary student grades output under the heading on screen
input: int key[TOTAL_QUESTIONS] (key array), int answer[][TOTAL_QUESTIONS] (answer array), int count (number of lines), double grade[] (array of student grades, int miss[][TOTAL_QUESTIONS] (array of questions missed)
ouput: none
*/

void outputResult(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, double grade[], int miss[][TOTAL_QUESTIONS]){
	
	int i;
	int j;
	count = 1;
	char c;
	
	printf("Key: ");
	
	for(i=0; i<TOTAL_QUESTIONS; ++i){
		printf("%i", key[i]);
	} // for
	printf("\n");
	printf("Student	Grade	Answer	  		     Wrong Questions\n");
	
	for(i=0; i<34; ++i){
		printf("%i	", count);
		printf("%.2f	", grade[i]*100);
		for(j=0; j<TOTAL_QUESTIONS; ++j){
			printf("%c", convertChar(answer[i][j]));
		} // for j
		for(j=0; j<TOTAL_QUESTIONS; ++j){
			if(miss[i][j] != 0){
				printf("% i", miss[i][j]);
			} // if
			else {
				printf(" ");
			} // else
		} // for j
		printf("\n");
		++count;
	}
		
	
} // outputResult
/*
for each question, find # of students that have correct answer and have each response
input: int key[TOTAL_QUESTIONS] (key array), int answer[][TOTAL_QUESTIONS] (answer array), int count (number of lines), int question_response[][MAX_CHOICES+1] (the choice made by eaach student), int question_correct[TOTAL_QUESTIONS] (array of number of students who answered the question correctly)
output: none
*/
void findQuestion(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int count, int question_response[][MAX_CHOICES+1], int question_correct[TOTAL_QUESTIONS]){
	
	int i;
	int j;
	int k;
	int blankCount = 0;
	int aCount = 0;
	int bCount = 0;
	int cCount = 0;
	int dCount = 0;
	int eCount = 0;
	count = 0;
	int correctCount = 0;


	for(j=0; j<TOTAL_QUESTIONS; ++j){
		for(k=0; k<MAX_CHOICES+1; ++k){
			for(i=0; i<34; ++i){

				if(answer[i][j] == key[j]){
					++correctCount;
				} // if// if
				
				if(key[j] == 1){
					++count;
				}
				else if(key[j] == 2){
					++count;
				} // else if
				else if(key[j] == 3){
					++count;
				} // else if
				else if(key[j] == 4){
					++count;
				} // else if
				else if(key[j] == 5){
					++count;
				} // else if
				question_correct[j] = correctCount;
			} // for i
			
			correctCount = 0;
			aCount = 0;
		} // for k
		
	} // for j

} // findQuestions

/*
to print all necessary output about each question under the heading on screen
input: int key[TOTAL_QUESTIONS] (key array), int answer[][TOTAL_QUESTIONS] (answer array), int count (number of lines), int question_response[][MAX_CHOICES+1] (the choice made by each student), int question_correct[TOTAL_QUESTIONS] (array of number of students who answered the question correctly)
output: none
*/

void outputQuestionResult(int key[TOTAL_QUESTIONS], int answer[][TOTAL_QUESTIONS], int question_correct[], int question_response[][MAX_CHOICES+1], int count) {

	int i;
	int j;
	int k;
	int questionNum = 1;
	int correct;
	double studentPer;

	printf("Question  Key  Correct %  Number of Responses\n");
	printf("               Students	  Blank  A  B  C  D  E\n");
	
	for(i=0; i<TOTAL_QUESTIONS; ++i){
		printf("%i	", questionNum);
		printf("%c 	 ", convertChar(key[i]));

		studentPer = question_correct[i];
		printf("%.02f	", (studentPer/34)*100);
		
		
		//for(k=0; k<MAX_CHOICES+1; ++k){
		//	for(j=0; j<MAX_STUDENTS; ++j){
		//		printf("%i", question_response[j][k]);
		//	}
		//}
		
		++questionNum;
		printf("\n");
	} // for

} // outputQuestionResult

/*
This sort the student grades only and sort in descending order 
input: double grade[](array of student grades, int n (number of students)
output: none
*/

void sortGrade(double grade[], int n) {
	int i;
	int j;
	int tmp;
	double median;

	printf("After sort:\n");
	for(i=0; i<n-1; ++i){
		for(j=0; j<n-i-1; ++j){
			if(grade[j] < grade[j+1]){
				swap(&grade[j], &grade[j+1]);
			} // if
			
		} // for j
		
	} // for i
	for(i=0; i<34; ++i){
		printf("%.2f\n", grade[i]*100);
	} // for
	median = findMedian(grade, n);
	printf("The median is %.2lf\n", median);
} // sortGrade

 /*
 swaps one element in an array with another
 input: double *a (pointer to a double), double *b (pointer to a double)
 output none
 */
void swap(double *a, double *b) {
    double tmp;

    tmp=*a;
    *a=*b;
    *b=tmp;

} // swap

/*
Finds the median in an array
input: double grade[](array of student grades), int n (number of students)
output: double grade (median grade)
*/
double findMedian(double grade[], int n) {

	if (n%2 == 1) // n is odd
		return grade[(n+1)/2-1];
	else
		return (grade[n/2-1]+grade[n/2])/2;

} // findMedian

/*
converts an int answer to a char answer
input: int ans (a integer answer)
output: char (a char answer)
*/

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

	} // switch

} // convertChar

 /*
 find unique grade and its frequency from grade  and returns number of rows in the unique grade array
 input: double grade[] (array of student grades), double unique_grade[] (array of unique student grades), int frequency[] (array of grade frequencies), int count (counter)
 */
int findFrequency(double grade[], double unique_grade[], int frequency[], int count) {

	int i, j, k;
	int gradeCount = 0;
	int rowCount = 0;
	int modeCount;
	double mode;
	double max = 0;
	
	printf("Grade	Frequency \n");
	for(i=0; i<34; ++i){
		if(grade[i] != grade[i+1]){
			unique_grade[i] = grade[i];
			printf("%.02f	", unique_grade[i]*100);
			++rowCount;
			
			
			if(grade[i] == unique_grade[i]){
				++gradeCount;
			} // if
			
			frequency[i] = gradeCount;
			printf("%i\n", frequency[i]);
		} // if
		
		modeCount = 0;
		//for(j=i+1; j<MAX_STUDENTS; ++j){
		//	if(grade[i] == grade[j]){
		//		++modeCount;
		//	} // if
		//	if(modeCount > max){
		//		max = modeCount;
		//		mode = grade[i];
		//	} // if
		//} // for j
	} // for i
	gradeCount = 0;
	
	
	printf("The mode is %.02f\n", mode);

	return rowCount;
} // findFrequency

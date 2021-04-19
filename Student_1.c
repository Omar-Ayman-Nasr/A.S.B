#include<stdlib.h>
#include<stdio.h>
 DynamicArray
// Students strcture
struct Students
{
	char Name[32];
	int ID;
	int BD[3];
	int Score;
};
void student_data(struct Students*stud,int i) {//function the collect initial students data
	char garbage;
	printf_s("please enter the name of student number %i \n", i + 1);
	scanf_s("%c", &garbage, 1);
	scanf_s("%[^\n]", stud->Name, 32);//entering the name of student
	
		printf_s("please enter ID of student number %i \n", i+1);
		scanf_s("%d", &stud->ID);
		printf_s("please enter birthday of student number %i day/month/year respectively each in a separate line \n", i+1);
		for (int i = 0;i < 3;i++)
		{
			scanf_s("%d", &stud->BD[i]);
		}
		printf_s("please enter Score of student number %i \n", i+1);
		scanf_s("%d", &stud->Score);
	    printf_s("Student number %i data taken successfully \n",i+1);
}
void insert(struct Students* stud) {//function to take data of student to be inserted
	char garbage;
	printf_s("please enter the name of new student \n");
	scanf_s("%c", &garbage, 1);
	scanf_s("%[^\n]", stud->Name, 32);

	printf_s("please enter ID of new student\n");
	scanf_s("%d", &stud->ID);
	printf_s("please enter birthday of new student  day/month/year respectively each in a separate line \n");
	for (int i = 0;i < 3;i++)
	{
		scanf_s("%d", &stud->BD[i]);
	}
	printf_s("please enter Score of new student\n");
	scanf_s("%d", &stud->Score);
	printf_s("New student data taken successfully \n");
}
void begin(struct Students* stud, int N) {
	for (int i = 1;i <= N;i++) {
		*(stud+N-i+1) = *(stud+N-i);//shifting elements of the array to the right to empty place at the begging



 main

	}
	printf_s("please enter the data of the new student \n");
	insert(stud);//insertion using insert function
}
void mid(struct Students* stud, int N) {
	int n = (N/2);
	for (int i = 1;i <= (N - n);i++){
		*(stud+N-i+1) = *(stud+N-i);//shifting elements of array after insertion index (N/2)
	}
	printf_s("please enter the data of the new student \n");
	insert(stud+n);//insertion using insert function
}
int main()
{
	printf_s("Welcome\n");
	int initial; //initial number of students
	int s;//variable used to store user choice of insertion
	struct Students* stud;//main pointer
	printf_s("please enter intial number of students\n");
	scanf_s("%d", &initial);
	stud = (struct Students*)malloc(initial);//initializing the dynamic array
	for (int i = 0;i < initial;i++) {
		student_data(stud+i,i);
	}// for loop to gather the initial students data
	printf_s("printing initial array elements \n");
	for (int i = 0;i < initial ;i++)//loop to print the array elements before insertion 
	{   
		printf_s("student %d name is: %s\n", i + 1, (stud + i)->Name);
		printf_s("student %d ID is: %d\n", i + 1, (stud + i)->ID);
		printf_s("student %d score is: %d\n", i + 1, (stud + i)->Score);
		printf_s("student %d birthdate is: %d /", i + 1, (stud + i)->BD[0]);
		printf_s(" %d /", (stud + i)->BD[1]);
		printf_s(" %d \n", (stud + i)->BD[2]);
	}
	if (initial == 1) {
		printf_s("please choose kind of insertion 1 for the beggining 2 for end \n");
		scanf_s("%d", &s);
		switch (s) {
		case 1: {begin(stud, initial);//function to insert at the beggining
			break;
		}
		case 2: { printf_s("please enter the data of the new student \n");
			insert(stud+initial );//insertion using student data function
			break;
		}
		default:printf_s("wrong entry you must choose 1 or 2 \n");
		}
	}
	else {
		printf_s("please choose kind of insertion 1 for the beggining 2 for middle 3 for end \n");
		scanf_s("%d", &s);
		switch (s) {
		case 1: {begin(stud, initial);//function to insert at the beggining
			break;
		}
		case 2: {mid(stud, initial);//function to insert at the middle
			break;
		}
		case 3: { printf_s("please enter the data of the new student \n");
			insert(stud+ initial );//insertion using student data function
			break;
		}
		default:printf_s("wrong entry you must choose from 1 to 3 \n");
		}
	}
	printf_s("printing array elemtens after insertion \n");
	for (int i = 0;i < initial + 1;i++)//loop to print the array elements after insertion the counter is incremented by 1 to consider the new insertion
	{
		
		printf_s("student %d name: %s\n", i + 1, (stud + i)->Name);
		printf_s("student %d ID: %d\n", i + 1, (stud + i)->ID);
		printf_s("student %d score: %d\n", i + 1, (stud + i)->Score);
		printf_s("student %d birthdate: %d /", i + 1, (stud + i)->BD[0]);
		printf_s(" %d /", (stud + i)->BD[1]);
		printf_s(" %d \n", (stud + i)->BD[2]);
	}
	return 0;
}

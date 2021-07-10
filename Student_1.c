#include<stdlib.h>
#include<stdio.h>
// Students strcture
struct Students
{
	char Name[32];
	int ID;
	int BD[3];
	int Score;
};
int N=0;//size of array
void student_data(struct Students* stud, int i) {//function the collect initial students data
	char garbage;
	printf("please enter the name of student number %i \n", i + 1);
	scanf("%c", &garbage, 1);
	scanf("%[^\n]", stud->Name, 32);//entering the name of student

	printf("please enter ID of student number %i \n", i + 1);
	scanf("%d", &stud->ID);
	printf("please enter birthday of student number %i day/month/year respectively each in a separate line \n", i+1);
		for (int i = 0;i < 3;i++)
		{
			scanf("%d", &stud->BD[i]);
		}
	printf("please enter Score of student number %i \n", i + 1);
	scanf("%d", &stud->Score);
	printf("Student number %i data taken successfully \n", i + 1);
	N++;
}
void newstudent(struct Students* stud) {//function to take data of new student to be inserted
	char garbage;
	printf("please enter the name of new student \n");
	scanf("%c", &garbage, 1);
	scanf("%[^\n]", stud->Name, 32);

	printf("please enter ID of new student\n");
	scanf("%d", &stud->ID);
	printf("please enter birthday of new student  day/month/year respectively each in a separate line \n");
	for (int i = 0;i < 3;i++)
	{
		scanf("%d", &stud->BD[i]);
	}
	printf("please enter Score of new student\n");
	scanf("%d", &stud->Score);
	printf("New student data taken successfully \n");
	N++;
}
void insert(struct Students* stud, int index) {//function to insert a new student
		for (int i = 0;i <=(N-index+1);i++) {
			*(stud + N +1- i ) = *(stud + N - i);//shifting elements of array after insertion index 
		}
		newstudent(stud + index-1);//insertion using insert function
		
}
int main()
{printf("The size of structure %d\n", sizeof(struct Students));
	
	printf("Welcome\n");
	int initial; //initial number of students
	int index;// variable used for insertion index
	int s;//variable used to store user choice of insertion
	int c=1;//variable to store when to terminate
	struct Students* stud;//main pointer
	printf("please enter intial number of students\n");
	scanf("%d", &initial);
	stud = (struct Students*)malloc(initial);//initializing the dynamic array
	for (int i = 0;i < initial;i++) {
		student_data(stud + i, i);
	}// for loop to gather the initial students data
	printf("printing initial array elements \n");
	for (int i = 0;i < initial;i++)//loop to print the array elements before insertion 
	{
		printf("student %d name is: %s\n", i + 1, (stud + i)->Name);
		printf("student %d ID is: %d\n", i + 1, (stud + i)->ID);
		printf("student %d score is: %d\n", i + 1, (stud + i)->Score);
		printf("student %d birthdate is: %d /", i + 1, (stud + i)->BD[0]);
		printf(" %d /", (stud + i)->BD[1]);
		printf(" %d \n", (stud + i)->BD[2]);
	}
	while (c) {
			printf("please choose kind of insertion 1 for the beggining 2 for end 3 for any index 4 to terminate \n");
			scanf("%d", &s);
			switch (s) {
			case 1: {insert(stud, 1);// insert at the beggining (insertion at index 1)
				break;
			}
			case 2: {insert(stud, N+1);// insert at the end (insertion at index N+1)
				break;
			}
			case 3: { printf("please enter the index of the new student \n");
				scanf("%d", &index);
				if(index<=(N+1))
				insert(stud, index);//insertion using insert function
				else {
					printf("wrong entry you must enter a valid index \n");

				}
				break;
			}
			case 4:c = 0;
				break;
			default:printf("wrong entry you must choose from 1 to 3 \n");
			}
		}
	printf("printing array elemtens after insertion \n");
	for (int i = 0;i < N ;i++)//loop to print the array elements after insertion 
	{

		printf("student %d name: %s\n", i + 1, (stud + i)->Name);
		printf("student %d ID: %d\n", i + 1, (stud + i)->ID);
		printf("student %d score: %d\n", i + 1, (stud + i)->Score);
		printf("student %d birthdate: %d /", i + 1, (stud + i)->BD[0]);
		printf(" %d /", (stud + i)->BD[1]);
		printf(" %d \n", (stud + i)->BD[2]);
	}
	return 0;
}
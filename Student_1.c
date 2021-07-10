/* Name: Omar Ayman Ahmed Nasr     Omar Ahmed Saad Ali      Ali Badry Abd El-Naim Abd EL-Malek
   Section: 3                         3                          3
   B.N:     12                        9                          4 */
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
// Students strcture
struct Students
{
    char Name[32];
    int ID;
    int BD[3];
    int Score;
};


int N = 0;//size of array


//dynamic array functions
void student_data(struct Students* stud, int i) {//function the collect initial students data
    char garbage;
    printf("please enter the name of student number %i \n", i + 1);
    scanf("%c", &garbage, 1);
    scanf("%[^\n]", stud->Name, 32);//entering the name of student

    printf("please enter ID of student number %i \n", i + 1);
    scanf("%d", &stud->ID);
    printf("please enter birthday of student number %i day/month/year respectively each in a separate line \n", i + 1);
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
    
    for (int i = 0;i <= (N - index + 1);i++) {
        *(stud + N + 1 - i) = *(stud + N - i);//shifting elements of array after insertion index 
    }
    newstudent(stud + index - 1);//insertion using insert function

}

// size of the linked list
int length = 0;

//Linked list structure
struct node
{
    struct node* next;
    struct Students data;
};

struct node* head = NULL;
struct node* tail = NULL;


// function for node creation
void Node_Creation(struct node* new)
{
    char garbage;
    printf("please enter the name of student number %d \n", length + 1);
    scanf("%c", &garbage, 1);
    scanf("%[^\n]", &new->data.Name, 32);
    printf("Please, Enter the ID of the student number %d \n", length + 1);
    scanf("%d", &new->data.ID);
    printf("Please, Enter the birthday of the student number %d \n", length + 1);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &new->data.BD[i]);
    }
    printf("Please, Enter the last year score of the student number %d \n", length + 1);
    scanf("%d", &new->data.Score);

}


// linked list functions
// function for inserting node
void insert_Linked_List()
{

    int option;  // to choose the position at which we will insert
    int terminate = 1; // to terminate the function if terminate = 0

    while (terminate)
    {
        printf("Please enter\n1.to insert at the beginning\n2.to insert at the end\n3.to insert at any any index\n4.to display and terminate\n");
        scanf("%d", &option);
        struct node* NewNode = (struct node*)malloc(sizeof(struct node));

        switch (option)
        {
        case 1:   // head insertion
        { 
            clock_t start_t1 =clock();
            Node_Creation(NewNode);
            if (head == NULL)
            {
                head = NewNode;
                head->next = NULL;
                tail = head;
                tail->next = NULL;
            }
            else
            {
                NewNode->next = head;
                head = NewNode;
            }
            clock_t end_t1 = clock();
            double time_spent1 = ((double)(end_t1 - start_t1)) / CLOCKS_PER_SEC;
            printf("Time taken when inserting at the beggining using Linked List is %f\n",time_spent1);
            length++;
            break;
        }


        case 2: // tail insertion
        {
            clock_t start_t2 =clock();
            Node_Creation(NewNode);
            if (head == NULL)
            {
                head = NewNode;
                head->next = NULL;
                tail = head;
                tail->next = NULL;
            }
            else
            {
                tail->next = NewNode;
                NewNode->next = NULL;
                tail = NewNode;
            }
            clock_t end_t2 = clock();
            double time_spent2 = ((double)(end_t2 - start_t2)) / CLOCKS_PER_SEC;
            printf("Time taken when inserting at the beggining using Linked List is %f\n",time_spent2);
            length++;
            break;
        }


        case 3:  // index insertion
        {
            int index;
            printf("Please enter the index at which you want to insert: ");
            scanf("%d", &index);
            clock_t start_t3 =clock();
            Node_Creation(NewNode);
            if (head == NULL)
            {
                head = NewNode;
                head->next = NULL;
                tail = head;
                tail->next = NULL;
            }
            else
            {
                struct node* temp = head;
                for (int i = 1; i < index - 1; i++)
                {
                    temp = temp->next;
                }
                NewNode->next = temp->next;
                temp->next = NewNode;

            }
            clock_t end_t3 = clock();
            double time_spent3 = ((double)(end_t3 - start_t3)) / CLOCKS_PER_SEC;
            printf("Time taken when inserting at any index using Linked List is %f\n",time_spent3);
            length++;
            break;
        }

        case 4:
        {
            terminate = 0;
            break;
        }
        }
    }
    return;
}


// function to display the data of each node
void display()
{
    int j = 1;
    for (struct node* tempp = head; tempp != NULL; tempp = tempp->next)
    {
        printf("The name of student number %d is %s  \n", j, tempp->data.Name);
        printf("The ID of student number %d is %d  \n", j, tempp->data.ID);
        printf("The Birthday of student number %d is ", j);
        for (int i = 0; i < 2; i++)
        {
            printf("%d/", tempp->data.BD[i]);
        }
        printf("%d\n", tempp->data.BD[2]);


        printf("The Score of student number %d is %d   \n", j, tempp->data.Score);
        j++;
    }
}
int main()
{
    int x; // variable to choose the insertion mode between linked list or dynamic array
    printf("                             Welcome\n");
    printf("The size of structure %d\n", sizeof(struct Students));
    printf("The size of node %d\n", sizeof(struct node));
    printf("Please enter 1 for linked list, 2 for dynamic array\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
    {
        insert_Linked_List();
        display();
    }
    break;
    case 2:
    {
        int initial; //initial number of students
        int index;// variable used for insertion index
        int s;//variable used to store user choice of insertion
        int c = 1;//variable to store when to terminate
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
            printf("Please enter\n1.to insert at the beginning\n2.to insert at the end\n3.to insert at any any index\n4.to display and terminate\n");
            scanf("%d", &s);
            switch (s) {
            case 1: {
                clock_t start_t1 =clock();
                insert(stud, 1);// insert at the beggining (insertion at index 1)
                clock_t end_t1 = clock();
             double time_spent1 = ((double)(end_t1 - start_t1)) / CLOCKS_PER_SEC;
             printf("Time taken when inserting at the beggining using dynamic array is %f\n",time_spent1);
                
                break;
            }
            case 2: {
                clock_t start_t2 =clock();
                insert(stud, N + 1);// insert at the end (insertion at index N+1)
                clock_t end_t2 = clock();
             double time_spent2 = ((double)(end_t2 - start_t2)) / CLOCKS_PER_SEC;
             printf("Time taken when inserting at the end using dynamic array is %f\n",time_spent2);
                break;
            }
            case 3: { printf("please enter the index of the new student \n");
                scanf("%d", &index);
                if (index <= (N + 1))
                {
                    clock_t start_t3 =clock();
                    insert(stud, index);//insertion using insert function
                    clock_t end_t3 = clock();
             double time_spent3 = ((double)(end_t3 - start_t3)) / CLOCKS_PER_SEC;
             printf("Time taken when inserting at any index using dynamic array is %f\n",time_spent3);
                }
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
        for (int i = 0;i < N;i++)//loop to print the array elements after insertion 
        {

            printf("student %d name: %s\n", i + 1, (stud + i)->Name);
            printf("student %d ID: %d\n", i + 1, (stud + i)->ID);
            printf("student %d score: %d\n", i + 1, (stud + i)->Score);
            printf("student %d birthdate: %d /", i + 1, (stud + i)->BD[0]);
            printf(" %d /", (stud + i)->BD[1]);
            printf(" %d \n", (stud + i)->BD[2]);
        }
    }
    break;

    }


    return 0;
}


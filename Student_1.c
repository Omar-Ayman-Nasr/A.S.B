#include<stdio.h>
#include <stdlib.h>
// Students strcture
struct Students
{
     char Name[32];
	 int ID;
	 int BD[3];
	 int Score;
};
int ii=0; //the global counter of the linked list
struct node
{
    struct Students st;
    struct node* next;
};
void insert(struct node* n)
{
    printf("please enter the student's name:"); scanf("%s", n->st.Name);
    printf("\n please enter the student's ID:"); scanf("%i",&n->st.ID);
    printf("\n please enter the student's birthday:(day month year)"); scanf("%i %i %i",&n->st.BD[0], &n->st.BD[1], &n->st.BD[2]);
    printf("\n please enter the last year score:"); scanf("%i", &n->st.Score);
    ii++;
};
void display(struct node* n)
{
    while(n!=NULL)
    {
    printf("\n -------------------------------------------");
    printf("\n student's name:"); printf("%s",n->st.Name);
    printf("\n student's ID:"); printf("%i",n->st.ID);
    printf("\n student's birthday:(day month year) "); printf(" %i %i %i", n->st.BD[0], n->st.BD[1], n->st.BD[2]);
    printf("\n last year score:"); printf("%i", n->st.Score);
    printf("\n --------------------------------------------");
    n=n->next;
    }
};
 int main ()
 {
	printf("Welcome\n");
	int QA1; //QA1 is the menu list numbers
    int QA2; //QA2 is the sub-menu list numbers
    int k;  //the node number in inserting in the middle
    struct node* head=NULL;
    struct node* tail=NULL;
    struct node* n=NULL;
    struct node* tem=NULL;
    n =(struct node*) malloc(sizeof(struct node));
    head=n;
    tail=n;
    n->next=NULL;
    insert(n);
    again:
    printf("\n Do you wish to.. (choose a number) \n");
    printf("1. insert a student's info \n");
    printf("2. display a students' info \n");
    printf("3. The number of nodes \n");
    printf("4. Exit \n");

    scanf("%i", &QA1);
    if(QA1==1)
    {
       repeat2:
        printf("1. At the beginning \n 2.In the middle \n 3.At the end \n");
        scanf("%i",&QA2);
        if(QA2==1)
        {
            n =(struct node*) malloc(sizeof(struct node));
            n ->next=head;
            head=n;
            insert(n);
        }
        else if(QA2==2)
        {
            n =(struct node*) malloc(sizeof(struct node));
            printf("\n please insert the node number(1 or more): "); scanf("%i",&k);
            while(k>=ii)
            {
                printf("please insert a number maller than %i", ii);
                scanf("%i", &k);
            }
            tem=head;
            for(int i=1;i<k;i++)
            {
                tem=tem->next;
            }
            n->next = tem->next;
            tem->next=n;
            insert(n);
        }
        else if(QA2==3)
        {
            n =(struct node*) malloc(sizeof(struct node));
            tail->next = n;
            tail = tail->next;
            n->next=NULL;
            insert(n);
        }
        else
        {
            printf("unavailable number");
            goto repeat2;
        }
    }
    else if(QA1==2)
    {
        tem=head;
        display(tem);
    }
    else if(QA1==3) printf("The number of students: %i \n", ii);
    else if(QA1==4) {goto hault;}
    goto again;
   hault:
    return 0;
 }


#include<stdio.h>
#include <stdlib.h>
// Students structure
struct Students
{
     char Name[20];
	 int ID;
	 int BD[3];
	 int Score;
};
int NO; // the number of the initialized linked list
struct node
{
    struct Students st;
    struct node* next;
};
struct node* n=NULL;
struct node* head=NULL;
struct node* tail=NULL;
void create_nodes()
{
    n =(struct node*) malloc(sizeof(struct node));
    struct node* tem=NULL;
    head=n;
    tail=n;
    n->next=NULL;
    for(int i=1;i<NO;i++)
    {
        tem=n;
        n =(struct node*) malloc(sizeof(struct node));
        tem->next=n;
        tail=n;
        n->next=NULL;
    }
}

void node_location()
{
    int QA2; //QA2 is the sub-menu list numbers
    int k;  //the node number in inserting in the middle
    struct node* tem=NULL;
    for(int i=0;i<NO;i++)
    {
        printf("Insert the node : \n 1. At the beginning \n 2.In the middle \n 3.At the end \n");
        scanf("%i",&QA2);
        if(QA2==1)
        {
            tem=head;
            insert(tem);
        }
        else if(QA2==2)
        {
            printf("\n please insert the node number(more than 1 and less than the size :3): "); scanf("%i",&k);
            while(k>=NO)
            {
                printf("please insert a number smaller than %i", NO);
                scanf("%i", &k);
            }
            tem=head;
            for(int j=1; j<=k ; j++)
            {
                tem=tem->next;
            }
            insert(tem);
        }
        else if(QA2==3)
        {
            insert(tail);
        }
    }
};

void insert(struct node* p)
{
    printf("please enter the student's name:"); scanf("%s", p->st.Name);
    printf("\n please enter the student's ID:"); scanf("%i",&p->st.ID);
    printf("\n please enter the student's birthday:(day month year)"); scanf("%i %i %i",&p->st.BD[0], &p->st.BD[1], &p->st.BD[2]);
    printf("\n please enter the last year score:"); scanf("%i", &p->st.Score);
};
void display()
{
    struct node* tem=NULL;
    tem=head;
    while(tem!=NULL)
    {
    printf("\n -------------------------------------------");
    printf("\n student's name:"); printf("%s",tem->st.Name);
    printf("\n student's ID:"); printf("%i",tem->st.ID);
    printf("\n student's birthday:(day month year) "); printf(" %i %i %i", tem->st.BD[0], tem->st.BD[1], tem->st.BD[2]);
    printf("\n last year score:"); printf("%i", tem->st.Score);
    printf("\n --------------------------------------------");
    tem=tem->next;
    }
};
 int main ()
 {
	printf("Welcome\n");
	int QA1; //QA1 is the menu list numbers
    struct node* tem=NULL;
    printf("please enter the number of nodes:");
    scanf("%i", &NO);
    create_nodes();
    node_location();
    printf("\n Do you wish to.. (choose a number) \n");
    printf("1. display a students' info \n");
    printf("2. The number of nodes \n");
    printf("3. Exit \n");

    scanf("%i", &QA1);
    if(QA1==1)
    {
        display();
    }
    else if(QA1==2) printf("The number of students: %i \n", NO);
    else if(QA1==3) {goto hault;}
   hault:
    return 0;
 }


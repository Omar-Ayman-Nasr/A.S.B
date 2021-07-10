#include <stdlib.h>
#include <stdio.h>
// Students structure
struct Students
{
    char Name[32];
    int ID;
    int BD[3];
    int Score;
};


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



// function for inserting node
void insert()
{

    int option;  // to choose the position at which we will insert
    int terminate = 1; // to terminate the function if terminate = 0

    while(terminate)
    {
    printf("Please enter\n1. to insert at the beginning\n2. to insert at the end\n3 to insert at any any index\n4.to display and terminate\n");
    scanf("%d",&option);
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));

    switch (option)
    {
     case 1 :   // head insertion
    {
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
    length++;
    break ;
    }


    case 2: // tail insertion
    {
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
    length++;
    break;
    }


    case 3:  // index insertion
    {
    int index;
    printf("\nPlease enter the index at which you want to insert: ");
    scanf("%d",&index);
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
        for(int i = 1 ; i < index-1 ; i++)
        {
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;

    }
    length++;
    break ;
    }

    case 4 :
    {
    terminate = 0;
    break ;
    }
    }
    }
    return ;
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
    printf("                             Welcome\n");
    insert();
    display();
    return 0;
}

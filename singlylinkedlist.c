#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30

struct emp_data
{
    int  empno;
    char empName[MAX];
    char designation[MAX];
    struct emp_data *next;
};

struct emp_data *insert(struct emp_data *front,int id, char name,char desg)
{
	struct emp_data *new_node;
	new_node = (struct emp_data*)malloc(sizeof(struct emp_data));
	if(new_node ==NULL)
	{
	printf("allocation failed\n");
	}
new_node->empno = id;
strcpy(new_node->empName,name);
strcpy(new_node->designation,desg);
new_node->next = front;
front= new_node;
return (front);
}

void printNode(struct emp_data *p)
{
    printf("\n Employee Details...\n");
    printf("\n Emp No       : %d", p->empno);
    printf("\n Name           : %s", p->empName);
    printf("\n Designation    : %s\n", p->designation);
    printf("-------------------------------------\n");
}

struct emp_data *delete(struct emp_data *front, int id)
{
struct emp_data *ptr, *bptr ;

	if(front->empno == id)
	{
	ptr = front;
printf("the deleted node : \n");
printNode(front);
front= front->next;
free(ptr);
	}

	for(ptr= front->next,bptr= front;ptr!=NULL;ptr= ptr->next,bptr= bptr->next)
	{
if(ptr->empno== id)
{
	 printf("\n Node deleted:");
            printNode(ptr);
            bptr->next = ptr->next;
            free(ptr);
            return(front);

}

	}

	printf("employee ID not found\n");

}

void search(struct emp_data *front, int key)
{
struct emp_data *ptr;
	for(ptr = front;ptr!=NULL;ptr = ptr->next)
	{
if(ptr->empno==key)
{
printf("the ID has been found\n");
printNode(ptr);
return;
}

	}

}

void display(struct emp_data  *front)
{
    struct emp_data *ptr;
 
    for (ptr = front; ptr != NULL; ptr = ptr->next)
    {
        printNode(ptr);
    }
}

void menu()
{
    printf("---------------------------------------------\n");
    printf("Press 1 to INSERT a node into the list       \n");
    printf("Press 2 to DELETE a node from the list       \n");
    printf("Press 3 to DISPLAY the list                 \n");
    printf("Press 4 to SEARCH the list                   \n");
    printf("Press 5 to EXIT                              \n");
    printf("---------------------------------------------\n");
}

char option()
{
    char choice;
 
    printf("\n\n>> Enter your choice: ");
    switch(choice=getchar())
    {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':   return(choice);
        default :   printf("\n Invalid choice.");
    }
    return choice;
}
void main()
{
    struct emp_data *linkList;
    char *name, *desig;
    char choice;
    int eno;
 
    linkList = NULL;
    printf("\n Welcome to demonstration of singly linked list \n");
    menu();
    do
    {
        /*  choose oeration to be performed */
        choice = option();
        switch(choice)
        {
        case '1':
            printf("\n Enter the Employee Number      : ");
            scanf("%d", &eno);
            
            printf("Enter the Employee Designation : ");
            scanf("%s",desig);

            printf("Enter the Employee name        : ");

            scanf("%s",name);
            linkList = insert(linkList, eno, name, desig);
            break;
        case '2':
            printf("\n\n Enter the employee number to be deleted: ");
            scanf("%d", &eno);
            linkList = delete(linkList, eno);
            break;
        case '3':
            if (linkList == NULL)
            {
                printf("\n List empty.");
                break;
            }
            display(linkList);
            break;
        case '4':
            printf("\n\n Enter the employee number to be searched: ");
            scanf("%d", &eno);
            search(linkList, eno);
            break;
        case '5': break;
        }
    } while (choice != '5');
}

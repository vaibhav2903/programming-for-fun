
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void main(){
	
struct node{
	
	int num;
	struct node *ptr;

};

typedef struct node NODE;
NODE *head, *first = 0 , *temp = 0;

int count = 0;

int choice = 1;

while(choice)
{
	head = (NODE *)malloc(sizeof(NODE));
printf("enter the data?\n");

scanf("%d",&head->num);

if(first!=0)
{
	
temp->ptr = head;
temp =  head;
}
else{
	first = head;
	 temp = head;
}

fflush(stdin);
printf("3");
printf("do u want to continue?(type 1 for yes and 0 for NO)\n");
scanf("%d",&choice);

}
temp->ptr= 0; temp = first;
printf("the linkied list is\n");

while(temp!=0)
{
	printf("%d=>",temp->num);
	count++;
	temp = temp->ptr;


}

printf("the number of nodes are %d",count);

}

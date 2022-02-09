#include<stdio.h>
struct node
{
	int id;
	struct node *next;
}*start=NULL,*ptr,*newnode,*pre;
struct node *create(struct node *);
struct node *insertbeg(struct node *);
struct node *insertend(struct node *);
struct node *insertmiddle(struct node *);
struct node *deletebeg(struct node *);
struct node *deleteend(struct node *);
struct node *deletemiddle(struct node *);
void display(struct node *);
void main()
{
	int ch;
	while(1)
	{
		
			printf("**********linked list menu************\n");
			printf("*      1.create                      *\n");
			printf("*      2.insert at begin             *\n");
			printf("*      3.insert at end               *\n");
			printf("*      4.insert at middle            *\n");
			printf("*      5.delete at begin             *\n");
			printf("*      6.delete at end               *\n");
			printf("*      7.delete at middle            *\n");
			printf("*      8.display                     *\n");
			printf("*      9.exit                        *\n");
			printf("**************************************\n");
		    printf("enter ur choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:start=create(start);
			break;
			case 2:start=insertbeg(start);
			break;
			case 3:start=insertend(start);
			break;
			case 4:start=insertmiddle(start);
			break;
			case 5:start=deletebeg(start);
			break;
			case 6:start=deleteend(start);
			break;
			case 7:start=deletemiddle(start);
			break;
			case 8:display(start);
			break;
			default:exit(0);
		}
	}
}
struct node *create(struct node *start)
{
	int n;
	printf("enter n \n");
	scanf("%d",&n);
	newnode=malloc(sizeof(struct node));
	newnode->id=n;
	if(start==NULL)
	{
	 start=newnode;
	 newnode->next=NULL;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
		ptr=ptr->next;
	    }
	    ptr->next=newnode;
	    newnode->next=NULL;
	}
	return start;
}
struct node *insertbeg(struct node *start)
{
	int n;
	printf("enter n \n");
	scanf("%d",&n);
	newnode=malloc(sizeof(struct node));
	newnode->id=n;
	newnode->next=start;
	start=newnode;
	return start;
}
struct node *insertend(struct node *start)
{
	int n;
	printf("enter n \n");
	scanf("%d",&n);
	newnode=malloc(sizeof(struct node));
	newnode->id=n;
     ptr=start;
		while(ptr->next!=NULL)
		{
		ptr=ptr->next;
	    }
	    ptr->next=newnode;
	    newnode->next=NULL;
	return start;
}
struct node *insertmiddle(struct node *start)
{
	int n,x,count=0;
	printf("enter n \n");
	scanf("%d",&n);
	printf("enter the position\n");
	scanf("%d",&x);
	newnode=malloc(sizeof(struct node));
	newnode->id=n;
	ptr=start;
	while(count!=x-1)
	{
		pre=ptr;
		count++;
		ptr=ptr->next;
	}
	pre->next=newnode;
	newnode->next=ptr;
	return start;
}

struct node *deletebeg(struct node *start)
{
	ptr=start;
	start=start->next;
	free(ptr);
	return start;
}
struct node *deleteend(struct node *start)
{
   ptr=start;
   while(ptr->next!=NULL)
   {
   	pre=ptr;
   	ptr=ptr->next;
	   }	
	pre->next=NULL;
	free(ptr);
	return start;
}
struct node *deletemiddle(struct node *start)
{
	int x,count=0;
	printf("enter the position\n");
	scanf("%d",&x);
	ptr=start;
		while(count!=x-1)
	{
		pre=ptr;
		count++;
		ptr=ptr->next;
	}
	pre->next=ptr->next;
	free(ptr);
	return start;
}
void display(struct node *start)
{
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d   ",ptr->id);
		ptr=ptr->next;
	}
	printf("\n");
}

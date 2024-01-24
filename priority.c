#include<stdio.h>
#define MAX 100
int QUEUE[MAX];
int FRONT=-1;
int REAR=-1;
void insert(int);
void pop();
void display();
void main()
{
    int choice;
   
    while(1)
    {
        printf("1.TO INSERT\n2.TO DELETE\n3.TO DISPLAY");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int val;
                printf("ENTER VALUE TO INSERT");
                scanf("%d",&val);
                insert(val);
                break;
            }
            case 2:
            {
               
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            default:printf("enter correct choice");
                    break;
            
        }
    }
}
void insert(int data)
{
    if (REAR == (MAX - 1))
    {
        printf("QUEUE OVERFLOW\n");
    }
    else if (FRONT == -1 && REAR == -1)
    {
        FRONT++;
        REAR++;
        QUEUE[REAR] = data;
    }
    else
    {
        int i;
        for (i = REAR; i >= 0 && data >= QUEUE[i]; i--)
        {
            QUEUE[i + 1] = QUEUE[i];
        }
        QUEUE[i + 1] = data;
        REAR++;
    }
}

void pop()
{
    int del_ele;
    printf("enter the element to delete");
    scanf("%d",&del_ele);
    if(FRONT==-1 && REAR==-1)
    {
       printf("QUEUE IS EMPTY\n") ;
    }
    else
    {
        for(int i=0;i<=REAR;i++)
        {
            if(QUEUE[i]==del_ele)
            {
                for(int j=i;j<=REAR;j++)
                {
                    QUEUE[i]=QUEUE[i+1];
                    
                }
                 REAR--;
            }
            else
            {
                printf("ELEMENT NOT FOUND!\n");
            }
        }
       
    }
}
void display()
{
    printf("THE QUEUE ELEMENTS ARE:");
    if(FRONT==-1 && REAR==-1)
    {
        printf("QUEUE IS EMPTY");
    }
    else
    {
    for(int i=FRONT;i<=REAR;i++)
   { printf("%d",QUEUE[i]);
    printf("\n");}
    }
}

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void display();
void sort();
void reverse();
void main()
{
    int choice;
    while(1)
    {
        printf("1.INSERT AT BEGINNING.\n2.INSERT AT END\n3.INSERT AT POSITION\n4.DELETE AT BEGINNING\n5.DELETE AT END\n6.DELETE AT POS\n7.DISPLAY\n8.SORT\n9.REVERSE\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert_beg();
                    break;
            case 2: insert_end();
                    break;
            case 3: insert_pos();
                    break;
            case 4:delete_beg();
                   break;
            case 5:delete_end();
                   break;
            case 6:delete_pos();
                   break;
            case 7: display();
                    break;
            case 8:sort();
                   break;
            case 9:reverse();
                   break;
            default:printf("ENTER CORRECT CHOICE\n");
                    break;
                    
        }
    }
}
void insert_beg()
{
    int val;
    printf("ENTER VALUE TO INSERT AT BEGINNING");
    scanf("%d",&val);
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("MEMORY FULL!");
    }
    else
    {
        ptr->data=val;
        if(head==NULL)
        {
          head=ptr;
          ptr->next=NULL;
        }
        else
        {
            ptr->next=head;
            head=ptr;
        }
    }
}
void insert_end()
{
     int val;
    printf("ENTER VALUE TO INSERT AT END");
    scanf("%d",&val);
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("MEMORY FULL!");
    }
    else
    {
        ptr->data=val;
        if(head==NULL)
        {
            head=ptr;
            ptr->next=NULL;
        }
        else
        {
            struct node* temp;
            temp=head;
            while(temp->next !=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
        }
    }
}
void display()
{
    struct node* ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("LINKED LIST IS EMPTY");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
    }
}

void insert_pos()
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("MEMORY FULL!");
        return;
    }

    int val, pos;
    printf("ENTER DATA: ");
    scanf("%d", &val);
    ptr->data = val;

    printf("ENTER POSITION: ");
    scanf("%d", &pos);

    if (pos == 0)
    {
        ptr->next = head;
        head = ptr;
        return;
    }

    struct node* temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid position.\n");
            free(ptr); // Release memory before returning
            return;
        }
    }

    ptr->next = temp->next;
    temp->next = ptr;
}
void delete_beg()
{
    if(head==NULL)
    {
        printf("LINKED LIST EMPTY");
    }
    else
    {
        struct node* ptr=head;
        head=ptr->next;
        free(ptr);
    }
}
void delete_end()
{
    struct node* ptr1;
    struct node* ptr2;
    if(head==NULL)
    {
        printf("LINKED LIST ID EMPTY");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
    }
    else
    {
      ptr1=head;
      while(ptr1->next!=NULL)
      {
          ptr2=ptr1;
          ptr1=ptr1->next;
      }
      ptr2->next=NULL;
      free(ptr1);
    }
   
}
void delete_pos()
{
    int pos;
    printf("enter position to delete");
    scanf("%d",&pos);
    struct node*ptr1,*ptr2;
    ptr1=head;
    for(int i=0;i<pos;i++)
    {
        ptr2=ptr1;
        ptr1=ptr1->next;
    }
    ptr2->next=ptr1->next;
    free(ptr1);
}
void sort()
{
    struct node* ptr;
    struct node* nxtptr;
    int temp;
    ptr=head;
    while(ptr->next!=NULL)
    {
        nxtptr=ptr->next;
        while(nxtptr!=NULL)
        {
            if(nxtptr->data >= ptr->data)
            {
                temp=nxtptr->data;
                nxtptr->data=ptr->data;
                ptr->data=temp;
            }
            nxtptr=nxtptr->next;
        }
       ptr=ptr->next; 
    }
}
void reverse()
{
    struct node* ptr,*next;
    struct node* prev=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
       next=ptr->next;
       ptr->next=prev;
       prev=ptr;
       ptr=next;
    }
    head=prev;
}

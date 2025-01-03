#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int a[MAX];
int top=-1;
void push(int item)
{
    if(top==MAX-1)
    {
        printf("stack overflow\n");
        return;
    }
    top=top+1;
    a[top]=item;
}
int pop()
{
    if (top==-1)
    {
        printf("stack underflow\n");
        return -1;
    }
    int item=a[top];
    top=top-1;
    return item;
}
void display()
{
    if (top==-1)
    {
        printf("stack is empty\n");
        return;
    }
    printf("stack elements are:\n");
    for (int i=top;i>=0;i--)
    {
        printf("%d\n",a[i]);
    }
    printf("\n");
}
void palindrome()
{
    int flag=1;
    int i;
    printf("stack elements are:\n");
    for (i=top;i>=0;i--)
    {
        printf("%d\n",a[i]);
    }
    printf("\nReversed stack elements are:\n");
    for (i=0;i<=top;i++)
    {
        printf("%d\n",a[i]);
    }
    for (i=0;i<=top/2;i++)
    {
        if (a[i]!=a[top-i])
        {
            flag=0;
            break;
        }
    }
    if (flag==1)
    {
        printf("stack elements are palindrome\n");
    }
    else
    {
        printf("stack elements are not palindrome\n");
    }
    {
        printf("stack is empty\n");
    }
}
void main()
{
    int item,choice;
    for(;;)
    {
        printf("1.push\n2.pop\n3.display\n4.palindrome\n5.exit\n");
        printf("enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the element to be pushed:");
                   scanf("%d",&item);
                   push(item);
                   break;
            case 2:item=pop();
                   if (item!=-1)
                   {
                       printf("popped item is:%d\n",item);
                   }
                   break;
            case 3:display();
                   break;
            case 4:palindrome();
                   break;
            case 5:exit(0);
            default:printf("invalid choice\n");
        }
    }
}
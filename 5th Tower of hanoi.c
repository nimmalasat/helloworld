#include<stdio.h>
#include<string.h>
#include<math.h>
int count=0,top=-1;
int operate(char symb,int op1,int op2)
{
    switch (symb)
    {
    case '+':return op1+op2;
    case '-':return op1-op2;
    case '*':return op1*op2;
    case '/':return op1/op2;
    case '^':return pow(op1,op2);
    case '%':return op1%op2;
    }
}
void push(int s[],int n)
{
    s[++top]=n;   
}
int pop(int s[])
{
    return s[top--];
}
void tower(int n,char source,char intr,char dest)
{
    if(n)
    {
        tower(n-1,source,dest,intr);
        printf("\nMove disk %d from %c to %c",n,source,dest);
        count++;
        tower(n-1,intr,source,dest);
    }
}
void main()
{
    int n,choice,s[20],op1,op2,ans,i;
    char expr[20],symbol;
    while (1)
    {
        printf("\program to perform evaluation of suffix expression and tower of hanoi\n");
        printf("1.Evaluate the suffix expression\n2.Tower of hanoi\n3.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:printf("Enter the suffix expression\n");
                   scanf("%s",expr);
                   for (i=0;expr[i]!='\0';i++) 
                   {
                          symbol=expr[i];
                          if (symbol>='0'&&symbol<='9')
                          {
                            push(s,symbol-'0');
                          }
                          else
                          {
                            op2=pop(s);
                            op1=pop(s);
                            ans=operate(symbol,op1,op2);
                            push(s,ans);
                          }
                   }
                   ans=pop(s);
                     printf("Answer=%d\n",ans);
                        break;
            case 2:printf("Enter the number of disks\n");
                     scanf("%d",&n);
                     tower(n,'A','B','C');
                     printf("\nNumber of moves=%d\n",count);
                     count=0;
                     break;
            case 3:return;
        }
    }
}

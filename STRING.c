#include<stdio.h>
char str[100],pat[100],rep[100],ans[100];
int i=0,j=0,k,c=0,m=0,flag=0;
void stringmatch()
{
    while (str[c] != '\0')
    {
        if (str[m]==pat[i])
        {
            i++;
            m++;
            if (pat[i]=='\0')
            {
                flag=1;
                for (k=0;rep[k]!='\0';k++,j++)
                {
                    ans[j]=rep[k];
                }
                i=0;
                c=m;
            }
        }
        else
        {
            ans[j]=str[c];
            j++;
            c++;
            m=c;
            i=0;
        }
        
    }
    ans[j]='\0';
}
void main()
{
    printf("enter the main string:");
    gets(str);
    printf("enter the pattern string:");
    gets(pat);
    printf("enter the replace string:");
    gets(rep);
    printf("srting before replacement:%s\n",str);
    stringmatch();
    if (flag==1)
    {
        printf("string after replacement:%s\n",ans);
    }
    else
    {
        printf("pattern string not found\n");
    }
}
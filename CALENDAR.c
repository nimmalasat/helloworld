#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct day
{
    char *dayname;
    int date;
    char *activity;
};
void create(struct day *day)
{
    day->dayname = (char *)malloc(sizeof(char) *20);
    day->activity=(char *)malloc(sizeof(char)*100);
    printf("enter the day name:");
    scanf("%s",day->dayname);
    printf("enter the date:");
    scanf("%d",&day->date);
    printf("enter the activity:");
    scanf("%s",day->activity);
}
void read(struct day *calendar,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("enter the details of day %d:\n",i+1);
        create(&calendar[i]);
    }
}
void display(struct day *calendar,int size)
{
    printf("week activity description\n");
    for (int i=0;i<size;i++)
    {
        printf("day %d:\n",i+1);
        printf("day name:%s\n",calendar[i].dayname);
        printf("date:%d\n",calendar[i].date);
        printf("activity:%s\n",calendar[i].activity);
        printf("\n");
    }
}
void freememory(struct day *calendar,int size)
{
    for (int i=0;i<size;i++)
    {
        free(calendar[i].dayname);
        free(calendar[i].activity);
    }
}
int main()
{
    int size;
    printf("enter the number of days in a week:\n");
    scanf("%d",&size);
    struct day *calendar=(struct day *)malloc(sizeof(struct day)*size);
    if(calendar==NULL)
    {
        printf("memory allocation failed");
        return 1;
    }
    read(calendar,size);
    display(calendar,size);
    freememory(calendar,size);
    free(calendar);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int count = 0;
char queue[MAX];
int front = 0, rear = -1;

void insert(char item) {
    if (count == MAX) {
        printf("Queue is full\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = item;
    count++;
    printf("Inserted %c\n", item);
}

void delete() {
    if (count == 0) {
        printf("Queue is empty\n");
        return;
    }
    char itemdel = queue[front];
    count--;
    printf("Deleted %c\n", itemdel);
    if (front == rear) {
        front = 0;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (count == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("front = %d, rear = %d\n", front, rear);
    int temp = front;
    printf("Queue elements are:\n");
    for (int i = 0; i < count; i++) {
        printf("%c\n", queue[temp]);
        temp = (temp + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch;
    char item;
    printf("------CIRCULAR QUEUE------\n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    for (;;) {
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to be inserted\n");
                scanf(" %c", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
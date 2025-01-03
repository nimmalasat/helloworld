#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node 
{
    int usn;
    char name[20], department[20], designation[20], phone[20];
    float salary;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE createNode(int usn, char name[], char department[], char designation[], char phone[], float salary) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->usn = usn;
    strcpy(newNode->name, name);
    strcpy(newNode->department, department);
    strcpy(newNode->designation, designation);
    strcpy(newNode->phone, phone);
    newNode->salary = salary;
    newNode->llink = NULL;
    newNode->rlink = NULL;
    return newNode;
}
NODE insertFront(NODE head, int usn, char name[], char department[], char designation[], char phone[], float salary) {
    NODE newNode = createNode(usn, name, department, designation, phone, salary);
    if (head == NULL) {
        return newNode;
    }
    newNode->rlink = head;
    head->llink = newNode;
    return newNode;
}
NODE insertRear(NODE head, int usn, char name[], char department[], char designation[], char phone[], float salary) {
    NODE newNode = createNode(usn, name, department, designation, phone, salary);
    if (head == NULL) {
        return newNode;
    }
    NODE temp = head;
    while (temp->rlink != NULL) {
        temp = temp->rlink;
    }
    temp->rlink = newNode;
    newNode->llink = temp;
    return head;
}
NODE deleteFront(NODE head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    NODE temp = head;
    head = head->rlink;
    if (head != NULL) {
        head->llink = NULL;
    }
    printf("Deleted node with USN: %d\n", temp->usn);
    free(temp);
    return head;
}
NODE deleteRear(NODE head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    NODE temp = head;
    if (head->rlink == NULL) {
        printf("Deleted node with USN: %d\n", head->usn);
        free(head);
        return NULL;
    }
    while (temp->rlink != NULL) {
        temp = temp->rlink;
    }
    temp->llink->rlink = NULL;
    printf("Deleted node with USN: %d\n", temp->usn);
    free(temp);
    return head;
}
void display(NODE head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE temp = head;
    while (temp != NULL) {
        printf("USN: %d, Name: %s, Department: %s, Designation: %s, Phone: %s, Salary: %.2f\n",
               temp->usn, temp->name, temp->department, temp->designation, temp->phone, temp->salary);
        temp = temp->rlink;
    }
}
int main() {
    NODE head = NULL;
    int choice, usn;
    char name[20], department[20], designation[20], phone[20];
    float salary;
    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter USN: ");
                scanf("%d", &usn);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Department: ");
                scanf("%s", department);
                printf("Enter Designation: ");
                scanf("%s", designation);
                printf("Enter Phone: ");
                scanf("%s", phone);
                printf("Enter Salary: ");
                scanf("%f", &salary);
                head = insertFront(head, usn, name, department, designation, phone, salary);
                break;
            case 2:
                printf("Enter USN: ");
                scanf("%d", &usn);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Department: ");
                scanf("%s", department);
                printf("Enter Designation: ");
                scanf("%s", designation);
                printf("Enter Phone: ");
                scanf("%s", phone);
                printf("Enter Salary: ");
                scanf("%f", &salary);
                head = insertRear(head, usn, name, department, designation, phone, salary);
                break;
            case 3:
                head = deleteFront(head);
                break;
            case 4:
                head = deleteRear(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
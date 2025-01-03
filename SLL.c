#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student structure
struct student {
    char usn[25], name[25], branch[25], phno[25];
    int sem;
    struct student *next;
};

// Global pointers for the linked list
struct student *f = NULL, *r = NULL, *temp = NULL;

// Function prototypes
void insert(int ch);
void delete(int ch);
void display();

void insert(int ch) {
    temp = (struct student*)malloc(sizeof(struct student));
    if (!temp) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the USN of the student: ");
    scanf("%s", temp->usn);
    printf("Enter the name of the student: ");
    scanf("%s", temp->name);
    printf("Enter the branch of the student: ");
    scanf("%s", temp->branch);
    printf("Enter the semester of the student: ");
    scanf("%d", &temp->sem);
    printf("Enter the phone number of the student: ");
    scanf("%s", temp->phno);
    temp->next = NULL;

    if (!r) {
        f = r = temp;
    } else {
        if (ch) {
            r->next = temp;
            r = temp;
        } else {
            temp->next = f;
            f = temp;
        }
    }
}

void delete(int ch) {
    if (!f) {
        printf("List is empty\n");
        return;
    }

struct student *temp1;
    if (f == r) {
        temp1 = f;
        f = r = NULL;
    } else if (ch) {
        temp1 = f;
        for (temp = f; temp->next != r; temp = temp->next);
        r = temp;
        r->next = NULL;
    } else {
        temp1 = f;
        f = f->next;
    }

    printf("The deleted node is\n");
    printf("USN: %s\n", temp1->usn);
    free(temp1);
}

void display() {
    struct student *temp = f;
    if (!f) {
        printf("List is empty\n");
        return;
    }
    while (temp) {
        printf("USN: %s\n", temp->usn);
        printf("Name: %s\n", temp->name);
        printf("Branch: %s\n", temp->branch);
        printf("Semester: %d\n", temp->sem);
        printf("Phone Number: %s\n", temp->phno);
        temp = temp->next;
    }
}

int main() {
    int ch, n;
    printf("---MENU---\n");
    printf("1. create\n2. display\n3. insertatend\n4. deleteatend\n5. insertatbeg\n6. deleteatbeg\n7. exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the number of students: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    insert(0);
                }
                break;
            case 2:
                display();
                break;
            case 3:
                insert(1);
                break;
            case 4:
                delete(1);
                break;
            case 5:
                insert(0);
                break;
            case 6:
                delete(0);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

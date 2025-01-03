#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int a[MAX], key, empno, i;

void initialize() {
    for (i = 0; i < MAX; i++) {
        a[i] = -1; // Initialize all slots to -1 indicating empty slots
    }
}

void linear_prob() {
    for (i = key; i != (key - 1 + MAX) % MAX; i = (i + 1) % MAX) {
        if (a[i] == -1) {
            a[i] = empno;
            return;
        }
    }
    printf("\nHASHTABLE FULL. No place for empno %d\n", empno);
}

void display() {
    printf("\nHash Table:\n");
    for (i = 0; i < MAX; i++) {
        if (a[i] != -1) {
            printf("Index %d: %d\n", i, a[i]);
        }
    }
}

void search(int empno) {
    key = empno % MAX;
    for (i = key; i != (key - 1 + MAX) % MAX; i = (i + 1) % MAX) {
        if (a[i] == empno) {
            printf("Employee number %d found at index %d\n", empno, i);
            return;
        }
        if (a[i] == -1) {
            break; // Stop searching if an empty slot is encountered
        }
    }
    printf("Employee number %d not found\n", empno);
}

int main() {
    int choice;
    initialize();

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Search\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter empno: ");
                scanf("%d", &empno);
                key = empno % MAX;
                linear_prob();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter empno to search: ");
                scanf("%d", &empno);
                search(empno);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
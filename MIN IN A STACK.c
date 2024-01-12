#include<stdio.h>
#define MAX 100

int STACK[MAX];
int TOP = -1;

void push(int ele);
int pop();
int min();
void display();

int main() {
    int choice;

    while (1) {
        printf("Enter your choice\n");
        printf("1. TO INSERT\n2. TO DELETE\n3. TO FIND MINIMUM\n4. TO DISPLAY\n5. TO EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int element;
                printf("Enter element: ");
                scanf("%d", &element);
                push(element);
            }
            break;

            case 2: {
                int deleted = pop();
                if (deleted != -1) {
                    printf("Deleted element: %d\n", deleted);
                }
            }
            break;

            case 3: {
                int minimum = min();
                if (TOP != -1) {
                    printf("Minimum: %d\n", minimum);
                }
            }
            break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program\n");
                return 0;

            default:
                printf("Enter correct choice\n");
                break;
        }
    }
}

void push(int ele) {
    if (TOP == (MAX - 1)) {
        printf("Stack overflow\n");
    } else {
        TOP = TOP + 1;
        STACK[TOP] = ele;
    }
}

int pop() {
    int deleted;
    if (TOP == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        deleted = STACK[TOP];
        TOP--;
        return deleted;
    }
}

int min() {
    int m = STACK[0];
    for (int j = 0; j <= TOP; j++) {
        if (STACK[j] < m) {
            m = STACK[j];
        }
    }
    return m;
}

void display() {
    if (TOP == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= TOP; i++) {
            printf("%d ", STACK[i]);
        }
        printf("\n");
    }
}

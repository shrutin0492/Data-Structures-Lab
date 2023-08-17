#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student data
struct Student {
    int rollNo;
    char name[50];
    int semester;
    struct Student *next;
};

// Function to create a new student node
struct Student *createStudent(int rollNo, const char *name, int semester) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    newStudent->semester = semester;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a student at the front of the linked list
void insertFront(struct Student **head, struct Student *newStudent) {
    newStudent->next = *head;
    *head = newStudent;
}

// Function to insert a student at the end of the linked list
void insertEnd(struct Student **head, struct Student *newStudent) {
    if (*head == NULL) {
        *head = newStudent;
        return;
    }

    struct Student *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newStudent;
}

// Function to delete a student from the front of the linked list
void deleteFront(struct Student **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Student *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Student deleted from the front.\n");
}

// Function to delete a student from the end of the linked list
void deleteEnd(struct Student **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Student deleted from the end.\n");
        return;
    }
    struct Student *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    printf("Student deleted from the end.\n");
}

// Function to display the count of nodes in the linked list
int countNodes(struct Student *head) {
    int count = 0;
    struct Student *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to display the student data
void display(struct Student *student) {
    printf("Roll No: %d, Name: %s, Semester: %d\n", student->rollNo, student->name, student->semester);
}

int main() {
    struct Student *head = NULL;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert Student at Front\n");
        printf("2. Insert Student at End\n");
        printf("3. Delete Student from Front\n");
        printf("4. Delete Student from End\n");
        printf("5. Display Count of Nodes\n");
        printf("6. Display All Students\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2: {
                int rollNo, semester;
                char name[50];
                printf("Enter Roll No: ");
                scanf("%d", &rollNo);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Semester: ");
                scanf("%d", &semester);
                struct Student *newStudent = createStudent(rollNo, name, semester);
                if (choice == 1) {
                    insertFront(&head, newStudent);
                    printf("Student inserted at the front.\n");
                } else {
                    insertEnd(&head, newStudent);
                    printf("Student inserted at the end.\n");
                }
                break;
            }
            case 3:
                deleteFront(&head);
                break;
            case 4:
                deleteEnd(&head);
                break;
            case 5: {
                int count = countNodes(head);
                printf("Number of nodes: %d\n", count);
                break;
            }
            case 6: {
                struct Student *current = head;
                printf("\nStudent List:\n");
                while (current != NULL) {
                    display(current);
                    current = current->next;
                }
                break;
            }
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    // Free memory by deallocating linked list
    struct Student *current = head;
    while (current != NULL) {
        struct Student *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

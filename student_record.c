#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Structure to represent a student
struct Student {
    int studentID;
    char name[50];
    int age;
    float grades[3];
};

// Function to input data for a new student and add it to the array
void insertStudent(struct Student students[], int *numStudents) {
    printf("Enter student ID: ");
    scanf("%d", &students[*numStudents].studentID);
    printf("Enter student name: ");
    scanf("%s", students[*numStudents].name);
    printf("Enter student age: ");
    scanf("%d", &students[*numStudents].age);
    printf("Enter grades for 3 subjects:\n");
    for (int i = 0; i < 3; i++) {
        printf("Course %d: ", i + 1);
        scanf("%f", &students[*numStudents].grades[i]);
    }
    (*numStudents)++;
    printf("Student added successfully!\n");
}

// Function to display the details of all students
void displayStudents(struct Student students[], int numStudents) {
    printf("Student Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student ID: %d\n", students[i].studentID);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Grades: ");
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", students[i].grades[j]);
        }
        printf("\n");
    }
}

// Function to search for a student by ID and display their information
void searchStudent(struct Student students[], int numStudents) {
    int searchID;
    printf("Enter student ID to search: ");
    scanf("%d", &searchID);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].studentID == searchID) {
            printf("Student ID: %d\n", students[i].studentID);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Grades: ");
            for (int j = 0; j < 3; j++) {
                printf("%.2f ", students[i].grades[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Student not found!\n");
}

int main() {
    struct Student students[100];
    int numStudents = 0;
    int choice;

    do {
        printf("====================================\n");
        printf("1. Insert Student Data\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Define new Function\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent(students, &numStudents);
                break;
            case 2:
                displayStudents(students, numStudents);
                break;
            case 3:
                searchStudent(students, numStudents);
                break;
            case 4:
                printf("You can define your own functions to perform specific tasks.\n");
                printf("For example:\n");
                printf("- Display Grade for each Course.\n");
                printf("- Find Maximum or Minimum grade of Students.\n");
                printf("- Sort Grade by average for Students in Ascending or Descending order.\n");
                printf("- Find the average grade for a particular Student.\n");
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
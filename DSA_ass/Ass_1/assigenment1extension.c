#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char* name;      
    int roll;
    char telephone[13];
    char* address;   
} Student;

typedef struct SReg {
    int maxStuds;    
    int count;      
    Student** arrStudPtr; 
} SReg;


Student* createStudentRecord();
Student* createStudentRecordFromFile(const char *sreg , Student* s);
void freeStudentRecord(Student* sp);
SReg* initializeRegister(int maxStudents);
void addStudentToRegister(SReg* reg, Student* s);
void displayStudent(Student* s);
void displayRegister(SReg* reg);
void freeRegister(SReg* reg);


Student* createStudentRecord() {
    Student* s = (Student*)malloc(sizeof(Student));
    if (s == NULL) {
        return NULL;
    }

    char buffer[50]; 

   
    printf("Enter student name: ");
 scanf("%s", &buffer);
    s->name = (char*)malloc(strlen(buffer)*sizeof(char));
    strcpy(s->name, buffer);
    if (s->name == NULL) {
        free(s);
        return NULL;
    }

    printf("Enter roll number: ");
    scanf("%d", &s->roll);
  
    printf("Enter telephone number (10 digits)with country code (like for india +91): ");
    scanf("%s", s->telephone);

    printf("Enter address: ");
    scanf(" %s", buffer); 
    buffer[strcspn(buffer, "\n")] = '\0';
    s->address = (char*)malloc(strlen(buffer) * sizeof(char));
    strcpy(s->address, buffer);
    if (s->address == NULL) {
        free(s->name);
        free(s);
        return NULL;
    }

    return s;
}


Student* createStudentRecordFromFile(const char *sreg, Student* s) {
    FILE* fp= fopen(sreg, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    char buffer[50];
    fscanf(fp, "%s", buffer);
    s->name = (char*)malloc(strlen(buffer) * sizeof(char));
    strcpy(s->name, buffer);

    fscanf(fp, "%d", &s->roll);
    fscanf(fp, "%s", s->telephone);

    fscanf(fp, "%s", buffer);
    s->address = (char*)malloc(strlen(buffer) * sizeof(char));
    strcpy(s->address, buffer);

    fclose(fp);
    return s;
}


void freeStudentRecord(Student* sp) {
    if (sp != NULL) {
        free(sp->name);
        free(sp->address);
        free(sp);
    }
}


SReg* initializeRegister(int maxStudents) {
    SReg* reg = (SReg*)malloc(sizeof(SReg));
    if (reg == NULL) {
        return NULL;
    }

    reg->maxStuds = maxStudents;
    reg->count = 0;
    reg->arrStudPtr = (Student**)malloc(maxStudents * sizeof(Student*));
    if (reg->arrStudPtr == NULL) {
        free(reg);
        return NULL;
    }

    return reg;
}


void addStudentToRegister(SReg* reg, Student* s) {
    if (reg == NULL || s == NULL || reg->count >= reg->maxStuds) {
        return;
    }
    reg->arrStudPtr[reg->count++] = s;
}

void displayStudent(Student* s) {
    if (s == NULL) {
        printf("NULL student record\n");
        return;
    }
    printf("Name: %s\n", s->name);
    printf("Roll: %d\n", s->roll);
    printf("Telephone: %s\n", s->telephone);
    printf("Address: %s\n", s->address);
    printf("----------------------------\n");
}

void displayRegister(SReg* reg) {
    if (reg == NULL) {
        printf("NULL register\n");
        return;
    }
    printf("\nStudent Register (Count: %d, Max: %d)\n", reg->count, reg->maxStuds);
    printf("----------------------------\n");
    for (int i = 0; i < reg->count; i++) {
        displayStudent(reg->arrStudPtr[i]);
    }
}

void freeRegister(SReg* reg) {
    if (reg != NULL) {
        for (int i = 0; i < reg->count; i++) {
            freeStudentRecord(reg->arrStudPtr[i]);
        }
        free(reg->arrStudPtr);
        free(reg);
    }
}

int main() {
    int maxStudents;
    printf("Enter maximum number of students: ");
    scanf("%d", &maxStudents);
   Student* s1 = NULL;
   s1 = (Student*)malloc(sizeof(Student));

    SReg* SR = initializeRegister(maxStudents);
    if (SR == NULL) {
        printf("Failed to initialize register\n");
        return 1;
    }

    int choice;
    do {
        printf("\nStudent Register ....\n");
        printf("1. Add student (manual entry)\n");
        printf("2. Add student from file\n");
        printf("3. Display all students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    

        switch (choice) {
            case 1: {
                if (SR->count >= SR->maxStuds) {
                    printf("Register is full!\n");
                    break;
                }
                Student* s = createStudentRecord();
                if (s == NULL) {
                    printf("Failed to create student record\n");
                    break;
                }
                addStudentToRegister(SR, s);
                printf("Student added successfully\n");
                break;
            }
            case 2: {
                if (SR->count >= SR->maxStuds) {
                    printf("Register is full!\n");
                    break;
                }
                char filename[20];
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
              

                FILE* fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("Failed to open file\n");
                    break;
                }

                Student* s = createStudentRecordFromFile(filename , s1);
                fclose(fp);

                if (s == NULL) {
                    printf("Failed to create student record from file\n");
                    break;
                }
                addStudentToRegister(SR, s);
                printf("Student added from file successfully\n");
                break;
            }
            case 3:
                displayRegister(SR);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    freeRegister(SR);
    free(s1);
    printf("Program terminated successfully.\n");
    return 0;
}
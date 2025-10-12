#define max_std 10

#include <stdio.h>
#include <string.h> 

struct Student {

    char name [20];
    int rollno;
    char address[20];
    char phoneno[11];
} s ;

struct SReg
{
     int count;
    struct Student studentarr[max_std];
} SR ;

int initilisation(struct SReg * SR ) {
    SR->count = 0;
    for (int i = 0; i < max_std; i++) {
        SR->studentarr[i].rollno = -1;
        strcpy(SR->studentarr[i].name, "");
    }
    return 1;
}

int addstd(struct SReg * SR, struct Student * s){
      int R = 0;
      printf(" Enter the roll no: ");
      scanf("%d", &SR->studentarr[SR->count].rollno);
      printf(" Enter the name: ");
      scanf("%s", SR->studentarr[SR->count].name);
      printf(" Enter the phone no: ");
      scanf("%s", SR->studentarr[SR->count].phoneno);
        printf(" Enter the address: ");
        scanf("%s", SR->studentarr[SR->count].address);

        int i = 0;

         while ( i < max_std) {
          if (i == SR->count) {
                  i++;            
          }

            else if (SR->studentarr[SR->count].rollno == SR->studentarr[i].rollno )
            {
                R = 23;
                printf("Student already exists.\n");
                SR->studentarr[SR->count].rollno = 0;
                SR->studentarr[SR->count].name[0] = '\0';
                SR->studentarr[SR->count].phoneno[0] = '\0';
                SR->studentarr[SR->count].address[0] = '\0';
                SR->count--;
                return 0;  

            }

            i++;
        }

        SR->count++;

        if (SR->count >= max_std) {
            printf("Cannot add more students, maximum limit reached.\n");
            return 0;
        }
        if(R == 0){
        printf("Student added: %s, Roll No: %d\n", SR->studentarr[SR->count - 1].name, SR->studentarr[SR->count - 1].rollno);
        return 1;
        }
    }

    int getstd(struct SReg * SR, int rollno){
        for (int i = 0; i < SR->count; i++) {
            if (SR->studentarr[i].rollno == rollno) {
                printf("Student found: \n name :  %s\n Roll No: %d\n Phone no : %s\n Addresse : %s \n", SR->studentarr[i].name, SR->studentarr[i].rollno ,SR->studentarr[i].phoneno, SR->studentarr[i].address);
                return 1;
            }
        }
        printf("Student with roll no %d not found.\n", rollno);
        return 0;
    }   
    
    int deletestd(struct SReg * SR, int rollno) {
        for (int i = 0; i < max_std; i++) {
            if (SR->studentarr[i].rollno == rollno) {
                SR->studentarr[i].rollno = -1;
                SR->studentarr[i].name[0] = '\0';
                SR->studentarr[i].phoneno[0] = '\0';
                SR->studentarr[i].address[0] = '\0';
                }
                printf("Student with roll no %d deleted.\n", rollno);
                return 1;
            }
        printf("Student with roll no %d not found.\n", rollno);
        return 0;
    }

    int modifystd(struct SReg * SR, int rollno) {
        for (int i = 0; i < max_std; i++) {
            if (SR->studentarr[i].rollno == rollno) {
                printf("Enter new name: current name is %s\n", SR->studentarr[i].name);
                scanf("%s", SR->studentarr[i].name);
            if (SR->studentarr[i].rollno == rollno) {
                printf("Enter new Roll no : current Roll no  is %d\n", SR->studentarr[i].rollno);
                scanf("%d", SR->studentarr[i].rollno);
                printf("Enter new phone no: current phone no is %s\n", SR->studentarr[i].phoneno);
                scanf("%s", SR->studentarr[i].phoneno);
                printf("Enter new address: current address is %s\n", SR->studentarr[i].address);
                scanf("%s", SR->studentarr[i].address);
                printf("Student with roll no %d modified.\n", rollno);
                return 1;
            
                printf("Student with roll no %d not found.\n", rollno);
                return 0;
            }
        }
        }
    }

    int countstd(struct SReg * SR) {
       int Count = 0;
        for (int i = 0; i < max_std; i++)
        {
            if(SR->studentarr[i].rollno > 0) {
                Count++;
            }
        }
         if (Count == 0) {
            printf("No students found.\n");
        }
         else {
            printf("There are %d students in the record.\n", Count);
        }
        return Count;
    }

    int shortstdbyname(struct SReg * SR) {
        struct Student temp;
        for (int i = 0; i < max_std; i++) {
            for (int j = i + 1; j < SR->count; j++) {
                if (strcmp(SR->studentarr[i].name, SR->studentarr[j].name) > 0) {
                    temp = SR->studentarr[i];
                    SR->studentarr[i] = SR->studentarr[j];
                    SR->studentarr[j] = temp;
                }
            }
        }
    
        if (SR->count == 0) {
            printf("No students found to sort.\n");
            return 0;
        }
        else {
            printf("Students sorted successfully.\n");
            printf("name :");
            for (int i = 0; i < SR->count; i++) {
                if (SR->studentarr[i].rollno != -1) {
                    printf(" %s ,", SR->studentarr[i].name);
                }
            }
            printf("\n");
        }
        return 1;
    }



int export(struct SReg *SR, const char *sreg) {
    FILE *fp = fopen(sreg, "w"); 
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    for (int i = 0; i < max_std; i++) {
        if (SR->studentarr[i].rollno == -1) 
        continue; 
    
        fprintf(fp, "%s\n", SR->studentarr[i].name);
        fprintf(fp, "%d\n", SR->studentarr[i].rollno);
        fprintf(fp, "%s\n", SR->studentarr[i].phoneno);
        fprintf(fp, "%s\n", SR->studentarr[i].address);
    }

    fclose(fp);
    printf("Student data exported successfully.\n");
    return 1;
}

int load(const char *serg, struct SReg *SR , int numberofstudents) {
   FILE *fp = fopen("serg.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    int count = 0;
    while ( count < numberofstudents) {
        struct Student s = { "" , 0, "", "" };
       
        int i = 0;
        char ch;
          while (( ch = fgetc(fp)) != EOF && ch != '\n') {
            s.name[i] = ch;
            i++;
        }
        i= 0;
        int roll=0;
          while (( ch = fgetc(fp)) != EOF && ch != '\n') {
            int n;
            
            n= ch - '0';   
            roll = roll * 10 + n; 
            i++;
        }
        s.rollno = roll;
        printf("roll no: %d\n", s.rollno);
         i= 0;
          while (( ch = fgetc(fp)) != EOF && ch != '\n') {
            s.phoneno[i] = ch;
            i++;
        }
         i= 0;
          while (( ch = fgetc(fp)) != EOF && ch != '\n') {
            s.address[i] = ch;
            i++;
        }

        SR->studentarr[count] = s;
        count++;
    }
    SR->count = numberofstudents;
    fclose(fp);
    printf("Student data loaded successfully.\n");
     return 1;
}

 int main() {
     struct SReg SR;
     struct Student s1;
     initilisation(&SR);
    int userinput = 0;

    printf("Welcome to Student Record System\n");
    int loop = 1;
    while (loop >= 0)
    {
        printf("1. Add Student\n");
        printf("2. Modify Student\n");
        printf("3. Delete Student\n");
        printf("4. Get Student\n");
        printf("5. Count Students\n");
        printf("6. Sort Students by Name\n");
        printf("7. Export Student Data\n");
        printf("8. Load Student Data\n");
        printf("Enter your choice as seriale  number: ");
        scanf("%d", &userinput);
        int Rollno;
        switch (userinput)
        {
            case 1:
            printf("Adding student...\n");
            addstd(&SR, &s1);
            break;
            case 2:
            printf("modifying student...\n");
             Rollno = -1;
            printf("Enter roll number of student to modify: ");
            scanf("%d", &Rollno);
            modifystd(&SR, Rollno);
            break;
            case 3:
            printf("deleting student...\n");
             Rollno = -1;
            printf("Enter roll number of student to delet: ");
            scanf("%d", &Rollno);
            deletestd(&SR, Rollno);
            break;
            case 4:
            printf("geting student...\n");
            Rollno -1;
            printf("Enter roll number of student to printdata: ");
            scanf("%d", &Rollno);
            getstd(&SR, Rollno);
            break;
            case 5:
            printf("counting student...\n");
            countstd(&SR);
            break;
            case 6:
            printf("shorting  student by ...\n");
            shortstdbyname(&SR);
            break;
            case 7:
            printf("exporting student data from student register ...\n");
            export(&SR, "student_data.txt");
            break;
            case 8:
            printf("loadinging student data to student register ...\n");
            int numberofstudents;
            printf("Enter the number of students to load: ");
            scanf("%d", &numberofstudents);
            load("student_data.txt", &SR, numberofstudents);
            break;
            
            default:
            printf("Invalid choice. Please try again.\n");
            break;

        }
        printf("for exist from student register enter -1 ... other wise  for continue with program inter 1 \n");
        scanf("%d", &loop);
        if (loop == -1) {
            printf("Exiting the program.\n");
            break;
        }
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_MARKS 100
#define SUBJECTS 5

//struct dtatype that contains details of every student
struct Student{
    char id[10];
    char name[30];
    int total;
    float percentage;
    float CGPA;
    char grade[3];
    int marks[SUBJECTS];
};

//checks for invalid ID's
//reject ID's with special symbols and duplicates
int validID(char id[]){
    for(int i =0;id[i]!='\0';i++){
        if(!isalnum(id[i])){
            return 0;
        }
    }
    return 1;
}

int uniqueID(char id[],struct Student students[],int count){
    for(int i=0;i<count;i++){
        if(strcmp(id, students[i].id)==0){
            return 0;
        }
    }
    return 1;
}

//NAME validation
//Rejects names with digits and symbols
int validName(char name[]){
    for(int i=0;name[i]!='\0';i++){
        if(!isalpha(name[i])){
            return 0;
        }
    }
    return 1;
}

//checks whether marks range is 0 to MAX_MARKS
int validMarks(int marks){
    if(marks<0 || marks>MAX_MARKS){
        return 0;
    }
    return 1;
}

//calculating total marks for student
int marksTotal(int marks[]){
    int total=0;
    for(int i=0;i<SUBJECTS;i++){
        total+=marks[i];
    }
    return total;
}

//calculating total  percentage
float calculatePercentage(int total){
    int totalP=total/(float)SUBJECTS;
    return totalP;
}

//50% is the pass percentage
//function to check whether student passed all subjects
int checkPassSubjects(int marks[]){
    for(int i=0;i<SUBJECTS;i++){
        if(marks[i]<50){
            return 0;
        }
    }
    return 1;
}

//function to calculate CGPA
float calculateCGPA(float percentage){
    return percentage/10;
}

//function to assign grade to the students
void gradeassignment(float percentage,char grade[]){
    if(percentage>=90){
        strcpy(grade,"O");
    }
    else if(percentage>=85){
        strcpy(grade,"A+");
    }
    else if(percentage>=75){
        strcpy(grade,"A");
    }
    else if(percentage>=65){
        strcpy(grade,"B+");
    }
    else if(percentage>=60){
        strcpy(grade,"B");
    }
    else if(percentage>=55){
        strcpy(grade,"C");
    }
    else if(percentage>=50){
        strcpy(grade,"D");
    }
    else{
        strcpy(grade,"F");
    }
}

//students final report display
//tabular data of all students along with the calcualtes grades and CGPA total and percentage

void displayReport(struct Student students[],int count){
    printf("\n\n----------STUDENT RESULTS----------------    \n\n");
    printf("ID\t\tNAME\t\tSUB1\tSUB2\tSUB3\tSUB4\tSUB5\tTOTAL\tPERCENTAGE\tGRADE\tCGPA\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<count;i++){
        printf("%-10s\t%-10s\t",students[i].id,students[i].name);
        for(int j=0;j<SUBJECTS;j++){
            printf("%d\t",students[i].marks[j]);
        }
        printf("%d\t%.2f\t\t%s\t%.2f\n",students[i].total,students[i].percentage,students[i].grade,students[i].CGPA);
    }
}

//computing statistics 
//function to compute class avg percentage ,lowest and highest percentage
void percentageStats(struct Student students[],int count){
    float sum=0;
    float highest,lowest;
    highest=students[0].percentage;
    lowest=students[0].percentage;
    for(int i=0;i<count;i++){
        float p=students[i].percentage;
        sum=sum+p;
        if(p>highest){
            highest=p;
        }
        if(p<lowest){
            lowest=p;
        }
    }
    printf("----Percentage Statistics----\n");
    printf("Class Average Percentage:%.2f\n",sum/count);
    printf("Highest Percentage :%.2f\n",highest);
    printf("Lowest Percentage :%.2f\n",lowest);
}

//this function calculates the number of students in each grade category
void gradeStats(struct Student students[],int count){
    int countO=0,countAplus=0,countA=0,countBplus=0,countB=0,countC=0,countD=0,countF=0;
    for(int i=0;i<count;i++){
        if(strcmp(students[i].grade,"O")==0){
            countO++;
        }
        else if(strcmp(students[i].grade,"A+")==0){
            countAplus++;
        }
        else if(strcmp(students[i].grade,"A")==0){
            countA++;
        }
        else if(strcmp(students[i].grade,"B+")==0){
            countBplus++;
        }
        else if(strcmp(students[i].grade,"B")==0){
            countB++;
        }
        else if(strcmp(students[i].grade,"C")==0){
            countC++;
        }
        else if(strcmp(students[i].grade,"D")==0){
            countD++;
        }
        else countF++;
    }
    printf("\nStudents in grade category count::\n");
    printf("O  :%d\n",countO);
    printf("A+ :%d\n",countAplus);
    printf("A  :%d\n",countA);
    printf("B+ :%d\n",countBplus);
    printf("B  :%d\n",countB);
    printf("C  :%d\n",countC);
    printf("D  :%d\n",countD);
    printf("F  :%d\n",countF);

}

int main(){
    printf("******STUDENT RESULT PROCESSING SYSTEM****** \n");
    FILE *filep=fopen("student_data.txt","r");
    if(filep==NULL){
        printf("Make sure file is present");
        return 1;
    }
    int N; //number of students
    fscanf(filep,"%d",&N);
    printf("Number of students in total are : %d\n",N);
    
struct Student students[N];  //store all student records
    int validstudents=0;         //students count after skipping invalid data
 for(int n=0;n<N;n++){
        struct Student buffer;
    fscanf(filep , "%s %s",buffer.id, buffer.name);
    for(int i =0;i<SUBJECTS; i++){
        fscanf(filep , "%d",&buffer.marks[i]);
    }
   
    //skips the records of students with invalid ID name marks
if(!validID(buffer.id)){
        printf("\nThe id of student : %s is invalid\n" ,buffer.id);
        continue;
    }
    if(!validName(buffer.name)){
    printf("name of student %s is invalid\n",buffer.name);
        continue;
    }
    int flag=0;
    for(int k=0;k<SUBJECTS;k++){
              if(!validMarks(buffer.marks[k])){
            printf("\ninvalid marks for ID %s \n",buffer.id);
            flag=1;
            break;
        }
    }
    if(flag) continue;
if(!uniqueID(buffer.id,students,validstudents)){
    printf("Duplicate ID is found");
        continue;
    }
 students[validstudents]=buffer;
    validstudents++;
}
fclose(filep);

//verfied student data display
printf("\n--VALID STUDENT DATA-- \n");
printf("valid student data count:%d\n",validstudents);
printf("ID\t\tName\t\tMarks   of     subjects\n");
for(int i=0;i<validstudents;i++){
    printf("%-10s\t%-10s\t",students[i].id,students[i].name);
    for(int j=0;j<SUBJECTS;j++){
        printf("%d\t",students[i].marks[j]);
        }
         printf("\n");
    }
   
//calculting the total marks ,percentage,CGPA
for(int i=0;i<validstudents;i++){
    students[i].total=marksTotal(students[i].marks);
    students[i].percentage=calculatePercentage(students[i].total);
    if(checkPassSubjects(students[i].marks)){
        gradeassignment(students[i].percentage,students[i].grade);
        }
    else{
        strcpy(students[i].grade,"F");
    }
    students[i].CGPA=calculateCGPA(students[i].percentage);
}

//fucntion call to display final result of students
displayReport(students,validstudents);
//function call to diplay percentage statistics
percentageStats(students,validstudents);
//function call to display the count of students in each grade category
gradeStats(students,validstudents);
    return 0;

}


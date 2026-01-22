#include "myheader.h"
//students list after removing all the invalid students form the list
//contains the verified students data before computing

void displayverifiedlist(struct Student students[],int validstudents){
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
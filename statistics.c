#include "myheader.h"
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
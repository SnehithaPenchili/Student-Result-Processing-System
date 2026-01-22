#include "myheader.h"
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

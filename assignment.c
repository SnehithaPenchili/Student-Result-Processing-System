#include "myheader.h"

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
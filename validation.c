#include "myheader.h"

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

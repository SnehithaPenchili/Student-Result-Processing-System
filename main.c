#include "myheader.h"
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
displayverifiedlist(students,validstudents);
   
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


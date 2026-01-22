#ifndef MYHEADER_H
#define MYHEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_MARKS 100
#define SUBJECTS 5

struct Student{
    char id[10];
    char name[30];
    int total;
    float percentage;
    float CGPA;
    char grade[3];
    int marks[SUBJECTS];
};

//validation module
int validID(char id[]);
int uniqueID(char id[],struct Student students[],int count);
int validName(char name[]);
int validMarks(int marks);

//computation module
int marksTotal(int marks[]);
float calculatePercentage(int total);
float calculateCGPA(float percentage);
int checkPassSubjects(int marks[]);

//assignment module
void gradeassignment(float percentage,char grade[]);

//statistics computation (percentage ,grade)
void percentageStats(struct Student students[],int count);
void gradeStats(struct Student students[],int count);

//display module
void displayReport(struct Student students[], int count);
void displayverifiedlist(struct Student students[],int validstudents);
#endif
#ifndef STUDENT_H
#define STUDENT_H

#define SUBJECTS 5

struct Student
{
    char id[20];
    char name[20];
    int minor[SUBJECTS];
    int major[SUBJECTS];
    int total[SUBJECTS];
    int grade[SUBJECTS];
    float cgpa;
    float percentage;
    int isPass;   // 1 = PASS, 0 = FAIL
};

#endif


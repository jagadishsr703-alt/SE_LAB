#include "calculation.h"

void calculateGrades(struct Student *s)
{
    for (int i = 0; i < SUBJECTS; i++)
    {
        s->total[i] = s->minor[i] + s->major[i];

        if (s->total[i] >= 90)      s->grade[i] = 10;
        else if (s->total[i] >= 85) s->grade[i] = 9;
        else if (s->total[i] >= 75) s->grade[i] = 8;
        else if (s->total[i] >= 65) s->grade[i] = 7;
        else if (s->total[i] >= 60) s->grade[i] = 6;
        else if (s->total[i] >= 55) s->grade[i] = 5;
        else if (s->total[i] >= 50) s->grade[i] = 4;
        else                        s->grade[i] = 0;
    }
}

float calculateCGPA(struct Student *s)
{
    int gradeSum = 0;
    for (int i = 0; i < SUBJECTS; i++)
        gradeSum += s->grade[i];

    s->cgpa = gradeSum / (float)SUBJECTS;
    return s->cgpa;
}

float calculatePercentage(struct Student *s)
{
    int totalMarks = 0;
    for (int i = 0; i < SUBJECTS; i++)
        totalMarks += s->total[i];

    s->percentage = totalMarks / (float)SUBJECTS;
    return s->percentage;
}


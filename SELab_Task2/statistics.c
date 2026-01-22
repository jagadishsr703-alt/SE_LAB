#include "statistics.h"

void updateStatistics(struct Student *s,float *classTotal,float *highest,float *lowest,int gradeCount[])
{
    *classTotal += s->percentage;

    if (s->percentage > *highest)
        *highest = s->percentage;

    if (s->percentage < *lowest)
        *lowest = s->percentage;

    gradeCount[(int)s->cgpa]++;
}

void printStatistics(FILE *fp,
                     float classTotal,
                     float highest,
                     float lowest,
                     int totalStudents,
                     int gradeCount[])
{
    fprintf(fp, "\nclass average percentage : %.2f\n",classTotal/totalStudents);
    fprintf(fp, "highest percentage       : %.2f\n", highest);
    fprintf(fp, "lowest percentage        : %.2f\n", lowest);

    fprintf(fp, "\ngrade distribution:\n");
    for (int i = 0; i <= 10; i++)
    {
        if (gradeCount[i] > 0)
            fprintf(fp, "grade %d : %d students\n", i, gradeCount[i]);
    }
}


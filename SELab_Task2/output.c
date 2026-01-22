#include "output.h"

void printHeader(FILE *fp)
{
    fprintf(fp,
        "%-10s %-12s "
        "| %-6s %-6s %-6s %-6s "
        "| %-6s %-6s %-6s %-6s "
        "| %-6s %-6s %-6s %-6s "
        "| %-6s %-6s %-6s %-6s "
        "| %-6s %-6s %-6s %-6s "
        "| %-5s %-8s %-6s\n",
        "ID","NAME",
        "S1_min","S1_Maj","S1_Tot","S1_Gra",
        "S2_min","S2_Maj","S2_Tot","S2_Gra",
        "S3_min","S3_Maj","S3_Tot","S3_Gra",
        "S4_min","S4_Maj","S4_Tot","S4_Gra",
        "S5_min","S5_Maj","S5_Tot","S5_Gra",
        "CGPA","PERC","STATUS");

    fprintf(fp,
        "====================================================================================================================================================================================================\n");
}

void printStudent(FILE *fp, struct Student *s)
{
    fprintf(fp, "%-10s %-12s ", s->id, s->name);

    for (int i = 0; i < SUBJECTS; i++)
    {
        fprintf(fp, "| %-6d %-6d %-6d %-6d ",
                s->minor[i],
                s->major[i],
                s->total[i],
                s->grade[i]);
    }

    fprintf(fp, "| %-5.2f %-8.2f %-6s\n",
            s->cgpa,
            s->percentage,
            s->isPass ? "PASS" : "FAIL");
}

void printFooter(FILE *fp)
{
    fprintf(fp,
        "====================================================================================================================================================================================================\n");
}


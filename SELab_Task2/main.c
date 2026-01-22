#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "student_input.h"
#include "calculation.h"
#include "statistics.h"
#include "output.h"

int main()
{
    FILE *in, *out;
    struct Student s[50];
    int count = 0;
    char inputFile[50];

    float classTotalPercentage = 0;
    float highest = 0, lowest = 100;
    int gradeCount[11] = {0};

    printf("Enter input file name: ");
    scanf("%s", inputFile);

    in = fopen(inputFile, "r");
    if (!in)
    {
        printf("Cannot open input file\n");
        return 1;
    }

    while (count < 50 && readStudent(in, &s[count]))
    {
        if (isDuplicateID(s, count, s[count].id))
            continue;

        calculateGrades(&s[count]);
        calculateCGPA(&s[count]);
        calculatePercentage(&s[count]);

        if (s[count].isPass)
        {
            updateStatistics(&s[count],
                             &classTotalPercentage,
                             &highest,
                             &lowest,
                             gradeCount);
        }

        count++;
    }

    fclose(in);

    out = fopen("output.txt", "w");
    if (!out)
        return 1;

    printHeader(out);

    for (int i = 0; i < count; i++)
        printStudent(out, &s[i]);

    printFooter(out);

    printStatistics(out,
                    classTotalPercentage,
                    highest,
                    lowest,
                    count,
                    gradeCount);

    fclose(out);

    printf("Output written to output.txt\n");
    return 0;
}


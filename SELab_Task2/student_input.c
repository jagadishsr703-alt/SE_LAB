#include <string.h>
#include "student_input.h"
#include "validation.h"

int isDuplicateID(struct Student s[], int count, char id[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(s[i].id, id) == 0)
            return 1;
    }
    return 0;
}

int readStudent(FILE *fp, struct Student *s)
{
    char subject[20];

    if (fscanf(fp, "%s", s->id) != 1)
        return 0;

    if (!isValidID(s->id))
    {
        fscanf(fp, "%s", s->name);
        for (int i = 0; i < SUBJECTS; i++)
            fscanf(fp, "%s %*d %*d", subject);
        return 0;
    }

    fscanf(fp, "%s", s->name);
    if (!isValidName(s->name))
    {
        for (int i = 0; i < SUBJECTS; i++)
            fscanf(fp, "%s %*d %*d", subject);
        return 0;
    }

    s->isPass = 1;   //assume passed initially

    for (int i = 0; i < SUBJECTS; i++)
    {
        fscanf(fp, "%s %d %d",
               subject,
               &s->minor[i],
               &s->major[i]);

        if (!isValidMarks(s->minor[i], s->major[i]))
            return 0;

        s->total[i] = s->minor[i] + s->major[i];

        if (s->total[i] < 50)
            s->isPass = 0;   // mark fail
    }

    return 1;  // always accept if format is valid
}


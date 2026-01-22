#include <ctype.h>
#include "validation.h"

int isValidID(char id[])
{
    for (int i = 0; id[i] != '\0'; i++)
    {
        if (!isalnum(id[i]))
            return 0;
    }
    return 1;
}

int isValidName(char name[])
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!isalpha(name[i]))
            return 0;
    }
    return 1;
}

int isValidMarks(int minor, int major)
{
    if (minor < 0 || minor > 40)
        return 0;
    if (major < 0 || major > 60)
        return 0;
    return 1;
}


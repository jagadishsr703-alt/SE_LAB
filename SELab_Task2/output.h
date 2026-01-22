#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include "student.h"

void printHeader(FILE *fp);
void printStudent(FILE *fp, struct Student *s);
void printFooter(FILE *fp);

#endif


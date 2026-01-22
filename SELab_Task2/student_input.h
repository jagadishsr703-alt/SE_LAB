#ifndef STUDENT_INPUT_H
#define STUDENT_INPUT_H

#include <stdio.h>          
#include "student.h"        

int readStudent(FILE *fp, struct Student *s);
int isDuplicateID(struct Student s[], int count, char id[]);

#endif


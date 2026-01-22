#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdio.h>
#include "student.h"

void updateStatistics(struct Student *s,
                      float *classTotal,
                      float *highest,
                      float *lowest,
                      int gradeCount[]);

void printStatistics(FILE *fp,
                     float classTotal,
                     float highest,
                     float lowest,
                     int totalStudents,
                     int gradeCount[]);

#endif


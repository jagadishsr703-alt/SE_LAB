#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Student
{
    char id[20];
    char name[20];
    int minor[5];
    int major[5];
    int total[5];
    int grade[5];
    float cgpa;
    float percentage;
};

//checking validataion
int isValidID(char id[])
{
    for(int i=0;id[i] !='\0';i++)
    {
    	 if(!isalnum(id[i]))
        {
        	return 0;
		}
	}    
            
    return 1;
}

//checking valid name
int isValidName(char name[])
{
    for (int i=0;name[i] !='\0';i++)
    {
	    if (!isalpha(name[i]))
            return 0;
	}
	return 1;
}


int main()
{
    FILE *in, *out;
    struct Student s[50];
    char inputFile[50];
    int count = 0;

    float classTotalPercentage=0;
    float highest=0, lowest=100;
    int gradeCount[11] ={0};

    printf("enter input file name:");
    scanf("%s", inputFile);

    in=fopen(inputFile,"r");
    if (in == NULL)
    {
        printf("cannot open input file\n");
        return 1;
    }

    while(fscanf(in,"%s",s[count].id)==1)
    {
        //check for duplicates
		int duplicate=0,valid=1;

        if (count>=50)
            break;

        
        if (!isValidID(s[count].id))
        {
            char temp[20]; int a, b;
            fscanf(in,"%s", temp);
            for (int i = 0; i < 5; i++)
                fscanf(in,"%s %d %d",temp,&a,&b);
            continue;
        }

        //checking for duplicates
        for (int i=0; i<count;i++)
        {
            if (strcmp(s[i].id,s[count].id)==0)
            {
                duplicate = 1;
                break;
            }
        }

        if (duplicate)
        {
            char temp[20];int a,b;
            fscanf(in,"%s",temp);
            for (int i = 0; i < 5; i++)
                fscanf(in,"%s %d %d",temp,&a,&b);
            continue;
        }

        fscanf(in, "%s",s[count].name);

        //Name validation
        if (!isValidName(s[count].name))
        {
            char temp[20];int a,b;
            for (int i=0; i<5;i++)
                fscanf(in,"%s %d %d", temp, &a,&b);
            continue;
        }

        int subjectPass=1;
        int totalMarks=0;

        for (int i=0;i<5;i++)
        {
            char subject[20];
            fscanf(in,"%s %d %d",subject,&s[count].minor[i],&s[count].major[i]);

            if (s[count].minor[i] < 0 ||s[count].minor[i] > 40 ||s[count].major[i] < 0 ||s[count].major[i] > 60)
                valid = 0;

            s[count].total[i] = s[count].minor[i] + s[count].major[i];
            totalMarks += s[count].total[i];

            if (s[count].total[i] < 50)
                subjectPass = 0;

            if (s[count].total[i] >= 90) s[count].grade[i] = 10;
            else if (s[count].total[i] >= 85)s[count].grade[i] = 9;
            else if (s[count].total[i] >= 75)s[count].grade[i] = 8;
            else if (s[count].total[i] >= 65)s[count].grade[i] = 7;
            else if (s[count].total[i] >= 60)s[count].grade[i] = 6;
            else if (s[count].total[i] >= 55)s[count].grade[i] = 5;
            else if (s[count].total[i] >= 50)s[count].grade[i] = 4;
            else s[count].grade[i] = 0;
        }

        if (!valid ||!subjectPass)
            continue;

        int gradeSum = 0;
        for (int i=0; i<5;i++)
            gradeSum += s[count].grade[i];

        s[count].cgpa = gradeSum/5.0;
        s[count].percentage = totalMarks/5.0;

        classTotalPercentage += s[count].percentage;

        if (s[count].percentage > highest)
            highest = s[count].percentage;
        if (s[count].percentage < lowest)
            lowest = s[count].percentage;

        gradeCount[(int)s[count].cgpa]++;
        count++;
    }

    fclose(in);

    out = fopen("output.txt", "w");
    if (out == NULL)
        return 1;


    fprintf(out,"%-10s %-12s " "| %-6s %-6s %-6s %-6s " "| %-6s %-6s %-6s %-6s " "| %-6s %-6s %-6s %-6s " "| %-6s %-6s %-6s %-6s " "| %-6s %-6s %-6s %-6s " "| %-5s %-8s\n",
        "ID","NAME",
        "S1_min","S1_Maj","S1_Tot","S1_Gra",
        "S2_min","S2_Maj","S2_Tot","S2_Gra",
        "S3_min","S3_Maj","S3_Tot","S3_Gra",
        "S4_min","S4_Maj","S4_Tot","S4_Gra",
        "S5_min","S5_Maj","S5_Tot","S5_Gra",
        "CGPA","PERC");

    fprintf(out,"============================================================================================================================================================================================\n");


    for(int i=0; i<count;i++)
    {
        fprintf(out,"%-10s %-12s ",s[i].id,s[i].name);

        for (int j = 0; j < 5; j++)
            fprintf(out,"| %-6d %-6d %-6d %-6d ",s[i].minor[j], s[i].major[j], s[i].total[j],s[i].grade[j]);

        fprintf(out,"| %-5.2f %-8.2f\n",s[i].cgpa,s[i].percentage);
    }

    fprintf(out,"=============================================================================================================================================================================================\n");


    fprintf(out,"\nclass average percentage :%.2f\n",
            classTotalPercentage / count);
    fprintf(out,"highest percentage       : %.2f\n",highest);
    fprintf(out,"lowest percentage        : %.2f\n",lowest);

    fprintf(out,"\ngrade distribution:\n");
    for(int i = 0; i <= 10; i++)
    {
	   if (gradeCount[i] > 0)
	   {
	   		fprintf(out,"grade %d : %d students\n",i,gradeCount[i]);
	   }
            
	}
    fclose(out);

    printf("output written to output.txt\n");
    return 0;
}


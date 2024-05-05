#include <stdio.h>
#include <string.h>
// CALENDAR
int months(int leap)
{

    char arr[12][20] = {
        {" January "},
        {" February "},
        {" March "},
        {" April "},
        {" May "},
        {" June "},
        {" July "},
        {" August "},
        {" September "},
        {" October "},
        {" November "},
        {" December "},
    };
    for (int i = 0; i < 12; i++)
    {
        

            printf("\n %s\n ", arr[i]);
            printf("\n Sun Mon Tue Wed Thu Fri Sat");
            printf("\n       1   2   3   4   5   6");
            printf("\n   7   8   9  10  11  12  13");
            printf("\n  14  15  16  17  18  19  20");
            printf("\n  21  22  23  24  25  26  27");
            if ((strcmp(arr[i] , " February ")==0) && (leap == 1))
            {
                printf("\n  28  29\n");
                continue;
            }
            else if ((strcmp(arr[i] , " February "))==0 && (leap == 0))
            {
                printf("\n  28\n");
                continue;
            }
            else{
            printf("\n  28  29  30  31\n");
            }
    }
    return 0;
}

/*
input olaraq daxil edilir 1999
1999cu ilin yanvardan dekabra qeder kalendar cixacaq


Enter a year: 2024
Calendar for the year 2024:

---------------- January ----------------
Sun Mon Tue Wed Thu Fri Sat
   1   2   3   4   5   6
7   8   9  10  11  12  13
14  15  16  17  18  19  20
21  22  23  24  25  26  27
28  29  30  31


*/
int main()
{
    printf("Input a year to show: ");
    int year;
    scanf("%d", &year);
    int leap = 0;
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                leap = 1;
            }
        }
        else
        {
            leap = 1;
        }
    }
    else
    {
        leap = 0;
    }
    months(leap);
    return 0;
}

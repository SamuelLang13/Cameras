#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main (void)
{
    int cameraID;
    char RZ[1001];
    char month[4];
    int day;
    int hour;
    int min;
    int input;

    while ((input=scanf("%d: %1000s %3s %d %d:%2d",&cameraID,RZ,month,&day,&hour,&min)==6))
    {
        printf("OK\n");
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%c\n",RZ[i]);
    }
    

    
    if(input!=EOF)
    {
        printf("END\n");
        return 0;
    }
    return 0;
}
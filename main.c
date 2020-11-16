#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Cameras{

    int s_cameraID;
    char s_RZ[1000];
    char s_month[4];
    int s_day;
    int s_hour;
    int s_min;

}CAMERA;

CAMERA *readCamera(int *n)
{
    CAMERA *data=NULL;
    int max=0;
    int cameraID;
    char RZ[1000];
    char month[4];
    int day;
    int hour;
    int min;
    int input;

    *n=0;

    while ((input=scanf("%d: %1000s %3s %d %d:%2d",&cameraID,RZ,month,&day,&hour,&min)==6))
    {
        //printf("OK\n");

        if(*n>=max)
        {
            if(max<500)
            {
                max=max+100;
            }
            else
            {
                max=max+50;
            }

            data=(CAMERA*)realloc(data,max*sizeof(*data));
            
        }
        strncpy(data[*n].s_RZ,RZ,sizeof(data[*n].s_RZ));
        strncpy(data[*n].s_month,month,sizeof(data[*n].s_month));
        data[*n].s_cameraID=cameraID;
        data[*n].s_month=month;
        data[*n].s_day=day;
        data[*n].s_hour=hour;
        data[*n].s_min=min;
        ++*n;
    }
    






}



int main(void)
{
    int n;
    CAMERA *data;
    printf("Data z kamer:\n");
    data=readCamera(&n);




    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function for checking if the day is good
int months(char *month,int day)
{
    int isGood=0;
    switch (month[0])
    {
        case 'A' :
        {
            if(month[1]=='p' && month[2]=='r' && month[3]=='\0')
            {
                if(day>30)
                {
                    isGood=0;
                    return isGood;                     
                }
                isGood=1;
                return isGood;   
            }
            else if(month[1]=='u'&& month[2]=='g' && month[3]=='\0')
            {
                if(day>31)
                {
                    isGood=0;
                    return isGood;                     
                }
                isGood=1;
                return isGood;   
            }
            else
            {
                isGood=0;
                return isGood; 
            }
            break;
        }
        case 'D' :
        {
            if(month[1]=='e')
            {
                if(month[2]=='c' && month[3]=='\0')
                {
                    if(day>31)
                    {
                        isGood=0;
                        return isGood;                     
                    }
                    isGood=1;
                    return isGood;                       
                }
            }
            else
            {
                isGood=0;
                return isGood;                
            }
            
        }
        case 'J' :
        {
            if(month[1]=='a'&& month[2]=='n' && month[3]=='\0')
            {
                if(day>31)
                {
                    isGood=0;
                    return isGood;                     
                }
                isGood=1;
                return isGood;                  
            }
            else if(month[1]=='u'&& month[2]=='n' && month[3]=='e'&& month[4]=='\0')
            {
                if(day>30)
                {
                    isGood=0;
                    return isGood;                     
                }
                isGood=1;
                return isGood;  
            }
            else if(month[1]=='u'&& month[2]=='l' && month[3]=='y'&& month[4]=='\0')
            {
                if(day>31)
                {
                    isGood=0;
                    return isGood;                     
                }
                isGood=1;
                return isGood;                  
            }
            else
            {
                isGood=0;
                return isGood;   
            }
            
        }
        case 'F' :
        {
            if(month[1]=='e'&& month[2]=='b' && month[3]=='\0')
            {
                if(day>28)
                {
                    isGood=0;
                    return isGood;                     
                }
                isGood=1;
                return isGood;                  
            }
            else
            {
                isGood=0;
                return isGood; 
            }
            
        }
        case 'M' :
        {
            if(month[1]=='a'&& month[2]=='r' && month[3]=='\0')
            {
                if(day>31)
                {
                    isGood=0;
                    return isGood;                     
                }
                isGood=1;
                return isGood;                  
            }
            else if(month[1]=='a'&& month[2]=='y' && month[3]=='\0')
            {
                if(day>31)
                {
                    isGood=0;
                    return isGood;                     
                }
                isGood=1;
                return isGood;    
            }
            else
            {
                isGood=0;
                return isGood; 
            }
        }
        case 'N' :
        {
            if(month[1]=='o'&& month[2]=='v' && month[3]=='\0')
            {
                if(day>30)
                {
                    isGood=0;
                    return isGood;                     
                }
                isGood=1;
                return isGood;                  
            }
            else
            {
                isGood=0;
                return isGood; 
            }
        }
        case 'O' :
        {
            if(month[1]=='c'&& month[2]=='t' && month[3]=='\0')
            {
                if(day>31)
                {
                    isGood=0;
                    return isGood;                     
                }
                isGood=1;
                return isGood;                  
            }
            else
            {
                isGood=0;
                return isGood; 
            }
        }      
        case 'S' :
        {
            if(month[1]=='e'&& month[2]=='p' && month[3]=='t' && month[4]=='\0')
            {
                if(day>30)
                {
                    isGood=0;
                    return isGood;                     
                }
                isGood=1;
                return isGood;                  
            }
            else
            {
                isGood=0;
                return isGood; 
            }
        }                                  
        default:
        {
            isGood=0;
            return isGood;
        }
    }
    return isGood;
}

typedef struct Cameras{

    int s_cameraID;
    char s_RZ[1000];
    char s_month[5];
    int s_day;
    int s_hour;
    int s_min;

}CAMERA;


//function for reading the parameters of camera/s
CAMERA *readCamera(int *n)
{
    CAMERA *data=NULL;
    int max=0;
    int cameraID;
    char RZ[1000];
    char month[5];
    int day;
    int hour;
    int min;
    int input;
    int isDayGood=0;
    int isFirst=1;
    int isLast=0;
    //int sizeOfMonth=0;

    *n=0;

    while ((input=scanf("%d: %1000s %5s %d %d:%2d",&cameraID,RZ,month,&day,&hour,&min)==6)!=EOF)
    {
        //sizeOfMonth=sizeof(month)/sizeof(month[0]);
        //reallocating the size of they array
        if(*n>=max)
        {
            if(max<1000)
            {
                max=max+500;
            }
            else
            {
                max=max+100;
            }

            data=(CAMERA*)realloc(data,max*sizeof(*data));
            
        }
        //checking if the first literal is capital
        if(month[0]>='a' && month[0]<='z')
        {
            printf("OK\n");
            return 0;
        }
        isDayGood=months(month,day);
        if(isDayGood==0)
        {
            return 0;
        }
        if(hour>23 || hour<0 || min>59 || min<0)
        {
            return 0;            
        }
        //printf("OK MONTH\n");
        //function for checking if the day is good
        isDayGood=months(month,day);
        strncpy(data[*n].s_RZ,RZ,sizeof(data[*n].s_RZ));
        strncpy(data[*n].s_month,month,sizeof(data[*n].s_month));
        data[*n].s_cameraID=cameraID;
        data[*n].s_day=day;
        data[*n].s_hour=hour;
        data[*n].s_min=min;
        ++*n;
    }
    //The format is not good
    if(input !=EOF)
    {
        free(data);
        return NULL;
    }
    return data;
}

int main(void)
{
    int n;
    CAMERA *data;
    printf("Data z kamer:\n");
    data=readCamera(&n);
    if(!data)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }
    printf("OK\n");
    free(data);
    return 0;
}
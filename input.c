#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
 
int main(void)
{
    FILE *fPtr1=freopen("1e4.txt", "w", stdout);
    
    srand(time(NULL));//讓每次隨機數都不同
    
    for(int i=0;i<10000;i++)
	{
        int a=(rand()%INT_MAX);//數值
        printf("%d\n",a);
	}

    fclose(fPtr1);

    FILE *fPtr2=freopen("1e5.txt", "w", stdout);
    
    srand(time(NULL));//讓每次隨機數都不同
    
    for(int i=0;i<100000;i++)
	{
        int a=(rand()%INT_MAX);//數值
        printf("%d\n",a);
	}

    fclose(fPtr2);

    FILE *fPtr3=freopen("1e6.txt", "w", stdout);
    
    srand(time(NULL));//讓每次隨機數都不同
    
    for(int i=0;i<1000000;i++)
	{
        int a=(rand()%INT_MAX);//數值
        printf("%d\n",a);
	}

    fclose(fPtr3);


    
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main()
{
    int number = 0;
    int pid,status;
 
    printf("Lutfen bir rakam girin \n");
    scanf("%d", &number);
 
       if(number < 0)
    {
          printf("Lutfen sifirdan buyuk bir rakam girin\n");
      scanf("%d", &number);
    }
 
    pid = fork();
 
    if(pid < 0)
    {
      printf(" Child process olusturulamadi\n");
      exit(-1);
    }
 
    else if(pid == 0)
    {
             do
        {
        if(number%2 != 0)
        {
          number = (number*3)+1;
                }
         
        else if(number%2 == 0)
        {
          number = number/2;
        }
 
        printf("%d \n",number);
        }while(number != 1);
    }
 
    else
    {
 
        printf("pid %d \n",pid);
    printf("Child processin bitmesi bekleniyor\n");
      wait(&status);
      }     
     
     
return 0;   
}

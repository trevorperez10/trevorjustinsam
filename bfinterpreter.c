// Compiled with: gcc -std=c11 -Wall -pthread -lm

#include <stdio.h>
#include <stdbool.h>



void fumarole (char* ascii, int arr[])
{
    int x = 0;
    int countopen = 0; //# of open parentheses
    int countclosed = 0; //# of closed parentheses
    bool searching = false;
    int man = arr[x];
    int searchingpos = 0;
    for(int i = 0; ascii[i] != '\0'; i++)
    {
        //printf("%d\n", man);
        if (searching == false)
        {
            if (ascii[i] == '>')
            {
                if(i + 1 == sizeof(ascii))
                {
                    printf("undestirable wrapping was prevented");
                    break;
                }
                else
                {
                    arr[x] = man;
                    man = arr[x + 1];
                }
            }
            else if (ascii[i] == '<')
            {    
                if (i == 0)
                {
                    printf("undestirable wrapping was prevented");
                    break;                      
                }
                else
                {
                    arr[x] = man;
                    man = arr[x - 1];
                }
            }
            else if (ascii[i] == '+')
            {
                if (man == 255)
                {
                    man = 0;
                }
                else
                {
                    man = man + 1;
                }
            }
            else if (ascii[i] == '-')
            {
                if (man == 0)
                {
                    man = 255;
                }
                else
                {
                    man = man - 1;
                }
                    
            }
            else if (ascii[i] == '(')
            { 
                if (man == 0)
                {
                    searching = true;
                    //printf("%d\n",searchingpos );
                    countopen += 1;
                }
                searchingpos = i;

            }
            else if (ascii[i] == ')')
            {
                if (man != 0)
                {
                    i = searchingpos - 1;
                }

            }
        
            else if (ascii[i] == '*')
            {
                printf( "%c", man);
            }
       }
       else
       {
            //printf("hi");
            if (ascii[i] == ')')
            {
                countclosed += 1; 
                if (countopen == countclosed)
                {
                    if (man == 0)
                    {
                        searching = false;
                    }
                    else 
                    {
                        i = searchingpos - 1;
                    }
                }
            }
           
        }
                
    }
    if (searching == true)
    {
        printf("bad parenthesis 2");
    }
}

int main(int argc, char** argv) 
{
    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");
    char buffer[50000];
    int arr[50000] = {0};
    fumarole(fgets(buffer, 50000, fp), arr );
    fclose(fp);

}
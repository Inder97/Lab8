# include <stdio.h>
# include <stdlib.h>
#include <string.h>
# include <ctype.h>

int main(int argc, char * argv[])
{
    int OutNotProvided=0;
    
    
    if (argc ==1 )
    {
        printf ("Please provide at least the input file name\n");
        exit(1);
    }
    
    FILE *in= fopen(argv[1], "r");
    if (!in)
    {
        printf("Unable to open the file\n");
        exit(1);
    }
    
    if (argc==2)
    {
        OutNotProvided=1;
    }
    else 
    {
        FILE *rev= fopen(argv[2], "w");
        if (!rev)
            {
                printf("Unable to open the file\n");
                exit(1);
            }
    }
  
    char line [1000];
    char revline[1000];
    //int j=0;
    FILE *rev= fopen(argv[2], "w");
    
    while (fgets(line,1000,in)!=NULL)
    {
        int j=0;
        
        for (int i=strlen(line)-2; i>=0; i--)
        {
            if (OutNotProvided==1)
            {
                printf("%c", line[i]);
            }
            else
            {
                //printf("%c\n", line[i]);
                fprintf(rev, "%c", line[i]);
            }
             
        }
        
         if (OutNotProvided==1)
            {
                printf("\n");
            }
            else
            {
                //printf("%c\n", line[i]);
                fprintf(rev, "%s", " \n");
            }
     
    }
    
    fclose (in);
    
    if (OutNotProvided==0)
    {
        fclose (rev);
    }

}
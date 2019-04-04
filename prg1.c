# include <stdio.h>
# include <stdlib.h>
#include <string.h>
# include <ctype.h>

int main(int argc, char * argv[])
{
    if (argc <2 )
    {
        printf ("Please provide a file name\n");
        exit(1);
    }
    
    FILE *in= fopen(argv[1], "r");
    if (!in)
    {
        printf("Unable to open the file\n");
        exit(1);
    }
    
    char line [1000];
    int charcount=0;
    int linecount=0;

    int words=0;;
    
    /*while (fgets(line,1000,in)!=NULL)
    {
        linecount++;
        for (int i=0; i< strlen (line); i++)
        {
           
            if( isalnum(line[i]) )
            {
                charcount++;
            }
        }
    }
    
     fclose(in);
     
      FILE *in2= fopen(argv[1], "r");*/

    int i=0;
    int something=0;
    while (fgets(line,1000,in)!=NULL)
    {
        linecount++;
        
        for (int i=0; i< strlen (line); i++)
        {
              while(isalnum(line[i]))
                {
                    
                    //printf("%c", line[i]);
                    something =1;
                    charcount++;
                    i++;
                }
                
                if (something==1)
                {
                    while(isspace(line[i]))
                    {
                        //printf("%c\n", line[i]);
                        i++;
                    }
                    words++;
                    i--;
                    something =0;
                }
                
        }        

    }
    
    printf("characters: %d\n", charcount );
    printf("lines: %d\n", linecount );
    printf("words: %d\n", words );
    
    fclose(in);

}
//Jenny Shen 260509776
#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {

    FILE *fileToRead;
    char fileName[100];
    int headInt;
    BOOLEAN stop = 0;
    int deleteInt;
    char keepGoing[100];

    while(fileToRead==NULL)
    {
        printf("ENTER A FILE NAME: ");
        scanf("%s", fileName);
        fileToRead = fopen(fileName, "rt");
    }
    
    if(fileToRead)
    {
        while(fscanf(fileToRead,"%d\n", &headInt)!=EOF)
        {
            if(headInt!=0)
            {
            add(headInt);
            }
        }
        fclose(fileToRead);
        prettyPrint();
    }

    while(!stop)
    {
        
        printf("ENTER THE NUMBER YOU WANT TO DELETE: ");
        scanf("%d", &deleteInt);
        if(delete(deleteInt))
        {
            printf("NUMBER DELETED \n");
        }
        else
        {
            printf("NUMBER NOT FOUND \n");
        }

        prettyPrint();
        printf("CONTINUE TO DELETE ANOTHER NUMBER? ");

        scanf("%s", keepGoing);
        if(strcasecmp(keepGoing, "yes")==0)
        {
            continue;
        }
        else if (strcasecmp(keepGoing, "y")==0)
        {
            continue;
        }
        else
        {
            stop = true;
        }
    }
    
    return 0;
}

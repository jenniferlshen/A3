//JENNY SHEN 260509776
#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    FILE *fileToRead;
    char fileName[100];
    int headNum;
    BOOLEAN stop = 0;
    int numToDelete;
    char boolcontinue[100];

    //ASK USER TO ENTER A FILE NAME, KEEP PROMPTING UNTIL GET A FILE THAT EXISTS
    while(fileToRead==NULL)
    {
        printf("ENTER A FILE NAME: ");
        scanf("%s", fileName);
        fileToRead = fopen(fileName, "rt");
    }
    
    //SCAN THROUGH AND PRINT FILE IF FILE EXISTS
    if(fileToRead)
    {
        while(fscanf(fileToRead,"%d\n", &headNum)!=EOF)
        {
            if(headNum!=0)
            {
            add(headNum);
            }
        }
        fclose(fileToRead);
        prettyPrint();
    }

    //UNTIL USER SAYS STOP (CHANGE 0 TO 1), KEEP PROMPTING USER FOR A NUMBER TO DELETE
    while(!stop)
    {
        
        printf("ENTER THE NUMBER YOU WANT TO DELETE: ");
        scanf("%d", &numToDelete);
        
        //IF DELETE FUNCTION RETURNS TRUE, THEN IT IS DELETED SUCCESSFULLY
        if(delete(numToDelete))
        {
            printf("NUMBER DELETED \n");
        }
        //IF DELETE FUNCTION RETURNS FALSE, THEN NODE CANNOT BE FOUND
        else
        {
            printf("NUMBER NOT FOUND \n");
        }

        //PRINT .TXT FILE CONTENT AGAIN, PROMPT FOR AGAIN
        prettyPrint();
        printf("CONTINUE TO DELETE ANOTHER NUMBER? ");

        //IF USER SAYS Y/y/YES/yes/YeS/yEs... ANY COMBINATION OF CASES, THEN CONTINUE.
        //IF NOT, THEN CHANGE STOP TO 1
        scanf("%s", boolcontinue);
        if(strcasecmp(boolcontinue, "yes")==0)
        {
            continue;
        }
        else if (strcasecmp(boolcontinue, "y")==0)
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

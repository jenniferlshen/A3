//JENNY SHEN 260509776
#include <stdlib.h>
#include "list.h"

NODE* head = NULL;

//ADD A NEW NODE TO LINKED LIST
void add(int newNum) {
    //INITIALIZE NEW NODE WITH NEW NUMBER, NO NEXT
    NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode -> value = newNum;
    newNode -> next = NULL;
    
    //IF HEAD DOESN'T EXIST IN LINKED LIST, THEN NEW NODE WILL BE THE FIRST NODE (AND HEAD)
    if(head==NULL)
    {
        head = newNode;
        head -> next = NULL;
    }
    //IF HEAD ALREADY EXISTS, NEWNODE WILL NOW BE THE LAST ELEMENT OF THE LINKED LIST
    else
    {
        NODE *current;
        current = head;
        //IF HEAD ISN'T THE ONLY NODE IN LINKED LIST, THEN SHIFT DOWN VALUES
        while (current -> next != NULL)
        {
            current = current->next;
        }
        //LAST ELEMENT
        current -> next = newNode;
    }
}

void prettyPrint() {
    NODE *current;
    current = head;
    //IF LINKED LIST ISNT NULL, THEN PRINT THE WHOLE LIST
    while (current!=NULL)
    {
        printf("%d ", current -> value);
        current = current -> next;
    }
}

BOOLEAN delete(int deleteNum) {
    NODE *delete;
    delete = find(deleteNum);
    //IF NODE TO DELETE IS ACTUALLY A NODE IN THE LINKED LIST THEN
    if(delete!=NULL)
    {
        NODE* pointer = delete -> next;
        if(pointer!=NULL)
        {
            if (pointer -> value == deleteNum)
            {
                delete -> next = pointer -> next;
                free(pointer);
                return 1;
            }
            else
            {
                head = pointer;
                free(delete);
                return 1;
            }
        }
        else
        {
            head = NULL;
            return 1;
        }
    }
    return 0;
}

//FIND THE NODE WITH THE VALUE
NODE *find(int number) {
    NODE *current;
    NODE *currentNext;
    current = head;
    
    //RUN THROUGH LIST IF LINKED LIST IS NOT NULL
    if(current!=NULL)
    {
        currentNext = current -> next;
        //IF CURRENT NODE'S VALUE IS EQUALED TO THE NUMBER WE ARE TRYING TO FIND, THEN RETURN
        if(current -> value == number)
        {
            return current;
        }
        //IF NOT, KEEP RUNNING THROUGH NEXT
        while(currentNext!=NULL)
        {
            if(currentNext -> value == number)
            {
                return current;
            }
            current = current -> next;
            currentNext = currentNext -> next;
        }
        //RETURN NULL IF DID NOT FIND A NODE WITH THE VALUE OF NUMBER
        return NULL;
    }
    //RETURN NULL IF LIST IS NULL
    return NULL;

 }


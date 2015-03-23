//JennyShen
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

NODE *find(int searchValue) {
    NODE *current;
    NODE *currentNext;
    current = head;
    if(current!=NULL)
    {
        currentNext = current -> next;

        if(current -> value == searchValue)
        {
            return current;
        }
        while(currentNext!=NULL)
        {
            if(currentNext -> value == searchValue)
            {
                return current;
            }
            current = current -> next;
            currentNext = currentNext -> next;
        }
        return NULL;
    }
    return NULL;

 }


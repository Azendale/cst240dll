#include "DoubleLinkedList.h"

// File to test double linked list.
// Erik Andersen <erik.andersen@oit.edu> on 2016-01-28

#include <stdio.h>
#include <stdlib.h>

void intPrinter(int intToPrint)
{
    printf("%d\n", intToPrint);
}

int main(int argc, char ** argv)
{
    linked_list_t * mylist = Init_List();
    
    for (int iterator = 0; iterator < 10; ++iterator)
    {
        Insert_At_Beginning(mylist, iterator);
    }
    
    if (10 != Count(mylist))
    {
        printf("Found %d items on the stack, instead of 10\n", Count(mylist));
        exit(1);
    }
    
    int expectedStacktop = 9;
    int stacktop = 0;
    while (! Empty(mylist))
    {
        Remove_From_Beginning(mylist, &stacktop);
        if (stacktop != expectedStacktop)
        {
            printf("Expected %d at the top of the stack but got %d\n", expectedStacktop, stacktop);
            exit(1);
        }
        if ( Count(mylist) != stacktop)
        {
            printf("Count(mylist) returned an unexpected number of items: %d\n", Count(mylist));
            exit(1);
        }
        --expectedStacktop;
    }
    if (0 != stacktop)
    {
        printf("Expected 0 now that we should be at the bottom of the stack, but got %d\n", stacktop);
        exit(1);
    }
    // If we got this far without calling exit, everything seems good.
    printf("Stack test of list worked for functions operating at the front.\n");
    
    // Now let's try it at the end of the list
    for (int iterator = 0; iterator < 10; ++iterator)
    {
        Insert_At_End(mylist, iterator);
    }
    
    if (10 != Count(mylist))
    {
        printf("Found %d items on the stack, instead of 10\n", Count(mylist));
        exit(1);
    }
    
    expectedStacktop = 9;
    stacktop = 0;
    while (! Empty(mylist))
    {
        Remove_From_End(mylist, &stacktop);
        if (stacktop != expectedStacktop)
        {
            printf("Expected %d at the top of the stack but got %d\n", expectedStacktop, stacktop);
            exit(1);
        }
        if ( Count(mylist) != stacktop)
        {
            printf("Count(mylist) returned an unexpected number of items: %d\n", Count(mylist));
            exit(1);
        }
        --expectedStacktop;
    }
    if (0 != stacktop)
    {
        printf("Expected 0 now that we should be at the bottom of the stack, but got %d\n", stacktop);
        exit(1);
    }
    // If we got this far without calling exit, everything seems good.
    printf("Stack test of list worked for functions operating at the end.\n");
    
    if (!Empty(mylist))
    {
        printf("Expected stack to be empty, but it is not.\n");
        exit(1);
    }
    
    int data = 0;
    for (int iterator = 0; iterator < 20; ++iterator)
    {
        data = rand() % 1000;
        printf("Adding %d to the list.\n", data);
        Insert_in_order(mylist, data);
    }
    
    Traverse(mylist, intPrinter);
    
    if (Count(mylist) != 20)
    {
        printf("Expected count of list after random insertion, should be 20 but it was %d\n", Count(mylist));
        exit(1);
    }
    
    Delete_List(mylist);
    free(mylist);
    mylist = NULL;
    return 0;
}
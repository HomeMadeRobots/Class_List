#include "List.h"

#include <stddef.h>

/*============================================================================*/
/* Public methods */
/*============================================================================*/
void List__Add_Head( List* list, List_Item* item )
{
    if( NULL!=list && NULL!=item )
    {
        if( list->Nb_Items < MAX_LIST_NB_ITEMS )
        {
            item->Previous_Item = NULL;
            if( NULL==list->Head_Item )
            { /* list is empty */
                item->Next_Item = NULL;
                list->Head_Item = item;
                list->Tail_Item = item;
            }
            else 
            { /* list is not empty */
                /* First becomes second */
                item->Next_Item = list->Head_Item;
                list->Head_Item->Previous_Item = item;
                
                /* Update Head */
                list->Head_Item = item;
            }
            (list->Nb_Items)++;           
        }
    }
}
/*----------------------------------------------------------------------------*/
void List__Add_Tail( List* list, List_Item* item )
{
    if( NULL!=list && NULL!=item )
    {
        if( list->Nb_Items < MAX_LIST_NB_ITEMS )
        {
            item->Next_Item = NULL;
            if( NULL==list->Head_Item )
            { /* list is empty */
                item->Previous_Item = NULL;
                list->Head_Item = item;
                list->Tail_Item = item;
            }
            else
            { /* list is not empty */
                /* Tail becomes before last */
                item->Previous_Item = list->Tail_Item;
                list->Tail_Item->Next_Item = item;
                
                /* Update Tail */
                list->Tail_Item = item;
            }
            (list->Nb_Items)++;
        }
    }
}            
/*----------------------------------------------------------------------------*/
List_Item* List__Remove_Head( List* list )
{
    List_Item* removed = NULL;
    if( NULL!=list )
    {
        /* Save removed item */
        removed = list->Head_Item;

        /* Second becomes Head*/
        list->Head_Item = list->Head_Item->Next_Item;
        if( NULL!=list->Head_Item )
        { /* list had more than 1 item */
            list->Head_Item->Previous_Item = NULL;
        }
        
        (list->Nb_Items)--;
    }
    return removed;
}
/*----------------------------------------------------------------------------*/
List_Item* List__Remove_Tail( List* list )
{
    List_Item* removed = NULL;    
    if( NULL!=list )
    {
        /* Save removed item */
        removed = list->Tail_Item;
        
        /* Before last becomes Tail */
        list->Tail_Item = list->Tail_Item->Previous_Item;
        if( NULL!=list->Tail_Item )
        { /* list had more than 1 item */
            list->Tail_Item->Next_Item = NULL;
        }
        (list->Nb_Items)--;
    }
    return removed;
}
/*----------------------------------------------------------------------------*/
List_Item* List__Get_Head( List* list )
{
    if( list!=NULL )
    {
        return list->Head_Item;
    }
    else
    {
        return NULL;
    }   
}
/*----------------------------------------------------------------------------*/
List_Item* List__Get_Tail( List* list )
{
    if( list!=NULL )
    {
        return list->Tail_Item;
    }
    else
    {
        return NULL;
    }    
}
/*----------------------------------------------------------------------------*/
uint8_t List__Get_Nb_Items( List* list )
{
    if( list!=NULL )
    {
        return list->Nb_Items;
    }
    else
    {
        return 0;
    }     
}
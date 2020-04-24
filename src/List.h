#ifndef LIST_H
#define LIST_H

#include <stdint.h>


/*============================================================================*/
/* Class */
/*============================================================================*/
typedef struct _List_Item {
    struct _List_Item* Next_Item;
    struct _List_Item* Previous_Item;
    void* Data;
} List_Item;

typedef struct {
    List_Item* Head_Item;
    List_Item* Tail_Item;
    uint8_t Nb_Items;
} List;

#define MAX_LIST_NB_ITEMS 255

/*============================================================================*/
/* Public methods */
/*============================================================================*/
void List__Add_Head( List* list, List_Item* item );
void List__Add_Tail( List* list, List_Item* item );
List_Item* List__Remove_Head( List* list );
List_Item* List__Remove_Tail( List* list );
List_Item* List__Get_Head( List* list );
List_Item* List__Get_Tail( List* list );
uint8_t List__Get_Nb_Items( List* list );


#endif
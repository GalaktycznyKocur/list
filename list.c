#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int value;
    struct node *next;

}node;

typedef struct linkedList {

    node *head;
    node *tail;
    int howManyNodes;

}linkedList;

void menu() {

    printf("\n\n============== MENU ==============\n\n");
    printf("1. Dodaj element na poczatek\n");
    printf("2. Dodaj element na koniec\n");
    printf("3. Usun poczatkowy element\n");
    printf("4. Usun ostatni element\n");
    printf("5. Wyswietl liste\n");
    printf("6. Sprawdz ilosc elementow w liscie\n");
    printf("0. Wyjdz\n\n\n");

    printf("Podaj co chcesz zrobic: ");

}

void createList(linkedList *list) {

    list->head = NULL;
    list->tail = NULL;
    list->howManyNodes = 0;

}

int howManyElements(linkedList *list) {

    printf("Ilosc elementow w liscie: %d", list->howManyNodes);
    return list->howManyNodes;

}

void addAtHead(linkedList *list, int valueToAdd) {

    if(list->head == NULL) {    //list is empty, the object we are creating becomes head and tail.
        node *newNode = (node*)malloc(sizeof(node));
        newNode->value = valueToAdd;
        newNode->next = NULL;
        list->head = newNode;
        list->tail = newNode;
        list->howManyNodes++;
    }
    else {
        node *newNode = (node*)malloc(sizeof(node));
        newNode->next = list->head;
        newNode->value = valueToAdd;
        list->head = newNode;
        list->howManyNodes++;
    }
}

void addAtTail(linkedList *list, int valueToAdd) {

    if(list->head == NULL) {  //list is empty, the object we are creating becomes head and tail.
        node *newNode = (node*)malloc(sizeof(node));
        newNode->value = valueToAdd;
        newNode->next = NULL;
        list->head = newNode;
        list->tail = newNode;
        list->howManyNodes++;
    }
    else {
        node *newNode = (node*)malloc(sizeof(node));
        newNode->next = NULL;
        newNode->value = valueToAdd;
        list->tail->next = newNode;
        list->tail = newNode;
        list->howManyNodes++;
    }


}

void printList(linkedList *list) {

    if(list->head == NULL) {
        printf("Lista jest pusta!");
    }
    else {
        node *printingNode = list->head;

        while(printingNode) {
            printf("%d  ", printingNode->value);
            printingNode = printingNode->next;
        }
    }

}

void deleteHead(linkedList *list) { // DEKAPITACJA

    if(!list->head) {
        printf("Nie ma czego usunac!");
        return;
    }


    node *OldHead = list->head;
    list->head = list->head->next;
    free(OldHead);
    list->howManyNodes--;

    printf("Glowa pomyslnie usunieta!\n");
    printf("Obecna lista:\n");
    printList(list);


}

void deleteTail(linkedList *list ) {

    if(!list->tail) {
        printf("Nie ma czego usunac!");
        return;
    }

    node *newTail = list->head;

    while(newTail->next != list->tail) {    //finding the pointer to old tail
        newTail = newTail->next;
    }

    free(list->tail);
    newTail->next = NULL;
    list->tail = newTail;
    printf("Tyl pomyslnie usuniety!\n");
    printf("Obecna lista:\n");
    printList(list);

}

int main(void) {

    linkedList list;
    createList(&list);

    int choice;
    int valueToAdd;

    while(1) {

        menu();
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                printf("Podaj liczbe ktora chcesz dodac na poczatek: ");
                scanf("%d", &valueToAdd);
                addAtHead(&list, valueToAdd);
                break;
            case 2:
                printf("Podaj liczbe ktora chcesz dodac na koniec: ");
                scanf("%d", &valueToAdd);
                addAtTail(&list, valueToAdd);
                break;
            case 3:
                deleteHead(&list);
                break;
            case 4:
                deleteTail(&list);
                break;
            case 5:
                printList(&list);
                break;
            case 6:
                howManyElements(&list);
                break;
            case 0:
                //there shoud be memory clearing
                exit(0);
        }


    }

    return 0;
}

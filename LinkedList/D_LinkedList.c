// ==>  Header Files
#include<stdio.h>
#include<stdlib.h>

// ==>  LinkedList structure
struct LinkedList{
    int data;
    struct LinkedList * next;
};

// ==>  Global Variables
struct LinkedList *head = NULL;
int size = 0;

void Startadd(){
    // ==> Create a LL pointer newnode
    struct LinkedList *newnode = malloc(sizeof(struct LinkedList));
    // ==> Take user data and assign it to the LL pointer
    int data;
    printf("\nEnter the data : ");
    scanf("%d", &data);
    newnode->data = data;
    // ==> Assign the address of head(i.e.eprevious new node) to the newnode & assign the address of current newnode to head
    newnode->next = head;
    head = newnode;
    size++;
}

void Midadd(){
    // ==> Take 2 LL pointer : 1 To create a new node & 2 : To traverse to the position where newnode is to be entered
    struct LinkedList *newnode = malloc(sizeof(struct LinkedList));
    struct LinkedList *current = malloc(sizeof(struct LinkedList));
    // ==> Take position & data to be entered in linked list, assign data to newnode
    int pos, data;
    printf("\nEnter data : ");
    scanf("%d", &data);
    newnode->data = data;
    printf("\nEnter pos : ");
    scanf("%d", &pos);
    // ==> Traverse current from head to one node before the position where new node is to placed
    current = head;
    for (int i = 1; i < pos-1; i++)
    {
        current = current->next;
    }
    // ==> Assign the value to current->next to newnode->next & current->next to newnode
    newnode->next = current->next;
    current->next = newnode;
    size++;
}

void Endadd(){
    // ==> Create 2 LinkedList pointer : 1 to traverse till last & 1 to store values
    struct LinkedList *newnode = malloc(sizeof(struct LinkedList));
    struct LinkedList *current = malloc(sizeof(struct LinkedList));
    // ==> Take data in variable "data" & put it in newnode
    int data;
    printf("\nEnter data : ");
    scanf("%d", &data);
    newnode->data = data;
    // ==> Traverse till current reaches last node
    current = head;
    while(current->next != NULL){
        current = current->next;
    }
    // ==> Assign newnode to current(i.e previos last node) & NULL to newnode(i.e new last node)
    current->next = newnode;
    newnode->next = NULL;
    size++;
}

void Display(){

    if(head == NULL){
        // ==> Print this if linked list is empty
        printf("\nNO DATA IN LINKED LIST\n");
    }else{
        // ==> Take a LinkedList pointer & traverse it while printing the LL values until it reaches NULL
        struct LinkedList *display = head;
        printf("\nData in Linked List : ");
        while(display != NULL){
            printf(" %d ", display->data);
            display = display->next;
        }
        free(display);
    }
}

void Deletenode(){
    // ==> Create a LL pointer to traverse to one the node we want to delete
    struct LinkedList *current = malloc(sizeof(struct LinkedList));
    // ==> Asking user which node to delete 
    int delete;
    printf("\nNode to Delete : ");
    scanf("%d", &delete);
    // ==> Check if the node to be deleted exists or not
    if(delete > size || delete < 1)
        printf("\nINVALID ELEMENT POSITION\n");
    else{
        // ==> Traverse till you reach one node before the node to be deleted
        current = head;
        for (int i = 1; i < delete-1; i++)
        {
            current = current->next;
        }
        // ==> Skip the node to delete and assign the address in delete->node to current->node
        current->next = current->next->next;
    }
     size--;
}

void Reverse(){
    // ==> Create 3 pointer : 1 To store head : 2&3 to Traverse & to reverse the LL
    struct LinkedList *current = head;
    struct LinkedList *ahead = NULL;
    struct LinkedList *behind = NULL;
    
    // ==> Traverse current till last node, Increment ahead and point behind towards last node update behind & curent
    while(current != NULL){
        ahead = current->next;
        current->next = behind;
        behind = current;
        current = ahead;
    }
    // ==> Put head at the previous last / new head (after reverse)
    head = behind;
}

int main(){
    int option = 1;
    printf("\nLinkedList Created!");
    do
    {
        printf("\nPress : \n0 : Exit\n1 : Add Node at Start\n2 : Add node in Middle\n3 : Add node at End\n4 : Delete Node\n5 : Reverse\n6 : View\n");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            printf("\nBYE BYE!");
            break;
        case 1:
            Startadd();
            break;
        case 2:
            Midadd();
            break;
        case 3:
            Endadd();
            break;
        case 4:
            Deletenode();
            break;
        case 5:
            Reverse();
            break;
        case 6:
            Display();
            break;
        
        default:
            printf("\nWrong Input!");
            break;
        }// Switch End

    }while(option != 0);// While Loop End
    
    return 0;
}

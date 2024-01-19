[[shows.c]]

![[Datenbank Ideen#Idee 2]]

# Linked List implementation

## Period 01
#### Tasks until 25.01.
- [x] Menu
- [x] manual data entry
- [ ] read from file
- [ ] print all datasets
### Linked List
#### data structure
```c
typedef struct
{
    char date[17];
    char venue[20];
    char headliner[20];
    char support_acts[128];

} show;

typedef struct Node
{
    show *data;
    struct Node *next;
    struct Node *previous;
} Node;
```
#### Operations
##### Creating a node
Basically serves as a _constructor_ of some sorts.
```c
Node *new_node(show *data, Node *previous, Node *next)
{
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->previous = previous;
    new->next = next;

    return new;
}
```

##### Get last node in list
Knowing the last node in a List is required for appending elements to the list. The last element can be foun very easily using recursion.
```c
Node *get_last_node(Node *n)
{
    if (n->next == 0)
        return n;
    return get_last_node(n->next);
}
```

##### Appending
First a gatekeeper statement handles the edge case of the passed list being empty. If this is not the case, [[#Get last node in list]] is called and the new node created according to the principles of a [[Doubly linked list]]. 

_Return_ - returning the list is necessary because of the edge case of the list being empty. Thus, the list will _always_ have to be passed and returned - not too clean, but necessary.
```c
Node *add_to_list(show *s, Node *list)
{
    if (!list)
    {
        list = new_node(s, 0, 0);
        return list;
    }
    Node *last = get_last_node(list);
    Node *temp = new_node(s, last, last->next);
    last->next = temp;

    return list;
}
```







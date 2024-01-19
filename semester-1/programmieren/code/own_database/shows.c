#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

//--------------------------------------------------------------------------------------------------------------------------------------------

typedef struct
{
    char date[17];
    char venue[20];
    char headliner[20];
    char support_acts[64];

} show;

typedef struct Node
{
    show *data;
    struct Node *next;
    struct Node *previous;
} Node;

Node *new_node(show *data, Node *previous, Node *next)
{
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->previous = previous;
    new->next = next;

    return new;
}

Node *get_last_node(Node *n)
{
    if (n->next == 0)
        return n;
    return get_last_node(n->next);
}

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

//--------------------------------------------------------------------------------------------------------------------------------------------

show *show_from_console();
void up_hex(Node *db);
void read_text_file();
Node *manual_entry(Node *db);
void show_datasets(Node *db);
void render_menu();

//--------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    int to_do = -0x7fffff;
    Node *db = 0;

    while (to_do)
    {
        render_menu();
        scanf("%d", &to_do);
        system("clear");
        fgetc(stdin); // for some reason this is important, otherwise the  console does madly weird shit

        switch (to_do)
        {
        case -1:
            up_hex(db);
            break;
        case 1:
            read_text_file();
            break;
        case 2:
            printf("Please enter the prompted attribute of your data set.\n\n");
            db = manual_entry(db);
            break;
        case 3:
            print_datasets(db);
            break;

        default:
            printf("\nHey Hannes, du Doedel, das ist keine valide Option!\n");
        }
    }

    return 0;
}

void render_menu()
{
    printf("\n1: read .txt file");
    printf("\n2: manually enter dataset");
    printf("\n3: show all datasets");
    printf("\n\n-1: up_hex() as control");

    printf("\n\n> ");
}

Node *manual_entry(Node *db)
{
    show *s = show_from_console();
    db = add_to_list(s, db);
    return db;
}

// i need to find a different representation, strings are bullshit
show *show_from_console()
{
    show *temp = malloc(sizeof(show));
    printf("enter date of show: ");
    // scanf("%s",&temp->date);
    fgets(temp->date, sizeof(temp->date) / sizeof(char), stdin);
    temp->date[strcspn(temp->date, "\n")] = 0;

    printf("enter venue of show: ");
    // scanf("%s", &temp->date);
    fgets(temp->venue, sizeof(temp->venue) / sizeof(char), stdin);
    temp->venue[strcspn(temp->venue, "\n")] = 0;

    printf("enter headliner: ");
    fgets(temp->headliner, sizeof(temp->headliner) / sizeof(char), stdin);
    temp->headliner[strcspn(temp->headliner, "\n")] = 0;

    printf("enter support acts (seperated by commata): ");
    fgets(temp->support_acts, sizeof(temp->support_acts) / sizeof(char), stdin);
    temp->support_acts[strcspn(temp->support_acts, "\n")] = 0;

    return temp;
}

void read_text_file() {}


void __print_datasets(Node *n, int index)
{
    show *s = n->data;
    printf("\nnode %3d: %-17s %-20s %-20s %-128s", index, s->date, s->venue, s->headliner, s->support_acts);
    if (n->next == 0)
        return n;
    return __print_datasets(n->next, index + 1);
}

void print_datasets(Node *db)
{
    printf("\n          %-17s %-20s %-20s %-128s", "date", "venue", "headliner", "support acts");
    printf("\n-----------------------------------------------------------------------------------------------------------------------------");
    __print_datasets(db, 0);
    printf("\n\n");
    
}

void __up_hex(Node *list, int index)
{
    printf("\nelement %3d: %20s %10x %10x",
           index,
           list->data->headliner,
           list->previous,
           list->next);
    if (!list->next)
        return;
    return __up_hex(list->next, index + 1);
}

void up_hex(Node *db)
{
    printf("\nelement      %20s %10s %10s", "headliner", "previous", "next");
    printf("\n-------------------------------------------------------");
    __up_hex(db, 0);
    printf("\n-------------------------------------------------------\n");
}

//-------------------------------------------------------------------------------------------------------------------------------------------

void write_to_file(Node *head, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    Node *current = head;
    int index = 0;

    while (current != NULL)
    {
        show *s = current->data;
        fprintf(file, "%d: %-17s %-20s %-20s %-64s\n",
                index, s->date, s->venue, s->headliner, s->support_acts);
        current = current->next;
        index++;
    }

    fclose(file);
}

Node *read_from_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file for reading: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    Node *head = NULL;
    Node *tail = NULL;

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        show *s = (show *)malloc(sizeof(show));
        Node *newNode = (Node *)malloc(sizeof(Node));

        int index;
        sscanf(line, "%d: %16s %19s %19s %63[^\n]",
               &index, s->date, s->venue, s->headliner, s->support_acts);

        newNode->data = s;
        newNode->next = NULL;
        newNode->previous = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    fclose(file);
    return head;
}

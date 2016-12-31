#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct SINGLY_LINKED_LIST
{
  int data;
  struct SINGLY_LINKED_LIST *next;
} List;

List *front = NULL;

/**
 * Creates a new node.
 *
 * @internal
 *
 * @param int data Data for node
 *
 * @return Node
 */
List *get_node(int data)
{
    List *temp = (List *) malloc(sizeof(List));

    temp->data = data;
    temp->next = NULL;

    return temp;
}

/**
 * Insert in front of the list.
 *
 * @param List list
 * @param List new_node Node to insert
 *
 * @return List
 */
List *insert_first(List *list, List *new_node)
{
    new_node->next = list;

    front = new_node;

    return new_node;
}

/**
 * Insert at the end of list.
 *
 * @param List list
 * @param List new_node Node to insert
 *
 * @return List
 */
List *insert_last(List *list, List *new_node)
{
    if (list->next) {
        insert_last(list->next, new_node);
    } else {
        list->next = new_node;
    }

    return list;
}

/**
 * Insert in between 2 nodes.
 *
 * @param List list
 * @param List new_node Node to insert
 *
 * @return
 */
List *insert_between(List *list, List *new_node)
{
    static List *parent;

    if (!list) {
        return list;
    }

    if (list->data > new_node->data) {
        parent->next = new_node;
        new_node->next = list;
    } else {
        parent = list;
        insert_between(list->next, new_node);
    }

    return list;
}

/**
 * Find position to insert a given node.
 *
 * @param List list
 * @param new_node
 *
 * @return List
 */
List *find_insert_position(List *list, List *new_node)
{
    static List *parent;

    if (NULL == parent) {
        parent = list;
    }

    if (new_node->data > list->data) {
        parent = list;

        if (list->next) {
            find_insert_position(list->next, new_node);
        }
    }

    return parent;
}

/**
 * Find parent of a given node.
 *
 * @param List list
 * @param new_node
 *
 * @return List
 */
List *find_parent(List *list, int data)
{
    if (!list) {
        return NULL;
    }

    if (list->next && list->next->data == data) {
        return list;
    }

    return find_parent(list->next, data);
}

/**
 * Find node in a list.
 *
 * @param List list
 * @param Int data Data to search
 *
 * @return List
 */
List *find(List *list, int data)
{
    if (!list) {
        return NULL;
    }

    if (data == list->data) {
        return list;
    }

    return find(list->next, data);
}

/**
 * Insert new node to a sorted list.
 *
 * @param List
 * @param int data Data to insert
 *
 * @return void
 */
void insert_sorted(List **list, int data)
{
    List *new_node = get_node(data);

    if (!*list) {
        *list = new_node;

        front = *list;

        return;
    }

    List *parent = find_insert_position(*list, new_node);

    if (!parent->next && new_node->data < parent->data) {
        *list = insert_first(*list, new_node);
    } else if (!parent->next && new_node->data > parent->data) {
        insert_last(*list, new_node);
    } else {
        *list = insert_between(*list, new_node);
    }
}

/**
 * Insert new node to a list.
 *
 * @param List
 * @param int data Data to insert
 * @param int poistion Start, end or inbetween
 *
 * @return void
 */
void insert(List **list, int data, int position)
{
    List *new_node = get_node(data);

    if (!*list) {
        *list = new_node;

        front = *list;

        return;
    }

    switch (position) {
        case 0:
            *list = insert_first(*list, new_node);
            break;

        case 1:
            *list = insert_between(*list, new_node);
            break;

        case 2:
            *list = insert_last(*list, new_node);
            break;
    }
}

/**
 * Delete given node from a list.
 *
 * @param List list
 * @param Int data Data to delete
 *
 * @return List|NULL
 */
List *delete(List **list, int data)
{
    if (!*list) {
        return NULL;
    }

    if (front->data == data) {
        List *deleted_node = front;

        front = front->next;
        (*list) = front;

        return deleted_node;
    }

    List *parent = find_parent(*list, data);

    if (!parent) {
        return NULL;
    }

    List *delete_node = parent->next;

    parent->next = delete_node->next;

    return delete_node;
}

/**
 * Print a given list.
 *
 * @param List
 *
 * @return void
 */
void print_list(List *list)
{
    if (!list) {
        return;
    }

    printf("%d -> ", list->data);
    print_list(list->next);
}

/**
 * Print a given list in inverted order.
 *
 * @param List
 *
 * @return void
 */
void print_inverted(List *list)
{
    if (!list) {
        return;
    }

    print_inverted(list->next);
    printf("%d -> ", list->data);
}

int main()
{
    int data_array[] = {3, 2, 8, 6, 4, 4, 12};

    List *l1 = NULL;
    List *l2 = NULL;

    insert(&l1, 3, 0); //root node
    insert(&l1, 2, 0); //insert at start
    insert(&l1, 8, 2); //insert at end
    insert(&l1, 6, 1); //insert between 2 and 8

    assert(front == l1);

    print_list(l1);

    free(l1);

    for (int i = 0; i < 7; i++) {
        insert_sorted(&l2, data_array[i]);
    }

    assert(front == l2);

    printf("\n\n");
    print_list(l2);
    printf("\n");
    print_inverted(l2);

    List *find_node = find(l2, 8);
    assert(8 == find_node->data);

    find_node = find(l2, 99);
    assert(NULL == find_node);

    List *deleted_node = delete(&l2, 2);
    assert(2 == deleted_node->data);
    assert(front == deleted_node->next);

    printf("\n\n");
    print_list(l2);

    deleted_node = delete(&l2, 4);
    assert(4 == deleted_node->data);

    printf("\n");
    print_list(l2);

    deleted_node = delete(&l2, 12);
    assert(12 == deleted_node->data);

    free(l2);

    return 0;
}

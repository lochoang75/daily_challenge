#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct list_node {
    struct list_node *next;
    struct list_node *prev;
    void *container;
};

#define FOR_EACH_NODE(node, head)  \
    for (node = (head->next); node != head; node = node->next)

static void init_list(struct list_node *node, void *container)
{
    node->next = node;
    node->prev = node;
    node->container = container;
}

static void __list_add(struct list_node *head, struct list_node *new_node)
{
    head->prev->next = new_node;
    new_node->prev = head->prev;
    new_node->next = head;
    head->prev = new_node;
}

static void list_add_head(struct list_node *head, struct list_node *new_node)
{
    __list_add(head, new_node);
    head = new_node;
}

static void list_add_tail(struct list_node *head, struct list_node *new_node)
{
    __list_add(head, new_node);
}
#endif /* LINKED_LIST_H*/
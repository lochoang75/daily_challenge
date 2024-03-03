#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdlib.h>
#include <string.h>

enum bst_key_type {
    BST_KEY_NUM = 0,
    BST_KEY_STR,
};

struct node_data {
    enum bst_key_type key_type;
    int key_int;
    const char *key_str;
    void *data;
};

struct node {
    struct node *left;
    struct node *right;
    struct node_data *data;
};

struct node *bst_create_node(struct node_data *data)
{
    struct node *bst_root = (struct node*)malloc(sizeof(struct node));
    bst_root->left = NULL;
    bst_root->right = NULL;
    bst_root->data = data;
    return bst_root;
}

static int node_compare(struct node_data *first, struct node_data *secc)
{
    int ret = 0;
    if (first->key_type != secc->key_type)
    {
        return -1;
    }

    if (first->key_type == BST_KEY_NUM)
    {
        if (first->key_int > secc->key_int)
        {
            ret = 1;
        } else if (first->key_int < secc->key_int)
        {
            ret = 1;
        } else {
            ret = 0;
        }
    } else if (first->key_type == BST_KEY_STR)
    {
        ret = strcmp(first->key_str, secc->key_str);
    }

    return ret;
}

int bst_add(struct node *root, struct node_data *node_data)
{
    if (root == NULL)
    {
        return -1;
    }

    if (node_compare(root->data, node_data) > 0)
    {
        if (root->right != NULL)
        {
            bst_add(root->right, node_data);
        } else
        {
            struct node *node = bst_create_node(node_data);
            root->right = node;
        }
    } else if (node_compare(root->data, node_data) < 0)
    {
        if (root->left != NULL)
        {
            bst_add(root->left, node_data);
        } else
        {
            struct node *node = bst_create_node(node_data);
            root->left = node;
        }
    } else
    {
        struct node *node = bst_create_node(node_data);
        if (root->right == NULL)
        {
            root->right = node;
        } else if (root->left == NULL)
        {
            root->left = node;
        } else
        {
            bst_add(root->right, node_data);
        }
    }
}

int bst_add_node(struct node *root, struct node *node)
{
    if (root == NULL)
    {
        return -1;
    }

    int ret = 0;
    int cmp_value = node_compare(root->data, node->data);

    if ( cmp_value == 0)
    {
        if (root->left == NULL)
        {
            root->left = node;
        } else if(root->right == NULL)
        {
            root->right = node;
        } else
        {
            ret = bst_add_node(root->left, node);
        }
    } else if (cmp_value < 0)
    {
        ret = bst_add_node(root->left, node);
    } else
    {
        ret = bst_add_node(root->right, node);
    }

    return ret;
}

int bst_search(struct node *root, struct node_data *node_data)
{
    if (root == NULL)
    {
        return 0;
    }

    int compare_value = node_compare(root->data, node_data);

    if (compare_value == 0)
    {
        node_data->data = root->data;
        return 1;
    } else if (compare_value < 0)
    {
        return bst_search(root->left, node_data);
    } else
    {
        return bst_search(root->right, node_data);
    }
    
    return 0;
}

int bst_remove(struct node *root, struct node_data *node_data)
{
    if (root == NULL)
    {
        return 0;
    }

    int compare_value = node_compare(root->data, node_data);

    if (compare_value == 0)
    {
        struct node *root_left = root->left;
        struct node *root_right = root->right;

        if (root_left != NULL && root_right != NULL)
        {
        } else if (root-> right != NULL)
        {
        } else
        {
        }
        node_data->data = root->data;
        return 1;
    } else if (compare_value < 0)
    {
        return bst_search(root->left, node_data);
    } else
    {
        return bst_search(root->right, node_data);
    }
    
    return 0;
}

int bst_traverse(struct node *root, void (*on_item)(struct node_data *, void *), void *args);
#endif /*BINARY_TREE_H*/
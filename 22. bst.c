#include <stdio.h>
#include <stdlib.h>

struct bst
{
    int data;
    struct bst *left, *right;
};

struct bst *createBst(int data)
{
    struct bst *root = (struct bst *)malloc(sizeof(struct bst));

    root->data = data;
    root->left = NULL;
    root->right = NULL;
}

struct bst *insert(struct bst *tree, int data)
{

    if (tree == NULL)
    {
        struct bst *temp = createBst(data);
        return temp;
    }

    if (data > tree->data)
    {
        tree->right = insert(tree->right, data);
    }
    else
    {
        tree->left = insert(tree->left, data);
    }

    return tree;
}

struct bst *search(struct bst *tree, int key)
{
    if (tree != NULL)
    {

        if (tree->data == key)
        {
            return tree;
        }
        else if (key > tree->data)
        {
            return search(tree->right, key);
        }
        else
        {
            return search(tree->left, key);
        }
    }
}

void bstInOrder(struct bst *tree)
{
    if (tree != NULL)
    {
        bstInOrder(tree->left);
        printf("%i\n", tree->data);
        bstInOrder(tree->right);
    }
}

struct bst *getParent(struct bst *tree, struct bst *node)
{

    if (tree != NULL)
    {
        if (tree->left == node || tree->right == node)
        {
            return tree;
        }
        else
        {
            struct bst *temp = getParent(tree->left, node);
            if (temp != NULL)
            {
                return temp;
            }
            else
            {
                return getParent(tree->right, node);
            }
        }
    }
}

struct bst *min(struct bst *tree)
{
    if (tree->left == NULL)
    {
        return tree;
    }

    return tree->left;
}

void delete (struct bst *tree, struct bst *node)
{

    struct bst *parent = getParent(tree, node);

    // delete this node
    if (node->left == NULL && node->right == NULL)
    {
        if (parent != NULL)
        {
            if (parent->left == node)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }

        free(node);
    }

    else if (node->left == NULL && node->right != NULL)
    {
        if (parent != NULL)
        {

            parent->right = node->right;
            free(node);
        }
    }

    else if (node->left != NULL && node->right == NULL)
    {
        if (parent != NULL)
        {

            parent->left = NULL;
            free(node);
        }
    }

    // 2 nodes
    else
    {
        struct bst *rightMin = min(node->right);

        struct bst *parentMin = getParent(tree, rightMin);

        if (rightMin->right != NULL)
        {
            parentMin->left = rightMin->right;
        }

        rightMin->left = node->left;
        rightMin->right = node->right;

        struct bst *temp = node;

        node = rightMin;
        free(temp);

        if (parent != NULL)
        {
            if (parent->left == temp)
            {
                parent->left = node;
            }
            else
            {
                parent->right = node;
            }
        }
    }
}

int main()
{

    struct bst *tree = NULL;

    printf("Welcome to the Binary Search Tree\n");

    int choice, n;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number to insert: ");
            scanf("%d", &n);
            tree = insert(tree, n);
            break;
        case 2:
            printf("Enter the number to search: ");
            scanf("%d", &n);
            struct bst *temp = search(tree, n);
            if (temp != NULL)
            {
                printf("%d found\n", n);
            }
            else
            {
                printf("%d not found\n", n);
            }
            break;
        case 3:
            bstInOrder(tree);
            break;
        case 4:
            printf("Enter the number to delete: ");
            scanf("%d", &n);
            delete (tree, search(tree, n));
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
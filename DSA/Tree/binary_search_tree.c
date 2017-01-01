#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct BINARY_SEARCH_TREE
{
  int data;
  struct BINARY_SEARCH_TREE *left;
  struct BINARY_SEARCH_TREE *right;
} Node;

/**
 * Creates a new node.
 *
 * @internal
 *
 * @param int data Data for node
 *
 * @return Node
 */
Node *get_Node(int data)
{
    Node *temp = (Node *) malloc(sizeof(Node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

/**
 * Insert new node to a tree.
 *
 * @param Node tree Search tree
 * @param int data Data to insert
 *
 * @return void
 */
void insert(Node **tree, int data)
{
    if (!*tree) {
        *tree = get_Node(data);

        return;
    }

    if (data < (*tree)->data) {
        //left subtree
        insert(&(*tree)->left, data);
    } else {
        //right subtree
        insert(&(*tree)->right, data);
    }
}

/**
 * Prints data using inorder traversal of a tree.
 *
 * @param Node tree Search tree
 *
 * @return void
 */
void inorder(Node **tree)
{
    if (!*tree) {
        return;
    }

    inorder(&(*tree)->left);
    printf("%d ", (*tree)->data);
    inorder(&(*tree)->right);
}

/**
 * Prints data using preorder traversal of a tree.
 *
 * @param Node tree Search tree
 *
 * @return void
 */
void preorder(Node **n)
{
    if (!*n) {
        return;
    }

    printf("%d ", (*n)->data);
    preorder(&(*n)->left);
    preorder(&(*n)->right);
}

/**
 * Prints data using postorder traversal of a tree.
 *
 * @param Node tree Search tree
 *
 * @return void
 */
void postorder(Node **n)
{
    if (!*n) {
        return;
    }

    postorder(&(*n)->left);
    postorder(&(*n)->right);
    printf("%d ", (*n)->data);
}

/**
 * Finds a node with given data from tree.
 *
 * @param Node tree Search tree
 * @param int data Data to search
 *
 * @return Node|Null
 */
Node *find(Node **tree, int data)
{
    static Node *item = NULL;

    if (!*tree) {
        return NULL;
    }

    if (!item) {
        item = (Node *) malloc(sizeof(Node));
    }

    if (data == (*tree)->data) {
        item = *tree;
    } else if (data < (*tree)->data) {
        find(&((*tree)->left), data);
    } else {
        find(&((*tree)->right), data);
    }

    return item;
}

/**
 * Find node with minimum data from given tree.
 *
 * @param Node root Root of a tree
 *
 * @return Node
 */
Node *find_minimum(Node *root)
{
    Node *subtree = root;

    while (subtree->left) {
        subtree = subtree->left;
    }

    return subtree;
}

/**
 * Find node with maximum data from given tree.
 *
 * @param Node root Root of a tree
 *
 * @return Node
 */
Node *find_maximum(Node *root)
{
    Node *subtree = root;

    while (subtree->right) {
        subtree = subtree->right;
    }

    return subtree;
}

/**
 * Checks if a node is a leaf node.
 *
 * @param Node n Node to check
 *
 * @return bool
 */
bool is_leaf_node(Node *n)
{
    return n->left == NULL && n->right == NULL;
}

/**
 * Checks if a node is root node of a given tree.
 *
 * @param Node tree Search tree
 * @param Node n Node to check against root node
 *
 * @return bool
 */
bool is_root_node(Node **tree, Node *n)
{
    return (*tree) == n;
}

/**
 * Deletes a node with given data from tree
 * and returns a new root.
 *
 * @param Node root Root of a tree
 * @param int data Data to be deleted
 *
 * @return Node New node of a tree
 */
Node *delete(Node *root, int data)
{
    if (!root) {
        return root;
    }

    if (data < root->data) {
        //left
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        //right
        root->right = delete(root->right, data);
    } else {
        //equal
        if (is_leaf_node(root)) {
            free(root);
            root = NULL;

            return NULL;
        }

        if (root->left && root->right) {
            //has both child
            Node *min = find_minimum(root->right);

            root->data = min->data;

            root->right = delete(root->right, min->data);
        } else if (root->left) {
            //left child
            Node *temp = root->left;

            free(root->left);
            root->left = NULL;

            return temp;
        } else if (root->right) {
            //right child
            Node *temp = root->right;

            free(root->right);
            root->right = NULL;

            return temp;
        }
    }

    return root;
}

int main()
{
    Node *n = NULL;

    int total, input, del;

    printf("%s", "How many data? ");
    scanf("%d", &total);

    printf("Enter %d numbers\n", total);
    for (int i = 0; i < total; i++) {
        scanf("%d", &input);
        insert(&n, input);
    }

    printf("%s", "Inorder: ");
    inorder(&n);

    printf("%s", "\nPreorder: ");
    preorder(&n);

    printf("%s", "\nPostorder: ");
    postorder(&n);

    printf("%s", "\n\nDelete? ");
    scanf("%d", &del);

    Node *found = find(&n, del);
    assert(del == found->data);

    Node *new_root = delete(n, del);
    assert(new_root->data == n->data);

    printf("\n%s", "After Deletion: ");
    preorder(&n);

    free(n);

    return 0;
}

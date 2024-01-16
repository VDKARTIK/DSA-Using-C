#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *insert(TreeNode *root, int key) {
    if (root == NULL) {
        TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

TreeNode *findMin(TreeNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children, get the inorder successor (smallest in the right subtree)
        TreeNode *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

TreeNode *search(TreeNode *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

void inorderTraversal(TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void displayMenu() {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Display (Inorder Traversal)\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    TreeNode *root = NULL;
    int choice, key;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;

            case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL) {
                    printf("Key %d found in the tree.\n", key);
                } else {
                    printf("Key %d not found in the tree.\n", key);
                }
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

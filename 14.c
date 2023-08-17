#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new BST node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node *insert(struct Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to traverse the BST in in-order
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to traverse the BST in pre-order
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to traverse the BST in post-order
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a given element in the BST and report its parent
struct Node *searchAndReportParent(struct Node *root, int key, struct Node **parent) {
    if (root == NULL || root->data == key) {
        return root;
    }
    *parent = root;
    if (key < root->data) {
        return searchAndReportParent(root->left, key, parent);
    }
    return searchAndReportParent(root->right, key, parent);
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 15);
    root = insert(root, 24);
    root = insert(root, 14);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. In-order Traversal\n");
        printf("2. Pre-order Traversal\n");
        printf("3. Post-order Traversal\n");
        printf("4. Search Element and Report Parent\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 4: {
                int key;
                printf("Enter the element to search: ");
                scanf("%d", &key);

                struct Node *parent = NULL;
                struct Node *foundNode = searchAndReportParent(root, key, &parent);

                if (foundNode != NULL) {
                    printf("Element %d found.\n", key);
                    if (parent != NULL) {
                        printf("Parent: %d\n", parent->data);
                    } else {
                        printf("Element %d is the root node.\n", key);
                    }
                } else {
                    printf("Element %d not found.\n", key);
                }
                break;
            }
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    // TODO: Free memory by deallocating BST nodes

    return 0;
}

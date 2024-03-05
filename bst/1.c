#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void display(struct Node* root) {
    printf("Elements in the tree: ");
    inOrderTraversal(root);
    printf("\n");
}
struct node* search(struct node* root,int key)
{
    if(root==NULL)
    return NULL;
    if(root->data==key)
    return root;
    else if(key<root->data)
    search(root->left,key);
    else
    search(root->right,key);
}
struct node* findmin(struct node* root)
{
    if(root==NULL)
    return NULL;
    else if(root->left!-NULL)
    return findmin(root->left);
    
    return root;
}
struct node* delete(struct node* root,int val)
{
    if(root==NULL)
    return NULL;
    if(val>root->data)
    root->right=delete(root->right,val);
    else if(val<root->data)
    root->left=delete(root->left,val);
    else{
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL)
        {
            if(root->left==NULL)
            {
                struct node* temp=root->right;
                
            }
            else
            {
                struct node* temp=root->left;
            }
            free(root);
            return temp;
        }
        else
        {
            struct node* temp=findmin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert element\n");
        printf("2. Display elements\n");
        printf("3. In-order traversal\n");
        printf("4. Pre-order traversal\n");
        printf("5. Post-order traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                display(root);
                break;
            case 3:
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Pre-order traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Post-order traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

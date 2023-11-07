#include <stdio.h>
#include <stdlib.h>

#define T 3  // B-tree order

typedef struct Node {
    int keys[2 * T - 1];
    struct Node* children[2 * T];
    int num_keys;
    int is_leaf;
} Node;

Node* createNode() {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->num_keys = 0;
    new_node->is_leaf = 1;
    for (int i = 0; i < 2 * T; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

Node* search(Node* root, int key) {
    int i = 0;
    while (i < root->num_keys && key > root->keys[i]) {
        i++;
    }
    if (i < root->num_keys && key == root->keys[i]) {
        return root;
    } else if (root->is_leaf) {
        return NULL;
    } else {
        return search(root->children[i], key);
    }
}

void splitChild(Node* parent, int index, Node* child) {
    Node* new_child = createNode();
    Node* split_child = parent->children[index];
    parent->num_keys++;
    
    for (int i = parent->num_keys - 1; i > index; i--) {
        parent->keys[i] = parent->keys[i - 1];
        parent->children[i + 1] = parent->children[i];
    }

    parent->keys[index] = split_child->keys[T - 1];
    parent->children[index + 1] = new_child;
    
    for (int i = 0; i < T - 1; i++) {
        new_child->keys[i] = split_child->keys[i + T];
    }
    
    if (!split_child->is_leaf) {
        for (int i = 0; i < T; i++) {
            new_child->children[i] = split_child->children[i + T];
        }
    }
    
    split_child->num_keys = T - 1;
    new_child->num_keys = T - 1;
    
    for (int i = parent->num_keys; i < 2 * T - 1; i++) {
        parent->keys[i] = 0;
    }
}

void insert(Node** root, int key) {
    Node* r = *root;
    if (r->num_keys == 2 * T - 1) {
        Node* new_root = createNode();
        new_root->is_leaf = 0;
        new_root->children[0] = r;
        *root = new_root;
        splitChild(new_root, 0, r);
        insertNonFull(new_root, key);
    } else {
        insertNonFull(r, key);
    }
}

void insertNonFull(Node* x, int key) {
    int i = x->num_keys - 1;
    if (x->is_leaf) {
        while (i >= 0 && key < x->keys[i]) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }
        x->keys[i + 1] = key;
        x->num_keys++;
    } else {
        while (i >= 0 && key < x->keys[i]) {
            i--;
        }
        i++;
        if (x->children[i]->num_keys == 2 * T - 1) {
            splitChild(x, i, x->children[i]);
            if (key > x->keys[i]) {
                i++;
            }
        }
        insertNonFull(x->children[i], key);
    }
}

void printTree(Node* root, int level) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->num_keys; i++) {
            printTree(root->children[i], level + 1);
            printf("%d ", root->keys[i]);
        }
        printTree(root->children[i], level + 1);
    }
}

int main() {
    Node* root = createNode();
    int num_keys;
    
    printf("Enter the number of keys to insert: ");
    scanf("%d", &num_keys);
    
    printf("Enter the keys to insert:\n");
    for (int i = 0; i < num_keys; i++) {
        int key;
        scanf("%d", &key);
        insert(&root, key);
    }

    int search_key;
    printf("Enter a key to search: ");
    scanf("%d", &search_key);
    Node* result = search(root, search_key);

    if (result != NULL) {
        printf("Key %d found in the B-tree.\n", search_key);
    } else {
        printf("Key %d not found in the B-tree.\n", search_key);
    }

    printf("B-tree structure:\n");
    printTree(root, 0);
    printf("\n");

    return 0;
}

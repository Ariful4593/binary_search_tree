#include<stdio.h>
typedef struct node Node;
struct node{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

Node *create_node(int item)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Error! Could not create new node.");
        exit(1);
    }

    new_node->data = item;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left_child(Node *node, Node *child)
{
    node->left = child;
    if(child != NULL){
        child->parent = node;
    }
}

void add_right_child(Node *node, Node *child)
{
    node->right = child;
    if(child != NULL){
        child->parent = node;
    }
}

Node *bst_insert(Node *root, Node *node)
{
    Node *parent_node, *current_node;
    if(root == NULL){
        root = node;
        return root;
    }
    parent_node = NULL;
    current_node = root;

    while(current_node != NULL){
        parent_node = current_node;
        if(node->data < current_node->data){
            current_node = current_node->left;
        }
        else
        {
            current_node = current_node->right;
        }
    }

    if(node->data < parent_node->data){
        add_left_child(parent_node, node);
    }
    else{
        add_right_child(parent_node, node);
    }

    return root;

}

Node *create_bst()
{
    Node *root, *node;
    int i;
    int ara[] = {5,17,3,7,12,19,1,4};
    root = create_node(10);
    for(i = 0; i < 8; i++){
        node = create_node(ara[i]);
        root = bst_insert(root, node);
    }
    return root;
}

void in_order(Node *node)
{
    if(node->left != NULL){
        in_order(node->left);
    }

    printf("%d ", node->data);

    if(node->right != NULL){
        in_order(node->right);
    }
}

Node *bst_largest(Node *root)
{
    Node *node = root;
    while(node->right != NULL){
        node = node->right;
    }
    return node;
}
int main()
{
    Node *root = create_bst();

    Node *largest_value;

    in_order(root);

    largest_value = bst_largest(root);

    printf("\n");

    printf("Largest value is %d\n", largest_value->data);

    return 0;
}

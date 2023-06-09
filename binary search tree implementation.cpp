#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
//bt function is used to create the 
//nodes of binary search tree
node *bt(node *root, int val)
{
    if (root == NULL)
    {
//if the next node is null then the new 
//node is created and value is inserted
        return new node(val);
    }
    if (val < root->data)
    {
//if value is smaller the value is inserted
//in the left node of the root node
        root->left = bt(root->left, val);
    }
    else
    {
//if value is larger the value is inserted
//in the right node of the root node        
        root->right = bt(root->right, val);
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << "->";
    inorder(root->right);
}
node *insertion()
{  
    node *root = nullptr;
    int value;
    cout << "enter a value : ";
    cin >> value;
//the root is passed to the bt function along with value
//to make the tree
    root = bt(root, value);
    char choice;
    do
    {
//asking for user choice to continue adding or not
        cout << "do u want to enter another node (y/n) : ";
        cin >> choice;
        if (choice == 'y')
        {
            cout << "enter a value : ";
            cin >> value;
            root = bt(root, value);
        }
    } while (choice == 'y');
    return root;
}
int main()
{
    node *root = insertion();
    cout << "\nThe inorder binary search tree traversal is : \n";
    inorder(root);
    return 0;
}
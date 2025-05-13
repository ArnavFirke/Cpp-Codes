#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

// AVLTree class
class AVLTree
{
private:
    Node *root;

public:
    AVLTree() : root(nullptr) {}

    // Function to calculate the height of a node
    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Function to find the maximum of two integers
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    // Function to create a new node
    Node *newNode(int key)
    {
        return new Node(key);
    }

    // Function to perform a right rotation
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    // Function to perform a left rotation
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    // Function to get the balance factor of a node
    int getBalance(Node *node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    // Function to insert a node in the tree
    Node *insert(Node *node, int key)
    {
        // Perform standard BST insertion
        if (node == nullptr)
            return newNode(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        // Update the height of the ancestor node
        node->height = 1 + max(height(node->left), height(node->right));

        // Get the balance factor of the node
        int balance = getBalance(node);

        // If the node is unbalanced, there are four cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the unchanged node pointer
        return node;
    }

    // Function to find the minimum value node in a tree
    Node *minValueNode(Node *node)
    {
        Node *current = node;

        // Find the leftmost leaf node
        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    // Function to delete a node from the tree
    Node *deleteNode(Node *root, int key)
    {
        // Perform standard BST delete
        if (root == nullptr)
            return root;

        // If the key to be deleted is smaller than the root's key,
        // then it lies in the left subtree
        if (key < root->key)
            root->left = deleteNode(root->left, key);

        // If the key to be deleted is greater than the root's key,
        // then it lies in the right subtree
        else if (key > root->key)
            root->right = deleteNode(root->right, key);

        // If the key to be deleted is equal to the root's key, then this is the node to be deleted
        else
        {
            // Node with only one child or no child
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                Node *temp = root->left ? root->left : root->right;

                // No child case
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else               // One child case
                    *root = *temp; // Copy the contents of the non-empty child

                delete temp;
            }
            else
            {
                // Node with two children
                Node *temp = minValueNode(root->right);           // Get the inorder successor
                root->key = temp->key;                            // Copy the inorder successor's key to this node
                root->right = deleteNode(root->right, temp->key); // Delete the inorder successor
            }
        }

        // If the tree had only one node, then return
        if (root == nullptr)
            return root;

        // Update the height of the current node
        root->height = 1 + max(height(root->left), height(root->right));

        // Get the balance factor of the node
        int balance = getBalance(root);

        // If the node is unbalanced, there are four cases

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        // Return the unchanged node pointer
        return root;
    }

    // Function to update the value of a node
    Node *update(Node *root, int oldVal, int newVal)
    {
        // Delete the node with the old value
        root = deleteNode(root, oldVal);

        // Insert a new node with the new value
        root = insert(root, newVal);

        // Return the root of the updated tree
        return root;
    }

    // Function to display the tree in inorder traversal
    void inorder(Node *root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    // Function to interact with the AVL tree
    void interact()
    {
        int choice, n;
        int key, oldVal, newVal;

        do
        {
            cout << "\nAVL Tree Menu" << endl;
            cout << "1. Insert" << endl;
            cout << "2. Delete" << endl;
            cout << "3. Update" << endl;
            cout << "4. Display" << endl;
            cout << "5. Exit" << endl;
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter the no. of elements: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    cout << "Enter the key to insert: ";
                    cin >> key;
                    root = insert(root, key);
                }
                break;
            case 2:
                cout << "Enter the key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                cout << "Node deleted successfully!" << endl;
                break;
            case 3:
                cout << "Enter the old value: ";
                cin >> oldVal;
                cout << "Enter the new value: ";
                cin >> newVal;
                root = update(root, oldVal, newVal);
                cout << "Node updated successfully!" << endl;
                break;
            case 4:
                cout << "Inorder traversal of the AVL tree: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }

            cout << endl;
        } while (choice != 5);
    }
};

// Driver function
int main()
{
    AVLTree avlTree;
    avlTree.interact();

    return 0;
}

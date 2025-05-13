#include <iostream>
#include <string>
using namespace std;

class Binary_Tree
{
private:
    string meaning;
    int word;
    Binary_Tree *left, *right;

public:
    Binary_Tree(int wd = 0, string mn = "", Binary_Tree *lt = nullptr, Binary_Tree *rt = nullptr)
    {
        word = wd;
        meaning = mn;
        left = lt;
        right = rt;
    }
    Binary_Tree *insert(Binary_Tree *, int, string);
    void inorder(Binary_Tree *);
    void preorder(Binary_Tree *);
    void postorder(Binary_Tree *);
    void search(Binary_Tree *, int);
    void update(Binary_Tree *, int);
    void Delete(Binary_Tree *, int);
};
Binary_Tree *Binary_Tree::insert(Binary_Tree *root, int val, string mean)
{
    if (!root)
    {
        return new Binary_Tree(val, mean);
    }
    else
    {
        Binary_Tree *temp = new Binary_Tree(val, mean);
        Binary_Tree *nptr = root, *parent = nullptr;
        while (1)
        {
            parent = nptr;
            if (val < parent->word)
            {
                nptr = nptr->left;
                if (!nptr)
                {
                    parent->left = temp;
                    return root;
                }
            }
            else
            {
                parent = nptr;
                if (val > parent->word)
                {
                    nptr = nptr->right;
                    if (!nptr)
                    {
                        parent->right = temp;
                        return root;
                    }
                }
            }
        }
    }
}
void Binary_Tree::search(Binary_Tree *root, int val)
{
    Binary_Tree *nptr = root, *parent = nullptr;
    while (1)
    {
        parent = nptr;
        if (val < parent->word)
        {
            nptr = nptr->left;
            if (!nptr)
            {
                cout << "Word not found" << endl;
                return;
            }
            if (nptr->word == val)
            {
                cout << "Found" << endl;
                cout << nptr->word << ": " << nptr->meaning << endl;
                break;
            }
        }
        else
        {
            parent = nptr;
            if (val > parent->word)
            {
                nptr = nptr->right;
                if (!nptr)
                {
                    cout << "Word not found" << endl;
                    return;
                }
                if (nptr->word == val)
                {
                    cout << "Found" << endl;
                    cout << nptr->word << ": " << nptr->meaning << endl;
                    break;
                }
            }
        }
    }
    return;
}

void Binary_Tree::update(Binary_Tree *root, int val)
{
    Binary_Tree *nptr = root, *parent = nullptr;
    while (1)
    {
        parent = nptr;
        if (val < parent->word)
        {
            nptr = nptr->left;
            if (!nptr)
            {
                cout << "Word not found" << endl;
                return;
            }
            if (nptr->word == val)
            {
                cout << "Enter the new meaning: ";
                cin >> nptr->meaning;
                break;
            }
        }
        else
        {
            parent = nptr;
            if (val > parent->word)
            {
                nptr = nptr->right;
                if (!nptr)
                {
                    cout << "Word not found" << endl;
                    return;
                }
                if (nptr->word == val)
                {
                    cout << "Enter the new meaning: ";
                    cin >> nptr->meaning;
                    break;
                }
            }
        }
    }
}
void Binary_Tree::Delete(Binary_Tree *root, int val)
{
    bool flag = false;
    Binary_Tree *nptr = root, *parent = nullptr;
    while (1)
    {
        parent = nptr;
        if (val < parent->word)
        {
            nptr = nptr->left;
            if (!nptr)
            {
                cout << "Word not found" << endl;
                return;
            }
            if (nptr->word == val)
            {
                Binary_Tree *temp = nptr;
                free(temp);
                break;
            }
        }
        else
        {
            parent = nptr;
            if (val > parent->word)
            {
                nptr = nptr->right;
                if (!nptr)
                {
                    cout << "Word not found" << endl;
                    return;
                }
                if (nptr->word == val)
                {
                    Binary_Tree *temp = nptr;
                    delete temp;
                    break;
                }
            }
        }
    }
}
void Binary_Tree::inorder(Binary_Tree *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout << root->word << ": " << root->meaning << endl;
        inorder(root->right);
    }
}
void Binary_Tree::preorder(Binary_Tree *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        cout << root->word << ": " << root->meaning << endl;
        inorder(root->left);
        inorder(root->right);
    }
}
void Binary_Tree::postorder(Binary_Tree *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        inorder(root->left);
        inorder(root->right);
        cout << root->word << ": " << root->meaning << endl;
    }
}
int main()
{
    Binary_Tree bst, *root = nullptr;
    int n, choice, data;
    string mem;
    cout << "1.create BST" << endl;
    cout << "2.Insert in BST" << endl;
    cout << "3.Delete from BST" << endl;
    cout << "4.update BST" << endl;
    cout << "5.Search BST" << endl;
    cout << "6.display BST" << endl;
    cout << "7.Exit" << endl;
    while (1)
    {
        cout << "\nEnter the operation: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number of words: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nEnter the data :";
                cin >> data;
                cout << "Enter the data meaning :";
                cin >> mem;
                if (!root)
                    root = bst.insert(root, data, mem);
                else
                    bst.insert(root, data, mem);
            }
            break;
        case 2:
            cout << "\nEnter the data :";
            cin >> data;
            cout << "Enter the data meaning :";
            cin >> mem;
            if (!root)
                root = bst.insert(root, data, mem);
            else
                bst.insert(root, data, mem);
            break;
        case 3:
            cout << "\nEnter the word to be deleted: ";
            cin >> data;
            bst.Delete(root, data);
            break;
        case 4:
            cout << "\nEnter the word which meaning is to be updated: ";
            cin >> data;
            bst.update(root, data);
            break;
        case 5:
            cout << "\nEnter the word to search: ";
            cin >> data;
            bst.search(root, data);
            break;
        case 6:
            cout << "a.Inorder" << endl;
            cout << "b.preorder" << endl;
            cout << "c.postorder" << endl;
            cout << "\nEnter the char: ";
            char ch;
            cin >> ch;
            switch (ch)
            {
            case 'a':
                bst.inorder(root);
                break;
            case 'b':
                bst.preorder(root);
                break;
            case 'c':
                bst.postorder(root);
                break;

            default:
                cout << "Enter correct char" << endl;
                break;
            }
            break;
        case 7:
            cout << "Exited successfully" << endl;
            exit(1);
        default:
            cout << "Enter the correct operation!!" << endl;
        }
    }
    return 0;
}
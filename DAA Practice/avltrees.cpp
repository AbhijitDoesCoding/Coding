#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
#define nline cout << '\n';

class node
{
public:
    string word;
    string meaning;
    node *left;
    node *right;
    friend class AVLTree;
    node(string word, string meaning)
    {
        this->word = word;
        this->meaning = meaning;
        this->left = NULL;
        this->right = NULL;
    }
};

class AVLTree
{
public:
    node *root;
    AVLTree()
    {
        root = NULL;
    }
    ll height(node *);
    ll diff(node *);
    node *rr_rotation(node *);
    node *ll_rotation(node *);
    node *lr_rotation(node *);
    node *rl_rotation(node *);
    node *update(node *, string, string);
    node *balance(node *);
    void insert();
    node *insert(node *, node *);
    void display(node *, int);
    node *search(node *, string);
    void inorder(node *);
};

node *search(node *root, string word)
{
    if (root == NULL || root->word == word)
    {
        return root;
    }
    if (root->word < word)
    {
        return search(root->right, word);
    }
    return search(root->left, word);
}

node *AVLTree::ll_rotation(node *parent)
{
    node *temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

node *AVLTree::rr_rotation(node *parent)
{
    node *temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

node *AVLTree::lr_rotation(node *parent)
{
    node *temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

node *AVLTree::rl_rotation(node *parent)
{
    node *temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

ll AVLTree::diff(node *temp)
{
    ll l_height = height(temp->left);
    ll r_height = height(temp->right);
    ll b_factor = l_height - r_height;
    return b_factor;
}

ll AVLTree::height(node *temp)
{
    ll h = 0;
    if (temp != NULL)
    {
        ll l_height = height(temp->left);
        ll r_height = height(temp->right);
        ll max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

node *AVLTree::balance(node *temp)
{
    ll bal_factor = diff(temp);
    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
        {
            temp = ll_rotation(temp);
        }
        else
        {
            temp = lr_rotation(temp);
        }
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
        {
            temp = rl_rotation(temp);
        }
        else
        {
            temp = rr_rotation(temp);
        }
    }
    return temp;
}

void AVLTree::insert()
{
    char ch = 'y';
    do
    {
        string word, meaning;
        cout << "Enter word of the node to be inserted:" << endl;
        cin >> word;
        cout << "Enter meaning of the word:" << endl;
        cin.ignore();
        getline(cin, meaning);
        node *newNode = new node(word, meaning);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            root = insert(root, newNode);
        }
        cout << "Do you want to insert another node? (y/n)" << endl;
        cin >> ch;
        if (ch != 'y')
        {
            break;
        }
    } while (1);
}

node *AVLTree::insert(node *root, node *temp)
{
    if (root == NULL)
    {
        root = temp;
    }
    else if (temp->word < root->word)
    {
        root->left = insert(root->left, temp);
        root = balance(root);
    }
    else if (temp->word >= root->word)
    {
        root->right = insert(root->right, temp);
        root = balance(root);
    }
    return root;
}

void AVLTree::display(node *ptr, int level)
{
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        cout << endl;
        if (ptr == root)
        {
            cout << "Root -> ";
        }
        for (int i = 0; i < level && ptr != root; i++)
        {
            cout << "        ";
        }
        cout << ptr->word << ": " << ptr->meaning;
        display(ptr->left, level + 1);
    }
}

void AVLTree::inorder(node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    inorder(tree->left);
    cout << tree->word << ": " << tree->meaning << "  ";
    inorder(tree->right);
}

node *AVLTree::update(node *root, string old_word, string new_meaning)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->word == old_word)
    {
        root->meaning = new_meaning;
    }
    else if (old_word < root->word)
    {
        root->left = update(root->left, old_word, new_meaning);
    }
    else
    {
        root->right = update(root->right, old_word, new_meaning);
    }
    root = balance(root);
    return root;
}

int main()
{
    AVLTree avl;
    int choice;
    do
    {
        nline;
        cout << "AVL Tree Operations" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Display AVL Tree" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "4. Update a node" << endl;
        cout << "5. Search a node" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            avl.insert();
            break;
        case 2:
            if (avl.root == NULL)
            {
                cout << "Tree is empty" << endl;
            }
            else
            {
                avl.display(avl.root, 1);
            }
            break;
        case 3:
            if (avl.root == NULL)
            {
                cout << "Tree is empty" << endl;
            }
            else
            {
                cout << "Inorder Traversal:" << endl;
                avl.inorder(avl.root);
                cout << endl;
            }
            break;
        case 4:
            if (avl.root == NULL)
            {
                cout << "Tree is empty" << endl;
            }
            else
            {
                string old_word, new_word;
                cout << "Enter the word of the node to be updated:" << endl;
                cin >> old_word;

                cout << "Enter the new meaning:" << endl;
                string new_meaning;
                cin >> new_meaning;
                cin.ignore();
                avl.root = avl.update(avl.root, old_word, new_meaning);
            }

            break;
        case 5:
            if (avl.root == NULL)
            {
                cout << "Tree is empty" << endl;
            }
            else
            {
                string word;
                cout << "Enter the word to be searched:" << endl;
                cin >> word;
                node *result = search(avl.root, word);
                if (result == NULL)
                {
                    cout << "Node not found" << endl;
                }
                else
                {
                    cout << "Node found: " << result->word << ": " << result->meaning << endl;
                }
            }
            break;
        case 6:

            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 6);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    struct TrieNode *child[26];

    bool endOfWord;
};

TrieNode *newNode()
{
    struct TrieNode *temp =  new TrieNode;

    temp->endOfWord = false;

    for (int i = 0; i < 26; i++)
        temp->child[i] = NULL;

    return temp;
}

bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < 26; i++)
        if (root->child[i])
            return false;
    return true;
}

void insert(TrieNode *root, string key)
{
    TrieNode *temp = root;

    for (int i = 0; i < key.length(); i++)
    {
        int j = key[i] - 'a';
        if (!temp->child[j])
            temp->child[j] = newNode();

        temp = temp->child[j];
    }

    temp->endOfWord = true;
}


TrieNode *erase(TrieNode* root, string key, int depth = 0)
{
    if (!root)
        return NULL;

    if (depth == key.size()) {

        if (root->endOfWord)
            root->endOfWord = false;

        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }

        return root;
    }

    int j = key[depth] - 'a';
    root->child[j] =
          erase(root->child[j], key, depth + 1);

    if (isEmpty(root) && root->endOfWord == false) {
        delete (root);
        root = NULL;
    }

    return root;
}

bool search(TrieNode *root, string key)
{
    TrieNode *temp = root;

    for (int i = 0; i < key.length(); i++)
    {
        int j = key[i] - 'a';
        if (!temp->child[j])
            return false;

        temp = temp->child[j];
    }

    return (temp != NULL && temp->endOfWord);
}

int main()
{
    struct TrieNode *root = newNode();

    int c;
    string key;
    do{
        cout<<"\nEnter choice:  1->insert  2->search  3->delete  0->Exit\n";
        cin>>c;
        switch(c){
            case 1: cout << "Enter string to be inserted : \n";
                    cin >> key;
                    insert(root,key);
                    break;

            case 2: cout << "Enter string to be searched : \n";
                    cin >> key;
                    search(root, key)? cout << "Yes\n" : cout << "No\n";
                    break;

            case 3: cout << "Enter string to be deleted : \n";
                    cin >> key;
                    erase(root,key);
                    break;

            case 0: break;

            default: cout<<"Invalid Choice";
        }
    }while(c != 0);

    return 0;
}

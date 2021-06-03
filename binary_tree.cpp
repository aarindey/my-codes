#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template<typename t>
class BTNode{
public:
    t data;
    BTNode* left;
    BTNode* right;
    BTNode(t data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }};
    void printTree(BTNode* root)
    {
        if(root==NULL)
            return;
        cout<<root->data<<": ";
        if(root->left)
        {
            cout<<"L"<<left->data;
        }
        if(root->right)
        {
            cout<<"R"<<right->data;
        }
        cout<<endl;
    printTree(root->left);
    printTree(root->right);

    }
int main()
{
    BTNode<int>* root=new BTNode<int>(1);
    BTNode<int>* n1=new BTNode<int>(2);
    BTNode<int>* n2=new BTNode<int>(3);
    root->left=n1;
    root->right=n2;
   printTree(root);
    return 0;
}

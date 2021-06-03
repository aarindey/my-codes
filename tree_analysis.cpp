#include<bits/stdc++.h>
#include<queue>
using namespace std;

template<typename t>
class treeNode
{
	public:
    t data;
vector<treeNode<t>*> children;
treeNode(t data)
{
this->data=data;
}
~treeNode()
{
    for(int i=0;i<root->children.size();i++)
    {
        delete root->children[i];
    }
}
};
void PrintAtLevelK(treeNode<int>* root,int k)
{
if(root==NULL)
{
    return;
}
if(k==0)
{
    cout<<root->data<<endl;
    return;
}
for(int i=0;i<root->children.size();i++)
{
    PrintAtLevelK(root->children[i],k-1);

}
}
void preOrder(treeNode<int>* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        preOrder(root->children[i]);
    }
}
void postOrder(treeNode<int>* root)
{
    if(root==NULL)
        return;

    for(int i=0;i<root->children.size();i++)
    {
        preOrder(root->children[i]);
    }
    cout<<root->data<<endl;
}
void deleteTree(treeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}
void PrintAtLevelKAnotherWay(treeNode<int>* root,int k,int c=0)
{
    if(root=NULL)
        return;
    if(k==c)
    {
        cout<<root->data<<"  ";
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        PrintAtLevelKAnotherWay(root->children[i],k,c+1);
    }
}

int CountLeafNode(treeNode<int>* root)
{int ans=0;
    if(root->children.size()==0)
        return 1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=CountLeafNode(root->children[i]);
    }
    return ans;
}
void CountLeafNodeOtherWay(treeNode<int>* root,int &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->children.size()==0)
    {
        ans++;
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        CountLeafNodeOtherWay(root->children[i],ans);
    }
}



void printNode(treeNode<int>* root)
{
    if(root==NULL)
    return;
 cout<<root->data<<":";
 for(int i=0;i<root->children.size();i++)
 {
     cout<<root->children[i]->data<<",";
 }
 cout<<endl;
 for(int i=0;i<root->children.size();i++)
 {
     printNode(root->children[i]);
 }
}
treeNode<int>* takeInputLevelWise()
{int rootData;
cout<<"Enter the data of the root:"<<endl;
cin>>rootData;
treeNode<int>* root=new treeNode<int>(rootData);
queue<treeNode<int>*> q;
q.push(root);
while(!q.empty())
{

    treeNode<int>* f=q.front();
    q.pop();

    int n;
    cout<<"enter the number of children node "<<f->data<<" has "<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    { int childData;
    cout<<"Enter the data of the child "<<i<<" of "<<f->data<<endl;
    cin>>childData;
        treeNode<int>* child=new treeNode<int>(childData);
        q.push(child);
        f->children.push_back(child);
    }
    }
    return root;
}
void PrintTreeLevelWise(treeNode<int>* root)
{
queue<treeNode<int>*> q;
q.push(root);
while(!q.empty())
{
  treeNode<int>* f=q.front();
  q.pop();
  cout<<f->data<<" :";
  for(int i=0;i<f->children.size();i++)
  {
    cout<<f->children[i]->data<<",";
  }
  cout<<endl;
    for(int i=0;i<f->children.size();i++)
  {
    q.push(f->children[i]);
  }
}}
int height(treeNode<int>* root){
int m=0;
for(int i=0;i<root->children.size();i++)
{
m=max(m,height(root->children[i]));
}
return m+1;
}



int countNodes(treeNode<int>* root)
{
    if(root==NULL)
    return 0;
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=countNodes(root->children[i]);
    }
    return ans;
}


treeNode<int>* inputNode()
{
int nodeData;
cout<<"Enter data "<<endl;
cin>>nodeData;
treeNode<int>* root=new treeNode<int>(nodeData);
int n;
cout<<"Enter the number of children:"<<endl;
cin>>n;
for(int i=1;i<=n;i++)
{
    treeNode<int>* child=inputNode();
    root->children.push_back(child);

}
return root;
}
int main()
{
    treeNode<int>* root=takeInputLevelWise();
    PrintTreeLevelWise(root);
    cout<<"Height     ="<<height(root)<<endl;
    PrintAtLevelK(root,2);
    cout<<endl;
    PrintAtLevelKAnotherWay(root,2);
    int TotalLeafNodes=0;
    cout<<"number of Leaf nodes="<<CountLeafNode(root)<<endl;
    CountLeafNodeOtherWay(root,TotalLeafNodes);
      cout<<"number of Leaf nodes="<<TotalLeafNodes<<endl;
    return 0;
}


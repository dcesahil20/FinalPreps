#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

template <class T>
class TreeNode{
    public:
        T data;
        vector<TreeNode*> children;

        TreeNode(T data){
            this->data = data;
        }
};


TreeNode<int>* takeInputLevelWise(){

    int rootData;
    cout << "Enter data for ROOT " << endl;
    cin >> rootData;

    TreeNode<int>* rootNode = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> q;
    q.push(rootNode);

    while (q.size()!=0)
    {
        TreeNode<int>* frontNode = q.front();
        q.pop();

        cout << "Enter number of children for " << frontNode->data << endl;
        int frontNodeChildCount;
        cin >> frontNodeChildCount;

        for(int i=0; i<frontNodeChildCount; i++){
            
            cout << "Enter data of " << i << "th child of " << frontNode->data << endl;
            int childData;
            cin >> childData;

            TreeNode<int>* childNode = new TreeNode<int>(childData);
            
            frontNode->children.push_back(childNode);

            q.push(childNode);
        }
    }
    return rootNode;
}


TreeNode<int>* takeInputRecursive(){
    int rootData;
    cout << "Enter data for Node: ";
    cin >> rootData;

    TreeNode<int>* rootNode = new TreeNode<int>(rootData);

    cout << endl;

    int childNum;
    cout << "Enter no of children for this Node: ";
    cin >> childNum;

    cout << endl;

    for(int i=0; i<childNum; i++){
        TreeNode<int>* child = takeInputRecursive();
        rootNode->children.push_back(child);
    }

    return rootNode;
}

void printAtLevelK(TreeNode<int>* root, int k){
    
    if(k==0){
        cout << root->data << endl;
        return;
    }

    for(int i=0; i<root->children.size(); i++){
        printAtLevelK(root->children[i], k-1);
    }
}


void printTreeRecursive(TreeNode<int>* root){

    cout << root->data  << ": ";

    for(int i=0; i<root->children.size(); i++){
        cout << root->children[i]->data << ", ";
    }

    cout << endl; 

    for(int i=0; i<root->children.size(); i++){
        printTreeRecursive(root->children[i]);
    }
}

void printTreeLevelWise(TreeNode<int>* root){

    queue<TreeNode<int>*> q;

    q.push(root);

    while(q.size()!=0){
        TreeNode<int>* frontNode = q.front();
        cout << frontNode->data << ":";

        q.pop();

        for(int i=0; i<frontNode->children.size(); i++){
            q.push(frontNode->children[i]);
            cout << frontNode->children[i]->data << ", ";
        } 
        cout << endl;
    }
}

void printPreOrderTraversal(TreeNode<int>* root){
    
    cout << root->data << " ";

    for(int i=0; i<root->children.size(); i++){
        printPreOrderTraversal(root->children[i]);
    }

}


void printPostOrderTraversal(TreeNode<int>* root){

    for(int i=0; i<root->children.size(); i++){
        printPreOrderTraversal(root->children[i]);
    }    

    cout << root->data << " ";

}

int countNodes(TreeNode<int>* root){

    queue<TreeNode<int>*> q;

    q.push(root);

    int count = 0;

    while(q.size()!=0){
        TreeNode<int>* frontNode = q.front();
        count++;
        q.pop();
        for(int i=0; i<frontNode->children.size(); i++){
            q.push(frontNode->children[i]);
        } 
    }

    return count;
}

int countNodesRecursive(TreeNode<int>* root){
    int ans = 1;
    for(int i=0; i<root->children.size(); i++){
        ans+=countNodesRecursive(root->children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int>* root) {    
    int sum = root->data;
    
    for(int i=0; i<root->children.size(); i++){
        sum+=sumOfNodes(root->children[i]);
    }
    return sum;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // traverse every node , create new node for comparison
    //find max and store that node
    // return node

    TreeNode<int>* x = root;
    
    for(int i=0; i<root->children.size(); i++){
        
        TreeNode<int>* childX = maxDataNode(root->children[i]);
        x->data = max(x->data, childX->data);
    }
    
    return x;
}


TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    // Write your code here
    
    for(int i=0; i<root->children.size(); i++){
        TreeNode<int>* child = nextLargerElement(root->children[i], n);
        if(child->data > n){
            return root;
        }
    }
    
    return root;
}

int main(){
    
    TreeNode<int>* root = new TreeNode<int>(10);
    TreeNode<int>* n1 = new TreeNode<int>(20);
    TreeNode<int>* n2 = new TreeNode<int>(30);
    TreeNode<int>* n3 = new TreeNode<int>(40);

    root->children.push_back(n1);
    root->children.push_back(n2);
    root->children.push_back(n3);

    printTreeRecursive(root);

    // printTreeRecursive(takeInputRecursive());

    TreeNode<int>* funcNodeRoot = takeInputLevelWise();
    cout << "next larger elem: " << nextLargerElement(funcNodeRoot,21)->data << endl;

    //printTreeRecursive(takeInputLevelWise());

    printTreeLevelWise(funcNodeRoot);

    cout << "NODE count : " << countNodes(funcNodeRoot) << endl;

    cout << "NODE count recursive : " << countNodesRecursive(funcNodeRoot) << endl;  

    printAtLevelK(funcNodeRoot,3);
    printPreOrderTraversal(funcNodeRoot);
    cout << endl;
    printPostOrderTraversal(funcNodeRoot);

}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
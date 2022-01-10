#include <iostream>
#include <queue>
#include <map>
using namespace std;


template <typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode<T>* left;
        BinaryTreeNode<T>* right;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

template <typename T>
class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
};

void printBinaryTree(BinaryTreeNode<int>* root){

    if(root==NULL){
        return;
    }

    cout << root->data;

    if(root->left!=NULL){
        cout << ":L" << root->left->data;
    }
    if(root->right!=NULL){
        cout << "R" << root->right->data;
    }

    cout << endl;

    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

void printBinaryTreeLevelWise(BinaryTreeNode<int>* root){

    queue<BinaryTreeNode<int>*> q;

    q.push(root);

    while(q.size()!=0){
        BinaryTreeNode<int>* frontNode = q.front();
        q.pop();

        cout << frontNode->data;

        if(frontNode->left!=NULL){
            q.push(frontNode->left);
            cout << ":L"<< frontNode->left->data;
        }
        
        if(frontNode->right!=NULL){
            q.push(frontNode->right);
            cout << "R"<< frontNode->right->data;
        }

        cout << endl;

    }

}

BinaryTreeNode<int>* takeInputRecursive(){
    int rootData;
    cout << "Enter Root Data " << endl;
    cin >> rootData;

    if(rootData==-1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftNode = takeInputRecursive();
    BinaryTreeNode<int>* rightNode = takeInputRecursive();

    root->left = leftNode;
    root->right = rightNode;

    return root;
}

BinaryTreeNode<int>* takeInputLevelWise(){

    cout << "Enter data for Root Node " << endl;

    int rootData;
    cin >> rootData;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (q.size()!=0)
    {
        BinaryTreeNode<int>* frontNode = q.front();
        q.pop();
        
        cout << "Enter left child of " << frontNode->data << endl;
        int leftChildData;
        cin >> leftChildData;

        if(leftChildData!=-1){
            BinaryTreeNode<int>* leftChildNode = new BinaryTreeNode<int>(leftChildData);
            frontNode->left = leftChildNode;
            q.push(leftChildNode);
        }
        
        cout << "Enter right child of " << frontNode->data << endl;
        int rightChildData;
        cin >> rightChildData;

        if(rightChildData!=-1){
            BinaryTreeNode<int>* rightChildNode = new BinaryTreeNode<int>(rightChildData);
            frontNode->right = rightChildNode;
            q.push(rightChildNode);
        }

    }

    return root;
}

int countNodesBinaryTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    return 1 + countNodesBinaryTree(root->left) + countNodesBinaryTree(root->right);
}


bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    
    if(root==NULL){
        return false;
    }
    
    if(root->data==x){
        return true;
    }
    
    if(isNodePresent(root->left, x) || isNodePresent(root->right, x)){
        return true;
    }
    else{
        return false;
    }
    
}


int height(BinaryTreeNode<int>* root) {
    // Write our code here
    
    if(root==NULL){
        return 0;
    }
    
    int hl = 1 + height(root->left);
    int hr = 1 + height(root->right);
    
    return max(hl,hr);
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    
    if(root==NULL){
        return;
    }
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void printBinaryTreeInorder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }

    printBinaryTreeInorder(root->left);
    cout << root->data << " ";
    printBinaryTreeInorder(root->right);

}

BinaryTreeNode<int>* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> mp){
        
        if(preStart>preEnd || inStart > inEnd){
            return NULL;
        }
        
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[preStart]);
        
        int inRoot = mp[root->data];
        int numsLeft = inRoot - inStart;
        
        root->left = buildTreeHelper(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, mp);
        root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot+1, inEnd, mp);
        
        return root;
}
    
    
 BinaryTreeNode<int>* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> mp;
        
        for(int i=0; i<inorder.size()-1; i++){
            mp[inorder[i]] = i;
        }
        
        BinaryTreeNode<int>* root = buildTreeHelper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
}

pair<int,int> findHeightDiameter(BinaryTreeNode<int>* root){
    
    if(root==NULL){
        //first = heigth, second = diameter
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int,int> leftTree = findHeightDiameter(root->left);
    pair<int,int> rightTree = findHeightDiameter(root->right);

    int height = 1 + max(leftTree.first, rightTree.first); 
    int dia = max(leftTree.first + rightTree.first , max(leftTree.second, rightTree.second));

    pair<int,int> res;
    res.first = height;
    res.second = dia;
    
    return res;
}

int minNum = INT8_MAX;
int maxNum = INT8_MIN;

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL){
        pair<int,int> p;
        p.first = minNum;
        p.second = maxNum;
        return p;
    }
    
    pair<int,int> minMaxLeft = getMinAndMax(root->left);
    pair<int,int> minMaxRight = getMinAndMax(root->right);
    
    minNum = min(root->data, min(minMaxLeft.first, minMaxRight.first));
    maxNum = max(root->data, max(minMaxLeft.second, minMaxRight.second));
    
    pair<int,int> res;
    res.first = minNum;
    res.second = maxNum;
    
    return res;
}


vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    
    vector<Node<int>*> res;

    if(root==NULL){
        return res;
    }

    queue<BinaryTreeNode<int>*> q;    
    q.push(root);

    Node<int>* headPtr = NULL;
    Node<int>* tailPtr = NULL;

    int curLevel = 1;
    int nexLevel = 0;

    while(q.size()!=0){
        
        BinaryTreeNode<int>* fr = q.front();
        q.pop();

        Node<int>* ll = new Node<int>(fr->data);

        if(headPtr==NULL){
            headPtr = ll;
            tailPtr = ll;
        }
        else{
            tailPtr->next = ll;
            tailPtr = ll;
        }

        if(fr->left!=NULL){
            q.push(fr->left);
            nexLevel++;
        }
        if(fr->right!=NULL){
            q.push(fr->right);
            nexLevel++;
        }

        curLevel--;

        if(curLevel==0){
            res.push_back(headPtr);
            headPtr=NULL;
            tailPtr=NULL;
            curLevel=nexLevel;
            nexLevel=0;
        }
    }
    return res;
}

vector<int>* longestPathA(BinaryTreeNode<int>* root) {
	// Write your code here
    
     if (root == NULL) {
        vector<int>* temp;
        return temp;
    }
 
    // Recursive call on root->right
    vector<int>* rightvect
        = longestPathA(root->right);
 
    // Recursive call on root->left
    vector<int>* leftvect
        = longestPathA(root->left);
 
    // Compare the size of the two vectors
    // and insert curren`t node accordingly
    if (leftvect->size() > rightvect->size())
        leftvect->push_back(root->data);
 
    else
        rightvect->push_back(root->data);
 
    // Return the appropriate vector
    return (leftvect->size() > rightvect->size()
                ? leftvect
                : rightvect);

}

vector<int> longestPath(BinaryTreeNode<int>* root)
{
 
    // If root is null means there
    // is no binary tree so
    // return a empty vector
    if (root == NULL) {
        vector<int> temp
            = {};
        return temp;
    }
 
    // Recursive call on root->right
    vector<int> rightvect
        = longestPath(root->right);
 
    // Recursive call on root->left
    vector<int> leftvect
        = longestPath(root->left);
 
    // Compare the size of the two vectors
    // and insert current node accordingly
    if (leftvect.size() > rightvect.size())
        leftvect.push_back(root->data);
 
    else
        rightvect.push_back(root->data);
 
    // Return the appropriate vector
    return (leftvect.size() > rightvect.size()
                ? leftvect
                : rightvect);
}

void printBoundaryLeft(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }

    if(root->left){
        cout << root->data << " ";
        printBoundaryLeft(root->left);
    }

    else if(root->right){
        cout << root->data << " ";
        printBoundaryLeft(root->right);
    }
}

void printLeafs(BinaryTreeNode<int>* root){

    if(root==NULL){
        return;
    }

    printLeafs(root->left);
    
    if(!root->left && !root->right){
        cout << root->data << " ";
    }

    printLeafs(root->right);

}

void printBoundaryRight(BinaryTreeNode<int>* root){
    
    if(root==NULL){
        return;
    }
    
    if(root->right){
        printBoundaryRight(root->right);
        cout << root->data << " ";
    }

    else if(root->left){
        printBoundaryRight(root->left);
        cout << root->data << " ";
    }

}

void printBoundaryTraversal(BinaryTreeNode<int>* root){
    
    if(root==NULL){
        return;
    }

    cout << root->data << " ";

    printBoundaryLeft(root->left);
    printLeafs(root->left);
    printLeafs(root->right);
    printBoundaryRight(root->right);
}

long long int mx = 0;

long long int helper(BinaryTreeNode<int> *root, long long int *mx){
    
    //left poora trace, right poora trace, wapas ate hue compare(backtrack)

    if(root==NULL){
        return 0;
    }
    
    long long int lsum = helper(root->left, mx);
    long long int rsum = helper(root->right, mx);

    *mx = max(*mx, lsum+rsum+root->data);

    return root->data + max(lsum,rsum);

    
}

long long int maximumSumLeafpath(BinaryTreeNode<int> *root)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    helper(root,&mx);
    return mx;
}

void printBinaryTreePattern(BinaryTreeNode<int>* root){
    
    if(root==NULL){
        return;
    }

    cout << root->data << " ";

    queue<BinaryTreeNode<int>*> qL;
    queue<BinaryTreeNode<int>*> qR;

    if(root->left){
        qL.push(root->left);
    }

    if(root->right){
        qR.push(root->right);
    }

    while(qL.size()>0){
        BinaryTreeNode<int>* qL_front = qL.front();
        qL.pop();

        cout << qL_front->data << " ";

        if(qL_front->left){
            qL.push(qL_front->left);
        }
        if(qL_front->right){
            qL.push(qL_front->right);
        }

        BinaryTreeNode<int>* qR_front = qR.front();
        qR.pop();

        cout << qR_front->data << " ";

        if(qR_front->right){
            qR.push(qR_front->right);
        }
        if(qR_front->left){
            qR.push(qR_front->left);
        }

    }
    
}

BinaryTreeNode<int>* helper(int *input, int n, int si, int ei){
    
    int mid = (si + ei)/2;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    
    BinaryTreeNode<int>* leftTree = helper(input, n, 0, mid-1);
    BinaryTreeNode<int>* rightTree = helper(input, n, mid+1, n-1);
    
    root->left = leftTree;
    root->right = rightTree;
    
    return root;
}



BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    
    return helper(input, n, 0, n-1);
    
}

int main(){

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;

    printBinaryTree(root);

    // BinaryTreeNode<int>* uin = takeInputRecursive();
    // printBinaryTree(uin);


    BinaryTreeNode<int>* uinLevelWise = takeInputLevelWise();

    // printBinaryTree(uinLevelWise);

    printBinaryTreeLevelWise(uinLevelWise);

    cout << "Node Count: " << countNodesBinaryTree(uinLevelWise) << endl;

    cout << isNodePresent(uinLevelWise,7) << endl;

    printBinaryTreeInorder(uinLevelWise);

    // pair<int,int> p = findHeightDiameter(uinLevelWise);

    // cout << "Height: " << p.first << " Diameter: " << p.second << endl;

    // pair<int,int> minMax = getMinAndMax(uinLevelWise);

    // cout << "MIN: " << minMax.first << " MAX: " << minMax.second << endl;

    // vector<int> m = longestPath(uinLevelWise);

    // cout << "longest path is: ";
    // for(int i=0; i<m.size(); i++){
    //     cout << m[i] << endl;
    // }

    cout << endl;
    cout << "Boundary Tree Traversal " << endl;
    printBoundaryTraversal(uinLevelWise);
    cout << endl;
    cout << "max sum leaf path: " << maximumSumLeafpath(uinLevelWise) << endl;

    printBinaryTreePattern(uinLevelWise);


}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
#include<iostream>
#include<queue>

using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            this->data = d;
            this -> left = NULL;
            this -> right = NULL;

        }


};

node* buildTree(node* root){
     cout<<"Enter the data: "<< endl;
     int data;
     cin>>data;

     root = new node(data);

     if(data == -1){
        return NULL;
     }

     cout<<"Enter the data for inserting in left node of: "<< data <<endl;
     root -> left = buildTree(root->left);

     cout<<"Enter the data for inserting in right node of: "<< data <<endl;
     root->right = buildTree(root->right);

      return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //first level has been completed so, now we moving on second line.
            cout<<endl;

            if(!q.empty()){
                //queue still has some child nodes.
                q.push(NULL);
            }
        }
        else{

            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
}

void inorder(node* root){
    if(root == NULL){
        return ;
    }

    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL){
        return ;
    }

    cout<< root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root->data<<" ";
}


void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }


int main(){
    //creating a tree
    node* root = NULL;
   
    buildFromLevelOrder(root);

    levelOrderTraversal(root);

    /*
    root = buildTree(root);


     //level order
    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);

    
    cout << "inorder traversal is:  ";
    inorder(root); 
   
    cout<<endl;
    cout << "preorder traversal is:  ";
    preorder(root); 
   
    cout<<endl;
    cout << "postorder traversal is:  ";
    postorder(root); 

// 2 3 1 -1 -1 4 -1 -1 7 -1 6 -1 -1 
*/
    return 0;
}
#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int key){
        data = key;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    Node* firstnode = new Node(10);
    Node* secondnode = new Node(20);
    Node* thirdnode = new Node(30);
    Node* fourthnode = new Node(40);

    firstnode->left = secondnode;
    firstnode->right = thirdnode;
    secondnode->left = fourthnode;
    secondnode->right = NULL;
    
	return 0;
}
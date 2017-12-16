//
//  main.cpp
//  BinarySearchTree
//
//  Created by Joshua on 4/13/17.
//  Copyright © 2017 Joshua. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;


//Define your tree chunk
class TreeChunk
{
public:
    int value;
    TreeChunk *right=NULL;
    TreeChunk *left=NULL;
    
    TreeChunk (int = 0);
    
    int getValue ()
    {
        return (value);
    }
};

TreeChunk::TreeChunk (int a)
{
    value = a;
}

class BST
{
public:
    TreeChunk *root=NULL;
    
    void searchBST(TreeChunk *start, int key)
    {
        //Anchor
        //Stop if you fell off tree(did not find key), or if you found key
        if (start ==NULL)
        {
            cout << "Did not find this in the tree\n";
            return;
        }
        if(start->value == key)
        {
            cout << "Found the key!\n";
        }
        
        //Recursive Step
        //We'll either go left or right, depending on how key compares to value
        if (key>start->value)
        {
            searchBST(start->right,key);
        }
        else
        {
            searchBST(start->left,key);
        }
    }
    
    //Function to add things to the tree
    void addNodeBST(int key)
    {
        //Phase-I: Look for key in this tree
        TreeChunk *follow, *chase;
        follow=chase=root;
        //check to see if tree is empty
        if (root==NULL)
        {
            TreeChunk *temp = new TreeChunk;
            temp ->value = key;
            root = temp;
            return; //so that the rest of the function does not get fired up
        }
        while (chase !=NULL)
        {
            follow=chase; //lock in chase position
            if (chase->value == key)
            {
                cout << "Will not add duplicates" << endl;
                return;
            }
            if (chase->value < key)
            {
                chase = chase->right;
            }
            else
            {
                chase = chase ->left;
            }
            
        }
        //at this point. chase is NULL. 'follow' has the new parent to be
        //Phase-II: Add key to tree if it's not a duplicate
        TreeChunk *temp = new TreeChunk;
        temp ->value = key;
        //should I add this to the left or right of follow
        if (key < follow->value)
        {
            follow ->left = temp; // add to left if it's smaller
        }
        else
        {
            follow ->right=temp;
        }
        
    }
    //Function to delete anything from the tree
    void deleteNodeBST(TreeChunk *start, int key)
    {
        TreeChunk *follow, *chase;
        follow=chase=start;
        //search for key: Follow is a node behind Chase
        while(chase->value != key)
        {
            if (chase->value < key)
            {
                follow = chase;
                chase = follow->right;
            }
            else if (chase == NULL)
            {
                cout << "Value does not exist\n";
                return;
            }
            else
            {
                follow = chase;
                chase = follow->left;
            }
        }
        
        //MARK: Case 1: the value to delete is a leaf node
        if (chase->right == NULL && chase->left==NULL)
        {
            if (follow ->left == chase)
            {
                follow->left=NULL;
            }
            else
            {
                follow->right=NULL;
            }
            delete chase;
            
        }
        
        //MARK: Case 2: The value to delete has 1 child
        if ((chase ->right != NULL && chase->left == NULL) || (chase ->left != NULL && chase->right == NULL))
        {
            if(follow ->right->left == NULL)
            {
                follow ->right = chase ->right;
                follow ->right->left =NULL;
            }
            else if(follow ->right->right == NULL)
            {
                follow ->right = chase ->left;
                follow ->right->right = NULL;
            }
            else if (follow ->left->left == NULL)
            {
                follow->left = chase->right;
                follow ->left->left = NULL;
            }
            else if (follow->left->right == NULL)
            {
                follow ->left = chase ->left;
                follow->left->right = NULL;
            }
            delete chase;
        }
        
        //MARK: Case 3: The value to delete has 2 children
        if(chase->left!=NULL && chase ->right !=NULL)
        {
            int minval;
            TreeChunk *temp;
            temp =follow = chase->right;
            while(temp->left !=NULL)
            {
                follow = temp;
                temp = follow->left;
                
            }
            
            minval = temp->value;
            //swap chase with minval
            chase ->value = minval;
            temp->value = key;
        
            if (chase->right == temp)//If Chase->right was equal to Temp, there would be issues. So I made an IF-ELSE to fix it.
            {
                follow = chase;
                follow->right = NULL;
                delete temp;
                
            }
            else
            {
                if (follow ->left->value == key)
                {
                follow->left=NULL;
                }
                else if (follow ->right->value == key)
                {
                follow->right=NULL;
                }
                delete temp;
            }
        }
        
        
    }
    //MARK: Display 1: In order
    void inorder(TreeChunk *start)
    {
        //you do left subtree, ROOT, and right subtree
        //anchor, and then recurse
        if(start == NULL)
        {
            return;
        }
        else
        {
            inorder(start->left);
            cout << start->value << ", ";
            inorder(start->right);
        }
    }
    //MARK: Display 2: Post order
    void postorder(TreeChunk *start)
    {
        if (start == NULL)
        {
            return;
        }
        else
        {
            postorder(start->left);
            postorder(start->right);
            cout << start->value << ", ";
        }
    }
    //MARK: Display 3: Pre order
    void preorder(TreeChunk *start)
    {
        if (start == NULL)
        {
            return;
        }
        else
        {
            cout << start->value << ", ";
            preorder(start->left);
            preorder(start->right);
        }
    }
};

int main()
{
    BST myTree;
    int choice;
    int key;
    while(1)
    {
        cout << "\n-------------------------------------";
        cout << "\nPress 1 to add something to the tree\n";
        cout << "Press 2 to search for something\n";
        cout << "Press 3 to delete\n";
        cout << "Press 4 for In-order traversal\n";
        cout << "Press 5 for Post-order traversal\n";
        cout << "Press 6 for Pre-order traversal\n";
        cout << "Anything else to quit";
        cout << "\n------------------------------------\n";
        cout << "Enter Option: ";
        cin >>choice;
        switch (choice)
        {
            case 1:
                cout << "Enter value to add: ";
                cin >> key;
                myTree.addNodeBST(key);
                break;
                
            case 2:
                cout << "Enter value to search: ";
                cin >> key;
                myTree.searchBST(myTree.root, key);
                break;
                
            case 3:
                cout << "Enter value to delete: ";
                cin >> key;
                myTree.deleteNodeBST(myTree.root, key);
                break;
                
            case 4:
                myTree.inorder(myTree.root);
                break;
            
            case 5:
                myTree.postorder(myTree.root);
                break;
                
            case 6:
                myTree.preorder(myTree.root);
                break;
                
            default:
                cout << "Goodbye\n";
                exit(1);
        }
    }
}


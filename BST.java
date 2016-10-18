/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package bst;

/**
 *
 * @author Science
 */
public class Main {
    public static void main(String[]args)
    {
        BinarySearchTree bst = new BinarySearchTree();
        bst.insert(6);
        bst.insert(4);
        bst.insert(10);
        bst.insert(3);
        bst.insert(5);
        bst.insert(9);
        bst.insert(11);
        bst.inorder(bst.root);
    }

}
class BinarySearchTree
{


    class Node
    {
        int data;
        Node left,right;
        Node(int _data)
        {
            data = _data;
        }
    }

    Node root;
    public void insert(int data)
    {
        Node newNode = new Node(data);
        Node itr = root;
        if(root == null)
        {
            root = newNode;
        }
        else
        {
            while(true)
            {
                if(data > itr.data)
                {
                    if(itr.right == null)
                    {
                        itr.right = newNode;
                        return;
                    }
                    itr = itr.right;
                }
                else
                {
                    if(itr.left == null)
                    {
                        itr.left = newNode;
                        return;
                    }
                    itr = itr.left;
                }
            }
        }
    }
    public void deleteData(int data)
    {
        root = deleteRec(root,data);
    }
    public Node deleteRec(Node root,int data)
    {
        if(root == null)
            return root;
        if(data < root.data)
        {
            root.left = deleteRec(root.left,data);
        }
        else if(data > root.data)
        {
            root.right = deleteRec(root.right,data);
        }
        else
        {
            if(root.left == null)
                return root.right;
            else if(root.right == null)
                return root.left;

            root.data = minValue(root.right);
            root.right = deleteRec(root.right,root.data);
        }
        return root;
    }
    public int minValue(Node root)
    {
        int _min = root.data;
        while(root.left != null)
        {
            _min = root.left.data;
            root = root.left;
        }
        return _min;
    }
    public void inorder(Node node)
    {
        if(node == null)
            return ;
        inorder(node.left);
        System.out.println(node.data);
        inorder(node.right);
    }
}

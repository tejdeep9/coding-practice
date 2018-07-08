/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class BinarySearchTree {
	
	class Node {
		int data;
		Node left, right;
		
		Node(int data){
			this.data = data;
			this.left = null;
			this.right = null;
		}
	}
	
	Node root;
	
	BinarySearchTree(){
		root = null;
	}
	
	public void insert(int item){
		root = insert(root, item);
	}
	
	private Node insert(Node root, int item){
		if (root == null) {
			root = new Node(item);
			return root;
		}
		
		if (item > root.data) {
			root.right = insert(root.right, item);
		} else {
			root.left = insert(root.left, item);
		}
		return root;
	}
	
	public boolean search(int item){
		return search(root, item);
	}
	
	private boolean search(Node root, int item){
		if (root == null) {
			return false;	
		}
		
		if (root.data == item)
			return true;
		else if (root.data < item) {
			return search (root.right, item);
		} else {
			return search (root.left, item);
		}
	}
	
	public void delete(int item) {
		root = delete(root, item);
	}
	
	public Node delete(Node root, int item) {
		if (root == null) {
			return root;
		}
		
		if (root.data < item) {
			root.right = delete(root.right, item);
		} else if (root.data > item) {
			root.left = delete(root.left, item);
		} else {
			if (root.left == null && root.right == null) {
				root = null;
			} else if (root.left == null) {
				root = root.right;
			} else if (root.right == null) {
				root = root.left;
			} else {
				Node temp = findMin(root.right);
				root.data = temp.data;
				root.right = delete(root.right, temp.data);
			}
		}
		return root;
	}
	
	private Node findMin(Node root) {
		Node current = root;
		while(current.left != null) {
			current = current.left;
		}
		return current;
	}
	
	public void inorder() {
		inorder(root);
	}
	
	public void inorder(Node root){
		if (root == null){
			return;
		}
		
		inorder(root.left);
		System.out.println(root.data);
		inorder(root.right);
	}
	
}
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BinarySearchTree bst = new BinarySearchTree();
		
		bst.insert(3);
		bst.insert(5);
		bst.insert(2);
		bst.insert(10);
		bst.insert(8);
		bst.insert(11);
		bst.insert(1);
		bst.insert(7);
		
		bst.inorder();
		System.out.println(bst.search(10));
		System.out.println(bst.search(19));
		bst.delete(10);
		bst.inorder();
		
	}
}
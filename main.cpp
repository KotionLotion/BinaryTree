#include "BinaryTree.h"
#include <iostream>

int main()
{
    BinaryTree myTree;

    // Add values to the tree
    myTree.insert(10);
    myTree.insert(20);
    myTree.insert(30);
    myTree.insert(40);
    myTree.insert(50);
    myTree.insert(60);
    myTree.insert(100);

    // Test different ways to walk through the tree
    std::cout << "Inorder Walk: ";
    myTree.inorder();

    std::cout << "Preorder Walk: ";
    myTree.preorder();

    std::cout << "Postorder Walk: ";
    myTree.postorder();

    std::cout << "Level-by-level Walk: ";
    myTree.levelorder();

    // Check if values exist
    std::cout << "Looking for 40: " << (myTree.contains(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Looking for 90: " << (myTree.contains(90) ? "Found" : "Not Found") << std::endl;

    // Show tree info
    std::cout << "Total nodes: " << myTree.size() << std::endl;
    std::cout << "Tree levels: " << myTree.depth() << std::endl;

    // Remove a value and show changes
    myTree.deleteValue(30);
    std::cout << "Inorder after removing 30: ";
    myTree.inorder();

    return 0;
}
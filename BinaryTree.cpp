#include "BinaryTree.h"

BinaryTree::BinaryTree() : treeRoot(nullptr) {}

BinaryTree::~BinaryTree()
{
    clearTree(treeRoot);
}

void BinaryTree::clearTree(TreeNode *current)
{
    if (current)
    {
        clearTree(current->leftChild);
        clearTree(current->rightChild);
        delete current;
    }
}
// Insertion
BinaryTree::TreeNode *BinaryTree::addNode(TreeNode *current, int value)
{
    if (!current)
    {
        return new TreeNode(value);
    }

    if (value < current->num)
    {
        current->leftChild = addNode(current->leftChild, value);
    }
    else if (value > current->num)
    {
        current->rightChild = addNode(current->rightChild, value);
    }

    return current;
}

void BinaryTree::insert(int value)
{
    treeRoot = addNode(treeRoot, value);
}
// Search
BinaryTree::TreeNode *BinaryTree::findNode(TreeNode *current, int value) const
{
    if (!current || current->num == value)
    {
        return current;
    }

    if (value < current->num)
    {
        return findNode(current->leftChild, value);
    }

    return findNode(current->rightChild, value);
}

bool BinaryTree::contains(int value) const
{
    return findNode(treeRoot, value) != nullptr;
}

BinaryTree::TreeNode *BinaryTree::getMinValueNode(TreeNode *current)
{
    while (current && current->leftChild)
    {
        current = current->leftChild;
    }
    return current;
}
// Deletion
BinaryTree::TreeNode *BinaryTree::removeNode(TreeNode *current, int value)
{
    if (!current)
        return current;

    if (value < current->num)
    {
        current->leftChild = removeNode(current->leftChild, value);
    }
    else if (value > current->num)
    {
        current->rightChild = removeNode(current->rightChild, value);
    }
    else
    {
        // Node with only one child or no child
        if (!current->leftChild)
        {
            TreeNode *temp = current->rightChild;
            delete current;
            return temp;
        }
        else if (!current->rightChild)
        {
            TreeNode *temp = current->leftChild;
            delete current;
            return temp;
        }

        // Node with two children
        TreeNode *temp = getMinValueNode(current->rightChild);
        current->num = temp->num;
        current->rightChild = removeNode(current->rightChild, temp->num);
    }
    return current;
}

void BinaryTree::deleteValue(int value)
{
    treeRoot = removeNode(treeRoot, value);
}
// Traversal
void BinaryTree::printInorder(TreeNode *current) const
{
    if (!current)
        return;
    printInorder(current->leftChild);
    std::cout << current->num << " ";
    printInorder(current->rightChild);
}

void BinaryTree::inorder() const
{
    printInorder(treeRoot);
    std::cout << std::endl;
}

void BinaryTree::printPreorder(TreeNode *current) const
{
    if (!current)
        return;
    std::cout << current->num << " ";
    printPreorder(current->leftChild);
    printPreorder(current->rightChild);
}

void BinaryTree::preorder() const
{
    printPreorder(treeRoot);
    std::cout << std::endl;
}

void BinaryTree::printPostorder(TreeNode *current) const
{
    if (!current)
        return;
    printPostorder(current->leftChild);
    printPostorder(current->rightChild);
    std::cout << current->num << " ";
}

void BinaryTree::postorder() const
{
    printPostorder(treeRoot);
    std::cout << std::endl;
}

void BinaryTree::levelorder() const
{
    if (!treeRoot)
        return;

    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(treeRoot);

    while (!nodeQueue.empty())
    {
        TreeNode *currentNode = nodeQueue.front();
        nodeQueue.pop();
        std::cout << currentNode->num << " ";

        if (currentNode->leftChild)
            nodeQueue.push(currentNode->leftChild);
        if (currentNode->rightChild)
            nodeQueue.push(currentNode->rightChild);
    }
    std::cout << std::endl;
}
// Help Func
int BinaryTree::countAllNodes(TreeNode *current) const
{
    if (!current)
        return 0;
    return 1 + countAllNodes(current->leftChild) + countAllNodes(current->rightChild);
}

int BinaryTree::size() const
{
    return countAllNodes(treeRoot);
}
// Tree Depth
int BinaryTree::getTreeDepth(TreeNode *current) const
{
    if (!current)
        return -1;
    return 1 + std::max(getTreeDepth(current->leftChild), getTreeDepth(current->rightChild));
}

int BinaryTree::depth() const
{
    return getTreeDepth(treeRoot);
}
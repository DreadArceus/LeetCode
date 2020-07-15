#include <iostream>
#include <cmath>
using namespace std;
//This question taught me alot about Binary Trees through the input process
//Was not able to actually complete compareTrees() though
struct TreeNode
{
  TreeNode()
  {
    val = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int x)
  {
    val = x;
    left = nullptr;
    right = nullptr;
  }
  TreeNode(int x, TreeNode *left, TreeNode *right)
  {
    val = x;
    this->left = left;
    this->right = right;
  }
  int val;
  TreeNode *left;
  TreeNode *right;
};
void TreeMaker(TreeNode t[])
{
  int size = sizeof(&t)/sizeof(TreeNode);
  int levelBuffer = 1;
  for(int i = 0; i < size; i++)
  {
    if((i + 1) % 2 == 0)
    {
      levelBuffer = i + 1;
    }
    t[i].left = &t[i + levelBuffer];
    t[i].right = &t[i + levelBuffer + 1];
  }
}
bool compareTrees(TreeNode *r1, TreeNode *r2)
{
  if(r1->val != r2->val)
  {
    return false;
  }
  return true;
}
int main()
{
  int n, treeSize;
  cin >> n;
  for(int i = 0; ; i++)
  {
    if(pow(2, i) >= n)
    {
      treeSize = pow(2, i);
      break;
    }
  }
  TreeNode t1[treeSize], t2[treeSize];
  for(int i = 0; i < n; i++)
  {
    cin >> t1[i].val;
  }
  for(int i = 0; i < n; i++)
  {
    cin >> t2[i].val;
  }
  TreeMaker(t1);
  TreeMaker(t2);
  bool result = compareTrees(&t1[0], &t2[0]);
  cout << result;
}

//
// CreatBed by Administrator on 2021/1/4 0004.
//



#include "iostream"
#include "deque"
#include "vector"
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

#include "algorithm"
#include "deque"
using namespace std;
class Solution {
public:
    int depth=0;
    int dir=1;
    vector<vector<int>>vector2;
    vector<vector<TreeNode*>>vector1;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector1[0][0]=root;
        for(int i = 1; i <dep(root) ; ++i) {
            int j=0;
            int p=0;
            while (p<vector1[i-1].size()){
                vector1[i][j]=vector1[i-1][p]->left;
                vector1[i][j+1]=vector1[i-1][p]->right;
                j=j+2;
            }
        }
        int dir=1;
        for (int i = 0; i <dep(root) ; ++i) {
            if (dir==1){
                for (int j = 0; j <vector1[i].size() ; ++j) {
                    vector2[i].push_back(vector1[i][j]->val);
                }
                dir=-1;
            } else{
                for (int j = vector1[i].size()-1; j >=0 ; --j) {
                    vector2[i].push_back(vector1[i][j]->val);
                }
                dir=1;
            }

        }
        return vector2;
    }
    int max(int i,int j){
        if (i>j){
            return i;
        } else{
            return j;
        }

    }
    int dep(TreeNode *root){
        if (!root){
            return 0;
        }
        return max(1+dep(root->left),1+dep(root->right));
    }
};

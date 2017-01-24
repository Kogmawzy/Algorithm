class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int vinLen=vin.size();
        if(vinLen==0)
            return NULL;
        vector<int> left_pre,right_pre,left_in,right_in;
        int val=pre[0];
        TreeNode* root=new TreeNode(val);     //创建根节点，根节点肯定是前序遍历的第一个数
        int p=0;
        for(p;p<vinLen;p++){                 //找到中序遍历根节点所在位置,存放于变量p中
            if(vin[p]==val)
                break;
        }

        //对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
 
        //利用上述这点，对二叉树节点进行归并
        for(int i=0;i<vinLen;i++){
            if(i<p){
                left_in.push_back(vin[i]);
                left_pre.push_back(pre[i+1]);
            }
            else if(i>p){
                right_in.push_back(vin[i]);
                right_pre.push_back(pre[i]);
            }
        }
        //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
        root->left=reConstructBinaryTree(left_pre,left_in);
        root->right=reConstructBinaryTree(right_pre,right_in);
        return root;
    }
};
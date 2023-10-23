#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;
struct TreeNode {
    int val;
    bool isChecked = false;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //打印二叉树
    void print_tree(const vector<vector<int> > &tree){
        for(int i = 0;i<tree.size();++i){
            for(int j = 0;j<tree[i].size();++j){
                cout<<tree[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    //前中后序遍历，递归实现
	std::vector<int> result;
	std::vector<int> result2;
	std::vector<int> result3;
	//中序遍历
	std::vector<int> inorderTraversalByRecursion(TreeNode* root) {
		if (root == nullptr)//中止条件
			return result;
		else {
			inorderTraversalByRecursion(root->left);
			result.push_back(root->val);
			inorderTraversalByRecursion(root->right);
		}
		return result;
		
	}
	//前序
	std::vector<int> preorderTraversalByRecursion(TreeNode* root) {
		if (root == nullptr)//中止条件
			return result2;
		else{
			result2.push_back(root->val);
		preorderTraversalByRecursion(root->left);
		preorderTraversalByRecursion(root->right);
		}
		return result2;

	}
	//后序
	std::vector<int> postorderTraversalByRecursion(TreeNode* root) {
		if (root == nullptr)//中止条件
			return result3;
		else {
			
			postorderTraversalByRecursion(root->left);
			postorderTraversalByRecursion(root->right);
			result3.push_back(root->val);
		}
		return result3;

	}
	//非递归实现，用到栈
	//前序
	std::vector<int> preorderTraversalByIteration(TreeNode* root) {
		std::stack<TreeNode*> stack;
		std::vector<int> result;
		if (root == nullptr) {
			return result;//空返
		}
		TreeNode* temp;
		stack.push(root);//首先根节点入栈

		while (!stack.empty()) {
			temp = stack.top();
			//std::cout << "栈顶元素为：" << temp->val << std::endl;
			stack.pop();//出栈
			result.push_back(temp->val);
			/*if (temp->left) {
				std::cout << "能进去" << std::endl;
			}
			else
				std::cout << "进不去" << std::endl;*/
			if (temp->left || temp->right) {
				std::cout << "进入了" << std::endl;
				if (temp->left && temp->right) {
					stack.push(temp->right);
					stack.push(temp->left);
				}
				else if (temp->left) {
					stack.push(temp->left);
				}
				else
					stack.push(temp->right);
			}
		}
		return result;

	}

	//中序
	std::vector<int> inorderTraversalByIteration(TreeNode* root) {
		std::stack<TreeNode*> stack;
		std::vector<int> result;
		if (root == nullptr) {
			return result;//空返
		}
		TreeNode* temp;
		stack.push(root);//首先根节点入栈
		temp = root;
		while (temp->left) {
			temp = temp->left;
			stack.push(temp);

		}
		while (!stack.empty()) {
			temp = stack.top();
			stack.pop();
			result.push_back(temp->val);
			if (temp->right) {
				temp = temp->right;
				stack.push(temp);
				while (temp->left) {
					temp = temp->left;
					stack.push(temp);
				}
			}
		}
		return result;

	}

	//后序，法一，为了避免重复考察节点设置标志isChecked
	std::vector<int> postorderTraversalByIteration(TreeNode* root) {
		std::stack<TreeNode*> stack;
		std::vector<int> result;
		if (root == nullptr) {
			return result;//空返
		}
		TreeNode* temp;
		stack.push(root);//首先根节点入栈
		temp = root;
		while (temp->left) {//左子树依次入栈
			temp = temp->left;
			stack.push(temp);

		}
		while (!stack.empty()) {
			temp = stack.top();
			/*std::cout << "temp = "<<temp->val << std::endl;
			if (temp->isChecked)
				std::cout << "state is true" << std::endl;
			else
				std::cout << "state is false" << std::endl;*/
			if (temp->right && !temp->isChecked) {//temp的右子树存在且已经考察过了
				temp->isChecked = true;//该节点已考察
				temp = temp->right;
				stack.push(temp);
				while (temp->left) {//左子树依次入栈
					temp = temp->left;
					stack.push(temp);

				}
				
			}
			else {//右子树不存在，则该节点是叶子节点
				//std::cout << temp->val << std::endl;
				result.push_back(temp->val);
				stack.pop();
			}
		}
		return result;
	}
	//后序，法二，为了避免重复考察节点，把考察过的节点的右子树切掉
	std::vector<int> postorderTraversalByIteration_2(TreeNode* root) {
		std::stack<TreeNode*> stack;
		std::vector<int> result;
		if (root == nullptr) {
			return result;//空返
		}
		TreeNode* temp;
		stack.push(root);//首先根节点入栈
		temp = root;
		while (temp->left) {//左子树依次入栈
			temp = temp->left;
			stack.push(temp);

		}
		while (!stack.empty()) {
			temp = stack.top();
			/*std::cout << "temp = "<<temp->val << std::endl;
			if (temp->isChecked)
				std::cout << "state is true" << std::endl;
			else
				std::cout << "state is false" << std::endl;*/
			if (temp->right) {//temp的右子树存在
				TreeNode* temp2 = temp;
				temp = temp->right;
				stack.push(temp);
				while (temp->left) {//左子树依次入栈
					temp = temp->left;
					stack.push(temp);

				}
				temp2->right = nullptr;//该节点的右子树已考察,切掉右子树

			}
			else {//右子树不存在，则该节点是叶子节点
				//std::cout << temp->val << std::endl;
				result.push_back(temp->val);
				stack.pop();
			}
		}
		
		return result;
	}

    //层序遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
		std::vector<std::vector<int> > result;
		std::queue<TreeNode*> queue;
		int curcount = 0;//记录队列中当前存放数目
		int nextcount;//下一个队列的数目
        if(root)
		    queue.push(root);//根节点入队列
		curcount++;
        std::vector<int> vec;
		while (!queue.empty()) {
            nextcount = 0;
			while (curcount) {
				TreeNode* temp = queue.front();
				if(temp){
					vec.push_back(queue.front()->val);
					queue.pop();
					curcount--;
					// if (temp->left || temp->right) {//version1 
					// 	if (temp->left && temp->right) {
					// 		queue.push(temp->left);
					// 		queue.push(temp->right);
					// 		nextcount += 2;
					// 	}
					// 	else if (temp->left) {
					// 		queue.push(temp->left);
					// 		nextcount++;
					// 	}
					// 	else {
					// 		queue.push(temp->right);
					// 		nextcount++;
					// 	}							
					// }


                    // if(temp->left && temp->right){//version2
                    //     queue.push(temp->left);
					//  	queue.push(temp->right);
					//  	nextcount += 2;
                    // }
                    // else if(temp->left&&!temp->right){
                    //     queue.push(temp->left);
                    //     nextcount++;
                    // }
                    // else if(!temp->left&&temp->right){
                    //     queue.push(temp->right);
                    //     nextcount++;
                    // }
                    
                    if(temp->left){
                        queue.push(temp->left);
                        nextcount++;

                    }
                        
                    if(temp->right){
                        queue.push(temp->right);
                        nextcount++;
                    }
                        
                }					
			}			
			curcount = nextcount;
			result.push_back(vec);
            vec.clear();
		}
		return result;

    }

    //求二叉树最大深度
    //递归实现
    int depth = 0;
    int maxDepthByRecursion(TreeNode* root) {
        int left_depth = 0;
        int right_depth = 0;
        if(root->left==nullptr&&root->right==nullptr){
            return 1;
        }
        if(root->left){
             left_depth = 1 + maxDepthByRecursion(root->left);
        }
        if(root->right){
            right_depth = 1 + maxDepthByRecursion(root->right);
        }
        depth = left_depth>right_depth?left_depth:right_depth;
        return depth;
    }
    //非递归，层序遍历实现
    int maxDepthByIteration(TreeNode* root){
        std::deque<TreeNode*> deque;//队列
		int curcount = 0;//记录队列中当前存放数目
		int nextcount;//下一个队列的数目
        int depth = 0;
        if(root)//判空
		    deque.push_back(root);//根节点入队列
		curcount++;

		while (!deque.empty()) {
			depth++;
            nextcount = 0;
			while (curcount) {
				TreeNode* temp = deque.front();
				if(temp){
					deque.pop_front();
					curcount--;
					if (temp->left || temp->right) {
						if (temp->left && temp->right) {
							deque.push_back(temp->left);
							deque.push_back(temp->right);
							nextcount += 2;
						}
						else if (temp->left) {
							deque.push_back(temp->left);
							nextcount++;
						}
						else {
							deque.push_back(temp->right);
							nextcount++;

						}							
					}

                }					
			}			
			curcount = nextcount;
            
		}
        return depth;
    }



    //求二叉树最小深度
    //非递归，层序遍历
    //最小深度，也就是所以叶子节点的深度的最小值，也就是层序遍历时，所遇到的第一个叶子节点的深度
    int minDepthByIteration(TreeNode* root) {
        queue<TreeNode*> queue;
        int min_depth = 0;
        if(root){
            queue.push(root);
        }
        else
            return 0;
        int level_num = 1;
        while(!queue.empty()){
            int size = queue.size();
            for(int i=0;i<size;++i){
                TreeNode* temp = queue.front();
                queue.pop();
                if(!temp->left&&!temp->right){
                    min_depth = level_num;
                    return min_depth;
                }
                if(temp->left){
                    queue.push(temp->left);
                   
                }
                if(temp->right){
                    queue.push(temp->right);
                }
            }
            level_num++;
        }
        return min_depth;


    }

    //完全二叉树的最小深度，非递归，层序遍历
    int totalBTMinDepth(TreeNode* root){
        queue<TreeNode*> queue;
        int min_depth = 0;
        if(root){
            queue.push(root);
            //min_depth++;
        }
        int level_max_num = 1;
        while(!queue.empty()){
            
            int size = queue.size();
            if(size==level_max_num)
                min_depth++;

            for(int i=0;i<size;++i){
                TreeNode* temp = queue.front();
                queue.pop();
                if(temp->left){
                    queue.push(temp->left);
                   
                }
                if(temp->right){
                    queue.push(temp->right);
                }
            }
            level_max_num<<=1;//左移一位，乘2
        }
        return min_depth;
    }


    //相同的树
    /*
    给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
    如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
    */
    //递归实现
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((!p&&q)||(p&&!q)){//q、p只有一个存在，肯定不一样
            return false;
        }
        if(!p&&!q){//都不存在
            return true;
        }
        if(p->val!=q->val)
            return false;
        //到这里，都存在且值相等
        if(!isSameTree(p->left,q->left))
            return false;
        if(!isSameTree(p->right,q->right))
            return false;
        return true;

    }

    //对称的树
    //给你一个二叉树的根节点 root ， 检查它是否轴对称
    //递归
    bool isSymmetric_Recursion(TreeNode* root) {
        TreeNode* lchild = root->left;
        TreeNode* rchild = root->right;
        bool result = handle_func(lchild,rchild);
        return result; 
    }
    bool handle_func(TreeNode* left,TreeNode* right){
        if(!left&&!right)
            return true;
        if((left&&!right)||(!left&&right))
            return false;
        if(left->val!=right->val)
            return false;
        
        // if(!left->left&&(!right->right))
        //     return true;
        // if((((!left->left&&(right->right))||(left->left&&(!right->right))))||(left->left->val!=right->right->val))
        //     return false;
        // if(!left->right&&(!right->left))
        //     return true;
        // if(((!left->right&&right->left)||(left->right&&(!right->left)))||(left->right->val!=right->left->val))
        //     return false;
        
        // if(!handle_func(left->left,right->right))
        //     return false;
        // if(!handle_func(left->right,right->left))
        //     return false;

        bool outside = handle_func(left->left,right->right);
        bool inside = handle_func(left->right,right->left);
        bool result = outside&&inside;
        return result;
    }
    //迭代，层序
    // bool isSymmetric_Iteration(TreeNode* root) {
    //     vector<vector<int> > result;
    //     result = Solution::levelOrder(root);
        

    // }

    //将有序数组转换为二叉平衡搜索树
    /*给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
    高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树
    */
    // TreeNode* sortedArrayToBST(vector<int>& nums) {
    //     TreeNode* root = new TreeNode(nums[0]);

    // }


    //翻转二叉树
    /*给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
    */
    //递归实现
    void swap_child(TreeNode *& lchild,TreeNode *& rchild){
        if(!lchild&&(!rchild))
            return;
        TreeNode* temp;
        temp = lchild;
        lchild = rchild;
        rchild = temp;
    }
    //前序
    TreeNode* invertTreeByRecursionPreOrder(TreeNode* root) {
        if(!root)
            return root;
        swap_child(root->left,root->right);
        invertTreeByRecursionPreOrder(root->left);
        invertTreeByRecursionPreOrder(root->right);
        return root;
    }
    //后序
    TreeNode* invertTreeByRecursionPostOrder(TreeNode* root){
        if(!root)
            return root;
        
        invertTreeByRecursionPreOrder(root->left);
        invertTreeByRecursionPreOrder(root->right);
        swap_child(root->left,root->right);
        return root;
    }
    //非递归实现,层序遍历


    //计算完全二叉树的节点个数
    /*给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
    完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
    并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。*/
    int countNodes(TreeNode* root) {
        //层序遍历，适用于所有树
        int node_count = 0;
        queue<TreeNode*> queue;
        if(root){
            queue.push(root);
        }
        else
            return 0;
        while(!queue.empty()){
            node_count++;
            TreeNode* temp = queue.front();
            queue.pop();
            if(temp->left)
                queue.push(temp->left);
            if(temp->right)
                queue.push(temp->right);

        }
        return node_count;
    }
    //利用完全二叉树特性
    //递归，后序遍历
    int countNodes_2(TreeNode* root){
        if(!root)
            return 0;
        int lcount = 0;
        int rcount = 0;
        int ldepth = 1;
        int rdepth = 1;
        int count_num = 0;
        TreeNode* ltemp = root->left;
        while(ltemp){
            ldepth++;
            ltemp = ltemp->left;
        }
        TreeNode* rtemp = root->right;
        while(rtemp){
            rdepth++;
            rtemp = rtemp->right;
        }
        if(ldepth == rdepth){
            count_num = pow(2,ldepth)-1;
            return count_num;
        }
        else{
            lcount = countNodes_2(root->left);//左
            rcount = countNodes_2(root->right);//右
        }
        
        return lcount+rcount+1;//中
    }


    //给定一个二叉树，判断它是否是高度平衡的二叉树。一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1
    bool isBalanced(TreeNode* root) {
        if(getHeight(root)== -1){
            return false;
        }
        return true;
    }
    int getHeight(TreeNode* root){
        int result;
        if(!root)
            return 0;
        int left_height = getHeight(root->left);
        if(left_height == -1){
            return -1;
        }
        int right_height = getHeight(root->right);
        if(right_height == -1){
            return -1;
        }
        if(abs(left_height - right_height)>1){
            return -1;
        }
        else{
            result = max(left_height,right_height) + 1;
        }
        return result;
    }


    //给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径
    //递归实现
    void travesal(TreeNode* root,vector<int> &path,vector<string> &result){
        path.push_back(root->val);
        if(!root->left&&!root->right){
            string str = to_string(path[0]);
            for(int i = 1;i<path.size();++i){
                str += "->" + to_string(path[i]);
            }
            result.push_back(str);
        }
        if(root->left){
            travesal(root->left,path,result);
            path.pop_back();//回溯思想体现
        }
            
        if(root->right){
            travesal(root->right,path,result);
            path.pop_back();
        }
            
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        travesal(root,path,result);
        return result;
    }
    //迭代实现
    //To be continue....

    //给定二叉树的根节点 root ，返回所有左叶子之和
    //递归，前序遍历
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        countLeftLeaves(root,sum);
        return sum;
    }
    void countLeftLeaves(TreeNode* root,int &sum){
        if(!root)
            return;
        if(root->left&&(!root->left->left&&!root->left->right)){
            sum += root->left->val;
        }
        countLeftLeaves(root->left,sum);
        countLeftLeaves(root->right,sum);
    }
    //迭代



    //找树左下角的值
    //给定一个二叉树的 根节点 root，请找出该二叉树的 最底层、最左边节点的值
    //！！！注意是最左边，不是第一个左叶子节点
    //层序遍历
    int findBottomLeftValue(TreeNode* root) {
        int bottom_left;
       
        queue<TreeNode*> queue;
        if(!root)
            return 0;
        else if(!root->left&&!root->right)
            return root->val;
        else
            queue.push(root);//根节点入队
        while(!queue.empty()){
            int queue_longth = queue.size();
            TreeNode* temp;
             int count = 0;//记录每一层节点个数
            for(int i = 0;i<queue_longth;++i){
                temp = queue.front();
                queue.pop();
                if(temp->left){
                    count++;
                    queue.push(temp->left);
                    //判断是否是第一次
                    if(count == 1)
                        bottom_left = temp->left->val;
                }
                if(temp->right){
                    count++;
                    queue.push(temp->right);
                    if(count == 1)
                        bottom_left = temp->right->val;
                }
            }
                       
        }
        return bottom_left;
    }
    //递归，带回溯的


    //路径总和
    //给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
    int _result = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
		vector<TreeNode*> vec;
        vector<int> result;
        getResult(root,vec,result);
        for(int i = 0;i<result.size();++i){
            if(result[i] == targetSum)
                return true;
            
            }
        return false;
    }
    void getResult(TreeNode* root,vector<TreeNode*> &vec,vector<int> &result){
        vec.push_back(root);
        _result += root->val;
        if(!root->left&&!root->right){
            result.push_back(_result);
        }
        if(root->left){
            getResult(root->left,vec,result);
            _result -= vec.back()->val;
            vec.pop_back();
        }
        if(root->right){
            getResult(root->right,vec,result);
            _result -= vec.back()->val;
            vec.pop_back();
        }
    }


    //从中序与后序遍历序列构造二叉树
    //根据一棵树的中序遍历与后序遍历构造二叉树，你可以假设树中没有重复的元素
    //给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(!postorder.size()){
            return nullptr;
        }
        

        int new_node_val = postorder.back();
        TreeNode* new_node = new TreeNode(new_node_val);//生成新节点

        if(postorder.size() == 1){
            return new_node;
        }

        //分割中序数组
        int index = 0;//index为分割元素所在下标
        for(int i = 0;i<inorder.size();++i){
            if(inorder[i] == new_node_val){
                break;
            }
            index++;
        }
        vector<int> inorder_left;
        vector<int> inorder_right;
        for(int i = 0;i<index;++i){
            inorder_left.push_back(inorder[i]);
        }
        for(int i = index+1;i<inorder.size();++i){
            inorder_right.push_back(inorder[i]);
        }

        //根据分割出的左前序数组的大小分割后序数组
        vector<int> postorder_left;
        vector<int> postorder_right;
        for(int i = 0;i<inorder_left.size();++i){
            postorder_left.push_back(postorder[i]);
        }
        for(int i =inorder_left.size();i<postorder.size()-1;++i){
            postorder_right.push_back(postorder[i]);
        }
        new_node->left = buildTree(inorder_left,postorder_left);
        new_node->right = buildTree(inorder_right,postorder_right);
        return new_node;

        
    }


    //从前序与后序遍历序列构造二叉树
    //给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点
    TreeNode* buildTree_2(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()){
            return nullptr;
        }
        int new_node_val = preorder[0];
        TreeNode* new_node = new TreeNode(new_node_val);

        if(preorder.size() == 1){
            return new_node;
        }

        //根据new_node_val分割中序数组
        int index = 0;
        for(int i =0;i<inorder.size();++i){
            if(inorder[i] == new_node_val)
                break;
            index++;
        }
        //构造左中序和右中序数组
        vector<int> inorder_left;
        vector<int> inorder_right;
        for(int i = 0;i<index;++i){
            inorder_left.push_back(inorder[i]);
        }
        for(int i = index + 1;i<inorder.size();++i){
            inorder_right.push_back(inorder[i]);
        }

        //根据左中序数组的大小构造左前序和右前序数组
        vector<int> preorder_left;
        vector<int> preorder_right;

        for(int i = 1;i<inorder_left.size()+1;++i){
            preorder_left.push_back(preorder[i]);
        }
        for(int i = inorder_left.size()+1;i<preorder.size();++i){
            preorder_right.push_back(preorder[i]);
        }

        new_node->left = buildTree_2(preorder_left,inorder_left);
        new_node->right = buildTree_2(preorder_right,inorder_right);
        return new_node;

    }

    //最大二叉树
    //给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
    // 二叉树的根是数组中的最大元素。
    // 左子树是通过数组中最大值左边部分构造出的最大二叉树。
    // 右子树是通过数组中最大值右边部分构造出的最大二叉树。
    // 通过给定的数组构建最大二叉树，并且输出这个树的根节点。
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(!nums.size())
            return nullptr;
        
        int max_num = *max_element(nums.begin(),nums.end());//max_element(begin,end)返回迭代器
        TreeNode* new_node = new TreeNode(max_num);
        if(nums.size() == 1)
            return new_node;
        
        int index = 0;
        for(int i = 0;i<nums.size();++i){
            if(nums[i] == max_num)
                break;
            index++;
        }
        
        vector<int> left;
        vector<int> right;
        for(int i = 0;i<index;++i){
            left.push_back(nums[i]);
        }
        for(int i = index +1;i<nums.size();++i){
            right.push_back(nums[i]);
        }

        new_node->left = constructMaximumBinaryTree(left);
        new_node->right = constructMaximumBinaryTree(right);
        return new_node;
        
    }

    //合并二叉树
    /*想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
    你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。
    返回合并后的二叉树。注意: 合并过程必须从两个树的根节点开始。*/
    //方法1，创建一个新的树,有错误
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1){
            return root2;
        }
        if(!root2)
            return root1;
        int new_val = root1->val + root2->val;
        TreeNode* new_node = new TreeNode(new_val);
        new_node->left = mergeTrees(root1->left,root2->left);
        new_node->right = mergeTrees(root1->right,root2->right);
        return new_node;
    }

    //方法2，在原本的一棵树上修改
    TreeNode* mergeTrees_2(TreeNode* root1, TreeNode* root2) {
        if(!root1)
            return root2;
        if(!root2)
            return root1;
        root1->val += root2->val;
        root1->left = mergeTrees_2(root1->left,root2->left);
        root1->right = mergeTrees_2(root1->right,root2->right);
        return root1;
    }

    //二叉搜索树中的搜索
    /*给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。*/
    //法1，正常递归遍历
    TreeNode* target_node;
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return nullptr;
        searchBST(root->left,val);
        if(root->val == val)
            target_node =  root;
        searchBST(root->right,val);
        //return nullptr;
        return target_node;

    }
    //法2，利用二叉搜索树的性质
    TreeNode* searchBST_2(TreeNode* root,int val){
        while(root && root->val != val){
            if(root->val > val)
                root = root->left;
            else
                root = root->right;
        }
        return root;

    }

    //验证二叉搜索树，给定一个二叉树，判断其是否是一个有效的二叉搜索树。
    //利用中序遍历是一个递增序列
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        //有错误
        // if(!root)
        //     return true;
        // if(!root->left&&!root->right)//叶子节点返回true
        //     return true;
        // bool left_result = isValidBST(root->left);
        // bool right_result = isValidBST(root->right);
        // if(!left_result||!right_result)
        //     return false;
        // if(root->left){
        //     if(root->left->val<root->val)
        //         left_result = true;
        //     else
        //         left_result = false;
            
        // }
        // if(root->right){
        //     if(root->right->val > root->val)
        //         right_result = true;
        //     else
        //         right_result = false;
        // }
        // if(left_result&&right_result)
        //     return true;
        // return false;
        if(!root)
            return true;
        bool left = isValidBST(root->left);

        if(!pre)
        {
            pre = root;
            //return true;
        }
            
        if(pre!=root){
            if(pre->val < root->val){
                 pre = root;
            }
            else
                return false;

        }
        
        
        bool right = isValidBST(root->right);

        return left&&right;

    }

    //BST的绝对值差最小值，该值是一个正值
    int min_abs = 0;//INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return 0;
        getMinimumDifference(root->left);
        if(!pre)
            pre = root;
        
        if(pre!=root){
            int min_temp = abs(pre->val - root->val);
            if(min_temp<min_abs)
                min_abs = min_temp;
            pre = root;
        }
        getMinimumDifference(root->right);
        return min_abs;
    }

    //669.修剪BST
    /*给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在
    [low, high]中。修剪树 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。可以证明，存在唯一的答案。
    所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变*/
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        //先判断是否换根
        while(root->val < low||root->val > high){
            if(root->val < low)
                root = root->left;
            else if(root->val > high)
                root = root->right;
        }
        //现在root->val属于[low,high]
        TreeNode* left_ = root->left;
        TreeNode* right_ = root->right;
        TreeNode* pre_left = root;
        TreeNode* pre_right = root;
        while(left_&&left_->val >= low){
            pre_left = left_;
            left_ = left_->left;
        }while(right_&&right_->val <= high){
            pre_right = right_;
            right_ = right_->right;
        }
        pre_left->left = nullptr;
        pre_right->right = nullptr;
        return root;

    }

    //108.将有序数组转换为二叉搜索树
    /*将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
    本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。*/
    TreeNode* sortedArrayToBST(vector<int>& nums,int left,int right) {
        if(left > right)
            return nullptr;
        int mid = (left+right)/2;
        TreeNode* new_node = new TreeNode(nums[mid]);
        new_node->left = sortedArrayToBST(nums,left,mid-1);
        new_node->right = sortedArrayToBST(nums,mid+1,right);
        return new_node;
    }

    //538.把二叉搜索树转换为累加树
    /*给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。*/
    //节点的左子树仅包含键 小于节点键的节点。节点的右子树仅包含键大于节点键的节点。左右子树也必须是二叉搜索树。
    int cur_count = 0;
    int pre_count = 0;
    void convertBST(TreeNode* root) {
        if(!root)
            return;
        convertBST(root->right);
        cur_count = pre_count + root->val;
        root->val = cur_count;
        pre_count = cur_count;
        convertBST(root->left);
    }

    




};

int main(){

    Solution solution;
    TreeNode *root = new TreeNode(2);
    TreeNode *lchild = new TreeNode(1);
    TreeNode *rchild = new TreeNode(3);
    //TreeNode *llchild = new TreeNode(4);
    //TreeNode *lrchild = new TreeNode(5);
    root->left = lchild;
    root->right = rchild;
    //lchild->left = llchild;
    //lchild->right = lrchild;

    TreeNode *root2 = new TreeNode(543);
    TreeNode *lchild2 = new TreeNode(384);
    TreeNode *rchild2 = new TreeNode(652);
    TreeNode *lrchild2 = new TreeNode(445);
    TreeNode *rrchild2 = new TreeNode(699);
    //TreeNode *lrchild2 = new TreeNode(6);
    root2->left = lchild2;
    root2->right = rchild2;
    //rchild2->left = rlchild2;
    lchild2->right = lrchild2;
    rchild2->right = rrchild2;
    // vector<vector<int> > result;
    // result = solution.levelOrder(root);
    

    // for(vector<vector<int> >::iterator it = result.begin();it != result.end();it++){
    //     for(vector<int>::iterator innerit = (*it).begin();innerit != (*it).end();it++){
    //         cout<<(*innerit)<<" ";
    //     }
    //     cout<<endl;
    // }
    //solution.print_tree(solution.levelOrder(root2));
    /*int depth = solution.maxDepthByRecursion(root);
    cout<<"最大深度为："<<depth<<endl;
    */

    /*
    测试相同二叉树
    if(solution.isSameTree(root,root2))
        cout<<"相同"<<endl;
    else
        cout<<"不同"<<endl;
    */
    
    /*测试对称二叉树
    bool result2 = solution.isSymmetric_Recursion(root);
    if(result2)
        cout<<"duicheeng"<<endl;
    else
        cout<<"buduicheng"<<endl;
    return 0;
    */

    //测试翻转二叉树
    // cout<<"翻转后"<<endl;
    // solution.invertTreeByRecursionPostOrder(root2);
    // solution.print_tree(solution.levelOrder(root2));

    // int min_depth = solution.minDepthByIteration(root2);
    // cout<<"最小深度："<<min_depth<<endl;
    
    // cout<<"个数为："<<solution.countNodes_2(root);

    // int sum = solution.sumOfLeftLeaves(root);
    // cout<<"左叶子之和为"<<sum<<endl;

    // int bottom_left = solution.findBottomLeftValue(root2);
    // cout<<"最下层最左边的值为："<<bottom_left<<endl;

    // vector<int> vec{3,2,1,6,0,5};
    // TreeNode* root3 = solution.constructMaximumBinaryTree(vec);
    // solution.print_tree(solution.levelOrder(root3));

    // TreeNode* newTree = solution.mergeTrees(root,root2);
    // solution.print_tree(solution.levelOrder(newTree));

    // TreeNode* newTree = solution.searchBST_2(root,6);
    // solution.print_tree(solution.levelOrder(newTree));
    // if(solution.isValidBST(root2)){
    //     cout<<"有效"<<endl;
        
    // }
    // else
    //     cout<<"无效"<<endl;
    cout<<solution.getMinimumDifference(root2)<<endl;

    
}
 
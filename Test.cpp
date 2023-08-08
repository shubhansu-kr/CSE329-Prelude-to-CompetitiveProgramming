// Test Cpp

#include <bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void addNode(TreeNode *root, string &pos, int &val){
    int n = pos.length();
    TreeNode *p = root;
    for (int i = 0; i < n-1; ++i)
    {   
        if (pos[i] == 'L') {
            p = p->left;
        } 
        else {
            p = p->right;
        }
    }

    TreeNode *q = new TreeNode(val);
    if (pos[n-1] == 'L') {
        p->left = q;
    }
    else {
        p->right = q;
    }
    
    return;
}


int magicParentSum(int n, int root, string pos[], int val[]) {
    int sum = -1;

    TreeNode *base = new TreeNode(root);
    for (int i = 0; i < n-1; ++i)
    {
        addNode(base, pos[i], val[i]);
    }

    stack<TreeNode *> st;
    st.push(base);
    int flag = 0;
    while(st.size()) {
        TreeNode *p = st.top();
        st.pop();

        if (p->left && p->right) {
            st.push(p->left);
            st.push(p->right);

            int a = min(p->right->val, p->left->val);
            int b = max(p->left->val, p->right->val);
            if (b % a == 0) {
                flag = 1;
                sum += p->val;
            }
        }
        else if (p->left) {
            st.push(p->left);
        }
        else if (p->right) {
            st.push(p->right);
        }
    }
    
    if (flag) sum += 1;
    return sum;
}

int main () {
    int n = 8, root = 111;
    string pos[] = {"L", "R", "LL", "LR", "RL", "RR", "RRL"};
    int val[] = {141, 282, 72, 36, 92, 141, 99};

    cout << magicParentSum(n, root, pos, val);

    return 0;
}
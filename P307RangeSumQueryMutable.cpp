class NumArray {
public:
    struct SegmentTreeNode{
        int start, end, sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        SegmentTreeNode() : start(-1), end(-1), sum(0){};
        SegmentTreeNode(int i, int j){
            start = i;
            end = j;
            sum = 0;
        }
    };
    SegmentTreeNode* build(const vector<int> & nums, int i, int j){
        if(i>j) return NULL;
        SegmentTreeNode* node = new SegmentTreeNode(i, j);
        if(i==j) {
            node->sum = nums[i];
            return node;
        }
        node->left = build(nums, i, (i+j)/2);
        node->right = build(nums, (i+j)/2+1, j);
        node->sum = node->left->sum + node->right->sum;
        return node;
    }
    int query(SegmentTreeNode* root, int i, int j){
        if(root==NULL) return -1; 
        if(i>j|| i> root->end || j < root->start) return -1;//error : start > end
        if(root->start >= i && root->end <=j) return root->sum;
        int mid = root->start + (root->end - root->start)/2;
        if(i>mid) return query(root->right, i, j);
        else if(j<=mid) return query(root->left, i, j);
        return query(root->left, i, mid) + query(root->right, mid+1, j);
    }
    void modify(SegmentTreeNode* root, int i, int val){
        if(root==NULL) return;
        if(root->start==i && root->end==i) {
            root->sum = val;
            return;
        }
        int mid = root->start + (root->end - root->start)/2;
        if(i<=mid){
            modify(root->left, i, val);
        }else{
            modify(root->right, i, val);
        }
        int leftsum = query(root->left, root->left->start, root->left->end);
        int rightsum = query(root->right, root->right->start, root->right->end);
        root->sum = leftsum + rightsum;
    }
    SegmentTreeNode* root;
    
    NumArray(vector<int> &nums) {
       root = build(nums, 0, nums.size()-1);
    }
    
    void update(int i, int val) {
        modify(root, i, val);
    }

    int sumRange(int i, int j) {
        return query(root, i, j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

class NumArray {
public:
    int n;
    vector<int> data, tree;
    NumArray(vector<int> &nums) {
        n = nums.size();
        data.resize(n, 0);
        tree.resize(n+1, 0);
        for(int i=0; i<n; i++){
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {
        int diff = val - data[i];
        data[i] = val;
        for(int j=i+1; j<=n; j+=(j&(-j))){
            tree[j] += diff;
        }
    }

    int sumRange(int i, int j) {
        return sum(j+1)-sum(i);
    }
    
    int sum(int i){
        int s = 0;
        for(int j=i; j>0; j-=(j&(-j))){
            s+= tree[j];
        }
        return s;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

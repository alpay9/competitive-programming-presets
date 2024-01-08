#include <iostream>
#include <vector>
#define ll long long
// Alpay Nacar
using namespace std;

class segmentTree {
private:
    ll calculate_val(ll lval, ll rval) { // range sum
        return lval + rval;
    }
    struct treeNode {
        treeNode* left, * right;
        int start, end;
        ll val;
        int mid() { return (start + end) / 2; }
        treeNode(int start, int end, ll val, treeNode* left = nullptr, treeNode* right = nullptr) : start(start), end(end), val(val), left(left), right(right) {}
    };
    treeNode* build(const vector<int>& vals, int start, int end) {
        if (left == right) return new treeNode(start, start, vals[start]);
        treeNode* left = build(vals, start, (start + end) / 2);
        treeNode* right = build(vals, (start + end) / 2 + 1, end);
        return new treeNode(start, end, calculate_val(left->val, right->val), left, right);
    }
    void update(treeNode* ptr, int idx, int val) {
        if (ptr->left == ptr->right) {
            ptr->val = val;
            return;
        }
        update(((idx > ptr->mid()) ? ptr->right : ptr->left), idx, val);
        ptr->val = calculate_val(ptr->left->val, ptr->right->val);
    }
    ll get(treeNode* ptr, int start, int end) {
        if (ptr->start == ptr->end) return ptr->val;
        else if (end <= ptr->mid()) return get(ptr->left, start, end);
        else if (ptr->mid() < start) return get(ptr->right, start, end);
        else return get(ptr->left, start, ptr->mid()) + get(ptr->right, ptr->mid() + 1, end);
    }
    treeNode* root;
public:
    segmentTree(vector<int> vals) {
        root = build(vals, 0, vals.size() - 1);
    }
    void update(int idx, int val) {
        if (idx < root->start || root->end < idx) throw "index out of range";
        update(root, idx, val);
    }
    ll get(int start, int end) {
        return get(root, start, end);
    }
};
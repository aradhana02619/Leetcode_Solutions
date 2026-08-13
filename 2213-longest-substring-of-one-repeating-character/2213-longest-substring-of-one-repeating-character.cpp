struct Node {
    int max_len;
    char prefix_char, suffix_char;
    int prefix_len, suffix_len;
    int total_len;
};
class SegmentTree {
private:
    int n;
    vector<Node> tree;

   
    Node merge(const Node& left, const Node& right) {
        Node parent;
        parent.total_len = left.total_len + right.total_len;
        parent.prefix_char = left.prefix_char;
        parent.suffix_char = right.suffix_char;

       
        parent.prefix_len = left.prefix_len;
        parent.suffix_len = right.suffix_len;

        
        parent.max_len = max(left.max_len, right.max_len);

        
        if (left.suffix_char == right.prefix_char) {
            int cross_len = left.suffix_len + right.prefix_len;
            parent.max_len = max(parent.max_len, cross_len);

            if (left.prefix_len == left.total_len) {
                parent.prefix_len = left.total_len + right.prefix_len;
            }
            
            if (right.suffix_len == right.total_len) {
                parent.suffix_len = right.total_len + left.suffix_len;
            }
        }

        return parent;
    }

    
    void build(const string& s, int tree_idx, int start, int end) {
        if (start == end) {
            tree[tree_idx] = {1, s[start], s[start], 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * tree_idx, start, mid);
        build(s, 2 * tree_idx + 1, mid + 1, end);
        tree[tree_idx] = merge(tree[2 * tree_idx], tree[2 * tree_idx + 1]);
    }

    
    void update(int tree_idx, int start, int end, int target_idx, char val) {
        if (start == end) {
            tree[tree_idx] = {1, val, val, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (target_idx <= mid) {
            update(2 * tree_idx, start, mid, target_idx, val);
        } else {
            update(2 * tree_idx + 1, mid + 1, end, target_idx, val);
        }
        tree[tree_idx] = merge(tree[2 * tree_idx], tree[2 * tree_idx + 1]);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    void update_char(int idx, char val) {
        update(1, 0, n - 1, idx, val);
    }

    int get_max_length() {
        return tree[1].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int k = queryIndices.size();
        vector<int> result(k);
        SegmentTree st(s);

        for (int i = 0; i < k; ++i) {
            st.update_char(queryIndices[i], queryCharacters[i]);
            result[i] = st.get_max_length();
        }

        return result;
    }
};

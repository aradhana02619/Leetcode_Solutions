
class Solution {
public:
    struct Group {
        int start;
        int len;
    };

    struct SparseTable {
        vector<vector<int>> st;
        vector<int> lg;

        SparseTable(const vector<int>& a) {
            int n = a.size();

            lg.resize(n + 1);
            for (int i = 2; i <= n; i++)
                lg[i] = lg[i / 2] + 1;

            int k = lg[n] + 1;
            st.resize(k, vector<int>(n));

            st[0] = a;

            for (int j = 1; j < k; j++) {
                for (int i = 0; i + (1 << j) <= n; i++) {
                    st[j][i] = max(
                        st[j - 1][i],
                        st[j - 1][i + (1 << (j - 1))]
                    );
                }
            }
        }

        int query(int l, int r) {
            int len = r - l + 1;
            int k = lg[len];

            return max(
                st[k][l],
                st[k][r - (1 << k) + 1]
            );
        }
    };

    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries
    ) {
        int n = s.size();
        string relominexa = s;

        int ones = 0;

        for (char c : s)
            if (c == '1')
                ones++;

        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0') {
                    zeroGroups.back().len++;
                } else {
                    zeroGroups.push_back({i, 1});
                }
            }

            zeroGroupIndex[i] = zeroGroups.size() - 1;
        }

        if (zeroGroups.empty())
            return vector<int>(queries.size(), ones);

        vector<int> merge;

        for (int i = 0; i + 1 < zeroGroups.size(); i++) {
            merge.push_back(
                zeroGroups[i].len +
                zeroGroups[i + 1].len
            );
        }

        SparseTable st(merge);

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int left;

            if (zeroGroupIndex[l] == -1) {
                left = -1;
            } else {
                int id = zeroGroupIndex[l];

                left =
                    zeroGroups[id].len -
                    (l - zeroGroups[id].start);
            }

            int right;

            if (zeroGroupIndex[r] == -1) {
                right = -1;
            } else {
                int id = zeroGroupIndex[r];

                right =
                    r -
                    zeroGroups[id].start +
                    1;
            }

            int startGroup = zeroGroupIndex[l] + 1;

            int endGroup;

            if (s[r] == '1')
                endGroup = zeroGroupIndex[r];
            else
                endGroup = zeroGroupIndex[r] - 1;

            int startPair = startGroup;
            int endPair = endGroup - 1;

            int active = ones;

            if (s[l] == '0' &&
                s[r] == '0' &&
                zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {

                active = max(
                    active,
                    ones + left + right
                );
            }
            else if (startPair <= endPair) {

                active = max(
                    active,
                    ones + st.query(startPair, endPair)
                );
            }

            if (s[l] == '0' &&
                zeroGroupIndex[l] + 1 <= endGroup) {

                active = max(
                    active,
                    ones +
                    left +
                    zeroGroups[zeroGroupIndex[l] + 1].len
                );
            }

            if (s[r] == '0' &&
                zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {

                active = max(
                    active,
                    ones +
                    right +
                    zeroGroups[zeroGroupIndex[r] - 1].len
                );
            }

            ans.push_back(active);
        }

        return ans;
    }
};
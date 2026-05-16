class Solution {
public:
    typedef long long ll;
    typedef pair<int, ll> pp;

    int n;
    int lim;
    // Two segment trees: one for "up" scores (next must be larger),
    // one for "down" scores (next must be smaller).
    vector<ll> segInc; // stores up scores
    vector<ll> segDec; // stores down scores

    // generic point‑update for a given segment tree vector
    void updateVec(vector<ll>& tree, int ss, int se, int si, int pos, ll val) {
        if (pos < ss || pos > se)
            return;
        if (ss == se) {
            tree[si] = max(tree[si], val);
            return;
        }
        int mid = (ss + se) / 2;
        updateVec(tree, ss, mid, 2 * si + 1, pos, val);
        updateVec(tree, mid + 1, se, 2 * si + 2, pos, val);
        tree[si] = max(tree[2 * si + 1], tree[2 * si + 2]);
    }

    // generic range‑max query for a given segment tree vector
    ll queryVec(const vector<ll>& tree, int ss, int se, int si, int qs,
                int qe) const {
        if (qe < ss || qs > se)
            return 0;
        if (ss >= qs && se <= qe)
            return tree[si];
        int mid = (ss + se) / 2;
        ll v1 = queryVec(tree, ss, mid, 2 * si + 1, qs, qe);
        ll v2 = queryVec(tree, mid + 1, se, 2 * si + 2, qs, qe);
        return max(v1, v2);
    }

    long long maxAlternatingSum(vector<int>& nums, int k) {
        n = nums.size(), lim = *max_element(nums.begin(), nums.end());

        // initialise both segment trees
        segInc.assign(4 * (lim + 1), 0);
        segDec.assign(4 * (lim + 1), 0);

        ll res = 0;
        // two queues: one for up‑scores, one for down‑scores
        queue<pp> qInc, qDec;

        for (int i = 0; i < n; ++i) {
            // release elements that are now far enough (distance >= k)
            if ((int)qInc.size() == k) {
                auto cur = qInc.front();
                qInc.pop();
                updateVec(segInc, 0, lim, 0, cur.first, cur.second);
            }
            if ((int)qDec.size() == k) {
                auto cur = qDec.front();
                qDec.pop();
                updateVec(segDec, 0, lim, 0, cur.first, cur.second);
            }

            // query best continuation for each direction
            ll bestDown = queryVec(segInc, 0, lim, 0, 0,
                                   nums[i] - 1); // next must be larger, next-> i
            ll bestUp = queryVec(segDec, 0, lim, 0, nums[i] + 1,
                                 lim); // next must be smaller, next-> i

            ll downScore = nums[i] + bestDown; // next must be smaller
            ll upScore = nums[i] + bestUp;     // next must be larger

            res = max({res, downScore, upScore});

            // push current scores into the delayed queues
            qInc.emplace(nums[i], upScore);
            qDec.emplace(nums[i], downScore);
        }

        return res;
    }
};
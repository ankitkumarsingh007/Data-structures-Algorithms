class Solution {
public:
    bool got24(vector<double> arr) {
        int n = arr.size();
        if (n == 1) {
            return fabs(arr[0] - 24) < 1e-6;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                vector<double> next;
                // keep the unused numbers
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j)
                        next.push_back(arr[k]);
                }

                double a = arr[i], b = arr[j];

                // Try all 4 operations
                // Addition
                next.push_back(a + b);
                if (got24(next))
                    return true;
                next.pop_back();

                // Subtraction (a - b)
                next.push_back(a - b);
                if (got24(next))
                    return true;
                next.pop_back();

                // Multiplication
                next.push_back(a * b);
                if (got24(next))
                    return true;
                next.pop_back();

                // Division (avoid divide by zero)
                if (fabs(b) > 1e-9) {
                    next.push_back(a / b);
                    if (got24(next))
                        return true;
                    next.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> arr;
        for(int a:cards){
            arr.push_back(double(a));
        }

        return got24(arr);
    }
};
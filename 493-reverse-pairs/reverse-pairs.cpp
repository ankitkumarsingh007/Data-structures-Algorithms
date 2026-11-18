class Solution {
public:
    int merge(vector<int>& nums, int l, int mid, int r) {
        int n1 = mid - l + 1, n2 = r - mid;
        vector<int> arr1, arr2;

        for (int i = l; i <= mid; i++) {
            arr1.push_back(nums[i]);
        }
        for (int i = mid + 1; i <= r; i++) {
            arr2.push_back(nums[i]);
        }

        int i = 0, j = 0, k = l;
        int res = 0;
        // Reverse pair counting cannot be combined with the normal merge loop
        // because pointer movements are based on arr1[i] > arr2[j], whereas
        // reverse pairs require arr1[i] > 2 * arr2[j].
        // Advancing either pointer during merging can skip valid reverse pairs.
        // Hence, count reverse pairs in a separate pass before merging.
        for (int i = 0; i < n1; i++) {
            while (j < n2 && long(arr1[i]) > 2 * long(arr2[j])) {
                j++;
            }
            res += j;
        }

        j = 0;
        while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                nums[k++] = arr1[i++];
            } else {
                nums[k++] = arr2[j++];
            }
        }

        while (i < n1)
            nums[k++] = arr1[i++];
        while (j < n2)
            nums[k++] = arr2[j++];

        return res;
    }
    int mergeSort(vector<int>& nums, int l, int r) {
        int res = 0;
        if (l < r) {
            int mid = l + (r - l) / 2;

            res += mergeSort(nums, l, mid);
            res += mergeSort(nums, mid + 1, r);
            res += merge(nums, l, mid, r);
        }
        return res;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
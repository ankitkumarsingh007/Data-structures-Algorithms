class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, currPetrol = 0, ExtraRequired = 0;
        for (int i = 0; i < gas.size(); i++) {
            currPetrol += (gas[i] - cost[i]);
            if (currPetrol < 0) {
                ExtraRequired += currPetrol;
                currPetrol = 0;
                start = i + 1;
            }
        }

        if (currPetrol + ExtraRequired >= 0)
            return start;
        else
            return -1;
    }
};
/*
For two stones
Assume there are only two stones.
First stone values a1, b1 for Alice and Bob respectively.
Second stone values a2, b2 for Alice and Bob respectively.
Let S1 = a1 + b1 and S2 = a2 + b2

Stone #	Alice's score	Bob's score
1	a1 = S1 - b1	b1
2	a2 = S2 - b2	b2
Let F be the points difference between the two players: the sum of Alice's points minus the sum of Bob's points

If Alice picks stone #1:

F = a1 - b2 = (S1 - b1) - b2 = S1 - (b1 + b2)
If Alice picks stone #2:

F = a2 - b1 = (S2 - b2) - b1 = S2 - (b1 + b2)
b1 + b2 is fixed for given stone values. So Alice should pick a stone with maximum sum of values to maximize F and make it positive.

*/


class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        //sort on the basis of alice+bob 
        //than take there respective value  
        vector<vector<int>>stone;
        int n=bobValues.size();
        for(int i=0;i<n;i++){
            stone.push_back({aliceValues[i]+bobValues[i],aliceValues[i],bobValues[i]});
        }
        sort(stone.rbegin(),stone.rend()); 
        int alice=0,bob=0;
        for(int i=0;i<n;i++){
            if(i&1) bob+=stone[i][2];
            else alice+=stone[i][1];
        }
    return alice>bob?1:alice<bob?-1:0;
    }
};

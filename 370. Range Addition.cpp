https://baihuqian.github.io/2018-08-16-range-addition/
vector<long long> getModifiedArray(int length, vector<vector<int>> rounds) {
        vector<long long> arr(length, 0);
        for(int i = 0; i < rounds.size(); i++) {
            arr[rounds[i][0]] += rounds[i][2];
            if(rounds[i][1] < length - 1)
                arr[rounds[i][1] + 1] -= rounds[i][2];
        }
        for(int i = 1; i < length; i++) {
            arr[i] += arr[i - 1];
        }
    return arr;
}

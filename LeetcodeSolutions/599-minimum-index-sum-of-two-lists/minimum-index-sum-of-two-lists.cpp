class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    map<int,vector<string>> mp;
    int mini_index=30000;
    int n=list1.size();
    int m=list2.size();
    for (int i=0;i< n ;i++){
        for (int j =0;j<m ; j++){
            if (list1[i]==list2[j]){
                mp[i+j].push_back(list1[i]);
            }

        }
    }
    for (auto x: mp ){
        return x.second;
    }
    return {""};
        
    }
};
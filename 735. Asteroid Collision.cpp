class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        int n=asteroids.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(s.empty()) s.push(asteroids[i]);
            //RR OR LL OR LR
            else if(!s.empty() && ((s.top()>=0 && asteroids[i]>=0) || (s.top()<0 && asteroids[i]<0) || (s.top()<0 && asteroids[i]>=0)) ) s.push(asteroids[i]);
            //RL 
            else if(!s.empty() && s.top()>=0 && asteroids[i]<0){
                //EQUAL CASE -> ONLY ONCE POP AND BREAK 
                //UN-EQUAL CASE -> POP TILL POSSIBLE AND AT LAST PUSH CURRENT ASTEROID
                bool ok=0;
                while(!s.empty() && s.top()>0 && ((s.top()==-asteroids[i]) || (s.top()<-asteroids[i]))){
                    if(s.top()==-asteroids[i]) ok=1;
                    s.pop();
                    if(ok) break;
                }
                if(!ok && (s.empty() || s.top()<0)) s.push(asteroids[i]);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
    return ans;
    }
};

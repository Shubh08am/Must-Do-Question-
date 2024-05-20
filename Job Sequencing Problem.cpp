/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done. 
    static bool comp(Job a,Job b){
        return a.dead > b.dead  ; 
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        priority_queue<int>pq; 
        sort(arr,arr+n,comp);
        int start=arr[0].dead,job=0,p=0,i=0; 
        while(start>0){
            while(i<n && arr[i].dead>=start) pq.push(arr[i++].profit); 
            if(!pq.empty()){
                p+=pq.top();
                pq.pop();
                job++;
            }
            start--;
        }
    return {job,p};
    } 
};

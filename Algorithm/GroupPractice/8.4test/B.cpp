#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,q;
        cin>>n>>q;
        vector<int> birthdays(n+1);
        vector<int> last_day(n+1,-1);
        vector<int> last_week(n+1,-1);
        vector<int> week_count(n+1,0);
        vector<ll> friendship(n+1,0);
        int total_success=0;
        for(int i=1;i<=n;i++){
            cin>>birthdays[i];
        }
        while(q--){
            int day,person,value;
            cin>>day>>person>>value;
            if(last_day[person]==day){
                continue;
            }
            if(day==birthdays[person]){
                last_day[person]=day;
                total_success++;
                friendship[person]+=value;
            }
            else{
                int current_week=(day-1)/7+1;
                if(last_week[person]!=current_week){
                    last_week[person]=current_week;
                    week_count[person]=0;
                }
                if(week_count[person]<2){
                    week_count[person]++;
                    last_day[person]=day;
                    total_success++;
                    friendship[person]+=value;
                }
            }
        }
        cout<<total_success<<endl;
        for(int i=1;i<=n;i++){
            cout<<friendship[i];
            if(i!=n) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
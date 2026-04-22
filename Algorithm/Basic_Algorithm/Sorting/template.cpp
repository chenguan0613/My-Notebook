#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 选择排序
void selectionSort(vector<int>& nums){
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        int index=i;
        for(int j=i+1;j<n;j++){
            if(nums[j]<nums[j]) index=j;
        }
        swap(nums[i],nums[index]);
    }
}
// 插入排序
void insertionSort(vector<int>& nums){
    int n=nums.size();
    for(int i=1;i<n;i++){
        int j=i-1,key=nums[i];
        while(j>=0 && nums[j]>key){
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=key;
    }
}
//冒泡排序
void bubbleSort(vector<int>& nums){
    int n=nums.size();
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                swapped=true;
            }
        }
        if(!swapped) return;
    }
}
//并归排序
void mergeSort(vector<int>& nums,int left,int right){
    if(left>=right) return;
    int mid=left+(right-left)/2;
    mergeSort(nums,left,mid);
    mergeSort(nums,mid+1,right);
    merge(nums,left,mid,right);
}
void merge(vector<int>& nums,int left,int mid,int right){
    vector<int> temp(right-left+1);
    int i=left,j=mid+1,k=0;
    while(i<=mid && j<=right){
        if(nums[i]<nums[j]) temp[k++]=nums[i++];
        else temp[k++]=nums[j++];
    }
    while(i<=mid) temp[k++]=nums[i++];
    while(j<=right) temp[k++]=nums[j++];
    for(int i=0;i<temp.size();i++){
        nums[left+i]=temp[i];
    }
}
//快速排序
void quicksort(vector<int>& nums,int left,int right){
    if(left>=right) return;
    int pivot=partition(nums,left,right);
    quicksort(nums,left,pivot-1);
    quicksort(nums,pivot+1,right);
}
int partition(vector<int>& nums,int left,int right){
    int pivot=nums[left];
    int i=left+1,j=right;
    while(true){
        while(i<=right && nums[i]<=pivot) i++;
        while(j>=left && nums[j]>pivot) j--;
        if(i>=j) break;
        swap(nums[i],nums[j]);
    }
    swap(nums[left],nums[j]);
    return j;
}
bool cmp(const int& a,const int& b){
    return a>b; //从大到小
}

//自定义全排列
vector<int> nums={1,2,3};
vector<vector<int>> res;
void backtrack(vector<int>& path,vector<bool>& used){
    if(path.size()==nums.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]) continue;
        used[i]=true;
        path.push_back(nums[i]);
        backtrack(path,used);
        path.pop_back();
        used[i]=false;
    }
}

int main(){
    //快排就直接用sort(),默认从小到大
    vector<int> nums={5,2,9,1,5,6};
    sort(nums.begin(),nums.end());
    sort(nums.begin(),nums.end(),greater<int>());//从大到小
    //并归排序用stable_sort(),默认从小到大
    stable_sort(nums.begin(),nums.end());
    stable_sort(nums.begin(),nums.end(),greater<int>());//从大到小

    //也可以用lambda表达式自定义排序规则
    sort(nums.begin(),nums.end(),[](int a,int b){
        return a>b; //从大到小
    });
    //也可以自定义比较函数
    sort(nums.begin(),nums.end(),cmp);

    //获得全排列
    string s="abc";
    sort(s.begin(),s.end());
    while(next_permutation(s.begin(),s.end())){
        cout<<s<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, num,k;
	cin>>n>>k;
	std::vector<int> v;
	for(int i = 0; i<n;i++){
		cin>>num;
		v.push_back(num);
	}
	make_heap(v.begin(),v.end());
	int i = 0;
	cout<<k<<" Largest:"<<endl;
	for(auto a=v.begin();a != v.end() && i < k; a++,i++){
		cout<<*a<<endl;

	}
	i = 0;
	cout<<k<<" Smallest:"<<endl;
	for(auto a = v.rbegin(); a != v.rend() && i < k; a++,i++){
		cout<<*a<<endl;
	}
return 0;
}
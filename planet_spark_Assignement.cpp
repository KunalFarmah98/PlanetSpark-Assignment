    // Kunal Farmah
	// kunalfarmah98@gmail.com
	
	#include <bits/stdc++.h>
	using namespace std;

	#define RTIME ((double)clock()/(double)CLOCKS_PER_SEC)
	#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	#define Mod 1000000007
	
	typedef long long int ll;
	typedef unsigned long long int ull;
	typedef long double ld;
	typedef pair < int, int > pii;
	typedef pair < ll, ll > pll;
	typedef vector<int> vi;
	typedef vector<vi> vvi;
	typedef vector<bool> vb;
	typedef queue<int> qi;
	typedef complex<double> base;
	
	const ld pi = 3.141592653589793238462643383; 
	const double PI = 3.141592653589793;
	
	template<class T>
	using max_pq = priority_queue<T>;
	template<class T>
	using min_pq = priority_queue<T,vector<T>,greater<T>>; 
	
	
	vector<bool> primeSieve(int n){
	    std::vector<bool> p(n+1,false);
		p[0]=p[1]=0;
		p[2]=1;
	    for(int i=3;i<=n;i+=2){
	        p[i] = 1;
	    }
	    for(int i=3;i<=sqrt(n);i+=2){
	        if(p[i]){
	            for(int j=i*i;j<=n;j+=2*i){
	                p[j] = 0;
	            }
	        }
	    }
	    return p;
	}
	
	ll power(ll x, ll y, ll m){
		if(y==0)
			return 1;
		ll smallpower = power(x,y/2,m);
		smallpower = smallpower%m;
		smallpower = (smallpower*smallpower)%m;
		if(y&1)
	         return (x*smallpower)%m;
		else
			return (smallpower%m);
	}

int interplSearch(vector<int> a, int n, int x){ 
	    int beg = 0, end = n - 1; 
	    while (beg<=end && x>=a[beg] && x<=a[end]){ 
	        if (beg==end){ 
	        	// only one element left, then check it
	            if (a[beg]==x) return beg; 
	            return -1; 
	        } 
	        // The interploration formula that leads
	        // the search to take place from beg is x is lower
	        // and end if x is higher
	        int ind = beg + (((float)(end - beg) / 
	            (a[end] - a[beg])) * (x - a[beg])); 
	 
	        if (a[ind] == x) 
	            return ind; 
	  
	        // If x is larger, search in right half
	        if (a[ind] < x) 
	            beg = ind + 1; 
	  
	        // If x is smaller, search in left half
	        else
	            end = ind - 1; 
	    } 
	    return -1; 
	}  
	
	
	int main(){
		IOS;
		#ifndef ONLINE_JUDGE
   			freopen("input.txt", "r", stdin);
    		freopen("output.txt", "w", stdout);
		#endif
		
		int n,target;
		cin>>n;
		vector<int> a(n);

		for(int i=0; i<n; i++)cin>>a[i];
			
		cin>>target;

		int ind = interplSearch(a,n,target);
		if(ind!=-1){
			cout<<"Element found at index: "<<ind<<endl;
		}
		else cout<<"Element not found"<<endl;
	
		return 0;
	}
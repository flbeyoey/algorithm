#include<bits/stdc++.h>
using namespace std;
const int MX=4e5+5;
int n,m,tot;
int head[MX],num[MX],fu[MX];
struct cmp{
	bool operator()(int a,int b){
		return num[a]==num[b]?a>b:num[a]>num[b];
	}
};
map< pair <int,int> ,int> app,ap;
priority_queue<int,vector<int>,cmp> Q; 
int main(){ 
	int a,b,c,d,e,f;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a); fu[i]=a;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		for(int j=1;j<=a;j++){
			for(int k=1;k<=n;k++){
				if(c&&fu[k]!=c) continue;
				if(d&&!app[make_pair(fu[k],d)]) continue;
				if(e&&ap[make_pair(k,e)]) continue;
				Q.push(k);
			}
			if(!Q.empty()) goto loop;
			if(f&&Q.empty()) {printf("0 "); continue;}
			for(int k=1;k<=n;k++){
				if(c&&fu[k]!=c) continue;
				if(d&&!app[make_pair(fu[k],d)]) continue;
				Q.push(k);
			}
			if(Q.empty()) {printf("0 "); continue;}
			loop:int x=Q.top();
			num[x]++; 
			ap[make_pair(x,b)]=app[make_pair(fu[x],b)]=1;
			printf("%d ",x);
			while(!Q.empty()) Q.pop();
		}
		puts("");
	}
	return 0;
}

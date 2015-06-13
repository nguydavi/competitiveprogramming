#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const long long MMM = (long long)2e9;
long long s[55][55],dp[1<<13][13],ans;
int sr[15],save[15],N;

void floyd(){
    int i,j,k;
    for(k=0;k<=N;k++)
        for(i=0;i<=N;i++)
            for(j=0;j<=N;j++)
                s[i][j] = min(s[i][j],s[i][k]+s[k][j]);
}
int rec(int state,int id,int pre){
    if(state==0)
        return 0;
    if(dp[state][pre]!=-MMM)
        return dp[state][pre];
    int i,j;
    long long ret = -MMM,tmp;

    if(state==(1<<pre))
        ret = -s[sr[pre]][0] + save[pre];
    else
        for(i=0;i<=id;i++){
            if(pre!=i && (state&(1<<i))!=0){
                tmp = rec(state-(1<<pre),id,i);
                tmp -= s[sr[i]][sr[pre]];
                tmp += save[pre];
                ret = max(ret,tmp);
            }
        }

    ans = max(ans, ret-s[sr[pre]][0]);
    return dp[state][pre] = ret;
}

int main()
{
    int T,t,n,M,m,P,p,i,j,k,x,y;
    scanf(" %d",&T);
    while(T--){
        scanf(" %d %d",&N,&M);
        for(i=0;i<=N;i++)
            for(j=0;j<=N;j++)
                s[i][j] = MMM;
        while(M--){
            scanf(" %d %d %d.%d",&x,&y,&i,&j);
            s[x][y] = min(s[x][y],(long long)100*i+j);
            s[y][x] = min(s[y][x],(long long)100*i+j);
        }
        scanf(" %d",&P);
        int tmp[55],id = 0;
        memset(tmp,0,sizeof(tmp));
        memset(save,0,sizeof(save));
        for(p=1;p<=P;p++){
            scanf(" %d %d.%d",&sr[p],&i,&j);
            tmp[sr[p]] += i*100+j;
        }
        for(n=1;n<=N;n++){
            if(tmp[n]){
                id++;
                sr[id] = n;
                save[id] = tmp[n];
            }
        }

        /*
        for(int i=0;i<=id;++i)
            cout << sr[i] << " ";
        cout << endl;
        for(int i=0;i<=id;++i)
            cout << save[i] << " ";
        cout << endl;
        */

        floyd();
        int lim = 1<<(id+1);
        for(i=0;i<lim;i++)
            for(n=0;n<=id;n++)
                dp[i][n] = -MMM;
        s[0][0] = 0;
        ans = 0;
        /*
        for(i=0;i<=N;i++) {
            for(j=0;j<=N;j++)
                printf("%lld ",s[i][j]);
            printf("\n");
        }
        */
        rec((lim-1),id,0);

        for(int i=0;i<=id;++i) {
            for(int j=0;j<(1<<(id+1));++j)
                cout << dp[j][i] << " ";
            cout << endl;
        }

        if(ans==0)
            printf("Don't leave the house\n");
        else
            printf("Daniel can save $%lld.%02lld\n",ans/100,ans%100);
    }
   
    return 0;
}

#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define popb pop_back

#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

#define maxB 1005

int T, N;
int B;
int M[maxB];

ll done;
int last_index;

void proc(ll now) {
  last_index = -1;
  done = 0;
  int now_done = 0;
  REP(i, B) {
    done += (now + M[i]) / M[i];
    if (now % M[i] == 0) ++now_done;
  }
  ll done2 = done - now_done;
  if (done2 < N) {
    REP(i, B) {
      if (now % M[i] == 0 && ++done2 == N) last_index = i;
    }
  }
//  printf("now %lld, done %lld, last_index %d, last_time %d\n", now, done, last_index, last_time);
}

int main(){
  scanf("%d", &T);
  FOR(t, 1, T) {
    scanf("%d%d", &B, &N);
    REP(i, B) scanf("%d", M + i);
    ll left = -1, right = 300000000000000L;
//    ll left = -1, right = 30;
    while (right > left + 1) {
      ll now = (left + right) / 2;
      proc(now);
      if (done < N) left = now;
      else right = now;
    }
    proc(right);
    printf("Case #%d: %d\n", t, last_index + 1);
  }

  return 0;
}

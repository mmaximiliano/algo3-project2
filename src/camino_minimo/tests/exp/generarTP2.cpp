#include <bits/stdc++.h>
using namespace std;

int main(){
  int n = 100;
  int m = 3000;

  //escribo n, m
  cout<<n<<' '<<m<<'\n';

  int from = 1;
  int to = 100;
  random_device rand_dev;
  mt19937 generator(rand_dev());
  uniform_int_distribution<int> distr(from, to);

  //imrpimo costos
  for(int i = 0; i < n; i++){
    cout<<distr(generator)<<'\n';
  }

  set<pair<int,int>> caminos;
  int from2 = 1;
  int to2 = 60;
  random_device rand_dev2;
  mt19937 generator2(rand_dev());
  uniform_int_distribution<int> distr2(from2, to2);

  int from3 = 0;
  int to3 = n-1;
  random_device rand_dev3;
  mt19937 generator3(rand_dev());
  uniform_int_distribution<int> distr3(from3, to3);

  while(caminos.size() < m){
    int d = distr3(generator3);
    int h = distr3(generator3);
    //cout<<d<<' '<<h<<' '<<caminos.size()<<'\n';
    if(d==h) continue;
    if(caminos.count(make_pair(d,h)) == 0 && caminos.count(make_pair(h,d)) == 0){
      caminos.insert(make_pair(d,h));
      int l = distr2(generator2);
      cout<<d<<' '<<h<<' '<<l<<'\n';
    }
  }

}

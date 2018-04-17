# 1 "./PreProcess/main01.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./PreProcess/main01.cpp"
# 49 "./PreProcess/main01.cpp"
long long junger= 0, mid= 0, top= 0, bot= 0, result= 0, sum= 0, s= 0, t= 0, d= 0, l= 0, sp= 0, k= 0, x, y, n, m, test, r;
bool kt= false, t1= false, t2= false;
string s1, s2;

int tl[55], nh[55];
string st[55];

int a[100];






long main()
{


 cin >> test;

 while( test-- ){
  cin >> n;

  long sp;
  priority_queue<long long, vector<long long>, greater<long long> > h;
  for(long long (i)= (0); (i) < (n); (i)++){cin >> sp;
   h.push(sp);
  }

  s= 0;
  while( h.size() > 1 ){
   x= h.top(); h.pop();
   y= h.top(); h.pop();
   s+= x+y;
   h.push(x+y);
  }

  cout << s << endl;
 }



 return 0;
}

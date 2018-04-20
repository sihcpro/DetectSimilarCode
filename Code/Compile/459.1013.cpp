# 1 "./Process/459.1013.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/459.1013.cpp"




int main() {
    int l, N;
    cin >> l >> N;
    vector<int> vA(N);
    int minmin = l+1, minmax = l+1;
    for (int i=0; i<N; ++i) {
        cin >> vA[i];
        if (vA[i] < minmax) minmax = vA[i];
        if (l-vA[i] < minmax) minmax = l-vA[i];
        if (abs(vA[i]-l/2) < minmin) minmin = abs(vA[i]-l/2);
    }
    cout << l/2-minmin << " " << l-minmax;
 return 0;
}

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void merge(int* a, const int& n, int* b, const int& m, int* c)
{
    int ai = 0, bi = 0;
    for (int i = 0; i < n+m; i++)
    {
        if (ai == n) c[i] = b[bi++];
        else if (bi == m) c[i] = a[ai++];
        else if (a[ai] < b[bi]) c[i] = a[ai++];
        else c[i] = b[bi++];
    }
}

int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t; cin >> t;
    while (cin >> n >> m || t > 0){
        t--;
        int *a = new int [n], *b = new int[m], *c = new int[n+m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

	merge(a, n, b, m, c);
	int nc = n + m;;
        for(int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
    }
    return 0;
}

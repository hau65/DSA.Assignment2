#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template<class InputIterator, class OutputIterator>
OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result)
{
    while (first!=last) {
        *result = *first;
        ++result; 
        ++first;
    }
  return result;
}

void merge(int* a, const int& n, int* b, const int& m, int* c)
{
    int *pa = a, *pb = b, *pc = c;
    while(pa < a+n && pb < b+m)
        *pc++ = (*pa < *pb)? *pa++ : *pb++;
    copy(pa, a + n, pc);
    copy(pb, b + m, pc);
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

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int cnt = 0;
vector <vector<int>> all;
void Merqe(vector<int>& L, vector<int>& R, vector<int>& ar)
{
    int Ln = L.size(), Rn = R.size();
    int i = 0, j = 0, k = 0;
    while(i < Ln && j < Rn)
        ar[k++] = (L[i] < R[j])? L[i++] : R[j++];
    while (i < Ln) ar[k++] = L[i++];
    while (j < Rn) ar[k++] = R[j++];
}

void Merges0rt(vector<int>& ar)
{
    cnt++;
    int n = ar.size();
    if (n <= 1) return;

    int middle = round(float(n) / 2);
    vector<int> L(ar.begin(), ar.begin() + middle);
    vector<int> R(ar.begin() + middle, ar.end());
    all.push_back(L);
    all.push_back(R);

    Merges0rt(L);
    Merges0rt(R);
    Merqe(L,  R, ar);

    // OUTPUT
    cout << "[ ";
    for (int i = 0; i < n; i++) cout << ar[i] << " ";
    cout << "] \n";
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        ar.push_back(temp);
    }
    Merges0rt(ar);
}

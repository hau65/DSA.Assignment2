#include <iostream>
using namespace std;

int main()
{
    //INPUT
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];

    //SORT
    for (int i = 0; i < n - 1; i++){
        int small = i;
        for (int j = i + 1; j < n; j++){
            if (ar[small] > ar[j]){
                small = j;
            }
        }

        //PRINT
        if (small != i){
            swap(ar[i], ar[small]);
            for (const auto& i : ar){
                cout << i << " ";
            }
            cout << endl;
        }
    }
}

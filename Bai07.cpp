#include <iostream>
using namespace std;

int main()
{
    //INPUT
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];

    //OUTPUT
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            bool hasFlip = false;
            if (ar[j] > ar[j+1]){
                swap(ar[j], ar[j+1]);
                hasFlip = true;
            }
            if (hasFlip){
                for (const auto &i : ar)
                    cout << i << " ";
                cout << endl;
            }
        }
    }
}

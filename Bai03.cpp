#include <iostream>
#include <algorithm>
using namespace std;

int Partition(int64_t ar[], int head, int tail)
{
    int64_t pivot = ar[tail];
    int j = head - 1;
    for (int i = head; i <= tail - 1; i++){
        if (ar[i] < pivot){
            j++;
            swap(ar[i], ar[j]);
        }
    }
    j++;
    swap(ar[j], ar[tail]);
    return j;
}

void Quicks0rt(int64_t ar[], int head, int tail)
{
    if (head >= tail) return;
    int pivot = Partition(ar, head, tail);
    Quicks0rt(ar, head, pivot - 1);
    Quicks0rt(ar, pivot + 1, tail);
}

int main()
{
    // INPUT
    int n;
    cin >> n;
    int64_t ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    Quicks0rt(ar, 0, n-1);

    //OUTPUT
    int p = 0;
    if (ar[0] != 0 || n == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++){
        if (p + 1 != ar[i] && p != ar[i]){
            cout << p + 1;
            return 0;
        }
        p = ar[i];
    }
    if (n != 0) cout << ar[n-1] + 1;
}

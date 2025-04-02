#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int Partition(int ar[], int head, int tail)
{
    int pivot = ar[tail];
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

void Quicksort(int ar[], int head, int tail)
{
    if (head >= tail) return;
    int pivot = Partition(ar, head, tail);
    Quicksort(ar, head, pivot - 1);
    Quicksort(ar, pivot + 1, tail);
}

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    Quicksort(ar, 0, n-1);

    vector<int> minA;
    vector<int> maxA;
    int small = numeric_limits<int>::max();
    for (int i = 0; i < n - 1; i++)
    {
        int calc = ar[i+1] - ar[i];
        if (calc < small)
        {
            minA.clear();
            maxA.clear();
            small = calc;
        }
        if (small == calc)
        {
            minA.push_back(ar[i]);
            maxA.push_back(ar[i+1]);
        }

    }

    for (int i = 0; i < minA.size(); i++)
        cout << minA[i] << " " << maxA[i] << " ";
}

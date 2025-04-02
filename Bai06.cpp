#include <iostream>
using std::cout;
using std::cin;

void Output(int ar[], const int& n)
{
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << "\n";
}

int main()
{
    //INPUT
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    //SORT
    for (int i = 1; i < n; i++){
        int temp = ar[i];
        int j = i - 1;

        // Move til find an int lower than ar[i]
        while (j >= 0 && ar[j] > temp){
            ar[j+1] = ar[j];
            j--;
            Output(ar, n);
        }

        // Insert ar[i] into the vacanted spot
        ar[j+1] = temp;
        Output(ar, n);
    }
}

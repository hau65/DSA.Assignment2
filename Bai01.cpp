#include <iostream>
#include <vector>
using std::cout;
using std::cin;

void Output(int ar[], const int& n)
{
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << "\n";
}
struct Point
{
    int x, y, z;
    Point()
    {
        cin >> x;
        cin >> y;
        cin >> z;
    }
};

int main()
{
    //INPUT
    int n;
    cin >> n;
    std::vector<Point> p;
    for (int i = 0; i < n; i++)
    {
        Point temp;
        p.push_back(temp);
    }
    //SORT
    for (int i = 1; i < p.size(); i++)
    {
        Point temp = p[i];
        int j = i - 1;
        while (j >= 0 && p[j].x >= temp.x)
        {
            if (p[j].x == temp.x)
            {
                if (p[j].y > temp.y) break;
                if (p[j].y == temp.y && p[j].z < temp.z) break;
            }
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = temp;
    }
    for (const auto& i : p) cout << i.x << " " << i.y << " " << i.z << "\n";
}

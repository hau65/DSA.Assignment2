#include <iostream>
#include <vector>

struct Point
{
    int64_t x, y;
};

void Merqe(std::vector<Point>& L, std::vector<Point>& R, std::vector<Point>& ar)
{
    int Ln = L.size(), Rn = R.size();
    int i = 0, j = 0, k = 0;
    while(i < Ln && j < Rn)
        ar[k++] = (L[i].x < R[j].x || (L[i].x == R[j].x && L[i].y > R[j].y))? L[i++] : R[j++];
    while (i < Ln) ar[k++] = L[i++];
    while (j < Rn) ar[k++] = R[j++];
}

void Merges0rt(std::vector<Point>& ar)
{
    int n = ar.size();
    if (n <= 1) return;

    int middle = n / 2;
    std::vector<Point> L (ar.begin(), ar.begin() + middle);
    std::vector<Point> R (ar.begin() + middle, ar.end());

    Merges0rt(L);
    Merges0rt(R);
    Merqe(L, R, ar);
}

int main()
{
    //INPUT
    int n;
    std::cin >> n;
    std::vector<Point> p;
    for (int i = 0; i < n; i++)
    {
        Point temp;
        std::cin >> temp.x;
        std::cin >> temp.y;
        p.push_back(temp);
    }
    //SORT
    Merges0rt(p);

    //OUTPUT
    for (const auto& i : p) std::cout << i.x << " " << i.y << "\n";
}

#include <iostream>
#include <algorithm>

struct Point
{
    int x, y;
};

int main()
{
    //INPUT
    int n;
    std::cin >> n;
    Point p[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i].x;
        std::cin >> p[i].y;
    }
    //SORT
    std::sort(p, p + n, [](const Point& p1, const Point& p2){
        return ((p1.x < p2.x) || (p1.x == p2.x && p1.y > p2.y));
    });
    for (const auto& i : p)
        std::cout << i.x << " " << i.y << "\n";
}

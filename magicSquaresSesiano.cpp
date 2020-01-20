#include<iostream>
#include<vector>

int map[100][100];

int main()
{
    int n{};
    std::cout << "n次魔方陣の次数を入力して,エンターを押してください" << "\n";

    signed errcnt{};
    do
    {
        if(errcnt)
        std::cout << "3 <= n <= 99です" << "\n";
 
        std::cin >> n;
        ++errcnt;
    }while(n <= 2 || n > 99);

    int x,y;

    x = (1+n)/2;
    y = 1;

    map[y][x] = 1;

    for(int i = 2; i <= n*n; ++i)
    {
        int nx, ny;
        nx = x + 1; ny = y - 1;

        if(nx > n)
            nx = 1;

        if(ny < 1)
            ny = n;

        if(map[ny][nx] != 0)
        {
            nx = x;
            ny = y + 1;
        }
        map[ny][nx] = i;
        x = nx;
        y = ny;
    }

    signed flag{};
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
    {
        if(map[i][j]<10)
            flag=1;
        std::cout << "|";
        if(flag)
        {
            std::cout << " ";
            flag=0;
        }
        std::cout << map[i][j];
        if(j == n)
        std::cout << "|" << "\n";
    }
}

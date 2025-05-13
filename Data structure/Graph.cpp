#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
class graph
{
private:
    int G[10][10];
    int visited[10];
    int size;

public:
    graph()
    {
        for (int i = 0; i < 10; i++)
            visited[i] = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
                G[i][j] = 0;
        }
        size = 0;
    }
    void setSize()
    {
        int n;
        cout << "Size: ";
        cin >> n;
        size = n;
    }
    void setmatrix()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                cin >> G[i][j];
        }
    }
    void DFS(int index)
    {
        visited[index] = 1;
        cout << index << " ";
        for (int i = 0; i < size; i++)
        {
            if (visited[i] == 0 and G[index][i] == 1)
                DFS(i);
        }
    }
    void nrec_DFS(int index)
    {
        for (int i = 0; i < 10; i++)
            visited[i] = 0;
        stack<int> s;
        s.push(index);
        while (!s.empty())
        {
            int ver = s.top();
            s.pop();
            if (visited[ver] == 0)
            {
                visited[ver] = 1;
                cout << ver << " ";
                for (int i = 0; i < size; i++)
                {
                    if (visited[i] == 0 and G[ver][i] == 1)
                        s.push(i);
                }
            }
        }
    }
    void nrec_BFS(int index)
    {
        for (int i = 0; i < 10; i++)
            visited[i] = 0;
        queue<int> q;
        q.push(index);
        while (!q.empty())
        {
            int ver = q.front();
            q.pop();
            if (visited[ver] == 0)
            {
                visited[ver] = 1;
                cout << ver << " ";
                for (int i = 0; i < size; i++)
                {
                    if (visited[i] == 0 and G[ver][i] == 1)
                        q.push(i);
                }
            }
        }
    }
};
int main()
{
    graph g;
    g.setSize();
    g.setmatrix();
    g.DFS(0);
    cout << endl;
    g.nrec_DFS(0);
    cout << endl;
    g.nrec_BFS(0);
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *parent;
    int x, y;
    int cost;
    int level;
    int matrix[3][3];
};

Node *child(int state[3][3], Node *par, int cost, int level, int x, int y, int newx, int newy)
{
    Node *tem = new Node();
    memcpy(tem->matrix, state, sizeof(tem->matrix));
    swap(tem->matrix[x][y], tem->matrix[newx][newy]);
    tem->x = newx;
    tem->y = newy;
    tem->cost = cost;
    tem->level = level;
    tem->parent = par;
    return tem;
}
struct comp
{
    bool operator()(const Node *lhs, const Node *rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};
int Cost(int initstate[3][3], int fstate[3][3])
{
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (initstate[i][j] != fstate[i][j] && initstate[i][j] != 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int row[4] = {1, 0, -1, 0};
int col[4] = {0, 1, 0, -1};
void printpath(Node *cur)
{
    if (cur != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << cur->matrix[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        printpath(cur->parent);
    }
}
void print(int mat[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
int r = 0;
bool solve(int initstate[3][3], int fstate[3][3], int x, int y)
{
    priority_queue<Node *, vector<Node *>, comp> pq;
    int c = Cost(initstate, fstate);
    Node *start = child(initstate, NULL, c, 0, x, y, x, y);
    pq.push(start);
    while (!pq.empty())
    {
        Node *cur = pq.top();
        pq.pop();
        if (cur->cost == 0)
        {
            printpath(cur);
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cur->x + row[i];
            int ny = cur->y + col[i];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
            {
                Node *ch = child(cur->matrix, cur, cur->cost, cur->level + 1, x, y, nx, ny);
                ch->cost = Cost(ch->matrix, fstate);
                pq.push(ch);
            }
        }
    }
    return false;
}

int main()
{
    int state[3][3], x, y;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> state[i][j];
            if (state[i][j] == 0)
            {
                x = i, y = j;
            }
        }
    }
    int fstate[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}};
    solve(state, fstate, x, y);
}

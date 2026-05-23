#include <bits/stdc++.h>
using namespace std;


//ME
class DisjointSet // union by size
{
private:
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void add(int u, int v)
    {
        int ultimateParent_u = findParent(u);
        int ultimateParent_v = findParent(v);
        if (ultimateParent_u == ultimateParent_v)
            return;
        if (size[ultimateParent_u] < size[ultimateParent_v])
        {
            parent[ultimateParent_u] = ultimateParent_v;
            size[ultimateParent_v] += size[ultimateParent_u];
        }
        else
        {
            // if same then attach v-->u
            parent[ultimateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultimateParent_v];
        }
    }

    int sizeOf(int node)
    {
        return size[findParent(node)];
    }
};

int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    DisjointSet st(n * n);
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int r = i + dir[k][0];
                    int c = j + dir[k][1];
                    if (r < 0 || r >= n || c < 0 || c >= n)
                        continue;
                    if (grid[r][c] == 1)
                    {
                        st.add(i * n + j, r * n + c);
                    }
                }
            }
        }
    }
    int maxSize = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                int size = 0;
                unordered_set<int> parents; // for storing parent of 4 directional islands
                for (int k = 0; k < 4; k++)
                {
                    int r = i + dir[k][0];
                    int c = j + dir[k][1];
                    if (r < 0 || r >= n || c < 0 || c >= n)
                        continue;
                    int parent = st.findParent(r * n + c);
                    if (grid[r][c] == 1 && parents.find(parent) == parents.end())
                    {
                        size += st.sizeOf(r * n + c);
                        parents.insert(parent);
                    }
                }
                maxSize = max(maxSize, size + 1);
            }
            else
                maxSize = max(maxSize, st.sizeOf(i * n + j));
        }
    }
    return maxSize;
}





int main()
{
}
class Solution 
{
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool validStep(vector<vector<char>>& maze, int& x, int& y)
    {
        if(x<0 || y<0 || x>= maze.size() || y>=maze[0].size() || maze[x][y]=='+') 
            return false;
        return true;
    }

    bool isBorder(vector<vector<char>>& maze, int x, int y)
    {
        if(x==0 || y==0 || x==maze.size()-1 || y==maze[0].size()-1) 
            return true;
        return false;
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int m = maze.size();
        int n = maze[0].size();
        
        queue<pair<int, int>> qu;
        qu.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps =0;
        while(!qu.empty())
        {
            int size = qu.size();
            while(size--)
            {
                int idx = qu.front().first;
                int idy = qu.front().second;
                qu.pop();
                for(int i=0; i<4; i++)
                {
                    int newX = idx + dx[i];
                    int newY = idy + dy[i];
                    if(validStep(maze, newX, newY))
                    {
                        maze[newX][newY] = '+';
                        if(isBorder(maze, newX, newY)) 
                            return steps+1;
                        else qu.push({newX, newY});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
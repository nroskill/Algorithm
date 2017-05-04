/**
 * https://leetcode.com/problems/01-matrix/
 * By Nroskill
 * runtime 236 ms
 * language cpp
 */

class Solution {
public:
    void search(vector<vector<int>>& matrix, queue<pair<int, int>>& q) {
        int x = q.front().first;
        int y = q.front().second;
        int curDis = matrix[x][y] + 1;
        if(x - 1 >= 0 && matrix[x - 1][y] > curDis) {
            matrix[x - 1][y] = curDis;
            q.push(pair<int, int>(x - 1, y));
        }
        if(x + 1 < matrix.size() && matrix[x + 1][y] > curDis) {
            matrix[x + 1][y] = curDis;
            q.push(pair<int, int>(x + 1, y));
        }
        if(y - 1 >= 0 && matrix[x][y - 1] > curDis) {
            matrix[x][y - 1] = curDis;
            q.push(pair<int, int>(x, y - 1));
        }
        if(y + 1 < matrix[x].size() && matrix[x][y + 1] > curDis) {
            matrix[x][y + 1] = curDis;
            q.push(pair<int, int>(x, y + 1));
        }
        q.pop();
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0)
                    q.push(pair<int, int>(i, j));
                else
                    matrix[i][j] = 0x7fffffff;
            }
        while(!q.empty()) {
            search(matrix, q);
        }
        return matrix;
    }
};
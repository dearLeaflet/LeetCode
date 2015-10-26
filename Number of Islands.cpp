/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically. You may assume all four edges of the grid are all 
surrounded by water
*/#include "lib.h"
using namespace std;
class Solution {
public:
	int numIslands(vector<vector<char>>& grid){
		if (grid.size() == 0 || grid[0].size() == 0) return 0;
		int islandsNum = 0;
		for (size_t x = 0; x < grid.size(); x++){
			for (size_t y = 0; y < grid[0].size(); y++){
				if (grid[x][y] == '1'){
					DFS(grid, x, y);
					++islandsNum;
				}
			}
		}
		return islandsNum;
	}
private:
	int DFS(vector<vector<char>>& gridChild, int x, int y){
		if (x < 0 || x >= gridChild.size() || y < 0 || y >= gridChild[0].size()) return 0;
		if (gridChild[x][y] == '1'){
			gridChild[x][y] = '0';
			DFS(gridChild, x, y - 1);
			DFS(gridChild, x, y + 1);
			DFS(gridChild, x - 1, y);
			DFS(gridChild, x + 1, y);
		}
		return 0;
	}
};
//void main()
//{
//	vector<vector<char>> v{ { 1 } };
//	Solution s;
//	cout << s.numIslands(v) << endl;
//}
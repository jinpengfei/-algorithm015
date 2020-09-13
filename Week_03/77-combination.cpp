
class Solution {
    public:
	void dfs(int n, int k, int index, vector<int>& path, vector<vector<int>>& res) {
		if (path.size() == k) {
			res.push_back(path);
			return;
		}
		for (int i = index; i <= n - (k - path.size()) + 1; ++i) {
			path.push_back(i);
			dfs(n, k, i + 1, path, res);
			path.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		if (k <= 0 || n < k) {
			return res;
		}
		vector<int> path;
		dfs(n, k, 1, path, res);
		return res;
	}
};
/*
隐藏条件：1.组合不分先后顺序
难点：k值>2时:肉眼组合不出来，所以得找到通用性。所以要采用什么结构呢？需要演化找到循环结构
方式：借助工具，递归树；全局考虑；回溯法
搜索起点的上界 + 接下来要选择的元素个数 - 1 = n
接下来要选择的元素个数 = k - path.size()
搜索起点的上界 = n - (k - path.size()) + 1
*/

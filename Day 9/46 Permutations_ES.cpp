class Solution {
  public:
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> result;
      int N = nums.size();
      int visited[N];
      for (int i = 0; i < N; i++) visited[i] = 0;
      vector < int > ds;
      permuteUtil(nums, result, visited, ds);
      return result;
    }
  private:
    void permuteUtil(vector < int > & nums, vector < vector < int >> & result, int visited[], vector < int > & ds) {
      if (ds.size() == nums.size()) {
        result.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!visited[i]) {
          visited[i] = 1;
          ds.push_back(nums[i]);
          permuteUtil(nums, result, visited, ds);
          ds.pop_back();
          visited[i] = 0;
        }
      }
    }
};
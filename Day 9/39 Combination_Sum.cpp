class Solution {
  public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> result;
      vector < int > ds;
      combinationSumUtil(candidates, ds, result, 0, target);//util function passing result vector as reference
      return result;
    }
  private:
    void combinationSumUtil(vector < int > & candidates, vector < int > & ds, vector < vector < int >> & result, int i, int target) {

      if (target == 0) {
        result.push_back(ds);
        return;
      }

      if (i == candidates.size()) {
        return;
      }

      if (candidates[i] <= target) {
        target -= candidates[i];
        ds.push_back(candidates[i]);
        combinationSumUtil(candidates, ds, result, i, target);
        //the below two steps are backtracking 
        target += candidates[i];
        ds.pop_back();
      }
      //skip the elements
      combinationSumUtil(candidates, ds, result, i + 1, target);
    }

};
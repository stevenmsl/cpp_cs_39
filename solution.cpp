#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol77;
using namespace std;

/*takeaways
  - refer to question 77 for how to generate combinations
  - sort the numbers in ascending order
  - {2, 3, 6, 7}
    - pick 2 all the way. After two recursive calls we get {2,2,2}
      - we can't continue as nothing you can pick to
        add the sum to 7 - abandon this route
    - pick 2, 2, and then 3 we get {2,2,3} which the numbers add up
      to
    - pick 3 and bigger
      - no solution
    - pick 4 and bigger
      - no solution
    - pick 7 and bigger. We get {7}

 */

void Solution::_find(
    vector<int> &candidates,
    int start, int target,
    vector<int> &combination, vector<vector<int>> &result)
{
  if (target == 0)
  {
    result.push_back(combination);
    return;
  }
  int n = candidates.size();
  for (auto picked = start; picked < n; picked++)
  {
    if (candidates[picked] > target)
      break;
    combination.push_back(candidates[picked]);
    /* the same repeated number can be chosen
       unlimited times
    */
    _find(candidates, picked, target - candidates[picked], combination, result);
    combination.pop_back();
  }
}

vector<vector<int>> Solution::find(vector<int> &candidates, int target)
{
  auto result = vector<vector<int>>();
  auto c = vector<int>();
  /* start from the smaller numbers */
  sort(begin(candidates), end(candidates));

  _find(candidates, 0, target, c, result);

  return result;
}

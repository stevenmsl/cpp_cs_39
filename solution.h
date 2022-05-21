
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol77
{
  class Solution
  {
  private:
    void _find(
        vector<int> &candidates,
        int start, int target,
        vector<int> &combination, vector<vector<int>> &result);

  public:
    vector<vector<int>> find(vector<int> &candidates, int target);
  };
}
#endif
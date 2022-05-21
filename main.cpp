#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol77;

/*
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
*/

tuple<vector<int>, int, vector<vector<int>>>
testFixture1()
{
  auto candidates = vector<int>{2, 3, 6, 7};
  auto output = vector<vector<int>>{
      {7},
      {2, 2, 3}};
  return make_tuple(candidates, 7, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.find(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  return 0;
}
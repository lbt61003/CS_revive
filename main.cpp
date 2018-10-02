#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    
    void subsetsDispatcher(vector<int> &A, vector<int> &subset,
                         size_t index, vector<vector<int>> &res)
    {
        if (index == A.size()) {
            res.push_back(subset);
            return;
        }
        
        if (subset.empty() || subset.back() != A[index]) {
        subsetsDispatcher(A, subset, index+1, res);
        }
        subset.push_back(A[index]);
        subsetsDispatcher(A, subset, index+1, res);
        subset.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int> &A)
    {
        vector<int> subset;
        vector<vector<int>> res;
        subsetsDispatcher(A, subset, 0, res);
        //print(res);
        return res;
    }
    
    int longestSubSeq(vector<int> &P, vector<int> &Q)
    {
        
    }
    
    void permRec(vector<int> &P, size_t start, vector<vector<int>> &Res)
    {
        if (start == P.size()-1)
        {
            Res.push_back(P);
            return;
        }
        
        for (int i = start; i<P.size(); ++i) {
            std::swap(P[start], P[i]);
            permRec(P, start+1, Res);
            std::swap(P[i], P[start]);
        }
    }
    
    void perm(vector<int> &P, vector<vector<int>> &Res)
    {
        permRec(P, 0, Res);
        
    }
};

template <typename T>
void print(vector<vector<T>> &vec2D)
{ 
    using namespace std;
    for (auto &row: vec2D) {
        cout << "[";
        for (auto &colVal: row) {
            std::cout << colVal << " ";
        }
        cout << "]";
        cout << std::endl;
    }
}


// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  vector<int> A ={3,1,2};
    sort(A.begin(), A.end());
    Solution sol;
    vector<vector<int>> res;
   //vector<vector<int>> res = sol.subsets(A);
   //sort(res.begin(), res.end());
    sol.perm(A, res);
    print(res);
  return 0;
}


/* 
Your previous Python 2 content is preserved below:

# This is a sandbox to experiment with CoderPad's execution capabilities.
# It's a temporary, throw-away session only visible to you.

def say_hello():
    print 'Hello, World'

for i in xrange(5):
    say_hello()

 */

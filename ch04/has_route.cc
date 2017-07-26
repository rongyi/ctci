#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Graph {
public:
  void addNode(int i) {
    vertices_.insert(i);
  }
  void addEdge(int from, int to) {
    if (edges_.find(from) == edges_.end()) {
      edges_[from] = std::vector<int>{to};
    } else {
      edges_[from].push_back(to);
    }
  }
  bool hasRoute(int from, int to) {
    std::unordered_map<int, bool> visited_map;
    std::queue<int> q;
    q.push(from);
    while (!q.empty()) {
      int cur = q.front();
      if (cur == to) {
        return true;
      }
      q.pop();
      visited_map[cur] = true;
      if (edges_.find(cur) != edges_.end()) {
        for (auto &n : edges_[cur]) {
          if (visited_map.find(n) == visited_map.end())
            q.push(n);
        }
      }

    }

    return false;
  }

private:
  std::unordered_set<int> vertices_;
  std::unordered_map<int, std::vector<int>> edges_;
};

int main() {
  Graph g;
  for (int i = 0; i < 6; ++i) {
    g.addNode(i);
  }
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  cout<<g.hasRoute(5,4)<<endl; // false
  cout<<g.hasRoute(5,1)<<endl; // true

  return 0;
}

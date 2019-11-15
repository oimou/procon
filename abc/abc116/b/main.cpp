/**
 * https://stackoverflow.com/questions/51138794/how-to-use-boost-make-label-writer-to-write-edge-properties
 */
#include "all.h"

using namespace std;

struct VertexProps
{
  string name;
};
struct EdgeProps {
  string name;
};

typedef std::pair<int, int> Edge;
typedef boost::adjacency_list<
  boost::listS,
  boost::vecS,
  boost::directedS,
  VertexProps,
  EdgeProps
> Graph;

int main () {
  auto f = [](int x) { return (x % 2 == 0 ? x / 2 : 3 * x + 1); };

  Graph g;
  map<int, Graph::vertex_descriptor> v;
  map<Edge, Graph::edge_descriptor> e;

  for (int s = 1; s <= 100; s++) {
    map<Edge, bool> duplicate_edges;

    v.insert(make_pair(s, add_vertex(g)));
    g[v.at(s)].name = to_string(s);

    int a = s;
    while (true) {
      int prev = a;
      a = f(a);

      if (!v.count(a)) {
        v.insert(make_pair(a, add_vertex(g)));
        g[v.at(a)].name = to_string(a);
      }

      Edge new_edge = make_pair(prev, a);

      if (!e.count(new_edge)) {
        e.insert(
          make_pair(
            new_edge,
            add_edge(v.at(prev), v.at(a), g).first
          )
        );
      }

      // duplicate!
      if (duplicate_edges.count(new_edge)) {
        e.insert(
          make_pair(
            new_edge,
            add_edge(v.at(prev), v.at(a), g).first
          )
        );
        break;
      }

      duplicate_edges.insert(make_pair(new_edge, true));
    }
  }

  std::ofstream file("collatz.dot");
  write_graphviz(
    file,
    g,
    make_label_writer(get(&VertexProps::name, g)),
    make_label_writer(get(&EdgeProps::name, g))
  );
}

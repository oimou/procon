#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/assign/list_of.hpp>

using namespace std;

struct myGraphProperty
{
  std::string name;
};

struct myVertexProperty
{
 std::string name;
};

struct myEdgeProperty
{
  std::string name;
};

using Graph = boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  myVertexProperty,
  myEdgeProperty,
  myGraphProperty
>;

/**
 * main
 */
int main () {
  int N, M, K;
  cin >> N >> M >> K;

  Graph graph;
  using Vertex = decltype(graph)::vertex_descriptor;
  using Edge = decltype(graph)::edge_descriptor;

  vector<Vertex> vertices;
  map<pair<int, int>, Edge> edges;

  for (int i = 0; i <= N; i++) {
    Vertex v = boost::add_vertex(graph);
    vertices.push_back(v);
  }

  for (int i = 0; i < M; i++) {
    int A, B;
    scanf("%d %d", &A, &B);

    Vertex va = vertices.at(A);
    Vertex vb = vertices.at(B);
    Edge e = std::get<0>(boost::add_edge(va, vb, graph));
    edges.insert(make_pair(make_pair(A, B), e));
  }

  for (int i = 0; i < K; i++) {
    int C, D;
    scanf("%d %d", &C, &D);

    Vertex vc = vertices.at(C);
    Vertex vd = vertices.at(D);

    try {
      Edge e = edges.at(make_pair(C, D));
      boost::remove_edge(e, graph);
    } catch(std::out_of_range&) {
      // do nothing
    }

    try {
      Edge e = edges.at(make_pair(D, C));
      boost::remove_edge(e, graph);
    } catch(std::out_of_range&) {
      // do nothing
    }
  }

  for (int i = 1; i <= N; i++) {
    Vertex from = vertices.at(i);
    int n_friends = 0;

    for (int j = 1; j <= N; j++) {
      if (i == j) continue;

      Vertex to = vertices.at(j);

      // TODO

      n_friends++;
    }

    printf("%d", n_friends);

    if (i != N) printf(" ");
  }

  printf("\n");
}

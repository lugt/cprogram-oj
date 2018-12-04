//
// Created by xc5 on 20/11/2018.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Vertex {
public:
  int indexNo;
  bool hasEnterQueue;
  int early;
  int later;

  Vertex(int indexNo) {
    this->indexNo = indexNo;
    this->hasEnterQueue = false;
    early = -1;
    later = 0x7FFFF;
  }
  void updateEarly(int parentEarly, int edgeValue) {
    int newEarly = parentEarly + edgeValue;
    if (newEarly > this->early)
      this->early = newEarly;
  }
  void updateLater(int childLater, int edgeValue) {
    int newLater = childLater - edgeValue;
    if (newLater < this->later)
      this->later = newLater;
  }
};


class Graph {
public:
  vector<Vertex> vertexes;
  int n;
public:
  void readVertexes() {
    cin >> n;
  }
  void readAdjMatrix() {
    //read the adjacent info into this->adjMat
    int edges;
    cin >> edges;
    int i=0;
    int s, t, w;
    for(; i<edges; ++i) {
      cin >> s >> t >> w;
      adjMat[s][t] = w;
    }
  }

  void main() {
    readVertexes();
    readAdjMatrix();
    findEarly();
    findLater();
  }
};


int main() {
  int t=1;
  //cin >> t;
  while (t--) {
    Graph g;
    g.main();
  }
  return 0;
}
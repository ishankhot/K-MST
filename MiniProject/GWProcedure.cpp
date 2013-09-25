#include <boost/graph/graphml.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>
#include <iostream>
#include<fstream>


class Vertex {
public:
	std::string color;

	Vertex(){
		color = "";
	}

	Vertex(std::string s){
		color = s;
	}

	std::string get(){
		return color;
	}
};

class Edge {
public:
	std::string name;
	double weight;

	Edge(){
		name = "";
		weight = 0.0;
	}

	Edge(std::string s, double d){
		name = s;
		weight = d;
	}
};

typedef boost::adjacency_list<boost::vecS,boost::vecS,boost::undirectedS, Vertex,Edge> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor CVertex;
typedef boost::graph_traits<Graph>::edge_descriptor CEdge;

int main() {
	Graph g;
	std::ifstream infile;
	infile.open("test.gml",std::ios::in);
	boost::dynamic_properties dp;
	dp.property("color", boost::get(&Vertex::color, g));
	dp.property("weight", boost::get(&Edge::weight,g));
	boost::read_graphml(infile,g,dp);
	infile.close();
	boost::graph_traits<Graph>::edge_iterator e = boost::edges(g).first;
	e++;
	e++;
	e++;
	e++;
	e++;
	e++;
	CEdge tp = *e;
	std::cout<<g[tp].name;
	return 0;
}

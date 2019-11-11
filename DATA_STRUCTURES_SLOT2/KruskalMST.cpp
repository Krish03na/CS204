#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int x;
	int y;
	int weight;
};

struct Graph{
	int v;
	int e;
	struct Edge* edge;
};


struct Graph* creategraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->e = E;
	graph->v = V;
	graph->edge = new Edge[E];
	return graph;
}

struct subset{
	int parent;
	int Rank;
};

int Find(struct subset Subsets[], int i){
	if(Subsets[i].parent != i) Subsets[i].parent = Find(Subsets, Subsets[i].parent);
	return Subsets[i].parent;
}


void UnionOfSubsets(struct subset Subsets[], int x, int y){
	int x1 = Find(Subsets, x);
	int y1 = Find(Subsets, y);

	if(Subsets[x1].Rank < Subsets[y1].Rank){
		Subsets[x1].parent = y1;
	}else if(Subsets[x1].Rank > Subsets[y1].Rank){
		Subsets[y1].parent = x1;
	}else{
		Subsets[y1].parent = x1;
		Subsets[x1].Rank++;
	}
}

int mycomparator(const void*a, const void*b){
	struct Edge* e1 = (struct Edge*)a;
	struct Edge* e2 = (struct Edge*)b;
	return e1->weight > e2->weight;
}

void Kruskal(struct Graph* graph){
	int E = graph->e;
	int V = graph->v;
	struct Edge result[V];
	qsort(graph->edge, graph->e, sizeof(graph->edge[0]), mycomparator);
	struct subset *Subsets = (struct subset*) malloc(V * sizeof(struct subset));

	for(int v=0; v<V; ++v){
		Subsets[v].parent = v;
		Subsets[v].Rank = 0;
	}
	int i=0;
	int d=0;

	while(d < V-1 && i < E){
		struct Edge nextEdge = graph->edge[i++];

		int a = Find(Subsets, nextEdge.x);
		int b = Find(Subsets, nextEdge.y);

		if(a!=b){
			result[d++] = nextEdge;
			UnionOfSubsets(Subsets, a, b);
		}

	}

	for(int i=0; i<d; i++) cout<<result[i].x<<" "<<result[i].y<<" "<<result[i].weight<<endl;
		return;
}

int main(){
	int V = 5;
    int E = 7;
    struct Graph* graph = creategraph(V, E);

    graph->edge[0].x = 0;
    graph->edge[0].y = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].x = 0;
    graph->edge[1].y = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].x = 0;
    graph->edge[2].y = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].x = 0;
    graph->edge[3].y = 4;
    graph->edge[3].weight = 15;

    graph->edge[4].x = 1;
    graph->edge[4].y = 2;
    graph->edge[4].weight = 12;

    graph->edge[4].x = 2;
    graph->edge[4].y = 3;
    graph->edge[4].weight = 20;

    graph->edge[4].x = 3;
    graph->edge[4].y = 4;
    graph->edge[4].weight = 17;


    Kruskal(graph);

    return 0;

}

#include <bits/stdc++.h> 
using namespace std; 

#define V 5 
 
int min_key(int key[], bool MST[]) 
{  
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (MST[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
} 

void printMST(int parent[], int graph[V][V]) 
{ 
	for (int i = 1; i < V; i++) 
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 

 
void Prim(int graph[V][V]) 
{ 
	int parent[V]; 
	
	int key[V]; 
	
	bool MST[V]; 

	for (int i = 0; i < V; i++) 
		key[i] = INT_MAX, MST[i] = false; 

	key[0] = 0; 
	parent[0] = -1; 

	for (int i = 0; i < V-1; i++) 
	{ 

		int u = min_key(key, MST); 
		//cout<<"u="<<u<<endl;

		MST[u] = true; 

		/*for(int i=0; i<V; i++) {
			cout<<"parent"<<i<<"="<<parent[i]<<endl;
			cout<<"mst"<<i<<"="<<MST[i]<<endl;*/
		for (int v = 0; v < V; v++) 
			if (graph[u][v] && MST[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 

	printMST(parent, graph); 
} 

int main() 
{ 

	int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
						{ 2, 0, 3, 8, 5 }, 
						{ 0, 3, 0, 0, 7 }, 
						{ 6, 8, 0, 0, 9 }, 
						{ 0, 5, 7, 9, 0 } }; 

	Prim(graph); 

	return 0; 
} 

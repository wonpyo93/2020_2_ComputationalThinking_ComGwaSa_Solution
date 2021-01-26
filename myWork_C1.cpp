#include<iostream> 
using namespace std; 

struct graph	 
{ 
	int v;		 
	int e;		 
	int **dir;	 
}; 

int findDegree(struct graph *G, int ver) 
{	 
	int degree = 0;		 
	for (int i=0; i<G->v; i++)	 
		if (G-> dir[ver][i] == 1) 
			degree++;			 
	return degree;		 
} 

void removeFromGraph(struct graph *G, int a)
{
  for(int i = 0; i < G->v; i++)
  {
    G->dir[a][i] = 0;
    G->dir[i][a] = 0;
  }
}

void addToGraph(struct graph *G, int a, int b)
{
	G->dir[a][b] = 1;
  G->dir[b][a] = 1;
}

struct graph *createGraph(int v,int e) 
{ 
	struct graph *G = new graph; 
	
	G->v = v; 
	G->e = e; 
	G->dir = new int*[v]; 
	
	for (int i = 0;i < v;i++) 
		G->dir[i] = new int[v];	
	return G;
} 

int input1, input2, input3;
int input4, input5;
int counter;
int main() 
{ 
  cin >> input1 >> input2 >> input3;
	struct graph *G = createGraph(input1, input3); 
	
  for(int i = 0; i < input3; i++)
  {
    cin >> input4 >> input5;
    addToGraph(G, input4-1, input5-1);
  }

  int degree;
  bool flag = false;
  while(flag == false)
  {
    counter = 0;
    flag = true;
    for(int i = 0; i < input1; i++)
    {
      if(findDegree(G, i) < input2 && findDegree(G, i) != 0)
      {
        removeFromGraph(G, i);
        flag = false;
      }
      else if(findDegree(G, i) >= input2)
      {
        counter++;
      }
    }
  }
  cout << counter; 
} 

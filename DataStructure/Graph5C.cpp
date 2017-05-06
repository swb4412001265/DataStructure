// Author: John Maslanka
// Date: 27-Dec-2002
// Installation: Home PC with MicroSoft Visual C++ V6.0
// Elementary Illustration of a Directed Graph adapted from 
// Figures 15.2 and 15.3 in Main and Savitch, but terminal 
// input is available. The program asks the user how many
// vertices to enter. (MAX is 100.) If the user enters 100,  
// the vertex numbers are from 0 to 99. The user then enters the
// edges by giving the start vertex followed by the end vertex
// up to the product of the number of vertices times the 
// number of vertices less 1, or you can terminate edge input  
// with control-z. Note: FWIW an edge looping back to its first 
// vertex is disallowed in this code.

#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

const int MAX = 100;

class Graph {
private:
	bool    edge [MAX][MAX];
	int     count_of_vertices;
	int		vflag [MAX];
public:
	Graph () { count_of_vertices = 0; }
	int size () const {return count_of_vertices; }

	void add_vertexes (const int);
	void add_edge (int source, int target);
	bool get_edge (int a, int b) { return edge [a][b]; }
	bool is_edge (int source, int target) const;
	void clear_vflags (int);
	void clear_vflag (int);
	void set_vflag (int);
	int  test_vflag (int);
	void tree_level (int, int);
};

void Graph::add_vertexes (const int nr)
{ int x, y;
  count_of_vertices = nr;
  for (x = 0; x < nr; ++x)
	 for (y = 0; y < nr; ++y)
	    edge[x][y] = false; }
void Graph::clear_vflags (int nr)
{ int x;
  for ( x = 0; x < nr; ++x)
		vflag[x] = 0; }
void Graph::set_vflag (int nr)
{ vflag[nr] = 1; }
void Graph::clear_vflag (int nr)
{ vflag[nr] = 0; }
int Graph::test_vflag (int nr)
{ return vflag[nr]; }
void Graph::add_edge (int source, int target)
{ edge[source][target] = true; }
bool Graph::is_edge(int source, int target) const
{ return edge[source][target]; }
void Graph::tree_level (int x, int level)
{ int j, i;
  ++level;
  ++vflag[x];
  for (j = 0; j < size(); ++j)
	 { if (is_edge (x, j))
		{ for (i = 1; i < level ; cout << "   ", ++i);
		  cout << "  (" << x << ", " << j << ")" << endl;
		  if ( x != j && vflag[j] < 1 )
			  tree_level (j, level);
	 }  }
  if (level == 2)
	{ clear_vflags(size());
	  ++vflag[0];
	}
}
int main () {
    Graph G;
	int i, j, nr, x;
	cout << "Enter number of vertices (1 < nr <= 100) ";
	cin >> nr;
	if (cin.eof() || !cin.good() || nr < 2 || nr > MAX)
		{cout << "Invalid input for number of vertices. "
		      << "Program terminating." << endl;
		 exit (1);}
	G.add_vertexes (nr);
	cout << "Number of vertices is " << G.size() << endl << endl;
	for (x=0; x < nr*(nr-1) && !cin.eof();)
		{cout << "Enter the two bounding vertexes of an edge " << endl;
		 cout << " Beginning and Terminating vertexes must be between 0 and " << (nr-1) << " inclusive" << endl;
		 cin >> i >> j;
		 if (!cin.eof())
		    {if (!cin.good() || i >= nr || j >= nr)
		        {cout << "Invalid input for an edge. "
			      << "Program terminating." << endl;
				 exit (1);}
		     if (i == j)
			 cout << "Beginning and terminating must not be "
                  << "the same for an edge in this graph." << endl;
			 else
				{G.add_edge (i,j);
				 ++x;}
			}
		}
	cout << "Lists of nearest neighbors of each vertex" << endl;
	for (i = 0; i < G.size(); ++i)
	{ cout << "From Vertex " << i << " Edges are ";
	  for (j = 0; j < G.size(); ++j)
		  if (G.is_edge (i, j))
			  cout << "  (" << i << ", " << j << ")";
	  cout << endl;
	}
	cout << endl;
	cout << "Directed List of Neighbor Vertexes for each Vertex" 
		 << endl;
	for (i = 0; i < G.size(); ++i)
		{ cout<< "For Vertex " << i << "     ";
	      for (j = 0; j < G.size(); ++j)
				if (G.is_edge(i, j)) 
					cout << "   " << j;
		  cout << endl;
		}
	cout << endl;
  system("PAUSE");
	for (i = 0; i < G.size(); ++i)
	   { cout << "Depth-First Traversal of Trees on Graph "
                  << "starting with Vertex " << i << endl;
		  G.clear_vflags (G.size());
		  G.tree_level ( i, 0 );
		}
  system("PAUSE");
	for (int h = 0; h < G.size(); ++h)
        {int que [201];
         int x = 0, y = 0;
	     cout << endl
                  << "Breadth-First Traversal of Trees on Graph "
                  << "starting with Vertex " << h << endl;
	     que [x++] = h;
	     G.clear_vflags (G.size());
	     while (x != y)
		    {int i = que [y];
             int j;
             y++;
		     if (!G.test_vflag(i))
		          cout << " " << i;
		     for (j = 0; j < G.size(); ++j)
		         {if (G.is_edge(i,j) && !G.test_vflag(i)) {
			        que [x++] = j;
					// cout << "+";
					cout << ' ';
                   }
				 }
			 // cout << "|";
		     G.set_vflag(i);
		    }
	 cout << endl;
	}
	  system("PAUSE");
}
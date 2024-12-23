#include <iostream>
#include<iterator>
#include <vector>
#include <list>
using namespace std;

struct DataNode
{
	int l_label;
	bool key;
	double weight;
	DataNode()
	{
		key = false;
		weight = 0;
	}
};
struct AdjecNode
{
	list<DataNode> l;
	double x_location;
	double y_location;
	int v_label;
	AdjecNode()
	{
		x_location = y_location = -1;
	}
};
class MyGraph
{
public:
	vector<AdjecNode> v;
	int numLinks;
	int edges;
public:
	MyGraph()
	{
		EmptyGraph();
		edges = 0;
	}
	bool EmptyGraph()
	{
		bool flag = false;
		if (v.empty()) {
			flag = true;
		}
		return flag;
	}
	void addVertex(int label)
	{
		if (vertexExist(label))
			cout << label << " Vertex Already Exist" << endl;
		else
		{
			AdjecNode a;
			a.v_label = label;
			v.push_back(a);
		}
	}
	int searchVertex(int label)
	{
		vector<AdjecNode>::iterator temp = v.begin(); int i = 0; int count = 0;
		for (temp, i; temp != v.end(), i < v.size(); ++temp, i++)
		{
			if (v[i].v_label == label)
			{
				count = i;
				break;
			}
			else
				continue;
		}
		return count;
	}
	void addEdge(int from, int to) //undirected graph
	{
		DataNode d;
		
		d.l_label = to;
		int vert1 = searchVertex(from);	
		v[vert1].l.push_back(d);
		
		
		d.l_label = from;
		int vert2 = searchVertex(to);
		v[vert2].l.push_back(d);
		
		edges++;
	}
	bool edgeExist(int label,int i)
	{
		list<DataNode>::iterator temp; bool flag = false;
		for (temp = v[i].l.begin(); temp != v[i].l.end(); ++temp)
		{
			if (temp->l_label == label)
			{
				flag = true;
				break;
			}
		}
		return flag;
	}
	bool vertexExist(int label)
	{
		bool flag = false; int i = 0;
		vector<AdjecNode>::iterator temp = v.begin();
		for (temp, i; temp != v.end(), i < v.size(); ++temp, i++)
		{
			if (v[i].v_label == label)
			{
				flag = true;
				break;
			}
		}
		return flag;
	}
	int getNumVertices()
	{
		vector<AdjecNode>::iterator temp = v.begin(); int i = 0; int count = 0;
		for (temp, i; temp != v.end(), i < v.size(); ++temp, i++)
		{
			if (v[i].v_label != -1)
			{
				count++;
				continue;
			}
			else
				break;
		}
		return count;
	}
	int getNumEdges() //unDirected Graph 
	{
		return edges;
	}
	int size(int label)
	{
		int vert = searchVertex(label);
		list<DataNode>::iterator temp;
		for (temp = v[vert].l.begin(); temp != v[vert].l.end(); ++temp)
		{
			numLinks++;
		}
		return numLinks;
	}
	bool searchEdge(int from, int to)
	{
		int ver = searchVertex(from);
		AdjecNode a; bool flag = false; DataNode d;
		list<DataNode> ::iterator temp = v[ver].l.begin();
		for (temp; temp != v[ver].l.end(); ++temp)
		{
			if (temp->l_label == to)
			{
				flag = true;
				break;
			}
		}
		return flag;
	}
	void deleteVertex(int label)
	{
		int i = 0; int j = 0;
		vector<AdjecNode>::iterator temp = v.begin();
		for (temp, i; temp != v.end(), i < v.size(); ++temp, i++)
		{
			list<DataNode> ::iterator temp2 = v[i].l.begin();
			for (temp2; temp2 != v[i].l.end(); ++temp2)
			{
				if (temp2->l_label == label)
				{
					v[i].l.erase(temp2);
					break;
				}
				if (v[i].v_label == label)
				{
					continue;
				}
			}
		}
		vector<AdjecNode>::iterator temp3 = v.begin();
		for (temp3, j; temp3 != v.end(), j < v.size(); ++temp3, j++)
		{
			if (v[j].v_label == label)
			{
				v.erase(temp3);
				break;
			}
		}
	}
	void deleteEdge(int from, int to)
	{
		vector<AdjecNode> ::iterator temp = v.begin(); int i = 0;
		for (temp, i; temp != v.end(), i < v.size(); ++temp, i++)
		{
			if (v[i].v_label == from)
			{
				list<DataNode> ::iterator temp2 = v[i].l.begin();
				for (temp2; temp2 != v[i].l.end(); ++temp2)
				{
					if (temp2->l_label == to)
					{
						v[i].l.erase(temp2);
						break;
					}
				}
			}
			if (v[i].v_label == to)
			{
				list<DataNode> ::iterator temp2 = v[i].l.begin();
				for (temp2; temp2 != v[i].l.end(); ++temp2)
				{
					if (temp2->l_label == from)
					{
						v[i].l.erase(temp2);
						break;
					}
				}
			}
		}
		edges--;
	}
	list<int> getNeighbors(int vert)
	{
		int ver = searchVertex(vert); list<int> l; int i = 0;
		list<DataNode>::iterator temp;
		cout << vert << " Vertex Neighbors are -> ";
		for (temp = v[ver].l.begin(), i; temp != v[ver].l.end(), i < v[ver].l.size(); ++temp, i++)
		{
			l.push_back(temp->l_label);
			cout  << temp->l_label<<" " ;
		}
		return l;
	}
	void insertWeight(int to,int from,double w)
	{
		list<DataNode> ::iterator temp2; int ver;
		ver= searchVertex(to);
		for (temp2 = v[ver].l.begin(); temp2 != v[ver].l.end(); ++temp2)
		{
			if (temp2->l_label == from)
			{
				temp2->weight = w;
				break;
			}
		}
		ver = searchVertex(from);
		for (temp2 = v[ver].l.begin(); temp2 != v[ver].l.end(); ++temp2)
		{
			if (temp2->l_label == to)
			{
				temp2->weight = w;
				break;
			}
		}
		
	}
	~MyGraph() //Destructor
	{
		v.~vector();
	}
};




#include <iostream>
#include <vector>
#include<random>
#include <ctime>
#include <stack>
#include<string>
#include<deque>
#include<math.h>
#include "myGraph.cpp"
using namespace std;

struct myDistance
{
	int label; double weight;
};
class WirelessNetwork :protected MyGraph
{
private:
	MyGraph g;
	float size; 
	int n;
	stack<int> s;
	vector<int> copy_s;
	vector<int> visited; 
	deque<int> q;
	vector<int> copy_q;
	//Shortest distance
	vector<myDistance> d;
	deque<myDistance> dq;
	//deque<myDistance> c_dq;
	stack<double> cst;
	//vector<double> c_cost_dq;
public:
	WirelessNetwork()
	{
		AdjecNode a;
		size = 1; n = 15;
		mt19937 generator;
		generator.seed(time(0));
		uniform_real_distribution<double> range(0.0,size);
		double rand_x, rand_y;
		for (int i = 0; i < n; i++)
		{
			g.addVertex(i + 1);
			rand_x = range(generator);
			rand_y = range(generator);
			g.v[i].x_location = rand_x;
			g.v[i].y_location = rand_y;
		}
		int check = 0; double disksDist; 
		for (int i = 0; i < n; i++)
		{
			while (check < n)
			{
				disksDist = calcDistance(g.v[i].y_location, g.v[check].y_location, g.v[i].x_location, g.v[check].x_location);
				if (disksDist <= 1.0 && disksDist > 0.0) // check with its own 
				{
					if (!g.edgeExist(check + 1, i))
						g.addEdge(i + 1, check + 1);
					g.insertWeight(i+1,check+1,disksDist);
				}
				check++;
			}
			check = 0;
		}
		
	}
	WirelessNetwork(float s,int num)
	{
		size = s; n = num;
		AdjecNode a;
		mt19937 generator;
		generator.seed(time(0));
		uniform_real_distribution<double> range(0.0, size);
		double rand_x, rand_y;
		for (int i = 0; i < n; i++)
		{
			g.addVertex(i + 1);
			rand_x = range(generator);
			rand_y = range(generator);
			g.v[i].x_location = rand_x;
			g.v[i].y_location = rand_y;
		}
		int check = 0; double disksDist;
		for (int i = 0; i < n; i++)
		{
			while (check < n)
			{
				disksDist = calcDistance(g.v[i].y_location, g.v[check].y_location, g.v[i].x_location, g.v[check].x_location);
				if (disksDist <= 1.0 && disksDist > 0.0) // check with its own 
				{
					if (!g.edgeExist(check + 1, i))
						g.addEdge(i + 1, check + 1);
					g.insertWeight(i + 1, check + 1, disksDist);
				}
				check++;
			}
			check = 0;
		}

	}
	double calcDistance(double y2, double y1, double x2, double x1)
	{
		double dist = sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
			return dist;
	}
	void traverseDFS()
	{
		list<DataNode>::iterator temp = g.v[0].l.begin(); int x;
		list<DataNode>::iterator temp2;
		for (temp; temp != g.v[0].l.end(); ++temp)
		{
			s.push(temp->l_label);
			copy_s.push_back(temp->l_label);
		}
		markVisited(s.top());
		turnkeyOn(s.top());
		cout << "DFS VERT -> " << s.top() ;
		s.pop();
		while (!s.empty())
		{
			x = gotoVertList(s.top());
			if (!checknode_Visited(s.top()))
			{
				for (temp2=g.v[x].l.begin(); temp2 != g.v[x].l.end(); ++temp2)
				{
					if((!checknode_Visited(temp2->l_label))&&(!searchStack(temp2->l_label)))
					{
						s.push(temp2->l_label);
						copy_s.push_back(temp2->l_label);
					}
				}
				if (!checknode_Visited(s.top()))
				{
					markVisited(s.top());
					turnkeyOn(s.top());
					cout << " -> " << s.top() << " ";
					s.pop();
				}
				else
					s.pop();	
			}
			else 
				s.pop();
		}
		turnkeyOff();
		visited.erase(visited.begin(), visited.end());
	}
	void markVisited(int label)
	{
		visited.push_back(label);
	}
	bool checknode_Visited(char label)
	{
		bool flag = false;
		vector<int>::iterator temp = visited.begin();
		for (temp; temp!=visited.end(); ++temp)
		{
			if (*temp == label)
			{
				flag = true; break;
			}
		}
		return flag;
	}
	int gotoVertList(int label)
	{
		int vert =g.searchVertex(label);
		return vert;
	}
	void turnkeyOn(int label)
	{
		vector<AdjecNode> ::iterator temp = g.v.begin(); int i = 0;
		list<DataNode> ::iterator temp2;
		for (temp,i; temp != g.v.end(),i<g.v.size(); ++temp,i++)
		{
			for (temp2 = g.v[i].l.begin(); temp2 != g.v[i].l.end(); ++temp2)
			{
				if (temp2->l_label == label)
				{
					temp2->key = true;
				}
			}
		}
	}
	void turnkeyOff()
	{
		vector<AdjecNode> ::iterator temp = g.v.begin(); int i = 0;
		list<DataNode> ::iterator temp2;
		for (temp, i; temp != g.v.end(), i < g.v.size(); ++temp, i++)
		{
			for (temp2 = g.v[i].l.begin(); temp2 != g.v[i].l.end(); ++temp2)
				temp2->key = false;
		}
	}
	bool searchStack(int label)
	{
		bool flag = false;
		vector<int>::iterator temp = copy_s.begin();
		for (temp; temp != copy_s.end(); ++temp)
		{
			if (*temp == label)
			{
				flag = true; break;
			}
		}
		return flag;
	}
	bool searchQueue(int label)
	{
		bool flag = false;
		vector<int>::iterator temp = copy_q.begin();
		for (temp; temp != copy_q.end(); ++temp)
		{
			if (*temp == label)
			{
				flag = true; break;
			}
		}
		return flag;
	}
	void traverseBFS()
	{
		list<DataNode>::iterator temp = g.v[0].l.begin(); int x;
		list<DataNode>::iterator temp2;
		for (temp; temp != g.v[0].l.end(); ++temp)
		{
			q.push_back(temp->l_label);
			copy_q.push_back(temp->l_label);
		}
		markVisited(q.front());
		turnkeyOn(q.front());
		cout << "BFS Vert -> " << q.front();
		q.pop_front();
		while (!q.empty())
		{
			x = gotoVertList(q.front());
			if (!checknode_Visited(q.front()))
			{
				for (temp2 = g.v[x].l.begin(); temp2 != g.v[x].l.end(); ++temp2)
				{
					if ((!checknode_Visited(temp2->l_label)) && (!searchQueue(temp2->l_label)))
					{
						q.push_back(temp2->l_label);
						copy_q.push_back(temp2->l_label);
					}
				}
				if (!checknode_Visited(q.front()))
				{
					markVisited(q.front());
					turnkeyOn(q.front());
					cout << " -> " << q.front() << " ";
					q.pop_front();
				}
				else
					q.pop_front();
			}
			else
			q.pop_front();
		}
		turnkeyOff();
		visited.erase(visited.begin(), visited.end());
		copy_q.erase(copy_q.begin(), copy_q.end());
	}
	
	void construct()
	{
		myDistance m;
		for (int i = 0; i < g.v.size(); i++)
		{
			m.label = i+1;
			m.weight = 9999999;
			d.push_back(m);
		}
	}
	void insertHeap(int l,double w)
	{
		myDistance m;
		m.label = l; m.weight = w;
		dq.push_back(m);
	}
	bool chekHeap(int l)
	{
		bool flag = false;
		deque<myDistance>::iterator temp = dq.begin();
		for (temp; temp != dq.end(); ++temp)
		{
			if (temp->label == l)
			{
				flag = true;
				break;
			}
		}
		return flag;
	}
	string ShortestPath(int src, int dest)
	{
		construct(); myDistance m; deque<myDistance> c_dq;
		int ver = g.searchVertex(src); int cost = 0;
		insertHeap(src, 0);
		markVisited(src);
		list<DataNode> ::iterator temp = g.v[ver].l.begin();
		for (temp; temp != g.v[ver].l.end(); ++temp)
		{
			cost = cost + temp->weight;
			if (temp->l_label != dest && cost < d[temp->l_label - 1].weight)
			{
				insertHeap(temp->l_label, temp->weight);
				temp->key = true;
			}
			else
			{
				insertHeap(temp->l_label, temp->weight);
				break;
			}
			cost = 0;
		}
		while (!dq.empty())
		{
			int x = g.searchVertex(dq.front().label);
			if (dq.front().label == dest)
			{
				break;
			}
			else
			{
				for (temp = g.v[x].l.begin(); temp != g.v[x].l.end(); ++temp)
				{
					if (!checknode_Visited(temp->l_label) && !chekHeap(temp->l_label))
					{
						cost = temp->weight + dq.front().weight;
						if (temp->l_label != dest && cost < d[temp->l_label - 1].weight)
						{
							insertHeap(temp->l_label, temp->weight);
							m.label = temp->l_label; m.weight = temp->weight;
							c_dq.push_back(m);
							m.label = temp->l_label; m.weight = temp->weight;
							c_dq.push_back(m);
							temp->key = true;
						}
						else if (temp->l_label == dest) {
							insertHeap(temp->l_label, temp->weight);
							m.label = temp->l_label; m.weight = temp->weight;
							c_dq.push_back(m);
							cst.push(temp->weight);
							temp->key = true;
							break;
						}
					}
					else {
						m.label = temp->l_label; m.weight = temp->weight;
						c_dq.push_back(m);
						cst.push(temp->weight);
					}

					dq.pop_front();
				}
			}
				dq.pop_front();
		}
		string s = " "; string s2 = "->"; int count = 0;
		deque<myDistance>::iterator temp2 = c_dq.begin();
		for (temp2; temp2 != c_dq.end(); ++temp2)
		{
			s = s + to_string(temp2->label) + s2;
			count++;
		}
		s = s + to_string(dest);
		turnkeyOff();
		visited.erase(visited.begin(), visited.end());
		cout << "SHORTEST PATH STRING LENGTH IS: " << count << endl;;
		//c_dq.erase(c_dq.begin(), c_dq.end());
		return s;
	}
	double get_ShortestPathCost()
	{
		double cost = 0.0;
		while(!cst.empty())
		{
			double x = cst.top();
			cost = cost + x;
			cst.pop();
		}
		return cost;
	}

};




#include <iostream>
#include<random>
#include <ctime>
#include <iomanip>
#include "wirelessNetwork.cpp";
using namespace std;
void main()
{
	cout << "***************************************************************************************** DATA STRUCTURES(EC-200) PROJECT *****************************************************************************************" << endl;
	cout << "Submitted by:\n    Muhammad Moiz Alvi \n    Syed M Ali \n    Arsal Sana\n\n Syndicate:      CE40-A\n\n";
	float squareSize = 10; int points = 1000; 
	WirelessNetwork G(squareSize,points);
	mt19937 generator;
	generator.seed(time(0));
	uniform_int_distribution<int> range(0,points);
	cout << "Source" << setw(20) << "Destination" << setw(20) << "ShortestPath" << setw(40) << "Cost" << setw(30)  << "\n\n";
	for (int i = 0; i < 10; i++)
	{
		string sPath; double cost; 
		int rand_src = range(generator);
		int rand_dest = range(generator);
		sPath = G.ShortestPath(rand_src,rand_dest);
		cost = G.get_ShortestPathCost();
		cout << rand_src << setw(20) << rand_dest << setw(160) << sPath << setw(75) << cost << setw(30) << "\n";
		cout << endl;
	}
	cout << "\n\n\n";
	cout << "*************************************************************************************** Traversing using Depth First Search *************************************************************************************** "<<endl;
	G.traverseDFS();
	cout << "\n\n";
	cout << "*************************************************************************************** Traversing using Breath First Search ************************************************************************************** " << endl;
	G.traverseBFS();
	cout << "\n\n";
	system("pause");
}

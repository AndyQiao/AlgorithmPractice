/************************************************
	File：MiniSpanTree.cpp
	Author:qiaoconglovelife@163.com
	Date:20160804
	LastModified Data:20160804
	Brief:

		最小生成树问题
		Kruskal算法

*************************************************/


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef unsigned int uint32_t;

// 图的边
struct CEdge
{
	int u;           // 顶点1
	int v;           // 顶点2
	int weight;      // 权重
	
	// 排序用
	bool operator<(const CEdge& a)
	{
		return weight < a.weight;
	}

};

// 合并顶点a和b各自位于的两棵子树
void UnionSubTree(uint32_t a, uint32_t b, vector<uint32_t> &vuRoot)
{
	vuRoot[a] = vuRoot[b];
}


void Kruskal
(
	const uint32_t uVertexNum,
	vector<CEdge> &vtEdges,
	vector<uint32_t> &vuRoot,
	vector<CEdge> &vtMiniSpanTree
)
{
	// 贪心算法，所以先升序排序
	sort(vtEdges.begin(), vtEdges.end());

	for (auto i = 0; i < vtEdges.size(); ++i)
	{
		if (vuRoot[vtEdges[i].u] != vuRoot[vtEdges[i].v])
		{
			UnionSubTree(vtEdges[i].u, vtEdges[i].v, vuRoot);
			vtMiniSpanTree.push_back(vtEdges[i]);
			if (vtMiniSpanTree.size() >= uVertexNum - 1)
			{
				break;
			}
		}
	}
}

int main()
{
	int V = 4;
	vector<CEdge> vtEdges;
	vtEdges.push_back({ 0, 1, 1 });
	vtEdges.push_back({ 0, 2, 2 });
	vtEdges.push_back({ 0, 3, 3 });
	vtEdges.push_back({ 1, 2, 4 });
	vtEdges.push_back({ 1, 3, 5 });
	vtEdges.push_back({ 2, 3, 2 });

	//使用一个vector来表示各个子树（即集合A），
	//vuRoot[i]=j，表示节点i与节点j位于同一子树上，并且所有位于此树的节点k，都有vuRoot[k]=j;
	//初始化vuRoot[i]=i，表示每棵子树只是一个节点
	vector<uint32_t> vuRoot(V, 0);
	for (int i = 0; i < V; ++i)
		vuRoot[i] = i;

	// 执行算法
	vector<CEdge> vtMiniSpanTree;
	Kruskal(V, vtEdges, vuRoot, vtMiniSpanTree);
	
	// 打印最小生成树
	for (auto i = 0; i < vtMiniSpanTree.size(); ++i)
	{
		cout << vtMiniSpanTree[i].u << "<------>" << vtMiniSpanTree[i].v
			 << "   " 
			 << vtMiniSpanTree[i].weight << endl;
	}


	system("PAUSE");

	return 0;
}
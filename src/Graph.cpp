/*
 * Graph.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: linger
 */

#include "Graph.h"
#include <string.h>
Graph::Graph(ListenReader &reader) {
	// TODO Auto-generated constructor stub


	idManager = new IDManager(reader);//将原本的user,item转换为统一的ID,每个user或者每个item都是唯一的

	graph.resize(idManager->totalUserItem());//申请空间

	RatingRecord * record;
	int user;
	int item;
	float pref;
	reader.reset();
	while(reader.hasNext())
	{
		record = reader.getNext();
		user = idManager->getUserInternalID(record->getUser());
		item = idManager->getItemInternalID(record->getItem());
		pref = record->getPref();

		graph[user][item]=pref;
		graph[item][user]=pref;
	}

	int userItemNum = idManager->totalUserItem();

	//printf("Graph \n");
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

bool cmpFucntion (Item i,Item j)
{
	return i.weight>j.weight;
}

vector<Item> Graph::personalRank(int userInternalID,float alpha,int maxIters)
{
	//printf("personalRank\n");
	int userItemNum = idManager->totalUserItem();
	float* rank = new float[userItemNum];

	//for(int i=0;i<userItemNum;i++)
	//{
	//	rank[i]=0;
	//}
	memset(rank,0,userItemNum*sizeof(float));
	rank[userInternalID]=1;

	float* rankCache =new float[userItemNum];
	map<int,float>::iterator edgeIter;
	pair<int,float> entry;
	for(int iter=0;iter<maxIters;iter++)
	{

		//for(int i=0;i<userItemNum;i++)
	//	{
		//	rankCache[i]=0;
	//	}
		memset(rankCache,0,userItemNum*sizeof(float));

		for(int i=0;i<userItemNum;i++)
		{

			edgeIter = graph[i].begin();
			int r=graph[i].size();
			while(edgeIter!=graph[i].end())
			{
				entry=*edgeIter;
				rankCache[entry.first] += alpha*rank[i]/(r*1.0);
				if(entry.first==userInternalID)
				{
					rankCache[entry.first] += 1.0-alpha;
				}
				edgeIter++;
			}
		}

		memcpy(rank,rankCache,userItemNum*sizeof(float));
		//for(int i=0;i<userItemNum;i++)
		//{
			//rank[i]=rankCache[i];
		//}
	}

	//vector<Item> candidates;
	candidates.clear();
	for(int i=idManager->getUserMaxIternalID()+1;i<userItemNum;i++)
	{
		candidates.push_back(Item(i,rank[i]));
	}


	delete[] rank;//释放空间
    delete[] rankCache;

	std::sort(candidates.begin(),candidates.end(),cmpFucntion);



	//cout<<candidates.size()<<endl;
	return candidates;

}

void Graph::personalRank(string userOriginID)
{
	//printf("personalRank\n");
	int userInternalID = idManager->getUserInternalID(userOriginID);
	//printf("userInternalID:%d\n",userInternalID);
	float alpha = (float) 0.8;
	//vector<Item> candidates=
	personalRank(userInternalID, alpha, 20);
	//cout<<sorted.size()<<endl;


	int k = 100;
	for(int i=0;i<k;i++)
	{
		Item item = candidates[i];
		string itemID = idManager->getOriginID(item.id);
		float w = item.weight;
		cout<<itemID<<":"<<w<<endl;
	}

}




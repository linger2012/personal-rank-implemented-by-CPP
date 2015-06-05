/*
 * Graph.h
 *
 *  Created on: Jun 5, 2015
 *      Author: linger
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include "Item.h"
#include "ListenReader.h"
#include "IDManager.h"

using std::pair;
using std::vector;
using std::map;
using std::string;
using std::cout;
using std::endl;

class Graph {
public:
	Graph(ListenReader &reader);
	virtual ~Graph();
	vector<Item> personalRank(int userInternalID,float alpha,int maxIters);
	void personalRank(string userOriginID);
private:
	vector<map<int,float> > graph;
	IDManager* idManager;

	vector<Item> candidates;
};

#endif /* GRAPH_H_ */

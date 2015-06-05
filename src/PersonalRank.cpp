//============================================================================
// Name        : PersonalRank.cpp
// Author      : linger
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "ListenReader.h"
#include "Graph.h"

using namespace std;


int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!



	string filePath="/home/linger/java-workspace/RecAlgorithm/dataset/user_music.dat";

	ListenReader reader(filePath);
	Graph graph(reader);


	time_t start,stop;
	start = time(NULL);
	printf("begin:\n");
	for(int i=0;i<100;i++)
	{
		//graph.personalRank("79057533");
		graph.personalRank(2546, 0.8, 20);
	}
	printf("end:\n");
	stop = time(NULL);
	printf("Use Time:%ld\n",(stop-start));





	return 0;
}

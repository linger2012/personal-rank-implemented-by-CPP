/*
 * ListenReader.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: linger
 */

#include "ListenReader.h"




ListenReader::ListenReader(string filePath) {
	// TODO Auto-generated constructor stub



	ifstream    input;
	input.open(filePath.c_str());
	string line;
	int offset;
	string user;
	string item;
	//int count=0;
	while(getline(input,line))
	{
		//cout<<line<<endl;//文件每行的格式为:user,item  我这里的数据没有pref,所以下面直接默认为1
		offset = line.find_first_of(',');
		user = line.substr(0,offset);
		item = line.substr(offset+1);
		records.push_back(new RatingRecord(user,item,1));
		//cout<<user<<":"<<item<<endl;


		//if(count++>3)break;
	}

	input.clear();
	input.close();
	//printf("ListenReader \n");
}

ListenReader::~ListenReader() {
	// TODO Auto-generated destructor stub
	reset();
	RatingRecord * record;
	while(hasNext())
	{
		record = getNext();
		delete record;
	}
}


void ListenReader::reset()
{
	iter = records.begin();
}

bool ListenReader::hasNext()
{
	return iter!= records.end();
}

RatingRecord * ListenReader::getNext()
{
	RatingRecord * cur = *iter;
	iter++;
	return cur;
}






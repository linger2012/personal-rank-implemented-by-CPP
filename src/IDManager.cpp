/*
 * IDManager.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: linger
 */

#include "IDManager.h"

IDManager::IDManager(ListenReader &reader) {
	// TODO Auto-generated constructor stub

	int count=0;
	reader.reset();
	RatingRecord * record;
	string user;
	while(reader.hasNext())
	{
		record = reader.getNext();
		user = record->getUser();
		if(user2Internal.count(user)<1)
		{
			user2Internal[user]=count++;
		}
	}

	userMaxInternalID=count-1;

	reader.reset();
	string item;
	while(reader.hasNext())
	{
		record = reader.getNext();
		item = record->getItem();
		if(item2Internal.count(item) <1)
		{
			item2Internal[item]=count++;
		}
	}

	assert(user2Internal.size()+item2Internal.size()==count);
	itemMaxInternalID = count-1;

	internalMapping = new string[count];

	pair<string,int> entry;
	map<string,int>::iterator iter = user2Internal.begin();
	while(iter!=user2Internal.end())
	{
		entry = *iter;
		internalMapping[entry.second] = entry.first;
		iter++;
	}

	iter = item2Internal.begin();
	while(iter!=item2Internal.end())
	{
		entry = *iter;
		internalMapping[entry.second] = entry.first;
		iter++;
	}


}

IDManager::~IDManager() {
	// TODO Auto-generated destructor stub
}


int IDManager::getUserInternalID(string originID)
{
	if(user2Internal.count(originID)>0)
		return user2Internal[originID];
	return -1;
}

int IDManager::getItemInternalID(string originID)
{
	if(item2Internal.count(originID)>0)
		return item2Internal[originID];
	return -1;
}

int IDManager::totalUserItem()
{
	return itemMaxInternalID+1;
}

int IDManager::getUserMaxIternalID()
{
	return userMaxInternalID;
}

string IDManager::getOriginID(int internalID)
{
	return internalMapping[internalID];
}




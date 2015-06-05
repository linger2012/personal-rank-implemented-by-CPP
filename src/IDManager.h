/*
 * IDManager.h
 *
 *  Created on: Jun 5, 2015
 *      Author: linger
 */

#ifndef IDMANAGER_H_
#define IDMANAGER_H_



#include <map>
#include <string>
#include <assert.h>

#include "ListenReader.h"


using std::map;
using std::string;

class IDManager {
public:
	IDManager(ListenReader &reader);
	virtual ~IDManager();
	int getUserInternalID(string originID);
	int getItemInternalID(string originID);
	int totalUserItem();
	int getUserMaxIternalID();
	string getOriginID(int internalID);
private:
	map<string,int> user2Internal;
	int userMaxInternalID;

	map<string,int> item2Internal;
	int itemMaxInternalID;
	string * internalMapping;
};

#endif /* IDMANAGER_H_ */

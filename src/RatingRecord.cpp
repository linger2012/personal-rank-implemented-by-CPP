/*
 * RatingRecord.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: linger
 */

#include "RatingRecord.h"

RatingRecord::RatingRecord(string u,string i,float p) {
	// TODO Auto-generated constructor stub
	user = u ;
	item = i;
	pref = p;
}

RatingRecord::~RatingRecord() {
	// TODO Auto-generated destructor stub
}

string RatingRecord::getUser()
{
	return user;
}

string RatingRecord::getItem()
{
	return item;
}

float RatingRecord::getPref()
{
	return pref;
}

/*
 * RatingRecord.h
 *
 *  Created on: Jun 5, 2015
 *      Author: linger
 */

#ifndef RATINGRECORD_H_
#define RATINGRECORD_H_

#include <string>
using std::string;

class RatingRecord {
public:
	RatingRecord(string u,string i,float p);
	virtual ~RatingRecord();
	string getUser();
	string getItem();
	float getPref();
private:
	string user;
	string item;
	float pref;
};

#endif /* RATINGRECORD_H_ */

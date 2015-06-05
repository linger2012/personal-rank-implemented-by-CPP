/*
 * ListenReader.h
 *
 *  Created on: Jun 5, 2015
 *      Author: linger
 */

#ifndef LISTENREADER_H_
#define LISTENREADER_H_

#include <iostream>
#include <list>
#include <iostream>
#include <fstream>


#include "RatingRecord.h"

using std::string;
using std::list;
using namespace std;

class ListenReader {
public:
	ListenReader(string filePath);
	virtual ~ListenReader();
	list<RatingRecord*> records;
	list<RatingRecord*>::iterator iter;
	void reset();
	bool hasNext();
	RatingRecord * getNext();

};

#endif /* LISTENREADER_H_ */

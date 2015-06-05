/*
 * Item.h
 *
 *  Created on: Jun 5, 2015
 *      Author: linger
 */

#ifndef ITEM_H_
#define ITEM_H_

class Item {
public:
	Item(int i,float w);
	virtual ~Item();
	int id;
	float weight;
};

#endif /* ITEM_H_ */

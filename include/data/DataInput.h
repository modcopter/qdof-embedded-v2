/*
 * DataInput.h
 *
 * Created: 08.05.2013 21:04:33
 *  Author: Simon
 */ 


#ifndef DATAINPUT_H_
#define DATAINPUT_H_

#include "data/DataModule.h"

class DataInput {
public:
	DataInput(DataModule *parent) {
		_parent = parent;
	}
	
	void update(void *data) {
		_parent->update(data);
	}
	
private:
	DataModule *_parent;
};


#endif /* DATAINPUT_H_ */
/*
 * DataOutput.h
 *
 * Created: 08.05.2013 20:59:24
 *  Author: Simon
 */ 


#ifndef DATAOUTPUT_H_
#define DATAOUTPUT_H_

#define MAX_CONNECTIONS		2

#include "data/DataInput.h"

template <class T>
class DataOutput {
public:
	DataOutput()
		: _connectedInputs(0)
	{}
	
	void sendData(T data) {
		for (int i = 0; i < _connectedInputs; i++) {
			_inputs[i]->update(&data);
		}
	}
	
	DataOutput &operator= (T const &rhs) {
		this->sendData(rhs);
		return *this;
	}
	
	bool operator> (DataInput &rhs) {
		return this->connect(&rhs);
	}
	
	bool connect(DataInput *input) {
		if (_connectedInputs >= MAX_CONNECTIONS)
			return false;
		//
		_inputs[_connectedInputs++] = input;
		return true;
	}
	
private:
	DataInput *_inputs[MAX_CONNECTIONS];
	int _connectedInputs;
};


#endif /* DATAOUTPUT_H_ */
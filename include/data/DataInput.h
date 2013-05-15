/*
 * DataInput.h
 *
 * Created: 08.05.2013 21:04:33
 *  Author: Simon
 */ 


#ifndef IDATAINPUT_H_
#define IDATAINPUT_H_

#include "data/DataModule.h"

class DataValue {
public:
	void *getRawData() { return _data; }
	void setRawData(void *data) { _data = data; }
	
		
	template <typename T> T getData() {
		return *(T *)_data;
	}
	
	template <typename T> void setData(T data) {
		_data = &data;
	}
	
	template <typename T> operator T() {
		return this->getData<T>();
	}
	
private:
	void *_data;
};

class DataInput{
public:
	DataInput(DataModule *parent) {
		static int _lastId = 0;
		this->id = _lastId++;
		//
		this->_parent = parent;
	}
	
	int getId() { return id; }

	void __update(void * data) {
		_data.setRawData(data);
		_parent->OnInputChanged(this);
	}
	
	void *getRawData() {
		return _data.getRawData();
	}
	
	DataValue getData() {
		return _data;
	}
	
private:
	int id;
	DataModule *_parent;
	DataValue _data;
};


#endif /* IDATAINPUT_H_ */
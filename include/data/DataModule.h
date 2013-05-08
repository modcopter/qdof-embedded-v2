/*
 * DataModule.h
 *
 * Created: 08.05.2013 20:46:25
 *  Author: Simon
 */ 


#ifndef DATAMODULE_H_
#define DATAMODULE_H_

class DataModule {
public:
	DataModule() {
		static int _lastId = 0;
		this->id = _lastId++;
	}
	
	virtual void update(void *);
	
	int id;
};


#endif /* DATAMODULE_H_ */
#pragma once
#include <stdio.h>
#include<list>
#include <map>
using namespace std;

class LRU
{
private:
	/*
	* @brief create a struct as the node of the data strucher
	*/
	struct  LrucacheNdoe
	{
		int key;
		int value;
		LrucacheNdoe(int k, int v):
			key(k),
			value(v)
		{}
	};

public:
	LRU(int capacity)
	{
		this->capavity = capacity;
	};

	~LRU(){};
	
public:
	int getValue(int key);
	void setValue(int key, int value);

private:
	int capavity;
	std::list<LrucacheNdoe>Lrucachelist;
	map<int, std::list<LrucacheNdoe>::iterator> cacheMap;
};


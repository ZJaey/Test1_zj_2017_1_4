#include "stdafx.h"
#include "LRU.h"

int LRU::getValue(int key)
{
	if (cacheMap.find(key) == cacheMap.end)
	{
		return -1;
	}
	else
	{
		Lrucachelist.splice(Lrucachelist.begin, Lrucachelist, cacheMap[key]);
		cacheMap[key] = Lrucachelist.begin();
		return cacheMap[key]->value;
	}
}

void LRU::setValue(int key, int value)
{
	if (cacheMap.find(key) == cacheMap.end())
	{
		if (Lrucachelist.size() == capavity)
		{
			cacheMap.erase(Lrucachelist.back().key));
			Lrucachelist.pop_back();
		}
		Lrucachelist.push_front(LrucacheNdoe(key, value));
		cacheMap[key] = Lrucachelist.begin();
	}
	else
	{

	}
}

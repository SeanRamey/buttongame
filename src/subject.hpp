#pragma once

#include <vector>

#include "observer.hpp"

class Subject
{
public:
	Subject();
	virtual ~Subject();
	virtual void addObserver(Observer *obs)
	{
		observerList.push_back(obs);
	}
	virtual void removeObserver(Observer *obs)
	{
		for(auto it = observerList.begin(); it != observerList.end(); ++it)
		{
			if(it = obs)
			{
				observerList.erase(it);
			}
		}
	}
	virtual void notifyObservers()
	{
		for(auto it = observerList.begin(); it != observerList.end(); ++it)
		{
			it->update();
		}
	}

protected:
	std::vector<Observer *> observerList;

};

#pragma once
#include "DietPlan.hpp"



class NodeDP
{
public:
	NodeDP(DietPlan newEPlan, NodeDP* pNext = nullptr);//constructor
	NodeDP(const NodeDP& copy);//copy constructor
	~NodeDP(); //destructor

	//getters
	NodeDP* getpNext();
	DietPlan& getDietPlan();

	//setters
	void setpNext(NodeDP* const nextNode);
	void setDietPlan(const DietPlan newDPlan);

private:
	NodeDP* mpNext;
	DietPlan mDietPlan;
};

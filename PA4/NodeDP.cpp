#include "PA4.hpp"
#include "NodeDP.hpp"


NodeDP::NodeDP(DietPlan newDPlan, NodeDP* pNext)
{
	setpNext(pNext);
	setDietPlan(newDPlan);
}

NodeDP::NodeDP(const NodeDP& copy)
{
	mpNext = copy.mpNext;
	mDietPlan = copy.mDietPlan;
}

NodeDP::~NodeDP()
{
}

NodeDP* NodeDP::getpNext()
{
	return mpNext;
}

DietPlan NodeDP::getDietPlan()
{
	return mDietPlan;
}

void NodeDP::setpNext(NodeDP* const nextNode)
{
	mpNext = nextNode;
}


void NodeDP::setDietPlan(const DietPlan newDPlan)
{
	mDietPlan = newDPlan;
}


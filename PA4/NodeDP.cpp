#include "PA4.hpp"
#include "NodeDP.hpp"

/// <summary>
/// constructor for NodeDP
/// </summary>
/// <param name="newDPlan">DietPlan class</param>
/// <param name="pNext">pointer to next node</param>
NodeDP::NodeDP(DietPlan newDPlan, NodeDP* pNext)
{
	setpNext(pNext);
	setDietPlan(newDPlan);
}

/// <summary>
/// copy constuctor for NodeDP
/// </summary>
/// <param name="copy">Node to be copied</param>
NodeDP::NodeDP(const NodeDP& copy)
{
	mpNext = copy.mpNext;
	mDietPlan = copy.mDietPlan;
}

/// <summary>
/// destructor
/// </summary>
NodeDP::~NodeDP()
{
}

/// <summary>
/// getter for mpNext
/// </summary>
/// <returns>mpNext</returns>
NodeDP* NodeDP::getpNext()
{
	return mpNext;
}

/// <summary>
/// getter for mDietPlan
/// </summary>
/// <returns></returns>
DietPlan NodeDP::getDietPlan()
{
	return mDietPlan;
}

/// <summary>
/// setter for mpNext
/// </summary>
/// <param name="nextNode">pointer to next node</param>
void NodeDP::setpNext(NodeDP* const nextNode)
{
	mpNext = nextNode;
}

/// <summary>
/// setter for mDietPlan
/// </summary>
/// <param name="newDPlan">DietPlan class</param>
void NodeDP::setDietPlan(const DietPlan newDPlan)
{
	mDietPlan = newDPlan;
}


#include "PA4.hpp"
#include "NodeEP.hpp"

/// <summary>
/// defualt constructor for NodeEP
/// </summary>
/// <param name="newEPlan">ExercisePlan to be added</param>
/// <param name="pNext">pointer to next node</param>
NodeEP::NodeEP(ExercisePlan newEPlan, NodeEP* pNext)
{
	setpNext(pNext);
	setExercisePlan(newEPlan);
}

/// <summary>
/// copy constructor for NodeEP
/// </summary>
/// <param name="copy">NodeEP to be copied</param>
NodeEP::NodeEP(const NodeEP& copy)
{
	mpNext = copy.mpNext;
	mExercisePlan = copy.mExercisePlan;
}

/// <summary>
/// destructor - empty
/// </summary>
NodeEP::~NodeEP()
{
}

/// <summary>
/// getter for mpNext
/// </summary>
/// <returns>mpNext</returns>
NodeEP* NodeEP::getpNext()
{
	return mpNext;
}

/// <summary>
/// getter for mExercisePlan
/// </summary>
/// <returns>mExercisePlan</returns>
ExercisePlan& NodeEP::getExercisePlan()
{
	return mExercisePlan;
}

/// <summary>
/// setter for mpNext
/// </summary>
/// <param name="nextNode">pointer to the next node in sequence</param>
void NodeEP::setpNext(NodeEP* const nextNode)
{
	mpNext = nextNode;
}

/// <summary>
/// setter for mExercisePlan
/// </summary>
/// <param name="newEPlan">ExercisePlan to be added</param>
void NodeEP::setExercisePlan(const ExercisePlan newEPlan)
{
	mExercisePlan = newEPlan;
}



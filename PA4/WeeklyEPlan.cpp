#include "PA4.hpp"
#include "WeeklyEPlan.hpp"

/// <summary>
/// defualt constructor
/// </summary>
WeeklyEPlan::WeeklyEPlan()
{
	mpHead = nullptr;
}

/// <summary>
/// destructor
/// </summary>
WeeklyEPlan::~WeeklyEPlan()
{
	NodeEP* pCur = mpHead;
	NodeEP* pPrev = nullptr;

	while (pCur != nullptr)
	{
		pPrev = pCur;
		pCur = pCur->getpNext();
		delete pPrev;
	}
}

/// <summary>
/// getter for mpHead
/// </summary>
/// <returns>pointer to a NodeEP</returns>
NodeEP* WeeklyEPlan::getpHead()
{
	return mpHead;
}

/// <summary>
/// insert function for inserting at the end of a linked list
/// </summary>
/// <param name="newEplan">an Exercise Plan Class</param>
/// <returns>true/false if memory is able to be allocated</returns>
bool WeeklyEPlan::insertAtEnd(const ExercisePlan newEplan)
{
	bool success = false;
	NodeEP* pMem = createNode(newEplan);
	NodeEP* pCur = mpHead;

	if (pMem != nullptr)
	{
		success = true;
		if (isEmpty())
		{
			mpHead = pMem;
		}
		else 
		{
			while (pCur->getpNext() != nullptr)
			{
				pCur = pCur->getpNext();
			}
			pCur->setpNext(pMem);
		}
	}
	return success;
}

/// <summary>
/// checks if list is empty
/// </summary>
/// <returns>returns true if list is empty</returns>
bool WeeklyEPlan::isEmpty()
{
	if (mpHead == nullptr)
	{
		return true;
	}
	return false;
}

/// <summary>
/// create node fuction for a linked list
/// </summary>
/// <param name="newEPlan">Exercise Plan class</param>
/// <returns>pointer to node</returns>
NodeEP* WeeklyEPlan::createNode(ExercisePlan newEPlan)
{
	NodeEP* pMem = new NodeEP(newEPlan);
	return pMem;
}



#include "PA4.hpp"
#include "WeeklyDPlan.hpp"

/// <summary>
/// constructor
/// </summary>
WeeklyDPlan::WeeklyDPlan()
{
	mpHead = nullptr;
}

/// <summary>
/// destructor, frees the members of the linked list
/// </summary>
WeeklyDPlan::~WeeklyDPlan()
{
	NodeDP* pCur = mpHead;
	NodeDP* pPrev = nullptr;

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
/// <returns></returns>
NodeDP* WeeklyDPlan::getpHead()
{
	return mpHead;
}

/// <summary>
/// insert function for a linked list 
/// </summary>
/// <param name="newDPlan">DietPlan class to be inserted</param>
/// <returns>true if memory is allocated</returns>
bool WeeklyDPlan::insertAtEnd(const DietPlan newDPlan)
{
	bool success = false;
	NodeDP* pMem = createNode(newDPlan);
	NodeDP* pCur = mpHead;

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
/// <returns>true if empty</returns>
bool WeeklyDPlan::isEmpty()
{
	if (mpHead == nullptr)
	{
		return true;
	}
	return false;
}

/// <summary>
/// create node function for WeeklyDPlan
/// </summary>
/// <param name="newDPlan">DietPlan node to be created</param>
/// <returns>pointer to node</returns>
NodeDP* WeeklyDPlan::createNode(DietPlan newDPlan)
{
	NodeDP* pMem = new NodeDP(newDPlan);
	return pMem;
}


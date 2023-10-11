#include "PA4.hpp"
#include "WeeklyDPlan.hpp"


WeeklyDPlan::WeeklyDPlan()
{
	mpHead = nullptr;
}

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

NodeDP* WeeklyDPlan::getpHead()
{
	return mpHead;
}

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

bool WeeklyDPlan::isEmpty()
{
	if (mpHead == nullptr)
	{
		return true;
	}
	return false;
}


NodeDP* WeeklyDPlan::createNode(DietPlan newDPlan)
{
	NodeDP* pMem = new NodeDP(newDPlan);
	return pMem;
}


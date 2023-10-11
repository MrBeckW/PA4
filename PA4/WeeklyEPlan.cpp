#include "PA4.hpp"
#include "WeeklyEPlan.hpp"


WeeklyEPlan::WeeklyEPlan()
{
	mpHead = nullptr;
}

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

NodeEP* WeeklyEPlan::getpHead()
{
	return mpHead;
}

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

bool WeeklyEPlan::isEmpty()
{
	if (mpHead == nullptr)
	{
		return true;
	}
	return false;
}


NodeEP* WeeklyEPlan::createNode(ExercisePlan newEPlan)
{
	NodeEP* pMem = new NodeEP(newEPlan);
	return pMem;
}



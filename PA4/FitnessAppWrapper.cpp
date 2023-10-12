#include "PA4.hpp"
#include "FitnessAppWrapper.hpp"

using std::ifstream;

FitnessAppWrapper::FitnessAppWrapper()
{
	
	mImputEPlan.open("exercisePlans.txt");
	mImputDPlan.open("dietPlans.txt");
	
	mOutputEPlan.open("exercisePlans.txt");
	mOutputDPlan.open("dietPlans.txt");
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	/*mImputDPlan.close();
	mImputEPlan.close();
	mOutputDPlan.close();
	mOutputDPlan.close();*/
}

void FitnessAppWrapper::runApp(void)
{
	if (mImputDPlan.is_open() && mImputEPlan.is_open())
	{
		int num = 0;
		while (num != 9)
		{
			displayMenu();
			cin >> num;
			switch (num)
			{
			case 1:
				loadWeeklyPlan(mImputDPlan, mWeeklyDietPlan);
				break;
			case 2:
				loadWeeklyPlan(mImputEPlan, mWeeklyExercisePlan);
				break;
			case 3:

				break;
			case 4:

				break;
			case 5:
				displayWeeklyPlan(mWeeklyDietPlan);
				break;
			case 6:
				displayWeeklyPlan(mWeeklyExercisePlan);
				break;
			case 7:

				break;
			case 8:

				break;
			case 9:

				break;
			default:

				break;
			}
		}
	}
	else
	{
		cout << "Error! file/s did not open!\n";
	}
}
/////////////////////////////////////////
// private member functions
void FitnessAppWrapper::loadDailyPlan(ifstream& imputStream, DietPlan& newPlan)
{
	imputStream >> newPlan;
}

void FitnessAppWrapper::loadDailyPlan(ifstream& imputStream, ExercisePlan& newPlan)
{
	imputStream >> newPlan;
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& imputStream, WeeklyEPlan& newPlan)
{
	ExercisePlan EPlans[7];

	imputStream >> EPlans[0] >> EPlans[1] >> EPlans[2] >> EPlans[3] >> EPlans[4] >> EPlans[5] >> EPlans[6];

	for (int i = 0; i < 7; i++)
	{
		newPlan.insertAtEnd(EPlans[i]);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& imputStream, WeeklyDPlan& newPlan)
{
	DietPlan DPlans[7];

	imputStream >> DPlans[0] >> DPlans[1] >> DPlans[2] >> DPlans[3] >> DPlans[4] >> DPlans[5] >> DPlans[6];
	
	for (int i = 0; i < 7; i++)
	{
		newPlan.insertAtEnd(DPlans[i]);
	}
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan EPlan) const
{
	cout << EPlan;
}

void FitnessAppWrapper::displayDailyPlan(DietPlan DPlan) const
{
	cout << DPlan;
}

void FitnessAppWrapper::displayWeeklyPlan(WeeklyEPlan& EPlan) const
{
	if (!EPlan.isEmpty())
	{
		NodeEP* pCur = EPlan.getpHead();

		for (int i = 0; i < 7; i++)
		{
			displayDailyPlan(pCur->getExercisePlan());
			pCur = pCur->getpNext();
		}
	}
	else
	{
		cout << "Weekly plan is empty and must be loaded!" << std::endl;
	}
}

void FitnessAppWrapper::displayWeeklyPlan(WeeklyDPlan& DPlan) const
{
	if (!DPlan.isEmpty())
	{
		NodeDP* pCur = DPlan.getpHead();

		for (int i = 0; i < 7; i++)
		{
			displayDailyPlan(pCur->getDietPlan());
			pCur = pCur->getpNext();
		}
	}
	else
	{
		cout << "Weekly plan is empty and must be loaded!" << std::endl;
	}
}

void FitnessAppWrapper::displayMenu()
{
	cout << "---Menu---\n"
		<< "1. Load weekly diet plan from file.\n"
		<< "2. Load weekly exercise plan from file.\n"
		<< "3. Store weekly diet plan to file.\n"
		<< "4. Store weekly exercise plan to file.\n"
		<< "5. Display weekly diet plan.\n"
		<< "6. Display weekly exercise plan.\n"
		<< "7. Edit daily diet plan.\n"
		<< "8. Edit daily exercse plan.\n"
		<< "9. Exit.\n"
		<< "\nENTER YOUR SELECTION > ";
}





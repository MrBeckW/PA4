#include "PA4.hpp"
#include "FitnessAppWrapper.hpp"

/// <summary>
/// defualt constructor opens requited files for input and output
/// </summary>
FitnessAppWrapper::FitnessAppWrapper()
{
	
	mImputEPlan.open("exercisePlans.txt");
	mImputDPlan.open("dietPlans.txt");
	
	mOutputEPlan.open("exercisePlans.txt");
	mOutputDPlan.open("dietPlans.txt");
}

/// <summary>
/// destructor for FitnessApp, closes all open files
/// </summary>
FitnessAppWrapper::~FitnessAppWrapper()
{
	mImputDPlan.close();
	mImputEPlan.close();
	mOutputDPlan.close();
	mOutputDPlan.close();
}

/// <summary>
/// checks if files are open and collects users menu option. then executes the desired function.
/// </summary>
/// <param name="">void</param>
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
				storeWeeklyPlan(mOutputDPlan, mWeeklyDietPlan);
				break;
			case 4:
				storeWeeklyPlan(mOutputEPlan, mWeeklyExercisePlan);
				break;
			case 5:
				displayWeeklyPlan(mWeeklyDietPlan);
				break;
			case 6:
				displayWeeklyPlan(mWeeklyExercisePlan);
				break;
			case 7:
				editDailyPlan(mWeeklyDietPlan);
				break;
			case 8:
				editDailyPlan(mWeeklyExercisePlan);
				break;
			case 9:
				storeWeeklyPlan(mOutputDPlan, mWeeklyDietPlan);
				storeWeeklyPlan(mOutputEPlan, mWeeklyExercisePlan);
				break;
			default:
				cout << "Selection out of bounds!\n";
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

void FitnessAppWrapper::loadWeeklyPlan(ifstream& inputStream, WeeklyEPlan& newPlan)
{
	while (!inputStream.eof())
	{
		ExercisePlan temp;
		loadDailyPlan(inputStream, temp);
		newPlan.insertAtEnd(temp);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream& inputStream, WeeklyDPlan& newPlan)
{
	while (!inputStream.eof())
	{
		DietPlan temp;
		loadDailyPlan(inputStream, temp);
		newPlan.insertAtEnd(temp);
	}
}

void FitnessAppWrapper::storeDailyPlan(ofstream& outputStream, DietPlan& DPlan)
{
	outputStream << DPlan;
}

void FitnessAppWrapper::storeDailyPlan(ofstream& outputStream, ExercisePlan& EPlan)
{
	outputStream << EPlan;
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream& outputStream, WeeklyDPlan& DPlans)
{
	NodeDP* pCur = DPlans.getpHead();

	while (pCur->getpNext() != nullptr)
	{
		DietPlan temp = pCur->getDietPlan();
		storeDailyPlan(outputStream, temp);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(ofstream& outputStream, WeeklyEPlan& EPlans)
{
	NodeEP* pCur = EPlans.getpHead();

	while (pCur->getpNext() != nullptr)
	{
		ExercisePlan temp = pCur->getExercisePlan();
		storeDailyPlan(outputStream, temp);
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

void FitnessAppWrapper::editDailyPlan(WeeklyDPlan& DPlans)
{
	int selection = 0;
	NodeDP* pCur = DPlans.getpHead();

	while (selection != 8)
	{
		cout << "For which day of the week you wish to edit?\nSelect [1-7] or 8 to exit.\n";
		cin >> selection;
		if (selection > 1 && selection < 7)
		{
			string name, date;
			int cal;

			for (int i = 0; i < selection; i++)
			{
				pCur = pCur->getpNext();
			}
			pCur->getDietPlan().editGoal();
		}
		else if (selection != 8)
		{
			cout << "Selection out of bounds!\n";
		}
		
	}
	cout << "Exiting...\n";
}

void FitnessAppWrapper::editDailyPlan(WeeklyEPlan& EPlans)
{
	int selection = 0;
	NodeEP* pCur = EPlans.getpHead();

	while (selection != 8)
	{
		cout << "For which day of the week you wish to edit?\nSelect [1-7] or 8 to exit.\n";
		cin >> selection;
		if (selection > 1 && selection < 7)
		{
			string name, date;
			int cal;

			for (int i = 0; i < selection; i++)
			{
				pCur = pCur->getpNext();
			}
			pCur->getExercisePlan().editGoal();
		}
		else if (selection != 8)
		{
			cout << "Selection out of bounds!\n";
		}

	}
	cout << "Exiting...\n";
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






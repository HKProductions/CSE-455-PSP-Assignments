#include "lineCounter.h"

lineCounter::lineCounter(string fileName)
{
	this->fileName = fileName;
}

void lineCounter::ObjectsAndFunctions()
{
	length = 0;
	string line = "";

	int objectsCount = 0;
	int functionsCount = 0;
	input.open(fileName.c_str());
	while (getline(input, line)) {
		if (!ignore(line)) {
			if (line[line.find("class")] == 'c') {
				status = 1;
				objectName.push_back(getClassName(line));
			}
			if (line[line.find("(")] == '(' && line[line.find(");")] == ')' && status == 1)
				functionsCount++;
			if (line[line.find("(")] == '(' && line[line.find("){")] == ')' && status == 1)
				functionsCount++;
			if (line[line.find("};")] == '}' && status == 1) {
				objectsCount++;
				functionCount.push_back(functionsCount);
				objectCount.push_back(objectsCount);
				functionsCount = 0;
				objectsCount = 0;
				status = 0;
			}
			if (status == 1)
				objectsCount++;

			length++;
		}
	}
	input.close();
}

void lineCounter::LOC()
{
	string line = "";
	int objectSize = objectName.size();
	int index = 0;
	int functionsCount = 0;
	int lineCount = 0;
	int bracket1 = 0;
	int bracket2 = 0;
	status = 0;
	string currentObject = objectName[index];
	input.open(fileName.c_str());
	while (getline(input, line)) 
	{
		if (!ignore(line)) 
		{
			if (index < objectSize) 
			{
				currentObject = objectName[index];
				if (line[line.find("{")] == '{')
					bracket1++;
				if (line[line.find("}")] == '}')
					bracket2++;
				if (line[line.find("}")] == '}' && status == 1 && bracket1 == bracket2) 
				{
					lineCount++;
					functionsCount++;
					if (functionCount[index] == functionsCount) 
					{
						int total = objectCount[index] + lineCount;
						objectCount[index] = total;
						functionsCount = 0;
						lineCount = 0;
						index++;
						bracket1 = 0;
						bracket2 = 0;
					}
					status = 0;
				}

				if (line[line.find(currentObject + "::")] == currentObject[0] && line[line.find("){")] == ')' && status == 0)
					status = 1;
				if (status == 1)
					lineCount++;
			}
		}
	}
	input.close();

}

void lineCounter::print()
{
	cout << "Lines of Code" << endl;
	for (int i = 0; i < objectName.size(); i++) {
		cout << endl;
		cout << "Class Name: " << objectName[i] << endl;
		cout << "Total Amount of Functions: " << functionCount[i] << endl;
		cout << "Total Number Lines of Code: " << objectCount[i] << endl;
		cout << endl;
	}
	cout << "Total Number Lines of Code in Entire Program: " << length << endl;
}

bool lineCounter::ignore(string a)
{
	cout << a << endl;
	if (a.length() == 0 || a[a.find("//")] == '/')
		return true;

	return false;
}

string lineCounter::getClassName(string name)
{
	string result = "";
	int index = name.find("class");


	name.replace(index, 5, "");
	if (name[name.find(":")] == ':')
	{
		for (int i = 0; i < name.find(":"); i++)
		{
			if (name[i] != ' ')
				result += name[i];
		}
	}
	return result;
}
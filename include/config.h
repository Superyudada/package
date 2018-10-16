#pragma once

/*
* ������
* @date : 2018/09/24
* @author : jihang
*/

#include <vector>

#include "RTI.hh"

using namespace std;

//��������
class ObjectNames {
public:
	string className;
	int attributeNumber;
	vector<string> attributeList;
};

//��������
class ObjectHandles {
public:
	RTI::ObjectClassHandle classHandle;
	int handleNumber;
	vector<RTI::AttributeHandle> handleList;
};
// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� HLAPORTINTERFACE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// HLAPORTINTERFACE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�

/*
* Interface��
* @date : 2018/09/22
* @author : jihang
*/

#include "config.h"

using namespace std;

#ifdef HLAPORTINTERFACE_EXPORTS
#define HLAPORTINTERFACE_API __declspec(dllexport)
#else
#define HLAPORTINTERFACE_API __declspec(dllimport)
#endif

// �����Ǵ� HLAPortInterface.dll ������
class HLAPORTINTERFACE_API CHLAPortInterface {
public:
	//����/����
public:
	CHLAPortInterface();
	virtual ~CHLAPortInterface() {};

	//״̬
public:
	bool isPause;
	bool isEnd;

	//�ӿڷ���
public:
	//��������
	bool createFederation(string fedFile, string federationName);
	//����������������ԱID��ʧ�ܷ���-1��Ĭ�ϼ���fed�ļ��ж������������
	long joinFederation(string federateName, string federationName = "");
	//�˳�����
	bool resignFederation();
	//�������Ĭ������fed�ļ��ж������������
	bool destroyFederation(string federationName = "");
	//��ʼ�������Ŀǰ���޶����࣬����һ��
	ObjectHandles* initOneHandle(ObjectNames);
	//ע������ͬ����
	bool registerSynchronization(string label);
	//���е�ͬ����
	bool synchronizationAchieved(string label);
	//����ʱ�����
	bool enableTimePolicy(double lookahead);
	//���������࣬Ŀǰ���޶����࣬����һ��
	bool publishOne(ObjectHandles*);
	//���Ķ����࣬Ŀǰ���޶����࣬����һ��
	bool subscribeOne(ObjectHandles*);
	//ע�������
	RTI::ObjectHandle registerObject(string className);
	//���Ͷ����࣬Ŀǰ���޶�����
	bool sendObject(RTI::ObjectHandle, RTI::AttributeHandleValuePairSet*);
	//���ն�����,Ŀǰ���޶�����
	virtual void processData(RTI::ObjectHandle,
		const RTI::AttributeHandleValuePairSet&, const char*) = 0;
	//ʱ�䲽��
	bool advanceTime(double timestep);
	//ɾ�������࣬Ŀǰ���޶�����
	bool deleteOne(RTI::ObjectHandle);
	//ͨ��������λ������
	RTI::ObjectClassHandle getObjectClass(RTI::ObjectHandle objectHandle);
};

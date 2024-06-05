#include<iostream>
#include<stdlib.h>
#define STACK_INIT_SIZE 100//����ջ�ĳ�ʼ����СΪ100
#define STACKINCREMENT 10//��������ͼ�10��
using namespace std;

typedef int SElemType;//����SelemType������


typedef struct {
	SElemType* base;//ջ��
	SElemType* top;//ջ��
	int staclzize;//��¼ջ���ܴ�С
}SqStack;

//��ʼ������
void InitStack(SqStack &st) {//�β������ڴ�Ķ�����ֱ�Ӳٿ��ڴ棩
	st.base = new SElemType[STACK_INIT_SIZE];
	//ջ��ָ���һ���ռ�
	st.top = st.base;
	//��ʼ��ջ���ܴ�С
	st.staclzize = STACK_INIT_SIZE;//ջĿǰ��ռ�ÿռ�Ĵ�С�������Ǵ������
	int num;//����Ҫ����ջ������
	cin >> num;//����Ҫ����ջ������ 

	//�ռ䲻���õ������
	while (num>st.staclzize) {
		cout << "������Ĵ�С���ܳ����ҵĳ�ʼ����С" << endl;
		cin >> num;//��������
		
	}
	for (int i = 0; i < num; i++)
	{
		cin >> *st.top;//��Ϊst.top��һ��ָ�룬����Ҫȡָ��
		st.top++;//ÿ����һ��ջ��������һ��
	}
}

//��ջ����
void Push(SqStack &st, SElemType put) {//st��Ҫ�ٿ��ڴ棬put����Ҫ�ٿ��ڴ�
	if (st.top-st.base>=st.staclzize)//ջ���
	{
		st.base = (SElemType*)realloc(st.base, ((st.top - st.base) + STACKINCREMENT) * sizeof(SElemType));//ջ����ռ�(����st.base)
		if (!st.base)//�����ڴ�ʧ��
		{
			return;
		}
		//�����ڴ�ɹ�
		st.top = st.base + st.staclzize;
		st.staclzize += STACKINCREMENT;

	}

	*st.top++ = put;
}

//��ջ����
void Pop(SqStack &st,SElemType get) {
	get = *(st.top - 1);
	st.top--;

}

//���Ҳ���
void GetTop(SqStack& st,SElemType read) {
	read = *(st.top - 1);
}

//�ж�ջ�Ƿ�Ϊ��ջ
bool StackEmpty(SqStack &st) {
	if (st.top == st.base)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ClearStack(SqStack& st) {
	st.top = st.base;
}


int main()
{	
	//����һ��ջ
	SqStack st;
	//��ʼ��
	InitStack(st);

	SElemType put;//��
	Push(st,put);//��ջ(�������)

	SElemType get;//ɾ
	Pop(st, get);//��ջ(ɾ������)
	cout << get << endl;

	SElemType read;
	GetTop(st,read);//��

	//�ж�ջ�Ƿ�Ϊ��ջ
	if (StackEmpty(st))
	{
		cout << "ջ��" << endl;
	}
	else
	{
		cout << "ջ����" << endl;
	}

	//���ջ
	ClearStack(st);

	system("pause");
	return 0;
}


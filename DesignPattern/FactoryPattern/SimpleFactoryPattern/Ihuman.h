
#include<iostream>

class IHuman                    //������࣬���ܴ��������͵Ķ��󣬵��ǿ��Դ���
								//������Ͷ����ָ���������
{
public:
	IHuman(void)
	{

	}
	~IHuman()                 //�������������Ҫ��������������
	{

	}
	virtual void Laugh() = 0;   //���麯�����������б������������������Լ��İ汾
	virtual void Cry() = 0;
	virtual void Talk() = 0;
 

};

class WhiteHuman : public IHuman
{
public:
	WhiteHuman(void)
	{

	}
	~WhiteHuman(void)
	{

	}
	void Laugh()
	{
		std::cout << "������Ц��" << std::endl;
	}
	void Cry()
	{
		std::cout << "�����˿ޣ�" << std::endl;
	}
	void Talk()
	{
		std::cout << "������˵����" << std::endl;
	}
};

class YellowHuman : public IHuman
{
public:
	YellowHuman(void)
	{

	}
	~YellowHuman(void)
	{

	}
	void Laugh()
	{
		std::cout << "������Ц��" << std::endl;
	}
	void Cry()
	{
		std::cout << "�����˿ޣ�" << std::endl;
	}
	void Talk()
	{
		std::cout << "������˵����" << std::endl;
	}
};

class BlackHuman : public IHuman
{
public:
	BlackHuman(void)
	{

	}
	~BlackHuman(void)
	{

	}
	void Laugh()
	{
		std::cout << "������Ц��" << std::endl;
	}
	void Cry()
	{
		std::cout << "�����˿ޣ�" << std::endl;
	}
	void Talk()
	{
		std::cout << "������˵����" << std::endl;
	}
};
class IHumanFactory                          //���󹤳�����
{
public:
	IHumanFactory(void)
	{

	}
	~IHumanFactory(void)
	{

	}
	virtual IHuman* CreateHuman() = 0;   //�������Ĵ����������ڲ�һ�㺬��new�����Ķ�
										 //��

};

class WhiteHumanFactory : public IHumanFactory
{
public:
	WhiteHumanFactory(void)
	{

	}
	~WhiteHumanFactory(void)
	{

	}
	IHuman *CreateHuman()           //����ʵ����Ĵ������������ڴ�������Ķ���
	{
		return new WhiteHuman();
	}

};


class YellowHumanFactory : public IHumanFactory
{
public:
	YellowHumanFactory(void)
	{

	}
	~YellowHumanFactory(void)
	{

	}
	IHuman *CreateHuman()
	{
		return new YellowHuman();
	}

};
class BlackHumanFactory : public IHumanFactory
{
public:
	BlackHumanFactory(void)
	{

	}
	~BlackHumanFactory(void)
	{

	}
	IHuman *CreateHuman()
	{
		return new BlackHuman();
	}
};

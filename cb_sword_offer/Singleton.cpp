#include <iostream>

using namespace std;

///����ģʽ
//
//1 ����ʽ���̲߳���ȫ��
//class Singleton{
//private:
//    static Singleton* st;
//    Singleton(){
//        cout<<"Singleton created!"<<endl;
//    };
//public:
//    static Singleton* getInstance(){
//    if(st==nullptr){
//        st=new Singleton();
//    }
//    return st;
//    };
//};
//
//Singleton* Singleton::st;
//Singleton *st1=Singleton::getInstance();

//2 ����ʽ���̰߳�ȫ���Ƽ�
//class Singleton{
//private:
//    Singleton(){cout<<"Singleton created!"<<endl;};
//    //Singleton(const Singleton&);
//	Singleton& operator=(const Singleton&);
//public:
//    static Singleton& getinstance(){
//        static Singleton st;            //ʹ�þֲ���̬����
//        return st;
//    }
//};
//Singleton st1=Singleton::getinstance();


//3 ����ʽ
//class Singleton{
//private:
//    static Singleton st;
//    Singleton(){
//        cout<<"Singleton created!"<<endl;
//    }
//public:
//    static Singleton&  getInstance(){
//        return st;
//    }
//};
//
//Singleton Singleton::st;    //ִ�й��캯��
//Singleton st1=Singleton::getInstance();



//main����֮ǰ���ǵ��߳�


#include <iostream>

using namespace std;

///单例模式
//
//1 懒汉式（线程不安全）
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

//2 懒汉式（线程安全）推荐
//class Singleton{
//private:
//    Singleton(){cout<<"Singleton created!"<<endl;};
//    //Singleton(const Singleton&);
//	Singleton& operator=(const Singleton&);
//public:
//    static Singleton& getinstance(){
//        static Singleton st;            //使用局部静态变量
//        return st;
//    }
//};
//Singleton st1=Singleton::getinstance();


//3 饿汉式
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
//Singleton Singleton::st;    //执行构造函数
//Singleton st1=Singleton::getInstance();



//main函数之前都是单线程


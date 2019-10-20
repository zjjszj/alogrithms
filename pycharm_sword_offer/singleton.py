#1 使用__new__
class Singleton(object):
    _instance = None
    def __new__(cls, *args, **kwargs):
        if not cls._instance:
            cls._instance=super(Singleton,cls).__new__(cls)     #调用object的__new__函数为Singleton类型的对象分配空间
        return cls._instance
    def __init__(self):                                         #调用完__new__，执行__init__
        pass
one=Singleton()
two=Singleton()
print(id(one),",",id(two))

#2 作为包被导入使用
# from singleton import my_singleton        #my_singleton是Singleton类的一个对象
# my_singleton.foo()
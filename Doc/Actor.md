## 什么是Actor

可放入关卡中的对象都是 **Actor**。Actor是一种支持三维变换（如平移、旋转和缩放）的泛型类。你可以通过游戏逻辑代码（C++或蓝图）创建（生成）及销毁Actor。在C++中，AActor是所有Actor的基类。

## 项目目录

[ActorOperate](https://github.com/hliangs/UnrealEngineSamples/tree/master/ActorOperate)

## Actor基本操作

- 自定义一个Actor

  使用UE类向导创建一个C++类，父类选择Actor，如图

  

![CreateActor](https://github.com/hliangs/UnrealEngineSamples/blob/master/Pic/CreateActor.png)

要注意的是，Actor的派生类类名以A开头。

## SpawnActor(创建/复制)

[头文件](https://github.com/hliangs/UnrealEngineSamples/blob/master/ActorOperate/Source/ActorOperate/Actors/EventActor.h)

[源文件](https://github.com/hliangs/UnrealEngineSamples/blob/master/ActorOperate/Source/ActorOperate/Actors/EventActor.cpp)

[[参见(资源创建加载.md)]](资源创建加载.md)
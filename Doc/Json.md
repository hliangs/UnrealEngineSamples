## Json文件的简单读写

- UE中提供了操作Json文件的类FJsonObject
- 使用其他的第三方库实现Json文件的读写(以后会写)

## 项目目录

[JsonRW](https://github.com/hliangs/UnrealEngineSamples/tree/master/JsonRW)

## 依赖

###### "Json", "JsonUtilities" 

## FJsonObject例子

```c++
void AMyJsonRW::WriteJson()
{
	FString Path("D:\\JsonRW.json");//文件路径
	FString JsonData_Write_Buff;
	
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);//创建一个FJsonObject对象
	TSharedPtr<FJsonObject> jsonObject_Child = MakeShareable(new FJsonObject);//创建一个FJsonObject对象

	JsonObject->SetStringField("Field", FString("Value"));//设置字段值
	jsonObject_Child->SetStringField("Field", FString("Value"));//Child设置字段值
	jsonObject_Child->SetBoolField("BOOL", false);//Child设置字段值
	jsonObject_Child->SetNumberField("Number", 123456789);//Child设置字段值

	//生成一个数组
	TSharedPtr<FJsonValueNumber> Number0 = MakeShareable(new FJsonValueNumber(1));
	TSharedPtr<FJsonValueNumber> Number1 = MakeShareable(new FJsonValueNumber(2));
	TArray<TSharedPtr<FJsonValue>> JsonValueArray;
	JsonValueArray.Add(Number0);
	JsonValueArray.Add(Number1);

	
	jsonObject_Child->SetArrayField("Array", JsonValueArray);//Child加入一个数组
	JsonObject->SetObjectField("Child_Object", jsonObject_Child);//加入一个对象
	if (JsonObject.IsValid() && JsonObject->Values.Num() > 0)
	{
        
        //创建一个JsonWriter
		TSharedRef<TJsonWriter<TCHAR>> writer = TJsonWriterFactory<>::Create(&JsonData_Write_Buff);
		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), writer);//序列化
	}
	FFileHelper::SaveStringToFile(JsonData_Write_Buff, *Path);//写文件
}

/*上述代码生成的Json结构
{
	"Field": "Value",
	"Child_Object":
	{
		"Field": "Value",
		"BOOL": false,
		"Number": 123456789,
		"Array": [ 1, 2 ]
	}
}
*/

//这里只写了读取字符串类型
void AMyJsonRW::ReadJson(FString& path, FString& Field, FString& value)
{
	FString JsonData_Read_Buff;
	if (!FFileHelper::LoadFileToString(JsonData_Read_Buff, *path)) //读取
	{
		return;
	}
	TSharedRef<TJsonReader<>> reader = TJsonReaderFactory<>::Create(JsonData_Read_Buff);//创建一个JsonReader
    
	//TSharedPtr<FJsonValue> JsonValueArray;//用法同下
	TSharedPtr<FJsonObject> JsonObject;
	if (!FJsonSerializer::Deserialize(reader, JsonObject))//反序列化
		return;
	//修改这里就可以读取其他类型了
    //转化为FJsonValue对象
	TSharedPtr<FJsonValue> JsonValue = JsonObject->GetField<EJson::String/*字段类型*/>(Field);
	value = JsonValue->AsString(); //获取段值string
}
```


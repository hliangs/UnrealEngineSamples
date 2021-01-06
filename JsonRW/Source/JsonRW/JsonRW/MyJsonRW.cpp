// Fill out your copyright notice in the Description page of Project Settings.


#include "MyJsonRW.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"
// Sets default values
AMyJsonRW::AMyJsonRW()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
void AMyJsonRW::WriteJson()
{
	//FPaths::ProjectContentDir()
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
		TSharedRef<TJsonWriter<TCHAR>> writer = TJsonWriterFactory<>::Create(&JsonData_Write_Buff);//创建一个JsonWriter
		//writer->WriteObjectStart();//{
		//writer->WriteObjectEnd();//}
		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), writer);//序列化到JsonData_w
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
	if (!FFileHelper::LoadFileToString(JsonData_Read_Buff, *path)) //读取到JsonData_r
	{
		return;
	}
	TSharedRef<TJsonReader<>> reader = TJsonReaderFactory<>::Create(JsonData_Read_Buff);//创建一个JsonReader
	
	TSharedPtr<FJsonValue> JsonValueArray;
	TSharedPtr<FJsonObject> JsonObject;
	
	if (!FJsonSerializer::Deserialize(reader, JsonObject))//反序列化
		return;
	//修改这里就可以读取其他类型了
	TSharedPtr<FJsonValue> JsonValue = JsonObject->GetField<EJson::String/*字段类型*/>(Field);//转化为FJsonValue对象
	value = JsonValue->AsString(); //获取段值string
}

// Called when the game starts or when spawned
void AMyJsonRW::BeginPlay()
{
	Super::BeginPlay();
	UInputComponent* Input = NewObject<UInputComponent>(this);
	Input->BindKey(EKeys::U, IE_Pressed, this, &AMyJsonRW::UKeyEvent);
	Input->BindKey(EKeys::I, IE_Pressed, this, &AMyJsonRW::IKeyEvent);
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	Controller->PushInputComponent(Input);
}

void AMyJsonRW::IKeyEvent()
{
	FString path("D:\\JsonRW.json");
	FString Field("Field");
	FString Value;
	ReadJson(path, Field, Value);
	UE_LOG(LogTemp, Error, TEXT("Field is %s"),*Value);
	FString LogMsg = FString::Printf(TEXT("Field is %s"), *Value);
	if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, LogMsg);
}

void AMyJsonRW::UKeyEvent()
{
	WriteJson();
	UE_LOG(LogTemp, Error, TEXT("write Json Finished"));
	if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "write Json Finished");
}


// Called every frame
void AMyJsonRW::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


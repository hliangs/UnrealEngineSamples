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
	FString Path("D:\\JsonRW.json");//�ļ�·��
	FString JsonData_Write_Buff;
	
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);//����һ��FJsonObject����
	TSharedPtr<FJsonObject> jsonObject_Child = MakeShareable(new FJsonObject);//����һ��FJsonObject����

	JsonObject->SetStringField("Field", FString("Value"));//�����ֶ�ֵ
	jsonObject_Child->SetStringField("Field", FString("Value"));//Child�����ֶ�ֵ
	jsonObject_Child->SetBoolField("BOOL", false);//Child�����ֶ�ֵ
	jsonObject_Child->SetNumberField("Number", 123456789);//Child�����ֶ�ֵ

	//����һ������
	TSharedPtr<FJsonValueNumber> Number0 = MakeShareable(new FJsonValueNumber(1));
	TSharedPtr<FJsonValueNumber> Number1 = MakeShareable(new FJsonValueNumber(2));
	TArray<TSharedPtr<FJsonValue>> JsonValueArray;
	JsonValueArray.Add(Number0);
	JsonValueArray.Add(Number1);

	
	jsonObject_Child->SetArrayField("Array", JsonValueArray);//Child����һ������
	JsonObject->SetObjectField("Child_Object", jsonObject_Child);//����һ������
	if (JsonObject.IsValid() && JsonObject->Values.Num() > 0)
	{
		TSharedRef<TJsonWriter<TCHAR>> writer = TJsonWriterFactory<>::Create(&JsonData_Write_Buff);//����һ��JsonWriter
		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), writer);//���л���JsonData_w
	}
	FFileHelper::SaveStringToFile(JsonData_Write_Buff, *Path);//д�ļ�
}

/*�����������ɵ�Json�ṹ
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

//����ֻд�˶�ȡ�ַ�������
void AMyJsonRW::ReadJson(FString& path, FString& Field, FString& value)
{
	FString JsonData_Read_Buff;
	if (!FFileHelper::LoadFileToString(JsonData_Read_Buff, *path)) //��ȡ��JsonData_r
	{
		return;
	}
	TSharedRef<TJsonReader<>> reader = TJsonReaderFactory<>::Create(JsonData_Read_Buff);//����һ��JsonReader
	
	TSharedPtr<FJsonValue> JsonValueArray;
	TSharedPtr<FJsonObject> JsonObject;
	
	if (!FJsonSerializer::Deserialize(reader, JsonObject))//�����л�
		return;
	//�޸�����Ϳ��Զ�ȡ����������
	TSharedPtr<FJsonValue> JsonValue = JsonObject->GetField<EJson::String/*�ֶ�����*/>(Field);//ת��ΪFJsonValue����
	value = JsonValue->AsString(); //��ȡ��ֵstring
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


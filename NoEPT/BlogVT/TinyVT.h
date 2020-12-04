#pragma once
#include"def.h"
#include"Asm.h"

#define VMM_STACK_SIZE 10*PAGE_SIZE

class TinyVT
{
public:
	int index;
	BOOLEAN isEnable;

	TinyVT(int index);
	~TinyVT();
	BOOLEAN StartVT();
private:
	BOOLEAN ExecuteVMXON();
	BOOLEAN InitVMCS(PVOID guestStack, PVOID guestResumeRip);

	ULONG_PTR VMX_Region;
	ULONG_PTR VMCS_Region;
	ULONG_PTR MsrBitmap;
	PCHAR VmmStack;
};

//���ڻ�ȡC++�����Ա������ַ
typedef union
{
	PVOID addr;
	BOOLEAN(TinyVT::* fun)(PVOID, PVOID);
} FunAddr;
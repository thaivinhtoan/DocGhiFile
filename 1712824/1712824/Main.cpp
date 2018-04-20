#include "Header.h"

/*
Do an duoc thuc hien tren VS 2013
Khong co LOI bien dich
*/

void main()
{
	FILE *fSV_in = _wfopen(L"ThongTinSinhVien.csv", L"rt, ccs=UTF-8");

	if (!fSV_in){
		printf("Khong tim thay file!!!\n");
	}
	else
	{
		_XuLiFile(fSV_in);
		fclose(fSV_in);
	}
	
}

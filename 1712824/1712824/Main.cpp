#include "Header.h"

void main()
{
	FILE *fSV_in = _wfopen(L"ThongTinSinhVien.csv", L"rt, ccs=UTF-8");

	if (!fSV_in){
		printf("Khong tim thay file!!!\n");
	}
	else
	{
		_DocFile(fSV_in);
		fclose(fSV_in);
	}
	
}

#include "Header.h"

void main()
{
	_setmode(_fileno(stdout), _O_U16TEXT); // Output

	FILE *fSV_in = _wfopen(L"ThongTinSinhVien.csv", L"rt, ccs=UTF-8");

	if (!fSV_in){
		printf("Khong tim thay file!!!\n");
	}
	else
	{
		_XuLiFile(fSV_in);
		fclose(fSV_in);

		wprintf(L"ĐÃ HOÀN THÀNH\n File được lưu trong //Output\n");
	}	
}

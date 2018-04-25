#include "Header.h"

/*
  Các bước chương trình thực hiện:
  -From file to struct
  -Sandardized data (delete redundant character (Ex: ' , " ) )
  -Create file .htm
  -Write recent .htm
  -Close file and finish program
*/

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

#include "Header.h"

void _XuLiFile(FILE* &f)
{
	SINHVIEN sv ;
	rewind(f);
	if (f != NULL)
	{
		while (!feof(f))
		{
			fwscanf(f, L"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^'\n']\n", &sv.MSSV, &sv.HoTen, &sv.Khoa, &sv.KhoaHoc, &sv.NgaySinh, &sv.Email, &sv.AnhCaNhan, &sv.MoTaBanThan, &sv.SoThich);
			_ChuanHoaSV(sv);
			_XuatHTML(sv);
		}
	}
}


void _XuatHTML(SINHVIEN &sv)
{
	//Tao file
	wchar_t Folder[30] = L"Output\\";
	wchar_t File[15];
	wcscpy(File, sv.MSSV);
	wcscat(File, L".htm");
	wcscat(Folder,	File);
	FILE* f = _wfopen(Folder, L"w");
	_setmode(_fileno(f), _O_U8TEXT);

	//Ghi File
	if (f != NULL)
	{
		fwprintf(f, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
		fwprintf(f, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
		fwprintf(f, L"<head>\n");
		fwprintf(f, L"<meta http-equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" / >\n");
		fwprintf(f, L"<link rel = \"stylesheet\" type = \"text/css\" href = \"personal.css\" / >\n");
		fwprintf(f, L"<title>HCMUS - %ls</title>\n", sv.HoTen);
		fwprintf(f, L"</head>\n");
		fwprintf(f, L"<body>\n");
		fwprintf(f, L"<div class = \"Layout_container\">\n");
		fwprintf(f, L"<!--Begin Layout Banner Region-->\n");
		fwprintf(f, L"<div class = \"Layout_Banner\" >\n");
		fwprintf(f, L"<div><img id = \"logo\" src = \"Images/logo.jpg\" height = \"105\" / ></div>\n");
		fwprintf(f, L"<div class = \"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Layout Banner Region-->\n");
		fwprintf(f, L"<!--Begin Layout MainContents Region-->\n");
		fwprintf(f, L"<div class = \"Layout_MainContents\">\n");
		fwprintf(f, L"<!--Begin Below Banner Region-->\n");
		fwprintf(f, L"<div class = \"Personal_Main_Information\">\n");
		fwprintf(f, L"<!--Begin Thông tin cá nhân của thầy cô---------------------------------------------------------------------------------------- - -->\n");
		fwprintf(f, L"<div class = \"Personal_Location\">\n");
		fwprintf(f, L"<img src = \"Images/LogoFooter.jpg\" width = \"27\" height = \"33\" / >\n");
		fwprintf(f, L"<span class = \"Personal_FullName\">%ls - %ls</span>\n", sv.HoTen, sv.MSSV);
		fwprintf(f, L"<div class = \"Personal_Department\">%ls</div>\n", sv.Khoa);
		fwprintf(f, L"<br />\n");
		fwprintf(f, L"<div class = \"Personal_Phone\">\n");
		fwprintf(f, L"Khóa : %ls\n", sv.KhoaHoc);
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<br />\n");
		fwprintf(f, L"<br />\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Thông tin cá nhân của thầy cô---------------------------------------------------------------------------------------- - -->\n");
		fwprintf(f, L"<div class = \"Personal_HinhcanhanKhung\">\n");
		fwprintf(f, L"<img src = \"Images/%ls\" class = \"Personal_Hinhcanhan\" / >\n", sv.AnhCaNhan);
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Below Banner Region-->\n");
		fwprintf(f, L"<!--Begin MainContents Region-->\n");
		fwprintf(f, L"<div class = \"MainContain\">\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"<!--Begin Top Region-->\n");
		fwprintf(f, L"<div class = \"MainContain_Top\">\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"<div class = \"InfoGroup\">Thông tin cá nhân</div>\n");
		fwprintf(f, L"<div>\n");
		fwprintf(f, L"<ul class = \"TextInList\">\n");
		fwprintf(f, L"<li>Họ và tên : %ls</li>\n", sv.HoTen);
		fwprintf(f, L"<li>MSSV : %ls</li>\n", sv.MSSV);
		fwprintf(f, L"<li>Sinh viên khoa : %ls</li>\n", sv.Khoa);
		fwprintf(f, L"<li>Email : %ls</li>\n", sv.Email);
		fwprintf(f, L"<li>Ngày sinh : %ls</li>\n", sv.NgaySinh);
		fwprintf(f, L"</ul>\n");
		fwprintf(f, L"</div>\n");
		if (iDemSoThich(sv.SoThich) > 0) 
		{
			fwprintf(f, L"<div class = \"InfoGroup\">Sở thích</div>\n");
			fwprintf(f, L"<div>\n");
			fwprintf(f, L"<ul class = \"TextInList\">\n");
			fwprintf(f, L"	<li>%ls</li>\n", sv.SoThich);
			/*int temp=0;
			for (int n = 1; n <= iDemSoThich(sv.SoThich); n++)
			{
				fwprintf(f, L"	<li>");
				while (sv.SoThich[temp] != ',' || sv.SoThich[temp] != '\0') {
					wchar_t ch = sv.SoThich[temp];
					fputwc(ch, f);
					temp++;
				}
				fwprintf(f, L"</li>\n");
			}*/
			fwprintf(f, L"</ul>\n");
			fwprintf(f, L"</div>\n");
		}
		fwprintf(f, L"<div class = \"InfoGroup\">Mô tả</div>\n");
		fwprintf(f, L"<div class = \"Description\">\n");
		fwprintf(f, L"%ls\n", sv.MoTaBanThan);
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"<!--Begin Layout Footer-->\n");
		fwprintf(f, L"<div class = \"Layout_Footer\">\n");
		fwprintf(f, L"<div class = \"divCopyright\">\n");
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"<img src = \"Images/LogoFooter_gray.jpg\" width = \"34\" height = \"41\" / ><br/>\n");
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"@2018</br>\n");
		fwprintf(f, L"Đồ án giữa kỳ</br>\n");
		fwprintf(f, L"Kỹ thuật lập trình</br>\n");
		fwprintf(f, L"TH2018 / 04</br>\n");
		fwprintf(f, L"1712824 - Thái Vĩnh Toàn </br>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Layout Footer-->\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</body>\n");
		fwprintf(f, L"</html>");
	}
	fclose(f);
}

void _ChuanHoaSV(SINHVIEN &sv)
{
	_ChuanHoa(sv.MSSV);
	_ChuanHoa(sv.HoTen);
	_ChuanHoa(sv.Khoa);
	_ChuanHoa(sv.KhoaHoc);
	_ChuanHoa(sv.NgaySinh);
	_ChuanHoa(sv.Email);
	_ChuanHoa(sv.AnhCaNhan);
	_ChuanHoa(sv.MoTaBanThan);
	_ChuanHoa(sv.SoThich, 1);
}

int iDemSoThich(wchar_t* n)
{
	//Khong co so thich
	if (iStringLength(n) == 0) return 0;

	int dem = 1;
	for (int i = 0; i< iStringLength(n); i++) {
		if (*(n + i) == ',') dem++;
	}

	return dem;
}
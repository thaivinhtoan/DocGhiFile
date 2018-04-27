#include "Header.h"

wchar_t FolderOutput[] = L"Output\\";
wchar_t FileTail[] = L".htm";
wchar_t YearSetup[] = L"2018";
wchar_t NumberStudent_Name[] = L"1712824 - Thái Vĩnh Toàn";

wchar_t FileMau[] = L"Output\\Mau.htm";

wchar_t Title[] = L"<title>HCMUS - ";
wchar_t NameMSSV[] = L"\"Personal_FullName\">";
wchar_t FacUp[] = L"\"Personal_Department\">KHOA ";
wchar_t EmailTop[] = L"Email: ";
wchar_t EndEmailTop[] = L"\n";
wchar_t Photo[] = L"<img src=\"Images/";
wchar_t EndPhoto[] = L"\" class=\"Personal_Hinhcanhan";

wchar_t Name[] = L"<li>Họ và tên: ";
wchar_t MSSV[] = L"<li>MSSV: ";
wchar_t	Khoa[] = L"<li>Sinh viên khoa ";
wchar_t EmailBot[] = L"<li>Email: ";
wchar_t Birth[] = L"<li>Ngày sinh: ";
wchar_t Mota[] = L"Description";
wchar_t Hobby[] = L"Sở thích";
wchar_t HobbyEnd[] = L"</ul>";
wchar_t HobbyElement[] = L"<li>";
wchar_t End[] = L"</";	

wchar_t Year[] = L"@";
wchar_t EndFooter[] = L"</br>";
wchar_t InfoFooter[] = L"MSSV - Tên sinh viên thực hiện";



//From file to struct
void _XuLiFile(FILE* &f)
{
	SINHVIEN sv;
	//sv.KhoaHoc
	wchar_t wKhoaHoc[size_KhoaHoc];
	int i = 0;
	rewind(f);
	if (f != NULL)
	{
		while (!feof(f))
		{
			//Input data
			fwscanf(f, L"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^'\n']\n", &sv.MSSV, &sv.HoTen, &sv.Khoa, &wKhoaHoc, &sv.NgaySinh, &sv.Email, &sv.AnhCaNhan, &sv.MoTaBanThan, &sv.SoThich);
			i++;
			//Sandardized SINHVIEN
			_ChuanHoaSV(sv);
			//add sv.KhoaHoc
			sv.KhoaHoc = StrtoInt(wKhoaHoc);
			//Print out console
			PrintSV(sv, i);

			//Tao .htm
			_XuatHTML(sv);
		}
	}
}

void PrintSV(SINHVIEN sv, int i)
{
	wprintf(L"\n\nThông tin của sinh viên thứ %ld:\n\n", i);
	wprintf(L" - MSSV: %ls\n", sv.MSSV);
	wprintf(L" - Họ và tên: %ls\n", sv.HoTen);
	wprintf(L" - Khoa: %ls\n", sv.Khoa);
	wprintf(L" - Khóa học: %ld\n", sv.KhoaHoc);
	wprintf(L" - Ngày sinh: %ls\n", sv.NgaySinh);
	wprintf(L" - Email: %ls\n", sv.Email);
	wprintf(L" - Ảnh cá nhân: %ls\n", sv.AnhCaNhan);
	wprintf(L" - Mô tả bản thân: %ls\n", sv.MoTaBanThan);
	if (iDemSoThich(sv.SoThich) == 0)
		wprintf(L" - Sở thích: Không có sở thích\n");
	else
		wprintf(L" - Sở thích: %ls\n", sv.SoThich);
}

//Create && write file .htm
void _XuatHTML(SINHVIEN sv)
{
	
	FILE* Mau = _wfopen(FileMau , L"rt, ccs=UTF-8");
	if (!Mau) {
		wprintf(L"\n\n\n%ls not exist\n\n\n",FileMau);
		return;
	}

	//Create file .htm
	wchar_t* Folder = (wchar_t*)malloc(sizeof(wchar_t) * 30);
	wchar_t* File = (wchar_t*)malloc(sizeof(wchar_t) * 15);
	wcscpy(Folder, FolderOutput);
	wcscpy(File, sv.MSSV);
	wcscat(File, FileTail);
	wcscat(Folder, File);
	FILE* f = _wfopen(Folder, L"w");
	_setmode(_fileno(f), _O_U8TEXT);
	free(Folder);
	free(File);

	wchar_t* KHOA = (wchar_t*)malloc(sizeof(wchar_t) * 30);
	wcscpy(KHOA, sv.Khoa);
	_ChuanHoa(KHOA, 2);

	wchar_t* Ten_MSSV = (wchar_t*)malloc(sizeof(wchar_t) * 50);
	wcscpy(Ten_MSSV, sv.HoTen);
	wcscat(Ten_MSSV, L" - ");
	wcscat(Ten_MSSV, sv.MSSV);

	int i;
	wchar_t* buf = (wchar_t*)malloc(1024);

	while (!feof(Mau)) {
		fgetws(buf, 1024, Mau);
		ReplaceString(buf, Title, End, sv.HoTen);
		ReplaceString(buf, FacUp, End, KHOA);
		ReplaceString(buf, EmailTop, EndEmailTop, sv.Email);
		ReplaceString(buf, NameMSSV, End, Ten_MSSV);
		ReplaceString(buf, Photo, EndPhoto, sv.AnhCaNhan);
		ReplaceString(buf, Name, End, sv.HoTen);
		ReplaceString(buf, MSSV, End, sv.MSSV);
		ReplaceString(buf, Khoa, End, sv.Khoa);
		ReplaceString(buf, Birth, End, sv.NgaySinh);
		ReplaceString(buf, EmailBot, End, sv.Email);
		ReplaceString(buf, Year, EndFooter, YearSetup);

		if (wcsstr(buf, Mota) != NULL) {
			fputws(buf, f);
			fgetws(buf, 1024, Mau);
			wchar_t keyend[] = L"\n";
			int i = 0;
			wchar_t* keybegin = (wchar_t*)malloc(125);
			for (i = 0; buf[i] == '\t' || buf[i] == ' '; i++)
			{
				keybegin[i] = buf[i];
			}
			keybegin[i] = '\0';

			ReplaceString(buf, keybegin, keyend, sv.MoTaBanThan);

			free(keybegin);
		}

		//Change sv.SoThich
		if (wcsstr(buf, Hobby) != NULL) {
			for (i = 1; i <= 3; i++) {
				fputws(buf, f);
				fgetws(buf, 1024, Mau);
			}

			if (iDemSoThich(sv.SoThich) == 0) {
				fgetws(buf, 1024, Mau);
				fgetws(buf, 1024, Mau);
			}
			else {
				ReplaceString(buf, HobbyElement, End, sv.SoThich);
				fputws(buf, f);
				fgetws(buf, 1024, Mau);
				fgetws(buf, 1024, Mau);
			}
		}

		//Change late file
		if (wcsstr(buf, InfoFooter) != NULL) {
			wchar_t* keybegin = (wchar_t*)malloc(125);
			for (i = 0; buf[i] != '\t' && buf[i] != ' '; i++)
			{
				keybegin[i] = buf[i];
			}
			keybegin[i] = '\0';

			ReplaceString(buf, keybegin, EndFooter, NumberStudent_Name);
			free(keybegin);
		}

		fputws(buf, f);
	}

	//Close file && delete memory
	fclose(Mau);
	fclose(f);
	free(KHOA);
	free(Ten_MSSV);
	free(buf);
}

//Sandardized string in SINHVIEN struct
void _ChuanHoaSV(SINHVIEN &sv)
{
	_ChuanHoa(sv.MSSV);
	_ChuanHoa(sv.HoTen);
	_ChuanHoa(sv.Khoa);
	_ChuanHoa(sv.NgaySinh);
	_ChuanHoa(sv.Email);
	_ChuanHoa(sv.AnhCaNhan);
	_ChuanHoa(sv.MoTaBanThan);
	_ChuanHoa(sv.SoThich, 1);
}

//Count hoppy
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
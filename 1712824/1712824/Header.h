#include <stdio.h>
#include <stdlib.h>
#include <wchar.h> //wchar_t
#include <fcntl.h> //_O_U8TEXT
#include <io.h>    //_setmode( )


struct SinhVien
{
	wchar_t MSSV[11];
	wchar_t HoTen[31];
	wchar_t Khoa[31];
	wchar_t KhoaHoc[5];
	wchar_t NgaySinh[11];
	wchar_t Email[31];
	wchar_t AnhCaNhan[50];
	wchar_t MoTaBanThan[1001];
	wchar_t SoThich[1001];
};
typedef struct SinhVien SINHVIEN;

void _XuLiFile(FILE* &f);
void _XuatHTML(SINHVIEN &sv);
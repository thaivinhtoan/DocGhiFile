#include <stdio.h>
#include <stdlib.h>
#include <wchar.h> //wchar_t
#include <fcntl.h> //_O_U8TEXT
#include <io.h>    //_setmode( ) && _open()

//So luong ki tu toi da cua chuoi  -->> De thay doi khi can
#define size_MSSV        11
#define size_HoTen       31
#define size_Khoa        31
#define size_KhoaHoc     5
#define size_NgaySinh    11
#define size_Email       31
#define size_AnhCaNhan   31
#define size_MoTaBanThan 1001
#define size_SoThich     1001

struct SinhVien
{
	wchar_t MSSV[size_MSSV];
	wchar_t HoTen[size_HoTen];
	wchar_t Khoa[size_Khoa];
	wchar_t KhoaHoc[size_KhoaHoc];
	wchar_t NgaySinh[size_NgaySinh];
	wchar_t Email[size_Email];
	wchar_t AnhCaNhan[size_AnhCaNhan];
	wchar_t MoTaBanThan[size_MoTaBanThan];
	wchar_t SoThich[size_SoThich];
};
typedef struct SinhVien SINHVIEN;


//Ham
void _XuLiFile(FILE* &f);
void _XuatHTML(SINHVIEN &sv);
void _ChuanHoaSV(SINHVIEN &sv);
int iDemSoThich(wchar_t* n);

//Ham Phu
int iStringLength(wchar_t* s);
wchar_t* CopyString(wchar_t* in, wchar_t* out, int &n);
void _ChuanHoa(wchar_t* A,int = 0);
void _Upper(wchar_t &a);
void _Lower(wchar_t &a);
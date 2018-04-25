#include "Header.h"

//Long string
int iStringLength(wchar_t* s)
{
	int i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return i;
}

//Sandardized string
void _ChuanHoa(wchar_t* A, int x )
{
	int i;
	//Chuan hoa truoc chuoi
	while (*A == ' ' || *A == '"' || *A == '\''|| *A == ','){
		for (i = 0; i<iStringLength(A) - 1; i++)
			*(A + i) = *(A + i + 1);
		A[iStringLength(A) - 1] = '\0';
	}

	//Chuan hoa sau chuoi
	while (A[iStringLength(A) - 1] == ' ' || A[iStringLength(A) - 1] == '"' || A[iStringLength(A) - 1] == '\'' || A[iStringLength(A) - 1] == ',')
	{
		A[iStringLength(A) - 1] = '\0';
	}

	//Xoa khoang cach thua 
	i = 0;
	while (i<iStringLength(A) - 1){

		if (A[i] == ' ')
			if (*(A + i + 1) == ' ')
			{
				for (int j = i + 1; j<iStringLength(A) - 1; j++)
					*(A + j) = *(A + j + 1);
				A[iStringLength(A) - 1] = '\0';
			}
			else
				i++;
		else
			i++;
	}

	//Xoa dau " hoac '
	i = 0;
	while (i < iStringLength(A) - 1)
	{
		if (*(A + i) == '"' || *(A + i) == '\'')
		{
			for (int j = i; j < iStringLength(A) - 1; j++)
				*(A + j) = *(A + j + 1);
			A[iStringLength(A) - 1] = '\0';
		}
		else
			i++;
	}

	//Dung de chuan hoa chuoi SoThich
	if (x != 0) {
		//Viet thuong chuoi
		i = 1;
		while (i < iStringLength(A))
		{
			_Lower(*(A + i));
			i++;
		}

		//Viet hoa chu cai dau chuoi
		i = 0;
		while (i < iStringLength(A)) {
			if (*(A + i) == ',')
				_Upper(*(A + i + 1));
			i++;
		}
	}
}

//Change lowercase to uppercase
void _Upper(wchar_t &a)
{
	wchar_t Thuong[] = L"áàảãạăắằẳẵặâấầẩẫậđéèẻẽẹêếềểễệíìỉĩịóòỏõọôốồổỗộơớờởỡợúùủũụưứừửữựýỳỷỹỵ";
	wchar_t Hoa[] = L"ÁÀẢÃẠĂẮẰẲẴẶÂẤẦẨẪẬĐÉÈẺẼẸÊẾỀỂỄỆÍÌỈĨỊÓÒỎÕỌÔỐỒỔỖỘƠỚỜỞỠỢÚÙỦŨỤƯỨỪỬỮỰÝỲỶỸỴ";
	bool IsWchar = false;

	for (int j = 0; Thuong[j] != '\0'; j++) {
		if (a == Thuong[j])
		{
			a = Hoa[j];
			IsWchar = true;
			break;
		}
	}
	if (!IsWchar)
		if (a >= 'a' && a <= 'z')
			a -= 32;
}

//Change uppercasel to owercase
void _Lower(wchar_t &a)
{
	wchar_t Thuong[] = L"áàảãạăắằẳẵặâấầẩẫậđéèẻẽẹêếềểễệíìỉĩịóòỏõọôốồổỗộơớờởỡợúùủũụưứừửữựýỳỷỹỵ";
	wchar_t Hoa[] = L"ÁÀẢÃẠĂẮẰẲẴẶÂẤẦẨẪẬĐÉÈẺẼẸÊẾỀỂỄỆÍÌỈĨỊÓÒỎÕỌÔỐỒỔỖỘƠỚỜỞỠỢÚÙỦŨỤƯỨỪỬỮỰÝỲỶỸỴ";
	bool IsWchar = false;

	for (int j = 0; Thuong[j] != '\0'; j++) {
		if (a == Hoa[j])
		{
			a = Thuong[j];
			IsWchar = true;
			break;
		}
	}
	if (!IsWchar)
		if (a >= 'A' && a <= 'Z')
			a += 32;
}
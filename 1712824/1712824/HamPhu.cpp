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
	if (x == 1) {
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

	//sv.Khoa
	if (x == 2)
	{
		i = 0;
		while (i < iStringLength(A))
		{
			_Upper(*(A + i));
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

	for (int i = 0; Thuong[i] != '\0'; i++) {
		if (a == Thuong[i])
		{
			a = Hoa[i];
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

	for (int i = 0; Thuong[i] != '\0'; i++) {
		if (a == Hoa[i])
		{
			a = Thuong[i];
			IsWchar = true;
			break;
		}
	}
	if (!IsWchar)
		if (a >= 'A' && a <= 'Z')
			a += 32;
}

//String to Int
int StrtoInt(wchar_t* a)
{
	int iOutput=1;
	wchar_t Char[] = L"0123456789";
	int     So[] = { 0,1,2,3,4,5,6,7,8,9 };
	int temp = 1;
	for (int i = iStringLength(a) - 1; i >= 0; i--)
	{
		for (int j = 0; Char[j] != '\0'; j++)
		{
			if (*(a + i) == Char[j])
			{
				iOutput += So[j] * temp;
				temp = temp * 10;
			}
		}
	}
	return iOutput;
}


void ReplaceString(wchar_t* buf, wchar_t*Begin, wchar_t*End, wchar_t*str)
{
	int Pos1 = FindSubString(buf, Begin);
	int Pos2 = FindSubString(buf, End);
	if (Pos1 != -1 && Pos2 != -1) {	
		int lenbuf = wcslen(buf);
		int pos_ins = Pos1 + wcslen(Begin);	
											
		wchar_t* temp1 = (wchar_t*)malloc(512 * sizeof(wchar_t));
		wchar_t* temp2 = (wchar_t*)malloc(512 * sizeof(wchar_t));
		wchar_t* temp3 = (wchar_t*)malloc(512 * sizeof(wchar_t));

		wcsncpy(temp1, buf, pos_ins);
		temp1[pos_ins] = '\0';
		wcscpy(temp2, buf + pos_ins);
		wcscpy(temp3, buf + Pos2);
		wcscpy(temp2, str);
		temp2[wcslen(str)] = '\0';
		wcscat(temp2, temp3);
		wcscat(temp1, temp2);
		wcscpy(buf, temp1);
		free(temp1);
		free(temp2);
		free(temp3);
	}
}

int FindSubString(wchar_t* str, wchar_t* substr)
{
	int len = wcslen(str);
	int slen = wcslen(substr);
	for (int i = 0; i < len - slen + 1; i++)
	{
		wchar_t* temp = (wchar_t*)malloc(sizeof(wchar_t)*(slen));
		wcsncpy(temp, str + i, slen);
		temp[slen] = '\0';
		if (wcscmp(temp, substr) == 0)
			return i;
	}
	return -1;
}
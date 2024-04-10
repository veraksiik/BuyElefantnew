#include <iostream>
//#include <Windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <limits>




//�������� - ����������, �������� - ���� �����

int size = 10;
int receiptSize = 1;


//������� ������
int* test = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
float* priceArr = new float[size];

//������� ����
std::string* nameReceipt = new std::string[receiptSize];
int* countReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];





//�������
void Start();
void CreateStorage();
template<typename ArrType>
void FillArray(ArrType staticArray[], ArrType dinArray[], int size);
template<typename ArrType>
void PrintArray(ArrType arr[], int size);
void Shop();
void ShowStorage();
void Selling();


int main() {


	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	//Start();
	CreateStorage();
	ShowStorage();
	Selling();

	delete[] test;
	delete[] nameArr;
	delete[] countArr;
	delete[] nameReceipt;
	delete[] countReceiptArr;
	delete[] priceReceiptArr;



	system("pause");
	return 0;
}

void Start()
{
	bool exit = false;
	std::string adminLogin = "sofas";
	std::string adminPassword = "sofas";
	std::string login, password;
	int choose;
	int chooseStorageType;


	std::cout << "\n\t\t\t����� ���������� � ������� *���� �����*" << std::endl;

	do
	{
		std::cout << "\n\t�����:   ";
		std::getline(std::cin, login, '\n');

		std::cout << "\t������:   ";
		std::getline(std::cin, password, '\n');

		if (login != adminLogin || password != adminPassword) {
			std::cerr << "\n\t�������� ����� � ������\n\n";
			std::cout << "\n\t����������� ��� ���? 1 - ��, 2 - ����� �� ��������\n\n";
			std::cin >> choose;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (choose == 2)
			{
				exit = true;
			}
		}
		else {
			exit = true;
			int chooseStorageType;

			do
			{
				std::cout << "�������� ������ ������: \n1-�o����� �����\n2-������� ����� ������� \n";
				std::cin >> chooseStorageType;
			} while (chooseStorageType < 1 || chooseStorageType>2);
			if (chooseStorageType == 1)
			{
				CreateStorage();
				//
			}
			else if (chooseStorageType == 2)
			{
				std::cout << "  ";

			}
			else
			{
				std::cout << "Error";

			}
		}
	} while (!exit);




}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 0,1,2,3,4,5,6,7,8,9, };
	std::string name[staticSize]{ "����","�������","������" ,
		"�����" ,"������" ,"������",
		"������","����","�������",
		"�������" };
	int count[staticSize]{ 10,10,10,7,6,30,9,10,9 };
	float price[staticSize]{ 90,50,20,599.99,799.99,499,30.50,399.99,200,250 };

	FillArray(id, test, staticSize);
	FillArray(name, nameArr, staticSize);
	FillArray(count, countArr, staticSize);
	FillArray(price, priceArr, staticSize);

}

void Shop()
{
	int choose;
	while (true)
	{

		do
		{
			std::cout << "1) �������� �����\n";
			std::cout << "2) ������ �������\n";
			std::cout << "3) �������� ����\n";
			std::cout << "4) ������� �����\n";
			std::cout << "5) ��������� �����\n";
			std::cout << "6) �������� �����\n";
			std::cout << "0) ��������� �����\n";
			std::cin >> choose;
		} while (choose < 0 || choose>6);
		if (choose == 1) {



		}
		else if (choose == 2) {

			Selling();

		}
		else if (choose == 3) {



		}
		else if (choose == 4) {



		}
		else if (choose == 5) {



		}
		else if (choose == 6) {



		}
		else if (choose == 0) {



		}
		else {

			std::cout << "Error";

		}

























	}
}

void ShowStorage()
{

	std::cout << "\tid ������\t��������\t\t����\t\t���-��\n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << "\t  " << test[i] + 1 << "\t\t" << nameArr[i] << "\t\t\t" << priceArr[i] << "\t\t" << countArr[i] << "\n";
	}

}

void Selling()
{
	int chooseId, chooseCount, confirm;


	while (true)
	{
		do
		{
			std::cout << " ������� id ������: ";
			std::cin >> chooseId;
			if (chooseId<1 || chooseId>size)
			{
				std::cerr << "��� ������ Id\n";
				continue;
			}
			do
			{
				std::cout << "\n�� �������: " << nameArr[chooseId - 1] << "\n";
				std::cout << "\n���-�� ������ �� ������:  " << countArr[chooseId - 1] << "\n";
				std::cout << "�������� ���-�� ������ ��� �������: ";
				std::cin >> chooseCount;
				if (chooseCount<1 || chooseCount>countArr[chooseId - 1])
				{
					std::cerr << "�o���� �� �������\n";
					continue;
				}
				else {
					break;
				}
			} while (true);
			std::cout << "\n�� �������: " << nameArr[chooseId - 1] << "\n";
			std::cout << "\n� ����������:  " << chooseCount << "\n";
			std::cout << "����������� �����: 1 - �� ������\n2 - ���������";
			std::cin >> confirm;
			if (confirm == 1)
			{
				break;
			}

		} while (true);




	}

}

template<typename ArrType>
void PrintArray(ArrType arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

template<typename ArrType>
void FillArray(ArrType staticArray[], ArrType dinArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		dinArray[i] = staticArray[i];
	}
}

#include <iostream>
//#include <Windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <limits>




//тематика - аксессуары, название - купи слона

int size = 10;
int receiptSize = 1;


//массивы склада
int* test = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
float* priceArr = new float[size];

//массивы чека
std::string* nameReceipt = new std::string[receiptSize];
int* countReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];





//функция
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


	std::cout << "\n\t\t\tДобро пожаловать в магазин *Купи слона*" << std::endl;

	do
	{
		std::cout << "\n\tЛогин:   ";
		std::getline(std::cin, login, '\n');

		std::cout << "\tПароль:   ";
		std::getline(std::cin, password, '\n');

		if (login != adminLogin || password != adminPassword) {
			std::cerr << "\n\tНеверный логин и пароль\n\n";
			std::cout << "\n\tПопробовать ещё раз? 1 - да, 2 - выход из прогаммы\n\n";
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
				std::cout << "Выберите формат склада: \n1-Гoтовый склад\n2-Создать склад вручную \n";
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
	std::string name[staticSize]{ "Очки","Браслет","Значок" ,
		"Сумка" ,"Рюкзак" ,"Кошелёк",
		"Кольца","Часы","Обложки",
		"Цепочка" };
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
			std::cout << "1) Показать склад\n";
			std::cout << "2) Начать продажу\n";
			std::cout << "3) Изменить цену\n";
			std::cout << "4) Списать товар\n";
			std::cout << "5) Пополнить товар\n";
			std::cout << "6) Изменить склад\n";
			std::cout << "0) Закончить смену\n";
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

	std::cout << "\tid товара\tНазвание\t\tЦена\t\tКол-во\n\n";
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
			std::cout << " Введите id товара: ";
			std::cin >> chooseId;
			if (chooseId<1 || chooseId>size)
			{
				std::cerr << "Нет такого Id\n";
				continue;
			}
			do
			{
				std::cout << "\nВы выбрали: " << nameArr[chooseId - 1] << "\n";
				std::cout << "\nКол-во товара на складе:  " << countArr[chooseId - 1] << "\n";
				std::cout << "Выберите кол-во товара для покупки: ";
				std::cin >> chooseCount;
				if (chooseCount<1 || chooseCount>countArr[chooseId - 1])
				{
					std::cerr << "Тoвара не хватает\n";
					continue;
				}
				else {
					break;
				}
			} while (true);
			std::cout << "\nВы выбрали: " << nameArr[chooseId - 1] << "\n";
			std::cout << "\nВ количестве:  " << chooseCount << "\n";
			std::cout << "Подтвердите выбор: 1 - Всё хорошо\n2 - Повторить";
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

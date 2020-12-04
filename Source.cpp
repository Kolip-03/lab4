#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>

using namespace std;

class Clothes
{
protected:
	string color;
	string material;
	string sex;
	int cost;
public:
	Clothes()
	{

	}
	Clothes(string color , string material , string sex, int cost)
	{
		this->color = color;
		this->material = material;
		this->sex = sex;
		this->cost = cost;
	}

	void setColor(string color)
	{
		this->color = color;
	}

	void setMaterial(string material)
	{
		this->material = material;
	}

	void setSex(string sex)
	{
		this->sex = sex;
	}

	void setCost(int cost)
	{
		this->cost = cost;
	}

};

class Shoes : public Clothes
{
protected:
	int size;
	string firm;
	string Mat;
	
public:
	Shoes()
	{

	}
	Shoes(string color, string material, string sex , int cost, int size, string firm ) : Clothes(color, material, sex, cost)
	{
		this->size = size;
		this->firm = firm;

	}

	void setMat(string Mat)
	{
		this->Mat = Mat;
		cout << Mat;

	}

	void setSize(int size)
	{
		this->size = size;
	}

	void setFirm(string firm)
	{
		this->firm = firm;
	}

	void Print()
	{
		cout << "����: " << this->color << ";\n��������: " << this->material << ";\n��� ����������: " << this->sex << ";\n����: " << this->cost << ";\n������: " << this->size << ";\n�����: " << firm << endl;
	}
};

class Trousers : public Clothes
{
protected:
	int height;
	int width;
	string vidIspolzovaniya;

public:
	Trousers()
	{

	}
	Trousers(string color, string material , string sex , int cost, int height , int width , string vidIspolzovaniya ) : Clothes(color, material, sex, cost)
	{
		this->height = height;
		this->width = width;
		this->vidIspolzovaniya = vidIspolzovaniya;
	}

	void setHeight(int height)
	{
		this->height = height;
	}

	void setWidth(int width)
	{
		this->width = width;
	}

	void setVidIspolzovaniya(string vidIspolzovaniya)
	{
		this->vidIspolzovaniya = vidIspolzovaniya;
	}

	void Print()
	{
		cout << "����: " << this->color << ";\n��������: " << this->material << ";\n��� ����������: " << this->sex << ";\n����: " << this->cost << ":\n�����: " << this->height << ";\n������: " << this->width << "; ��� �������������: " << vidIspolzovaniya << endl;
	}
};

class Hat : public Clothes
{
protected:
	string season;
	string model;
public:
	Hat()
	{

	}
	Hat(string color , string material , string sex , int cost, string season , string model ) : Clothes(color, material, sex, cost)
	{
		this->season = season;
		this->model = model;
	}

	void setSeason(string season)
	{
		this->season = season;
	}

	void setModel(string model)
	{
		this->model = model;
	}

	void Print()
	{
		cout << "����: " << this->color << ";\n��������: " << this->material << ";\n��� ����������: " << this->sex << ";\n����: " << this->cost << ";\n�����: " << season << ";\n�����: " << this->model << endl;
	}
};

int numericNumber();
string correctString();
int mainMenu();
void shoes(Shoes& shoes);
void trousers(Trousers& trousers);
void hat(Hat& hat);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	Shoes MyShoes;
	Trousers MyTrousers;
	Hat MyHat;

	while (true)
	{
		switch (mainMenu())
		{
		case 1:
			shoes(MyShoes);
			system("cls");
			break;
		case 2:
			trousers(MyTrousers);
			system("cls");
			break;
		case 3:
			hat(MyHat);
			system("cls");
			break;
		default:
			system("pause");
			return 0;
		}
	}
}

int mainMenu()
{
	int selection = 0;

	cout << "����� -- ����� -- �����" << endl;
	cout << "1.�����.\n2.�����.\n3.�����.\n������ - �����" << endl;
	cout << "�������: ";

	selection = numericNumber();
	cout << "\n";

	return selection;
}

string correctString()
{
	bool trigger;
	string str;

	do
	{
		trigger = false;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if ((str[i] < '�' || str[i] > '�') && (str[i] < '�' || str[i] > '�'))
			{
				trigger = true;
				cout << "������������ ���� ������!\n���������� �����: ";
				break;
			}
		}
	} while (trigger);

	return str;
}

int numericNumber()
{
	int number;
	cin >> number;

	while (cin.get() != '\n')
	{
		cout << "������������ ����!" << endl;
		cout << "������� �����: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> number;
	}

	return number;
}

void shoes(Shoes& shoes)
{
	while (true)
	{
		int selection = 0;

		cout << "1.���������� ����.\n2.���������� ��������.\n3.���������� ��� ����������.\n4.���������� ����.\n5.���������� ������.\n6.���������� �����.\n7.������� ����������.\n������ - �����" << endl;
		selection = numericNumber();

		switch (selection)
		{
		case 1:
		{
			string newColor;

			cout << "������� ����: ";
			newColor = correctString();
			shoes.setColor(newColor);

			break;
		}
		case 2:
		{
			string newMaterial;

			cout << "������� ��������: ";
			newMaterial = correctString();
			shoes.setMaterial(newMaterial);

			break;
		}
		case 3:
		{
			string newSex;
			bool trigger;

			do
			{
				trigger = false;
				cout << "������� ��� ����������(������� ��� �������): ";
				newSex = correctString();

				if (newSex != "�������" && newSex != "�������")
				{
					trigger = true;
					cout << "������ ���� �� ����������!" << endl;
				}

			} while (trigger);

			shoes.setSex(newSex);

			break;
		}
		case 4:
		{
			bool trigger;
			int newCost;

			do
			{
				trigger = false;
				cout << "������� ����: ";
				newCost = numericNumber();

				if (newCost < 0)
				{
					trigger = true;
					cout << "���� �� ����� ���� �������������!" << endl;
				}
			} while (trigger);

			shoes.setCost(newCost);

			break;
		}

		case 5:
		{
			bool trigger;
			int newSize;

			do
			{
				trigger = false;
				cout << "������� ������: ";
				newSize = numericNumber();

				if (newSize < 0)
				{
					trigger = true;
					cout << "������ �� ����� ���� �������������!" << endl;
				}
			} while (trigger);

			shoes.setSize(newSize);

			break;
		}
		case 6:
		{
			string newFirm;

			cout << "������� �����: ";
			newFirm = correctString();
			shoes.setFirm(newFirm);

			break;
		}
		case 7:
		{
			shoes.Print();
			break;
		}
		default: return;
		}

		system("pause");
		system("cls");
	}
}

void trousers(Trousers& trousers)
{
	while (true)
	{
		int selection = 0;

		cout << "1.���������� ����.\n2.���������� ��������.\n3.���������� ��� ����������.\n4.���������� ����.\n5.���������� �����.\n6.���������� ������.\n7.���������� ��� �������������.\n8.������� ����������.\n������ - �����" << endl;
		selection = numericNumber();

		switch (selection)
		{
		case 1:
		{
			string newColor;

			cout << "������� ����: ";
			newColor = correctString();
			trousers.setColor(newColor);

			break;
		}
		case 2:
		{
			string newMaterial;

			cout << "������� ��������: ";
			newMaterial = correctString();
			trousers.setMaterial(newMaterial);

			break;
		}
		case 3:
		{
			string newSex;
			bool trigger;

			do
			{
				trigger = false;
				cout << "������� ��� ����������(������� ��� �������): ";
				newSex = correctString();

				if (newSex != "�������" && newSex != "�������")
				{
					trigger = true;
					cout << "������ ���� �� ����������!" << endl;
				}

			} while (trigger);

			trousers.setSex(newSex);

			break;
		}
		case 4:
		{
			bool trigger;
			int newCost;

			do
			{
				trigger = false;
				cout << "������� ����: ";
				newCost = numericNumber();

				if (newCost < 0)
				{
					trigger = true;
					cout << "���� �� ����� ���� �������������!" << endl;
				}
			} while (trigger);

			trousers.setCost(newCost);

			break;
		}

		case 5:
		{
			bool trigger;
			int newHeight;

			do
			{
				trigger = false;
				cout << "������� �����: ";
				newHeight = numericNumber();

				if (newHeight < 0)
				{
					trigger = true;
					cout << "����� �� ����� ���� �������������!" << endl;
				}
			} while (trigger);

			trousers.setHeight(newHeight);

			break;
		}
		case 6:
		{
			bool trigger;
			int newWidth;

			do
			{
				trigger = false;
				cout << "������� ������: ";
				newWidth = numericNumber();

				if (newWidth < 0)
				{
					trigger = true;
					cout << "������ �� ����� ���� �������������!" << endl;
				}
			} while (trigger);

			trousers.setHeight(newWidth);

			break;
		}
		case 7:
		{
			string newVidIspolzovaniya;

			cout << "������� ��� �������������: ";
			newVidIspolzovaniya = correctString();
			trousers.setVidIspolzovaniya(newVidIspolzovaniya);

			break;
		}
		case 8:
		{
			trousers.Print();
			break;
		}
		default: return;
		}

		system("pause");
		system("cls");
	}
}

void hat(Hat& hat)
{
	while (true)
	{
		int selection = 0;

		cout << "1.���������� ����.\n2.���������� ��������.\n3.���������� ��� ����������.\n4.���������� ����.\n5.���������� �����.\n6.���������� ������.\n7.������� ����������.\n������ - �����" << endl;
		selection = numericNumber();

		switch (selection)
		{
		case 1:
		{
			string newColor;

			cout << "������� ����: ";
			newColor = correctString();
			hat.setColor(newColor);

			break;
		}
		case 2:
		{
			string newMaterial;

			cout << "������� ��������: ";
			newMaterial = correctString();
			hat.setMaterial(newMaterial);

			break;
		}
		case 3:
		{
			string newSex;
			bool trigger;

			do
			{
				trigger = false;
				cout << "������� ��� ����������(������� ��� �������): ";
				newSex = correctString();

				if (newSex != "�������" && newSex != "�������")
				{
					trigger = true;
					cout << "������ ���� �� ����������!" << endl;
				}

			} while (trigger);

			hat.setSex(newSex);

			break;
		}
		case 4:
		{
			bool trigger;
			int newCost;

			do
			{
				trigger = false;
				cout << "������� ����: ";
				newCost = numericNumber();

				if (newCost < 0)
				{
					trigger = true;
					cout << "���� �� ����� ���� �������������!" << endl;
				}
			} while (trigger);

			hat.setCost(newCost);

			break;
		}

		case 5:
		{
			bool trigger;
			string newSeason;

			do
			{
				trigger = false;
				cout << "������� �����(����, ����, �����, �����): ";
				newSeason = correctString();

				if (newSeason != "����" && newSeason != "����" && newSeason != "�����" && newSeason != "�����")
				{
					trigger = true;
					cout << "��� ������ ������!" << endl;
				}
			} while (trigger);

			hat.setSeason(newSeason);

			break;
		}
		case 6:
		{
			string newModel;

			cout << "������� ������: ";
			newModel = correctString();
			hat.setModel(newModel);

			break;
		}
		case 7:
		{
			hat.Print();
			break;
		}
		default: return;
		}

		system("pause");
		system("cls");
	}
}
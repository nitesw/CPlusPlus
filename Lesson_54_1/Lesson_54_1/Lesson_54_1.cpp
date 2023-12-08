#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Vagon
{
	int number_Vagony;
	int amount_Of_Pasanger_Place;
	int amountPasangers;
	Vagon() :number_Vagony(0), amount_Of_Pasanger_Place(0), amountPasangers(0) {}
	Vagon(int num, int places)
	{
		number_Vagony = num;
		amount_Of_Pasanger_Place = places;
		amountPasangers = 0;
	}
	void Print()
	{
		cout << "Number : " << number_Vagony << endl;
		cout << "amount_Of_Pasanger_Place : " << amount_Of_Pasanger_Place << endl;
		cout << "amountPasangers : " << amountPasangers << endl;
	}

	friend ofstream& operator << (ofstream& out, const Vagon& vagon);
	friend ifstream& operator >> (ifstream& in, Vagon& vagon);
};

class Train
{
	string model;
	int amount_of_vagons;
	Vagon* vagon;
public:
	Train()
	{
		model = "no model";
		amount_of_vagons = 0;
		vagon = nullptr;
	}
	Train(string model)
	{
		this->model = model;
		this->amount_of_vagons = 0;
		this->vagon = nullptr;
	}
	Train(const Train& other)
	{
		this->model = other.model;
		this->amount_of_vagons = other.amount_of_vagons;
		this->vagon = new Vagon[other.amount_of_vagons];
		for (int i = 0; i < other.amount_of_vagons; i++)
		{
			vagon[i] = other.vagon[i];
		}
	}
	
	void Show()
	{
		cout << "Name Train : " << model << endl;
		cout << "Number of wagons : " << amount_of_vagons << endl;
		for (int i = 0; i < amount_of_vagons; i++)
		{
			vagon[i].Print();
			cout << endl;
		}
	}
	void Add_Vagon(Vagon v);
	void Add_One_Passenger(int number_vagon)
	{
		for (int i = 0; i < amount_of_vagons; i++)
		{
			if (vagon[i].number_Vagony == number_vagon)
			{
				vagon[i].amountPasangers++;
			}
		}
	}
	~Train() {
		if (vagon != nullptr) {
			delete[]vagon;
		}
		cout << "Destructor" << endl;
	}
	Train operator+(const Train& other)
	{
		Train result(*this);
		for (int i = 0; i < other.amount_of_vagons; i++)
		{
			result.Add_Vagon(other.vagon[i]);
		}
		return result;
	}
	void operator++()
	{
		for (int i = 0; i < amount_of_vagons; i++)
		{
			vagon[i].amountPasangers++;
		}
	}

	Vagon getVagon(int index)
	{
		if (index < 0 || index >= amount_of_vagons) return Vagon();
		return vagon[index];
	}
	Vagon operator[](int index)
	{
		if (index < 0 || index >= amount_of_vagons) return Vagon();
		return vagon[index];
	}
	void ChangePassangers(int count)
	{
		for (int i = 0; i < amount_of_vagons; i++)
		{
			vagon[i].amountPasangers += count;
		}
	}
	void operator()(int count)
	{
		for (int i = 0; i < amount_of_vagons; i++)
		{
			vagon[i].amountPasangers += count;
		}
	}
	void operator()(int count, int number)
	{
		for (int i = 0; i < amount_of_vagons; i++)
		{
			if (vagon[i].number_Vagony == number)
				vagon[i].amountPasangers += count;
		}
	}

	operator string()
	{
		return model;
	}

	void SaveToFile()
	{
		ofstream out_file("train.txt", ios_base::out);
		out_file << model << endl;
		out_file << amount_of_vagons << endl;
		for (size_t i = 0; i < amount_of_vagons; i++)
		{
			out_file << vagon[i] << endl;
		}
		out_file.close();
	}
	void Load()
	{
		ifstream in("train.txt", ios_base::in);

		getline(in, model);
		in >> amount_of_vagons;
		if (vagon != nullptr)
			delete[]vagon;

		vagon = new Vagon[amount_of_vagons];
		for (size_t i = 0; i < amount_of_vagons; i++)
		{
			in >> vagon[i];
		}
		in.close();
	}
};

ofstream& operator << (ofstream& out, const Vagon& vagon)
{
	out << vagon.amountPasangers << " " << vagon.amount_Of_Pasanger_Place << " " << vagon.number_Vagony;
	return out;
}
ifstream& operator >> (ifstream& in, Vagon& vagon)
{
	in >> vagon.amountPasangers >> vagon.amount_Of_Pasanger_Place >> vagon.number_Vagony;
	return in;
}


void Train::Add_Vagon(Vagon v)
{
	amount_of_vagons++;
	Vagon* temp = new Vagon[amount_of_vagons];
	for (size_t i = 0; i < amount_of_vagons - 1; i++)
	{
		temp[i] = vagon[i];
	}
	temp[amount_of_vagons - 1] = v;
	if (vagon != nullptr)
	{
		delete[]vagon;
	}
	vagon = temp;
}

int main()
{

	Train train("Tom");

	/*train.Show();
	Vagon v{ 1,15 };
	train.Add_Vagon(v);
	train.Add_Vagon(Vagon{ 2,30 });
	train.Add_Vagon(Vagon{ 3,10 });
	train.Add_One_Passenger(1);
	train.Add_One_Passenger(1);
	train.Add_One_Passenger(1);
	train.Add_One_Passenger(1);
	train.Add_One_Passenger(2);*/
	train.Show();
	cout << "*****************************" << endl;

	//train.SaveToFile();
	train.Load();
	train.Show();
}
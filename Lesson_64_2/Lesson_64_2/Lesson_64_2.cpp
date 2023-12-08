#include <iostream>
#include <vector>
using namespace std;

class Parcel 
{
	int weight;
	int deliveryDate;
public:
	Parcel(int w, int d) : weight(w), deliveryDate(d) {}

	void Info()const 
	{
		cout << "----------------------" << endl;
		cout << "Weight: " << weight << " kg" << endl;
		cout << "Delivery date: " << deliveryDate << " day" << endl << endl;
	}

	int GetWeight()const 
	{
		return weight;
	}

	int GetDeliveryDate()const 
	{
		return deliveryDate;
	}
};

class Transport 
{
public:
	virtual void Info() const = 0;
};

class PassengerCar : public Transport 
{
public:
	void Info() const override 
	{
		cout << "Passenger car" << endl;
		cout << "Payload: " << 15 << " kg" << endl;
	}
};

class Bus : public Transport 
{
public:
	void Info() const override 
	{
		cout << "Bus" << endl;
		cout << "Payload: " << 100 << " kg" << endl;
	}
};

class Plane : public Transport 
{
public:
	void Info() const override 
	{
		cout << "Plane" << endl;
		cout << "Payload: " << 300 << " kg" << endl;
	}
};

class TransportFactory 
{
public:
	Transport* CreateTransport(Parcel p) 
	{
		if (p.GetWeight() >= 30) 
		{
			if (p.GetDeliveryDate() >= 7) 
			{
				p.Info();
				return new Plane();
			}
			else if (p.GetDeliveryDate() >= 3 && p.GetDeliveryDate() < 7) 
			{
				p.Info();
				return new Bus();
			}
		}
		else if (p.GetWeight() >= 15 && p.GetWeight() < 30) 
		{
			if (p.GetDeliveryDate() >= 7) 
			{
				p.Info();
				return new Plane();
			}
			else if (p.GetDeliveryDate() >= 3 && p.GetDeliveryDate() < 7) 
			{
				p.Info();
				return new Bus();
			}
		}
		else if (p.GetWeight() >= 1 && p.GetWeight() < 15) 
		{
			if (p.GetDeliveryDate() >= 7) 
			{
				p.Info();
				return new Plane();
			}
			else if (p.GetDeliveryDate() >= 3 && p.GetDeliveryDate() < 7) 
			{
				p.Info();
				return new Bus();
			}
			else if (p.GetDeliveryDate() >= 1 && p.GetDeliveryDate() < 3) 
			{
				p.Info();
				return new PassengerCar();
			}
		}

		return nullptr;
	}
};

class NovaPoshta 
{
	vector<Parcel> parcels;
public:
	void Add(Parcel p) 
	{
		if (p.GetDeliveryDate() <= 0 || p.GetWeight() <= 0) {
			cout << "Error!" << endl;
		}
		else 
		{
			parcels.push_back(p);
		}
	}

	Parcel Delete(int index) 
	{
		Parcel tmp = parcels[index];
		parcels.erase(parcels.begin() + index);
		return tmp;
	}

	void Show() const 
	{
		for (const auto& parcel : parcels) 
		{
			parcel.Info();
		}
	}
};

int main() 
{
	NovaPoshta nP;
	nP.Add(Parcel(4, 0));
	nP.Add(Parcel(0, 3));
	nP.Add(Parcel(7, 2));
	nP.Add(Parcel(44, 4));
	nP.Add(Parcel(111, 1));
	nP.Add(Parcel(428, 10));
	nP.Add(Parcel(8, 2));

	cout << "Parcel" << endl;
	nP.Show();

	cout << "\nDelivery" << endl;
	TransportFactory factory;
	Parcel parcelToDelete = nP.Delete(0);
	Transport* transport = factory.CreateTransport(parcelToDelete);
	if (transport) 
	{
		transport->Info();
		delete transport;
	}
	else 
	{
		cout << "Unable to create transport for the given parcel." << endl;
	}

	return 0;
}

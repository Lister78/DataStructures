#include <iostream>

#include "ArrayList.h"
#include "randomize.h"
#include "timer.h"

void  Array_list()
{
	my_tab tab1;
	random_data_generator random;
	int choice;
	int value;
	int how_many;
	int choose_type;
	do
	{
	std::cout<<"\n1.Dodawanie z tylu\n";
	std::cout<<"2.Dodawanie z przodu\n";
	std::cout<<"3.Dodawanie w losowych miejscach\n";
	std::cout<<"4.Wylosuj dane do tablicy\n";
	std::cout<<"5.Otworz inne menu";
	std::cin>>choice;
	
	switch(choice)
	{
	
	case 1:
		{
		std::cout<<"Ile dodac elementow: ";
		std::cin>>how_many;
		for(int i = 0;i<how_many;i++){
		std::cout<<"Podaj wartosc: "<<std::endl;
		std::cin>>value;
		tab1.add_to_tab_e(value);
		std::cout<<"Max pojemnosc tablicy: "<<tab1.get_size()<<"\nAktualna ilosc zapelnionych pol: "<<tab1.get_filling()<<"\n";
		std::cout<<"\n";
		}
		}
	break;
	
	case 2:
		{
		std::cout<<"Ile dodac elementow: ";
		std::cin>>how_many;
		for(int i = 0;i<how_many;i++){
			std::cout<<"Podaj wartosc: "<<std::endl;
			std::cin>>value;
			tab1.add_to_tab_b(value);
			std::cout<<"Max pojemnosc tablicy: "<<tab1.get_size()<<"\nAktualna ilosc zapelnionych pol: "<<tab1.get_filling()<<"\n";
			std::cout<<"\n";
		}
		
		}
	break;

	case 3:
		{
		std::cout<<"Ile dodac elementow: ";
		std::cin>>how_many;
		for(int i = 0;i<how_many;i++){
			std::cout<<"Podaj wartosc: "<<std::endl;
			std::cin>>value;
			tab1.add_to_tab_r(value);
			std::cout<<"Max pojemnosc tablicy: "<<tab1.get_size()<<"\nAktualna ilosc zapelnionych pol: "<<tab1.get_filling()<<"\n";
			std::cout<<"\n";
		}
		}
	break;

	case 4:
	{ 
		std::cout<<"1.Wylosuj do tylu\n2.Wylosuj do przodu\n3.Wylosuj w losowych miejscach\n";
		std::cin>>choose_type;
		std::cout<<"\nIle danych do tablicy: ";
		std::cin>>how_many;
		switch(choose_type)
		{
			case 1:
			{
				for(int i = 0;i<how_many;i++)
					tab1.add_to_tab_e(random.rng_data_to_array());
				break;
			}
			case 2:
			{
				for(int i = 0;i<how_many;i++)
					tab1.add_to_tab_b(random.rng_data_to_array());
				break;	
			}
			
			case 3:
			{
				for(int i = 0;i<how_many;i++)
					tab1.add_to_tab_r(random.rng_data_to_array());
				break;
			}
			default:
				std::cout<<"Error";
			break;
			
		}
		break;
	}
	case 5:
	{
		std::cout<<"Wybierz co dalej\n1.Wyswietl tablice\n2.Usun z tablicy\n3.Szukaj w tablicy\n";
		std::cin>>choose_type;
		std::cout<<"\n";
		switch(choose_type)
		{
			case 1:
			{	
				for(int i = 0;i<tab1.get_filling();i++)
					std::cout<<tab1.get_array_element(i)<<" ";
				std::cout<<"\n";
				break;
			}
			case 2:
			{
				int choose_delete;
				std::cout<<"Wybierz skad chcesz usunac\n1.Z przodu\n2.Z tylu\n3.Z losowych miejsc\n";
				std::cin>>choose_delete;
				std::cout<<"Ile elementow\n";
				std::cin>>how_many;
				switch(choose_delete)
				{
					case 1:
						tab1.delete_from_tab_b(how_many);
						break;
					case 2:
						tab1.delete_from_tab_e(how_many);
						break;
					case 3:
						tab1.delete_from_tab_r(how_many);
							break;
					default:
						std::cout<<"error";
						break;
				}

				break;
			}
			case 3:
			{
				std::cout<<"Jaka liczbe wyszukac w tablicy";
				std::cin>>how_many;
				std::cout<<"\n";
				tab1.search(how_many);
				break;
			}
			default:
				std::cout<<"error";
		}
	}

	}
	}
	while(1);
}
int main()
{
	int choose_structure;
	std::cout<<"Wybierz strukture:\n";
	std::cout<<"1.Array List\n";
	std::cin>>choose_structure;
	std::cout<<"\n";
	switch(choose_structure)
	{
		case 1:
			Array_list();
		break;
		default:
			std::cout<<"error";
	}
	
	return 0;
}

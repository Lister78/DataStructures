#include <iostream>

#include "ArrayList.h"
#include "randomize.h"
#include "timer.h"
#include "LinkedList1.h"
void  Array_list()
{
	my_tab tab1;
	random_data_generator random;
	timer time;
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
				time.start_m();
				for(int i = 0;i<how_many;i++)
					tab1.add_to_tab_e(random.rng_data_to_array());
				time.end_m();
				std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
			break;
			}
			case 2:
			{
				time.start_m();
				for(int i = 0;i<how_many;i++)
					tab1.add_to_tab_b(random.rng_data_to_array());
				time.end_m();
				std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
				break;	
			}
			
			case 3:
			{
				time.start_m();
				for(int i = 0;i<how_many;i++)
					tab1.add_to_tab_r(random.rng_data_to_array());
				time.end_m();
				std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
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
					time.start_m();
						tab1.delete_from_tab_b(how_many);
						time.end_m();
						std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
						break;
					case 2:
					time.start_m();
						tab1.delete_from_tab_e(how_many);
						time.end_m();
						std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
						break;
					case 3:
					time.start_m();
						tab1.delete_from_tab_r(how_many);
						time.end_m();
						std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
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
				time.start_m();
				tab1.search(how_many);
				time.end_m();
				std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
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
void Linked_List1()
{
	LinkedList1 list1;
	random_data_generator random;
	timer time;
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
		std::cout<<"Ile dodac elementow: ";
		std::cin>>how_many;
		for(int i = 0;i<how_many;i++)
		{
			std::cout<<"\nJaka wartosc wpisac do listy: ";
			std::cin>>value;
			list1.add_to_list_e(value);
			
		}
		break;
		case 2:
		std::cout<<"Ile dodac elementow: ";
		std::cin>>how_many;
		for(int i = 0;i<how_many;i++)
		{
			std::cout<<"\nJaka wartosc wpisac do listy: ";
			std::cin>>value;
			list1.add_to_list_b(value);
			
		}
		break;
		case 3:
			std::cout<<"Ile dodac elementow: ";
		std::cin>>how_many;
		for(int i = 0;i<how_many;i++){
			std::cout<<"Podaj wartosc: "<<std::endl;
			std::cin>>value;
			list1.add_to_list_r(value);
		}
		break;
		case 4:
		std::cout<<"1.Wylosuj do tylu\n2.Wylosuj do przodu\n3.Wylosuj w losowych miejscach\n";
		std::cin>>choose_type;
		std::cout<<"\nIle danych do tablicy: ";
		std::cin>>how_many;
		switch(choose_type)
		{
			case 1:
			{
				time.start_m();
				for(int i = 0;i<how_many;i++)
					list1.add_to_list_e(random.rng_data_to_array());
				time.end_m();
				std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
			
			break;
			}
			case 2:
			{
				time.start_m();
				for(int i = 0;i<how_many;i++)
					list1.add_to_list_b(random.rng_data_to_array());
				time.end_m();
				std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
				break;	
			}
			
			case 3:
			{
				time.start_m();
				for(int i = 0;i<how_many;i++)
					list1.add_to_list_r(random.rng_data_to_array());
				time.end_m();
				std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
				break;
			}
			default:
				std::cout<<"Error";
			break;
		}
		break;
		case 5:
		std::cout<<"Wybierz co dalej\n1.Wyswietl liste\n2.Usun z listy\n3.Szukaj w liscie: \n";
		std::cin>>choose_type;
		std::cout<<"\n";
		switch(choose_type)
		{
			case 1:
				list1.show_list();
			break;
			case 2:
			int choose_delete;
				std::cout<<"Wybierz skad chcesz usunac\n1.Z tylu\n2.Z przodu\n3.Z losowych miejsc\n";
				std::cin>>choose_delete;
				std::cout<<"Ile elementow\n";
				std::cin>>how_many;
				switch(choose_delete)
				{
					case 1:
					time.start_m();
					for(int i = 0;i<how_many;i++)
						list1.delete_from_list_e();
					time.end_m();
				std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
					break;
					case 2:
					time.start_m();
						for(int i = 0;i<how_many;i++)
						list1.delete_from_list_b();
					time.end_m();
				std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
					break;
					case 3:
					time.start_m();
					for(int i = 0;i<how_many;i++)
						list1.delete_from_list_r();
					time.end_m();
				std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
					break;


				}
			break;
			case 3:
			std::cout<<"Jaka liczbe wyszukac w tablicy";
				std::cin>>how_many;
				std::cout<<"\n";
				time.start_m();
				list1.search_in_list(how_many);
				time.end_m();
				std::cout<<"\nCzas wykonania operacji to: "<<time.duration_t()<<" jednostek czasu procesora";
			break;
		}
		break;


	}
	}while(1);
}

int main()
{
	Node node;
	int choose_structure;
	std::cout<<"Wybierz strukture:\n";
	std::cout<<"1.Array List\n2.Linked List(head pointer)";
	std::cin>>choose_structure;
	std::cout<<"\n";
	switch(choose_structure)
	{
		case 1:
			Array_list();
		break;
		case 2:
			Linked_List1();
		break;
		default:
			std::cout<<"error";
	}
	
	return 0;
}

#include <iostream>
#include "ArrayList.h"
#include "randomize.h"


	my_tab::my_tab()
	{
		size = 1;		//konstruktor klasy my_tab gdzie ustawiamy rozmiar na 1 i pozniej przez to tablice dynamiczna,filling na 0 poniewaz nic narazie nie jest wpisane
		filling = 0;
		tab1 = new int[size];
		place = 0;
	}
	int my_tab::get_size()
	{	
		return size;
	}
	my_tab::~my_tab()
	{	
		delete[] tab1;	//destruktor, usuwamy tablice dynamiczna z pamieci
	}	
	bool my_tab::size_to_filling()
	{
		if(size==filling) //metoda ktora sprawdza czy rozmiar jest rowny wypelnieniu, sluzy glownie do sprawdzania kiedy powiekszyc tablice
			return 1;
		else
			return 0;
	}
	void my_tab::add_to_tab_e(int value) //Dodawanie na koniec
	{
		if(!size_to_filling())
		{
			tab1[filling]=value; // jezeli wypelnienie jest mniejsze niz rozmiar, to w nastepne wolne miejsce jest wstawiana wartosc podana do metody
			filling +=1;
		}
		else
		{
			expand_tab();            // jezeli rozmiar jest rowny wpelnieniu, najpierw dwukrotnie zwiekszany jest rozmiar tablicy, a pozniej dodawana jest podana wartosc
			tab1[filling]=value;
			filling +=1;
		}
	}
	void my_tab::add_to_tab_b(int value) //Dodawanie na poczatek tablicy
	{
		if(!size_to_filling())
		{
			for(int i = filling;i>0;i--)
				tab1[i]=tab1[i-1];    //sprawdany jest rozmiar i wypelnienie, jezeli wypelnienie jest wieksze niz rozmiar cala tablica przeuswana jest w prawo
						      //a na pierwsze miejsce dodawana jest wartosc przekazana do metody
			
			tab1[0] = value;
			filling+=1;
		}
		else
		{

			expand_tab();	
			for(int i = filling;i>0;i--)	//jezeli wypelnienie jest rowne rozmiarowi, najpierw zwiekszany jest rozmiar tablicy, nastepnie cala tablica przesuwana jest	
				tab1[i]=tab1[i-1];	//przesuwana w prawo, a na index 0 wpisywana jest wartosc przekazana do metody
			
			tab1[0] = value;
			filling+=1;
		}
	}
	void my_tab::expand_tab()
	{
		int* tab2 = new int[size*2]; //Alokowana jest nowa tablica, ktora jest dwa razy wieksza niz poprzednia
		for(int i=0;i<size;i++)		// mniejsza tablica jest kopiowana do wiekszej, a nastepnie jest usuwana z pamieci
			tab2[i] =  tab1[i];
		delete[] tab1;
		tab1 = tab2;	//wskaznik tab1 jest ustawiany na tab2, aby po utworzeniu nowej tab2 jakis wskaznik dalej na te dane wskazywal, a na koncu aktualizowany jest rozmiar tab
		size *=2;
	} 
	int my_tab::get_filling()
	{
		return filling;
	}
	int my_tab::get_array_element(int nu)
	{
		return tab1[nu];
	}
	//TO_DO
	void my_tab::add_to_tab_r(int value)	//Dodawanie w losowych miejscach
	{
		random_data_generator random1;			//Tworzony jest obiekt klasy losujacej, losowane jest miejsce w ktore zostanie wstawiona wartosc, nastepnie sprawdzane jest
		place = random1.rng_place_in_array(filling);		//czy rozmiar jest rowny wypelieniu, jezeli nie to dane od konca do wylosowanego miejsca (wraz z nim)
									//sa przesuwane w prawo, a na wylosowane miejsce jest wstawiana wartosc przekazana do metody
		std::cout<<"\nWylosowane miejsce to: "<<place + 1<<std::endl;
		if(!size_to_filling())
		{
			for(int i = filling;i>place;i--)
			{
				tab1[i] = tab1[i-1];
			}
			tab1[place] = value;
			filling +=1;
		}
		else
		{
			expand_tab();
			for(int i = filling;i>place;i--)
			{					//jezeli rozmiar jest rowny wypelnieniu, najpierw zwiekszany jest rozmiar tablicy, a pozniej powtarzane sa operacje
				tab1[i] = tab1[i-1];		//opisane w komentrzy wyzej
			}
			tab1[place] = value;
			filling +=1;
		}
	}

	void my_tab::shrink_tab()
	{
		int* tab2 = new int[size-1];			//alokowana jest nowa tablica dynamiczna o rozmiarze o jeden mniejszym niz poprzednia tablica, ta metoda 
		size -= 1;					// jest zawsze wywolywana przy usuwaniu elementow
		for (int i = 0;i<size;i++)			//nastepnie tablica poprzednia jest kopiowana do nowej tablicy, nastepnie uwalniane jest miejsce 
			tab2[i]=tab1[i];			//zajmowane przez stara tablice, a na koniec ustawiamy wskaznim tab1, aby wskazywal na nowa tablice
		delete[] tab1;
		tab1 = tab2;
	}
	void my_tab::delete_from_tab_e(int how_many)	//Usuwanie z tylu
	{
		for(int i =0;i<how_many;i++)		//uzytkownik zostaje zapytane ile danych chce usunac, nastepnie usuwane sa dane metoda shrink_tab()
		{
		if (filling > 0) 
		{
        	shrink_tab();
        	filling--;
    	}
	 	else 
		{
        	std::cout << "Tablica jest już pusta." << std::endl; //jezeli wypelnienie jest rowne 0, co znaczy ze tablica jest pusta, wyswietlany jest stosowny komunikat
    	}
		}
	}
	void my_tab::search(int number)
	{
		for(int i=0;i<filling;i++)
		{
			if(tab1[i] == number)
				std::cout<<number<<" znajduje sie na miejscu "<<i+1<<"\n";  //metoda iteruje sie po elementach tablicy i jezeli na danej pozycji znajduje sie
		}										//liczba przekazana w metodzie, wyswietlany jest komunikat na jakim miejscu
		
	}
	void my_tab::delete_from_tab_b(int how_many)	//Usuwanie elementu z przodu
	{
		for(int i =0;i<how_many;i++)
		{
			if(filling>0)								//uzytkownik jest pytany ile elementow chce usunac, jezeli wypelnienie jest wieksze
			{									//od 0 to cala tablica jest przesuwana w lewo, elment o inexie 0 jest tracony
			for(int i = 1;i<filling;i++)						//a tablica jest zmniejszana przy uzyciu metody shrink_tab()
			{
				tab1[i-1]=tab1[i];
			}
			filling-=1;
			shrink_tab();
			}
			else 
			{
        	std::cout << "Tablica jest już pusta." << std::endl;				//jezeli wypelnienie jest rowne 0, to tablica jest pusta i wyswietlany jest stosowny
												//komuniktat
    		}
	
		}
	}
	void my_tab::delete_from_tab_r(int how_many) {		//Usuwanie z losowego miejsca
    random_data_generator random;
    if (filling > 0) {
        for (int i = 0; i < how_many; i++) {
            place = random.rng_place_in_list(filling);			//Tworziny jest obiekt klasy losujacej
            if (place == filling - 1) {
                delete_from_tab_e(1);
                filling -= 1;
                shrink_tab();
                return;
            }
            for (int j = place; j < filling - 1; j++) { 		//losujemy miejsce z ktorego zostanie usuniety element,nastepnnie cala tablica od konca do wylosowanego
                tab1[j] = tab1[j + 1];							//miejsca jest przesuwana w lewo. Element z wylosowanego miejsca jest zatracany,a cala tablica
            }													//jest zmniejszana przy uzyciu metody shrink_tab()
            shrink_tab();
            filling -= 1;
        }
    } else {
        std::cout << "Tablica jest już pusta." << std::endl;
    }
}

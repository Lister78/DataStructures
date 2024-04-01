#include <iostream>
#include "ArrayList.h"
#include "randomize.h"


	my_tab::my_tab()
	{
		size = 1;
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
		delete[] tab1;
	}	
	bool my_tab::size_to_filling()
	{
		if(size==filling)
			return 1;
		else
			return 0;
	}
	void my_tab::add_to_tab_e(int value) //Dodawanie na koniec
	{
		if(!size_to_filling())
		{
			tab1[filling]=value;
			filling +=1;
		}
		else
		{
			expand_tab();
			tab1[filling]=value;
			filling +=1;
		}
	}
	void my_tab::add_to_tab_b(int value) //Dodawanie na poczatek tablicy
	{
		if(!size_to_filling())
		{
			for(int i = filling;i>0;i--)
				tab1[i]=tab1[i-1];
			
			tab1[0] = value;
			filling+=1;
		}
		else
		{

			expand_tab();	
			for(int i = filling;i>0;i--)
				tab1[i]=tab1[i-1];
			
			tab1[0] = value;
			filling+=1;
		}
	}
	void my_tab::expand_tab()
	{
		int* tab2 = new int[size*2];
		for(int i=0;i<size;i++)
			tab2[i] =  tab1[i];
		delete[] tab1;
		tab1 = tab2;
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
	void my_tab::add_to_tab_r(int value)
	{
		random_data_generator random1;
		if(filling ==0)
		{
			tab1[0]=value;
			filling =1;
		}
		place = random1.rng_place_in_array(filling);
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
			{
				tab1[i] = tab1[i-1];
			}
			tab1[place] = value;
			filling +=1;
		}
	}

	void my_tab::shrink_tab()
	{
		int* tab2 = new int[size-1];
		size -= 1;
		for (int i = 0;i<size;i++)
			tab2[i]=tab1[i];
		delete[] tab1;
		tab1 = tab2;
	}
	void my_tab::delete_from_tab_e(int how_many)
	{
		for(int i =0;i<how_many;i++)
		{
		if (filling > 0) 
		{
        	shrink_tab();
        	filling--;
    	}
	 	else 
		{
        	std::cout << "Tablica jest już pusta." << std::endl;
    	}
		}
	}
	void my_tab::search(int number)
	{
		for(int i=0;i<filling;i++)
		{
			if(tab1[i] == number)
				std::cout<<number<<" znajduje sie na miejscu "<<i+1<<"\n";
		}
		
	}
	void my_tab::delete_from_tab_b(int how_many)
	{
		for(int i =0;i<how_many;i++)
		{
			if(filling>0)
			{
			for(int i = 1;i<filling;i++)
			{
				tab1[i-1]=tab1[i];
			}
			filling-=1;
			shrink_tab();
			}
			else 
			{
        	std::cout << "Tablica jest już pusta." << std::endl;
    		}
	
		}
	}
	void my_tab::delete_from_tab_r(int how_many)
	{
		random_data_generator random;
		if(filling>0){

		for(int i = 0;i<how_many;i++)
		{
			place = random.rng_place_in_array(filling);
			for(int i = place;i<filling;i++)
				tab1[i-1]=tab1[i];
			shrink_tab();
			filling-=1;
		}
		}
		else 
			{
        	std::cout << "Tablica jest już pusta." << std::endl;
    		}
	
	}

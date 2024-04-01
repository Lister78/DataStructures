#pragma once

class my_tab
{
	private:
		int* tab1; 
		int size;
		int filling;
		int place;
	public:
		int get_size();
		my_tab();
		~my_tab();
		bool size_to_filling();
		void add_to_tab_b(int);
		void add_to_tab_e(int);
		void expand_tab();
		int get_filling();
		int get_array_element(int);
		void add_to_tab_r(int);
		void shrink_tab();
		void delete_from_tab_e(int);
		void search(int);
		void delete_from_tab_b(int);
		void delete_from_tab_r(int);
};

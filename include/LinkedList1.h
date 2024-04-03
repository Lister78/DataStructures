class Node
	{
	public:
		int node_value;
		Node* next_value_ptr;
		Node* prev_value_ptr;
		Node();
		
	};

class LinkedList1
{
	private:
		Node* head;
		int filling;
	public:
		LinkedList1();
		~LinkedList1();
		void add_to_list_b(int);
		void show_list();
		bool check_if_list_empty();
		void add_to_list_e(int);
		void delete_from_list_b();
		void delete_from_list_e();
		void search_in_list(int);
		void delete_from_list_r();
		void add_to_list_r(int);
};

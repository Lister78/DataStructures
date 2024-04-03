
class DoubleLinkedL{
	private:
		Node* head;
		Node* tail;
		int filling;
	public:
		DoubleLinkedL();
		~DoubleLinkedL();
		void add_to_list_e(int);
		void add_to_list_b(int);
		void delete_from_list_b();
		void delete_from_list_e();
		void delete_from_list_r();
		void add_to_list_r(int);
		void show_list();
		void search_in_list(int);
};

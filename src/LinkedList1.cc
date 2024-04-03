#include "LinkedList1.h"
#include "iostream"
#include "randomize.h"
Node::Node()
{
	node_value=0;			//Konsturktor "wezla", wezel to klasa ktora przechowuje wlasna wartosc, oraz wskaznik na nastepny wezel
	next_value_ptr=nullptr;
	prev_value_ptr=nullptr;
}

LinkedList1::LinkedList1()
{
		head=nullptr;		//Konsturktor klasy odpowiadajaca za liste jednokierunkowa, head jest wskaznikiem na 1 wezel calej listy
		filling = 0;
}
LinkedList1::~LinkedList1()
{
    while (!check_if_list_empty()) {
            Node* temp = head;
            head = head->next_value_ptr;
            delete temp;
        }
}
void LinkedList1::add_to_list_b(int value)	//Dodanie elemntu do listy na poczatek
{
	Node* node = new Node;              //Tworzony jest wezel, oraz wskaznik na niego, do pola value wezla jest wpisywana wartosc podana przez uzytkownika, a pole next jest zmaieniane na aktualne
	node->node_value = value;           //pole head, poniewaz po dodanu nowego wezla, aktualny head jest wskaznikiem na 2 element listy. Head jest zastepowany adresem nowego wezla, po kazdym
	node->next_value_ptr=head;              //wykonaniu iteruje sie zmienna odpowiadajaca za wypelnienie listy
	head = node;
	filling +=1;
}

bool LinkedList1::check_if_list_empty()
{
    if(!head)                                       //Funkcja sprawdza czy lista jest pusta(wtedy head, czyli poczatek listy ma wartosc nullptr)
        return 1;
    else    
        return 0;
}

void LinkedList1::show_list()
{
        Node* show = head;
        while (show != 0) {
            std::cout << show->node_value << " ";    //Tworzony jest tymczasowy wskaznik na pierwszy element listy, nastepmie dzieki petli while iterowane jest po calej liscie, wyswietlana jest wartosc  
            show= show->next_value_ptr;                //aktualnego wezla, a nastepnie wskaznik jest zmieniany na nastepny wezel
        }
    
}

void LinkedList1::add_to_list_e(int value) //Dodawanie do konca listy
{
    
	Node* node = new Node;              //Tworzony jest wskaznik ktory wskazuje na nowy wezeal, do niego wpisywana jest wartosc podana do metody, jezeli lista jest pusta head jest ustawiany na  
    node->node_value = value;         // adres wlasnie wpisanego wezla, nastepnie zostaje stworzony obiekt tymczasowy, a jego adresem pozostaje wskaznik na 1 element, a nastepnie adres
	if (check_if_list_empty())                  //"przeskakuje" na nastepny wezel do momentu dojscia do ostatniego wezla (wskaznik na nastepny element to nullptr),a nastepnie wskaznik na nastepny
	    {                                   //element jest zmieniany z nullptr na adres wezla ktory zostal stworzony na poczatku metody
        head = node;
        return;
        }
        Node* curr = head;
    while (curr->next_value_ptr)
    {
        curr = curr->next_value_ptr;
    }
    curr->next_value_ptr = node;
    filling+=1;
	
}

void LinkedList1::delete_from_list_b() //Usuwanie z poczatku
{
        if (check_if_list_empty()) {                                       //Jezeli w liscie nie ma zadnego elementu wyswietlany jet komunikat, jezeli w liscie sa elemnty tworzony jest nowy wskaznik
            std::cout << "Lista jest pusta." << std::endl;      //i jest ustawiany a adres 1 elementu, a wskaznik head jest ustawiany na nastepny element, a pierwszy element jest usuwany
            return;
        }
        Node* curr = head;                                      //Jezeli nie stworzylibysmy curr i nie wskazali na 1 element, tylko zmienili wartosc head na nastepy element, nie moglibysmy
        head = head->next_value_ptr;                            //usunac starego 1 elementu z pamieci, co moglo by doprowadzic do problemow w zarzadzaniu pamiecia
        delete curr;
	filling -=1;
}
void LinkedList1::delete_from_list_e() //Usuwanie z tylu
{
    if (check_if_list_empty()) {                                    //Najpierw sprawdzane jest czy lista jest pusta, jeseli tak to wyswietlany jest stosowny komunikat
            std::cout << "Lista jest pusta." << std::endl;
            return;
        }
        if (filling==1) {                                    //Jezeli w liscie znajduje sie jeden element usuwany jest wskaznik tego elementu, a head jest ustawiany na nullptr
            delete head;
            head = nullptr;
            filling=0;
            return;
        }
        Node* curr = head;                                          //Jezlei znajduje sie tam wiecej niz 1 element, tworzony jest wskaznik tymaczasowy, a nastpnie sprawdzanie jest czy wskaznik na
        while (curr->next_value_ptr->next_value_ptr) {             //nastepny wezel posiada wskaznik na nastepny wezel czy jest nullptr, jezeli posiada wskaznik jest przesuwany na nastepy wezel
            curr = curr->next_value_ptr;                            //i operacja jest powtarzana, jezeli zmienna "znajdzie" koniec listy, ustawia sie na przedostatni element, usuwa ostatni wezel
        }                                                           //oraz ustawia wskaznik nastpnego wezla na nullptr
        delete curr->next_value_ptr;
        curr->next_value_ptr = nullptr;
	filling -=1;
}

void LinkedList1::search_in_list(int value) {
    Node* curr = head;                                                                          //Tworzony jest wskaznik i ustawiany jest na poczatek listy
    int place = 0;
    while (curr != 0) {                                                                         //petla sprawdza kazdy wezel, czy wartosc w nim zgadza sie z wartoscia szukana przez uzytkownika,
        if (curr->node_value == value) {                                                        //jezeli tak, wyswietla stosowny komunikat, jezeli nie wskaznik ustawiany jest na nastepny wezel
            std::cout << "Liczba " << value << " znajduje się na pozycji " << place+1 << std::endl;  //jezeli ostatni zmienna tymczasowa bedzie wskazywala nullptr(petla przejdzie wszystkie elementy)
        }                                                                                                // petla sie zakonczy
        curr = curr->next_value_ptr;
        place++;
    }
}

void LinkedList1::delete_from_list_r()
{
	random_data_generator random;                                                       //Tworzony jest obiekt do losowania liczb, nastepnie sprawdzane jest czy lista jest pusta, jezeli tak
        if (check_if_list_empty()) {                                                    //Wyswietlany jest odpowiedni komunikat
            std::cout << "Lista jest pusta." << std::endl;
            return;
        }                                                                               //Jezeli nie, to tworzony jest wskaznik tymczasowy, ktory wksazuje na 1 element listy
        Node* curr = head;                                                                //Pozniej losowane jest miejsce w liscie na ktore zostanie wusuniete
        int randomIndex = random.rng_place_in_list(filling);                               
        if (randomIndex == 0) {                                                             //Jezeli wylosowana wartosc to 0 to uzywana jest metoda do usuwania elementow z przodu listy
            delete_from_list_b();
            filling-=1;
	    return;
        }   
        if(randomIndex == filling)
        {   
            delete_from_list_e();
            filling-=1;
            return;
        }                                                                                
        for (int i = 0; i < randomIndex - 1; i++) {                                     //Nastpnie przestawiamy wskaznik(przez iterowanie sie odpowiednia ilosc razy), na element 1 przed elementem majacym byc usuniety
            curr = curr->next_value_ptr;                                                //tworzywmy wskaznik na element majacy byc usuniety, a chwile pozniej go usuwamy, nastepnie wskaznik na nastepny element, na elemencie
            }                                                                          //wskazywanym przez wskaznik tymczasowy, przestawiamy na wskaznik 2 do przodu(wskaznik na wskaznik(trzeba to zrobic przed usuwnieciem elementu))
        
        Node* del = curr->next_value_ptr;
        curr->next_value_ptr = curr->next_value_ptr->next_value_ptr;
        delete del;
	filling-=1;
}
void LinkedList1::add_to_list_r(int value)
{
    random_data_generator random1;
    if (check_if_list_empty()) {
        
        add_to_list_b(value);
        filling+=1;                       // Jesli lista jest pusta, wywolywana jest metoda, ktora na poczatku dodaje element dany przez uzytkownika
        return;
    }
    Node* curr = head;                              //Jezeli lista nie jest pusta tworzony jest wskaznik typczasowy, ktory ustawiany jest na poczatek listy
    int randomIndex = random1.rng_place_in_array(filling);           //Losowane jest miejsce w ktore ma zostac wstawione
    if (randomIndex == 0) {                          //Jezeli wylosowany index wynosi 0, uzywana jest metoda do wstawiania wartosci na poczataek
        add_to_list_b(value);
        filling+=1; 
        return;
    }
    if (randomIndex == filling) {       //Jezeli wyllosowane zostanie ostatnie miejsce, to uzywana jest metoda dodawania elementu na koniec
        add_to_list_e(value);
        filling+=1;
        return;
    }
    for (int i = 0; i < randomIndex - 1; i++) {                         //Jezeli zostanie wylosowane inne miejsce to wskaznik jest przesuwany na element przed miejsce w ktore zaraz ma wejsc inny
        curr = curr->next_value_ptr;                                    //element, tworzony jest nowy wezel oraz wskaznik ktory na niego wskazuje. Wskaznik ten uzupelniany jest wartoscia podana
    }                                                                   //przez uzytkownika, oraz adresem nastepnego wezla. Natomiast adres w wezle bedacym wskazany przez wskaznik tymczasowy
    Node* add = new Node;                                               //zostaje ustwiony na nowo stworzony wezel
    add->node_value=value;
    add->next_value_ptr = curr->next_value_ptr;
    curr->next_value_ptr = add;
}

#include "LinkedList1.h"
#include "DoubleLinkedList.h"
#include "randomize.h"
#include <iostream>

DoubleLinkedL::DoubleLinkedL()
{	
	head = nullptr;			//Konstruktor, ustawia wkaznikiki head i tail na nullptr, a wypelnienie na 0
	tail = nullptr;
	filling =	0;
}

    								
DoubleLinkedL::~DoubleLinkedL() 
{
        while (head != nullptr) 
	{				//Destruktor, poki nie trafi na opcje gdy head jest nullptr(co znaczy ze lista jest pusta), tworzony jest
            Node* curr = head;					//wskaznik tymczasowy, ktoremu wskazuje sie nastepna wartosc, a nastepnie usuwa sie caly wezel, na ktory on wskazuje
            head = curr->next_value_ptr;
            delete curr;
        }
}

    						
void DoubleLinkedL::add_to_list_e(int value) //Dodawanie na koniec listy
{										
        Node* node = new Node;						//Tworzony jest wskaznik na nowy wezel, a wartosc nowego wezla od razu jest ustawiana na wartosc podana
        node->node_value = value;					//przez uzytkownika. Nastepnie sprawdzane jest czy lista jest pusta, jezeli tak to head oraz tail,
									//ustawiane sz na ten sam nowy wezel
        if (filling == 0) 
	{
		head = node;
        tail = node;
    } 
	else 
	{							//Jezeli lista nie jest pusta tail ustawiany jest na nowy dodawany wezel, a wczesniejsza wartosc taila, ustawiona jest
            tail->next_value_ptr = node;			//na wskaznik dla wczessniejszego wezla, a na koncu dodawana jest zmienna odopwiadajaca za 
            node->prev_value_ptr = tail;
            tail = node;
        }
        filling++;
    }

    void DoubleLinkedL::delete_from_list_b() //Usuwanie z poczatku listy
    {
        if (filling==0)    
        { 
            std::cout <<"Lista jest pusta." << std::endl;  //Sprawdzane jest czy lista jest pusta, jezeli tak wyswietlany jest odpowiedni komunikat
            return;
        }
        Node* curr = head;                  //Nastepnie tworzony jest wskaznik tymczasowy ktoremu wkzaywana jest 1 wartosc z listy
        head = head->next_value_ptr;        //Nastepnie jako 1 element listy ustawiany jest aktualny 2 element
        if (head != nullptr)
            head->prev_value_ptr = nullptr;     //Jezeli w liscie byl tylko 1 element to po prostu usuwany jest stary 1 element, jezeli bylo wiecej to wskaznik na
                                                // wczesniejsza wartosc 2 elementu jest ustawiany na nullptr, aby nie wskazywala na obszar z ktorego wartosc ma zaraz zostac usunieta
        delete curr;
        filling--;
    }

    void DoubleLinkedL::delete_from_list_e() //Usuwanie z konca listy
    {
        if (filling==0) 
        {                                                       //Jezeli wypelnienie wynosi 0, wyswietlany jest stosowny komunikat
            std::cout << "Lista jest pusta." << std::endl;
            return;
        }
        Node* curr = tail;                                          //Jezeli wielkosc listy jrst wieksza od 0, tworzony jest nowy wskaznik ktory wskazuje na statni element listy
        tail = tail->prev_value_ptr;                                //A nowy tail ustawiany jest na adres poprzednio przedostatniego elementu listy
        if (filling!=1)                                        //jezeli tail po tych operacjach jest rozny od nullptr co znaczy ze rozmiar listy byl wiekszy od 1 to wskaznik na nastepna wartos taila
            tail->next_value_ptr = nullptr;
        else
        {
            tail=nullptr;
            head=nullptr;
        }                              //ustwaiana jest na nullptr, a wskaznik tymczasowy wskazujacy na akualnie ostaatni element na liscie jest usuwany, jezeli wielkosc listy wynosi 1 head i tail
        delete curr;                    //ustawiany jest na nullptr, a jedyny element jest usuwany
        filling--;
    }

    void DoubleLinkedL::delete_from_list_r() //usuwanie z losowego miejsca w liscie
    {
        if (filling==0) 
        {                                                           //Na poczatku sprawdzane jest czy lista nie jest pusta, jezeli tak to wyswietlany jest komunikat
            std::cout << "Lista jest pusta." << std::endl;
            return;
        }
        random_data_generator random;                                   //Tworzony jest obiekt metody losujacej
        int randomIndex = random.rng_place_in_list(filling);                         
        if (randomIndex == 0)                   //Jezeli wylosowany index wskazuje na poczatek listy, wykonywana jest metoda suwajaca element z poczatku
        {
            delete_from_list_b();
        } else if (randomIndex == filling - 1) 
        {                                                   //Jezeli wylosowany index to numer ostatniego elementu to wywolywana jest metoda usuwajaca ostatni element
            delete_from_list_e();
        } else 
        {                                                   //Jezeli wylosowany element jest inny od poprzednich przypadkow, tworzony jest wskaznik tymczasowy, a jego wartosc ustawiana jest 
            Node* curr = head;                              //na poczatek listy, nastepnie przez przesuwanie wskaznika na wskazniki nastepnych wartosci docieramy do tego, ze wskaznik
            for (int i = 0; i < randomIndex; i++) {         //wkazuje na element majacy zostac usuniety
                curr = curr->next_value_ptr;
            }
            curr->prev_value_ptr->next_value_ptr = curr->next_value_ptr; //Wskaznik nastepnej wartosci, poprzedniego elementu ustawiany jest na wskaznik nastpnego elementu(tego po majacym byc usuniety)
            curr->next_value_ptr->prev_value_ptr = curr->prev_value_ptr;    //Wkaznik poprzedniej wartosc, nastepnego elementu jest ustawiany na adres poprzedniego elementu
            delete curr;                                                        //wskaznik tymaczsowy jest usuwany razem z wartoscia
            filling--;
        }
    }

      void DoubleLinkedL::add_to_list_b(int value) //Dodanie na poczatek listy
      {
        Node* node = new Node;                     //Tworzony jest wskaznik na nowy wezel i przypisywana jest mu wartosc podana przez uzytkownika
        node->node_value = value;
        if (filling==0 )                        //Jezeli lista jest pusta head i tail sa ustawiane na ten wezel
        { 
            head = node;
            tail = node;
        } else                                      //Jezeli lista nie jset pusta
        {
            node->next_value_ptr = head;                    //wskaznik na nastepna wartosc elementu jest ustawiana na aktualny head
            head->prev_value_ptr = node;                    //a wsk na wartosc poprzedniego elementu aktualnie 1 w liscie elementu jest ustawiana na adres nowwego wezla
            head = node;                                    //head jest zmieniany na adres nowego wezla
        }
        filling++;
    }

    
    void DoubleLinkedL::add_to_list_r(int value)    //dodawanie w losowych miejscach 
    {
        if (filling == 0) {     // Dodajemy na poczatek jezeli lista jest pusta
            add_to_list_b(value);
        } else
        {
            int randomIndex = rand() % filling; //Jezeli nie jest pusta losujemy index
                if (randomIndex==0)
                {                                                  //Jezeli wylosowany index to poczatek, to wywolujemy metode dodawania na poczaatek listy
                    add_to_list_b(value);
                    return;
                }
            if (randomIndex == filling-1) { // Jezeli wylosowany index jest ostatnim elementem to dodajemy na koniec
                add_to_list_e(value);
            } else 
            {        //Jezeli niee to tworzymy wskazik na nowy wezel
                Node* node = new Node;      //wpisujemy mu wartosc i tworzymy tymczasowy wskaznik na poczatek listy
                node->node_value=value;
                Node* curr = head;
                for (int i = 0; i < randomIndex; i++) //przesuwamy wskaznik na miejsce w ktorym ma byc dodany nowy element 
                {
                    curr = curr->next_value_ptr;
                }
                node->next_value_ptr = curr->next_value_ptr;        //wskaznik na nastepna wartosc nowaego wezla jest ustawiana na wskaznik na nastepny wezel wskaznika tymaczasowego
                node->prev_value_ptr = curr;                        //wskaznik na poprzedni element jest ustawiany na wskaznik tymczasowy
                curr->next_value_ptr->prev_value_ptr = node;        //wskaznik poprzedniego wezla elementu bedacego przed nowym wezlem ustawiana jest na adres nowego wezla
                curr->next_value_ptr = node;                        //wskaznik na nastepny element, elementu wskazanego przez wskaznik tymczasowy jest ustawiany na adres nowego wezla
                filling++;
            }
        }
    }

    void DoubleLinkedL::show_list() //Wyswietla liste
    {
        Node* curr = head; //tworzy wskaznik na poczatek listy
        while (curr != nullptr)    //dopoki nie dojdzie do konca listy, to wyswietla kazdy element(
        {
            std::cout << curr->node_value << " ";
            curr = curr->next_value_ptr;
        }
        std::cout << std::endl;
    }

    void DoubleLinkedL::search_in_list(int value) //wyszukiwanie w liscie
    {   
        Node* curr = head;                                              //Tworzony jest wskaznik tymczasowy, i jego adres ustawiany jest na poczatek listy, tworzona jest zmienna int ktora ma
        int place = 0;                                                  //wksazywac na ktorym miejscu w liscie jestesmy
        while (curr != nullptr)                                         //wskaznik przesuwany jest po calej liscie, dopki nie dojdzie do ostatniego elementu 
        {
            if (curr->node_value == value)                              //z kazda iteracja wartosc w wezle porownywana jest z wartoscia szukana 
            {
                std::cout << "Liczba " << value << " znajduje się na pozycji " << place + 1 << std::endl;
            }
            curr = curr->next_value_ptr;
            place++;
        }
    }



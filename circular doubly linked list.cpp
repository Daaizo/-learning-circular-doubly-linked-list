#include <iostream>
using namespace std;
struct element
{
    element *next;
    element *prev;
    int number;

};
// próba 17 ja ju¿ nie wiem
void add_before(element *& , int);
void add_after(element *& , int);
void delete_after(element *&);
void delete_before(element *&);
void delete_current(element *&);
bool is_Empty(element *);
void print_list(element *);

int main()
{
    element *List = nullptr;

    int choice= -1;
    while(choice != 9)
    {
        if(!is_Empty(List)) cout << "\n element biezacy : " << List->number ;
        if(!is_Empty(List)){ cout << "\n list : "; print_list(List);} ;
        cout <<"\n\nMENU\n1.sprawdzenie czy lista jest pusta\n2.dodanie elementu za element biezacy\n3.dodanie elementu przed element biezacy\n4.usuniecie elementu stojacego za elementem biezacym";
        cout << "\n5.usuniecie elementu stojacego przed elementem biezacym\n6.usuniecie elementu biezacego,a element stojacy za nim staje sie biezacym\n7.wyswietlenie elementow\n8.usuniecy listy\n9.wyjscie z programu\n";
        cin >> choice;
        system("cls");

      //  cout << endl;
        switch(choice)
        {
            case 1:
            {
                cout <<( is_Empty(List) ? " lista jest pusta " :" lista nie jest pusta" );
                break;
            }
            case 2:
            {
                int v;
                cout << " podaj numer do dodania za element biezacy : ";
                cin >> v;
                add_after(List, v);
                break;
            }
            case 3:
            {
                int v;
                cout << " podaj numer do dodania przed element biezacy : ";
                cin >> v;
                add_before(List, v);
                break;
            }
            case 4:
            {
                if(is_Empty(List))
                {
                    cout << " lista jest pusta i nie ma co usunac";
                }
                else if(List == List->next)
                {
                    cout << " jest tylko jeden element i nie ma elementu nastepnego !";

                }
                else
                {
                    delete_after(List);

                }
                break;
            }
            case 5:
            {
                if(is_Empty(List))
                {
                    cout << " lista jest pusta i nie ma co usunac";
                }
                else if(List == List->next)
                {
                    cout << " jest tylko jeden element i nie ma elementu poprzedniego !";

                }
                else
                {
                    delete_before(List);

                }

                break;
            }
            case 6:
            {
                if(is_Empty(List))
                {
                    cout << " lista jest pusta i nie ma co usunac";
                }
                else if(List == List->next)
                {
                    string ans ;
                    cout << "jest tylko jeden element czy chcesz go usunac TAK/NIE : ";
                    cin >> ans;
                    if(ans == "T" || ans == "t" || ans == "TAK" || ans == "tak" )
                    {
                        List = nullptr;
                    }
                }
                else
                {
                    delete_current(List);
                }
                break;
            }
            case 7:
            {
                if(is_Empty(List))
                {
                    cout << " lista jest pusta i nie ma co wyswietlic";
                }
                else
                {
                    cout << " list : " ;
                    print_list(List);
                }

                break;
            }
            case 8:
                {
                    if(is_Empty(List)) cout << " lista jest pusta i nie ma co usunac ";
                    else
                    {
                        while(List != List->next)
                        {
                            delete_current(List);
                        }
                        List = nullptr;
                    }
                    break;
                }
            case 9:
            {
                cout << "wychodzenie .." ; exit(1);
                break;
            }
            default : cout << " poano zly numer, sprobuj ponownie";




        }

    }

    return 0;
}
void add_before(element *&current , int value_too_add)
{
   if(current == nullptr)
   {
        current = new element;
        current->number = value_too_add;
        current->next = current;
        current->prev = current;
    }
   else
   {
        element *el = new element; // nowy element
        element *temp = current;  // biezacy element
        element *previous = current->prev;  // jeden przed biezacym

        el->number = value_too_add;
        el->next = temp;
        el->prev = previous;
        previous->next = el;
        temp->prev = el;
        current = el;

   }
}

void add_after(element *&current , int value_too_add)
{
    if(current == nullptr)
    {
        current = new element;
        current->number = value_too_add;
        current->next = current;
        current->prev = current;
    }
    else
    {
        element *el = new element; // nowy element
        element *temp = current;  // biezacy element
        element *next = current->next;  // jeden za biezacym
        el->number = value_too_add;
        el->next = next;
        el->prev = temp;
        temp->next = el;
        next->prev = el;
        current = el;
    }
}

void delete_after(element *&current )
{

    element *temp = current->next->next;
    element *el = current;
    el->next = temp;
    temp->prev = el;

}


bool is_Empty(element *current)
{
    return !current;
}
void print_list(element *current)
{
    element * temp = current;
    while(temp->next != current)
    {
        cout << temp->number << " ";
        temp = temp->next;
    }
    cout << temp->number << " ";
}
void delete_before(element *&current)
{
    element *temp = current->prev->prev;
    element *el = current;
    temp->next = el;
    el->prev = temp;

}
void delete_current(element *&current)
{
    element *previous = current->prev;
    element *next = current->next;
    previous->next = next;
    next->prev = previous;
    current = next;
}

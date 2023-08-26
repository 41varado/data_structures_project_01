#include <iostream>

#include "circular_linked_list.h"
#include "project.h"
#include "..\util.h"

using namespace std;

bool circular_linked_list::remove(const NODE& node)
{
if (head_node == nullptr) {
        return false;  
    }

    NODE* current_node = head_node;
    NODE* previous_node = nullptr;

    do {
        if (current_node->data == node) {
            if (current_node == head_node) {
                if (current_node->next_node == head_node) {
                   
                    delete current_node;
                    head_node = tail_node = nullptr;
                } else {
                    head_node = current_node->next_node;
                    tail_node->next_node = head_node;
                    delete current_node;
                }
            } else if (current_node == tail_node) {
                tail_node = previous_node;
                previous_node->next_node = head_node;
                delete current_node;
            } else {
                previous_node->next_node = current_node->next_node;
                delete current_node;
            }
            return true;  
        }

        previous_node = current_node;
        current_node = current_node->next_node;
    } while (current_node != head_node);

    return false; 
}

NODE* circular_linked_list::find(const PROJECT& project)
{
NODE* current_node = head_node;
    
    if (head_node) {
        do {
            if (current_node->data == project) {
                
                return current_node;
            }
            current_node = current_node->next_node;
        } while (current_node != head_node);
    }

    return nullptr;
}

void circular_linked_list::append(const PROJECT& project)
{
	NODE* new_node = new NODE();
	new_node->data = project;
	
	if (!head_node) {
	   head_node = tail_node = new_node;
	   head_node->next_node = head_node->previous_node = head_node;
	} else {
		head_node->previous_node = new_node;
		tail_node->next_node = new_node;
		
		new_node->next_node = head_node;
		new_node->previous_node = tail_node;
		tail_node = new_node;
	}
}

void remove(const PROJECT& project)
{
	NODE *current_node = head_node;
	NODE *previous_node = nullptr;
	bool found = false;

	if(head_node){
		do {
			if (current_node->data == project) {
				MoveCursor(60,6);
				cout<<"Nombre país         :  "<<current_node->data.name;
				MoveCursor(60,7);
				cout<<"Número de habitantes:  "<<current_node->data.population;
				MoveCursor(60,8);
				cout<<"Número de kilometros:  "<<current_node->data.area;
				MoveCursor(60,9);
				cout<<"Ingreso percápita $:   "<<current_node->data.perCapitaIncome;
				found = true;	  	
				char borrar='N';
				MoveCursor(60,11);
				cout<<"¿Desea eliminar el nodo?";
				cin>>borrar;
				if(borrar=='S' || borrar =='s') {
					if (current_node == head_node){
						head_node = head_node->next_node;
						head_node->previous_node = tail_node;
						tail_node->next_node = head_node;
					} else if(current_node==tail_node){
						tail_node = previous_node;
						tail_node->next_node = head_node;
						head_node->previous_node = tail_node;	
					} else{
						previous_node->next_node = current_node->next_node;
						current_node->next_node->previous_node = previous_node;
					}
					MoveCursor(60,13);
					cout<<"El nodo fue eliminiado correctamente!!";
				}
		  	}
		
			current_node = current_node->next_node;
		} while(current_node != head_node && found == false);
	}
	else
	{
	   MoveCursor(60,13);	
	   cout<<"La lista está vacía!!";
	}
	  MoveCursor(60,13);
	  if (found == false)
	    cout<<"El "<<pais<<" no existe en la lista!";
 	  MoveCursor(60,14);
      system("Pause");	
}

void mostrarDatos(){
	NODE* current_node = new NODE();
	current_node = head_node;
	int fila=7;
	int totKm=0, totHab=0;
	int mayorHab=0, mayorKm=0;
	float mayorIPC;
	string pais1, pais2, pais3;
	MoveCursor(60,2);
    cout<<"Listado de ciudades  en la lista";
    MoveCursor(50,4);
    cout<<"País";
    
    MoveCursor(62,4);
    cout<<"Número";
    MoveCursor(77,4);
    cout<<"Número";
    MoveCursor(92,4);
    cout<<"Ingreso";
	
	MoveCursor(60,5);
	cout<<"habitantes";
    MoveCursor(75,5);
    cout<<"kilometros";
    MoveCursor(90,5);
    cout<<"percápita ($)";
	MoveCursor(44,6);
	cout<<"---------------------------------";
	MoveCursor(72,6);
	cout<<"---------------------------------";
	if(head_node != nullptr){
		mayorHab = head_node->data.population;
		mayorKm  = head_node->data.area;
		mayorIPC = head_node->data.perCapitaIncome;
 		pais1 = pais2 = pais3 = head_node->data.name;
 		do{
            MoveCursor(45,fila);
            cout<<current_node->data.name;
            MoveCursor(62,fila);
            cout<<current_node->data.population;
            MoveCursor(77,fila);
            cout<<current_node->data.area;
            MoveCursor(94,fila);
            cout<<current_node->data.perCapitaIncome;
            totKm  += current_node->data.area;               
            totHab += current_node->data.population;
			if (current_node->data.population > mayorHab){
				mayorHab = current_node->data.population;
				pais1 = current_node->data.name;
			}
			if (current_node->data.area > mayorKm){
				mayorKm = current_node->data.area;
				pais2 = current_node->data.name;				
			}
			if (current_node->data.perCapitaIncome > mayorIPC){
				mayorIPC = current_node->data.perCapitaIncome;
				pais3 = current_node->data.name;								
			}
			fila++;          
			current_node = current_node->next_node;
		}while(current_node != head_node);
	}
	else
	{
	   cout<<"La lista está vacía!!";
	}
	  MoveCursor(44,fila);
	  cout<<"-----------------Fin del listado--";
	  MoveCursor(76,fila);
	  cout<<"-----------------------------";
	  fila+=2;
	  MoveCursor(50,fila); fila+=2;
	  cout<<"Total kilometros países en la lista: "<<totKm;
	  MoveCursor(50,fila); fila+=2;
	  cout<<"Total habitantes países en la lista: "<<totHab;
	  MoveCursor(50,fila); fila+=2;
	  cout<<"Paï¿½ses con mï¿½s poblaciï¿½n "<<pais1<<" con "
	      <<mayorHab<<" habitantes.";
	  MoveCursor(50,fila); fila+=2;
	  cout<<"Paï¿½ses con mayor nï¿½mero de kilï¿½metros "<<pais2
	      <<" con "<<mayorKm<<" kilï¿½metros.";
	  MoveCursor(50,fila); fila+=2;
	  cout<<"Paï¿½ses con mayor ingreso percï¿½pita "<<pais3
	      <<" con "<<mayorIPC<<" dï¿½lares por persona.";  
	  MoveCursor(50,fila);
      system("Pause");	
}
 
void buscarNodo(string pais) {
	bool found = false;
	NODE *current_node;

	if (head_node) {
		current_node = head_node;

		do {
			if (current_node->data.name == pais){
				MoveCursor(60,6);
				cout << "Nombre país:				" << current_node->data.name;
				MoveCursor(60,7);
				cout << "Número de habitantes: 		" << current_node->data.population;
				MoveCursor(60,8);
				cout << "Número de kilometros:  	" << current_node->data.area;
				MoveCursor(60,9);
				cout << "Ingreso percápita $:   	" << current_node->data.perCapitaIncome;
				found = true;
				break;
		  	}

 			current_node = current_node->next_node;
		} while(current_node != head_node);
	}
	else
	{
	   MoveCursor(60,12);	
	   cout << "La lista está vacía!!";
	}

	MoveCursor(60,12);
	if (found == false) {
		cout << "El elemento \"" << pais << "\" no existe en la lista!";
	}

	MoveCursor(60,14);
	system("Pause");	
}
 
void eliminarLista(){
    NODE *reco = head_node->next_node;
    NODE *borrar;
    while (reco != head_node)
        {
            borrar = reco;
            reco = reco->next_node;
            delete borrar;
        }
        head_node=nullptr;
        tail_node=nullptr;
    	MoveCursor(65,23);
    	cout<<"La lista fue totalmente eliminada !!!";
    	MoveCursor(65,24);
        system("Pause");
}

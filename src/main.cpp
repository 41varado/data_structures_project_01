#include<iostream>

#include <windows.h>

#include "circular_linked_list.h"
#include "project.h"

// TODO: Just a little test: https://en.cppreference.com/w/cpp/chrono/parse
void get_date()
{
    std::chrono::year_month_day date;
    //auto manipulator = std::chrono::parse("%d/%m/%Y", date);
    std::cin >> std::chrono::parse("%d/%m/%Y", date);
    // OR: std::chrono::from_stream(std::cin, "%d/%m/%Y", date);

    std::cout << date;

    //PROJECT project { 
    //    .startDate = DATE::year_month_day(std::chrono::year(2023), std::chrono::month(2), std::chrono::day(14))
    //};
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Helló!\n";
}

//int main() {
//	SetConsoleOutputCP(CP_UTF8);
//    //setlocale(LC_ALL,"");
//    int numHabitantes, numKilometros, opcion = 0;
//    char pais[MAX_COUNTRY_NAME_SIZE];
//	float ingPercapita;
// 
//    do{
//    	system("CLS");
//    	MoveCursor(10,2);
//    	cout<<"Lista circular doblemente enlazada";
//    	MoveCursor(10,4);
//    	cout<<"1. Agregar nodo";
//    	MoveCursor(10,5);
//    	cout<<"2. Eliminar nodo ";
//    	MoveCursor(10,6);
//    	cout<<"3. Buscar nodo ";
//    	MoveCursor(10,7);
//    	cout<<"4. Ver listado en la lista";
//    	MoveCursor(10,8);
//    	cout<<"5. Eliminar toda la lista";
//    	MoveCursor(10,9);
//    	cout<<"6. Salir";
//    	MoveCursor(10,10);
//    	cout<<"Digite opción: ";
//    	cin>>opcion;
//    	switch(opcion){
//    		case 1: 
//    		      MoveCursor(60,2);
//    		      cout<<"Inclusión de datos";
//    		      MoveCursor(60,4);
//    		      cout<<"Digite nombre país : ";
//    		      cin.ignore();
//    		      cin.getline(pais, MAX_COUNTRY_NAME_SIZE, '\n');
//    		      MoveCursor(60,5);
//    		      cout<<"Digite número de habitantes : ";
//    		      cin>>numHabitantes;
//    		      MoveCursor(60,6);
//    		      cout<<"Digite número de kilometros : ";
//    		      cin>>numKilometros;
//    		      MoveCursor(60,7);
//    		      cout<<"Digite ingreso percápita ($): ";
//    		      cin>>ingPercapita;
//    		      append(pais, numHabitantes, numKilometros, ingPercapita);
//                  MoveCursor(60,23);
//    		      system("Pause");	
//				  break;
//			case 2:
//    		      MoveCursor(60,2);
//    		      cout<<"Eliminación de país";
//    		      MoveCursor(60,4);
//    		      cout<<"Digite nombre país a eliminar : ";
//    		      cin.ignore();
//    		      cin.getline(pais, MAX_COUNTRY_NAME_SIZE, '\n');
//    		      remove(pais);
//				  break;			  
//    		case 3:
//    		      MoveCursor(60,2);
//    		      cout<<"Búsqueda de país";
//    		      MoveCursor(60,4);
//    		      cout<<"Digite nombre país a buscar : ";
//    		      cin.ignore();
//    		      cin.getline(pais, MAX_COUNTRY_NAME_SIZE, '\n');
//    		      buscarNodo(pais);
//				  break;
//			case 4:
//				  mostrarDatos();
//				  break;
//			case 5:
//                   eliminarLista();
//				  break;
//		    default: break;				  
//		}
//	} while(opcion < 6);
//  	
//	return 0;
//}

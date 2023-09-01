#include <iostream>

#include <windows.h>

#include "circular_doubly_linked_list.h"
#include "project.h"
#include "util.h"

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

template <typename T>
bool read_number(T& buffer);

void get_non_empty_string(std::string& buffer, std::string&& inputMessage, std::string&& errorMessage);

int main()
{
    circular_doubly_linked_list projects;
    short option = -1;

    SetConsoleOutputCP(CP_UTF8);

    do
    {
        system("cls");
        std::cout <<    "Sistema de administración de proyectos de obra pública\n"
                        "1. Agregar nuevo proyecto.\n"
                        "2. Eliminar proyecto.\n"
                        "4. Modificar proyecto.\n"
                        "3. Mostrar información de proyecto.\n"
                        "5. Listar proyectos.\n"
                        "6. Eliminar todos los proyectos.\n"
                        "7. Salir.\n"
                        "\nElija una opción: ";

        
        if (!read_number<short>(option))
        {
            std::cout << "Debe ingresar un número entero.";
            std::cin.get();
            continue;
        }
        
        system("cls");
        switch (option)
        {
            case 1:
            {
                PROJECT newProject
                {
                    // .cost       = ,
                    // .endDate    = ,
                    // .name       = std::move(projectName),
                    // .number     = ,
                    // .startDate  = ,
                };
                
                std::cout   <<  "Información del nuevo proyecto\n";
                get_non_empty_string(
                    newProject.name,
                    "Nombre del proyecto: ",
                    "Debe ingresar un nombre de proyecto. Intentelo de nuevo.\n");
                
                do
                {
                    std::cout << "Número del proyecto: ";
                    
                    if (read_number<int>(newProject.number)) {
                        break;
                    }

                    std::cout << "Debe ingresar un número entero. Intentelo de nuevo.\n";
                } while (true);

                do
                {
                    std::cout << "Costo del proyecto: ";
                    
                    if (read_number<double>(newProject.cost)) {
                        break;
                    }

                    std::cin.clear();
                    std::cout << "Debe ingresar un número (puede contener decimales). Intentelo de nuevo.\n";
                } while (true);

                // WIP

                break;
            }
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                std::cout << "Debe ingresar una opción del menú.";
                std::cin.get();
                break;
        }
    }
    while (option != 7);
}

template<typename T>
bool read_number(T& buffer)
{
    bool invalidInput;
    if ((invalidInput = !(std::cin >> buffer)))
    {
        std::cin.clear();
    }

    if ((invalidInput = std::cin.peek() != '\n'))
    {
        std::cin.ignore(1000, '\n');
    }

    return !invalidInput;
}

void get_non_empty_string(std::string& buffer, std::string&& inputMessage, std::string&& errorMessage)
{
    do
    {
        std::cout << inputMessage;
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, buffer);
        trim(buffer);

        if (!buffer.empty()) {
            break;
        }

        std::cout << errorMessage;
    } while (true);
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

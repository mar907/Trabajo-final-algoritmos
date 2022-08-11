#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

#include "app.hpp"
#include "../commands/commands.hpp"
#include "../structs/invitation.hpp"

/*Documentacion:
En esta seccion del proyecto aplico la funcion runApp() donde basicamente llamo a las funciones
displayMenu() para mostrar el menu con las opciones, tambien la funcion appComand input que es la 
informacion ingresada por el usuario y los comandos para cada utilidad del proyecto y ListExecuteCommand()
donde se elijen esos comandos por switch.  */

void runApp()
{
    AppCommand input;
    List list = loadInformation();

    do
    {

        displayMenu();

        input = getUserInput();

        list = executeCommand(input, list);

    } while (input != CLOSE_APP);
};

void displayMenu()
{

    cout << "Selecione una opcion del menu:";
    cout << endl;
    cout << "1 - Crear una invitacion: ";
    cout << endl;
    cout << "2 - Actualizar la invitacion: ";
    cout << endl;
    cout << "3 - Reservar la invitacion: ";
    cout << endl;
    cout << "4 - Borrar invitacion: ";
    cout << endl;
    cout << "5 - Invitaciones totales: ";
    cout << endl;
    cout << "6 - Invitaciones confirmadas: ";
    cout << endl;
    cout << "7 - Salir y gaurdar";
    cout << endl;
};

AppCommand getUserInput()
{
    int input;

    cin >> input;

    return static_cast<AppCommand>(input);
};

List executeCommand(AppCommand command, List list)
{
    switch (command)
    {
    case CREATE_INVITATION:
        return create_invitation_command(list);
    case UPDATE_INVITATION:
        return update_invitation_command(list);
    case RESERVE_INVITATION:
        return reserve_invitation(list);
    case DELETE_INVITATION:
        return delete_invitation(list);
    case GET_INVITATIONS:
        get_invitations(list);
        return list;
    case GET_ASSISTANTS:
        get_assistants(list);
        return list;
    case CLOSE_APP:
        close_app(list);
        return list;
    default:
        return list;
    }
}

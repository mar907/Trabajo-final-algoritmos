#ifndef APP_HPP
#define APP_HPP

#include "../structs/invitation.hpp"

/* Documentacion:
En esta seccion creo un enum con los diferentes comandos y llamo a las funciones principales */

enum AppCommand
{
    CREATE_INVITATION = 1,
    UPDATE_INVITATION,
    RESERVE_INVITATION,
    DELETE_INVITATION,
    GET_INVITATIONS,
    GET_ASSISTANTS,
    CLOSE_APP
};

void runApp();
void displayMenu();
AppCommand getUserInput();
List executeCommand(AppCommand, List);

#endif /* APP_HPP */

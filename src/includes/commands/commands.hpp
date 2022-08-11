#ifndef COMMANDS_HPP 
#define COMMANDS_HPP

#include "../structs/invitation.hpp"

/* Documentacion:
En esta seccion llamo a las funciones de los comandos */
List update_invitation_command(List);
List delete_invitation(List);
List create_invitation_command(List);
List reserve_invitation(List);
void get_invitations(List);
void get_assistants(List);
void close_app(List);
List loadInformation();

#endif /* COMMANDS_HPP */

#ifndef INVITATION_HPP 
#define INVITATION_HPP

#include <iostream>

/* Documentacion: 
En esta seccion declaro la struct invitation con los datos que necesito del usuario y 
la struct List con el array de invitaciones y un contador. Tambien declaro el maximo de 
indices que necesito para ese array */
struct Invitation
{
    std::string name;
    unsigned int age;
    std::string ticket;
    bool isConfirmed = false;
};

const int MAX_INVITATIONS = 100;

struct List
{
    Invitation invitations[MAX_INVITATIONS];
    int count;
};

#endif /* INVITATION_HPP */



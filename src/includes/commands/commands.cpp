#include <iostream>
#include <fstream>

using namespace std;

#include "commands.hpp"
#include "../structs/invitation.hpp"

/* Documentacion: 
En esta seccion cree todas las funciones de los comandos para las listas */

List create_invitation_command(List list)
{
    Invitation invitation;

    cin.ignore();
    cout << "Escriba el nombre del invitado: " << endl;
    getline(cin, invitation.name);
    cin.clear();

    cout << "Escriba la edad del invitado: " << endl;
    cin >> invitation.age;
    cin.clear();

    cin.ignore();
    cout << "Escriba el numero de ticket del invitado: " << endl;
    getline(cin, invitation.ticket);
    cin.clear();

    list.invitations[list.count] = invitation;
    list.count++;

    return list;
}

List update_invitation_command(List list)
{

    string newName;
    unsigned int newAge;
    string ticketTemporal;
    cout << "Ingrese el numero de ticket que desea cambiar: ";
    cin >> ticketTemporal;

    for (int i = 0; i < list.count; i++)
        if (list.invitations[i].ticket == ticketTemporal)
        {
            cin.ignore();
            cout << "Ingrese el nombre: " << endl;
            getline(cin, newName);
            cin.clear();

            cout << "Ingrese la edad: " << endl;
            cin >> newAge;
            cin.clear();

            list.invitations[i].name = newName;
            list.invitations[i].age = newAge;
        }

    return list;
}

List delete_invitation(List list)
{
    string ticketTemporal;
    cout << "Ingrese el numero de ticket que desea cambiar: ";
    cin >> ticketTemporal;

    int elementIndex = -1;

    for (int i = 0; i < list.count; i++)
    {
        Invitation current = list.invitations[i];

        if (current.ticket == ticketTemporal)
        {
            elementIndex = i;
        }
    }

    if (elementIndex != -1)
    {
        for (int i = 0; i < list.count; i++)
        {
            if (i >= elementIndex)
            {
                list.invitations[i] = list.invitations[i + 1];
            }
        }

        list.count--;
    }

    return list;
}

List reserve_invitation(List list)
{

    string ticketTemporal;
    cout << "Ingrese el numero de ticket que desea reservar: ";
    cin >> ticketTemporal;

    for (int i = 0; i < list.count; i++)
    {
        Invitation &current = list.invitations[i];

        if (current.ticket == ticketTemporal)
        {
            current.isConfirmed = true;
        }
    }

    return list;
}

void get_invitations(List list)
{
    cout << "Lista de invitados: " << endl;
    cout << "----------------" << endl;

    for (int i = 0; i < list.count; i++)
    {
        cout << "Ticket: " << list.invitations[i].ticket << endl;
        cout << "Nombre: " << list.invitations[i].name << endl;
        cout << "Edad: " << list.invitations[i].age << endl;
        cout << "----------------" << endl;
    }
}

void get_assistants(List list)
{

    cout << "Lista de asistentes: " << endl;

    for (int i = 0; i < list.count; i++)
    {
        Invitation current = list.invitations[i];
        if (current.isConfirmed)
        {
            cout << current.name << endl;
        }
    }
}

void close_app(List list)
{
    ofstream file;
    file.open("invitations.txt");

    for (int i = 0; i < list.count; i++)
    {
        Invitation current = list.invitations[i];

        file << current.ticket << " " << current.age << ' '
             << current.isConfirmed << ' ' << current.name << endl;
    }

    file.close();
}

List loadInformation()
{

    List list;
    ifstream file;
    string currentLine;
    char aux;

    file.open("invitations.txt");

    while (file.is_open() && file.peek() != EOF)
    {
        Invitation current;

        file >> current.ticket >> current.age >> current.isConfirmed;
        file.get(aux);
        getline(file, current.name);

        list.invitations[list.count] = current;
        list.count++;
    }

    file.close();

    return list;
}
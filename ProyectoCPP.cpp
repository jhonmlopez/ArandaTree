//============================================================================
// Name        : ArandaBinaryTree.cpp
// Author      : Jhon Manuel Lopez
// Version     : 1.0
// Copyright   : N/A
// Description : Find a common ancestor in a Binary Tree in C++, Ansi-style
//============================================================================


#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "sqlite/sqlite3.h"

using namespace std;

// A Binary Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};

// Creación de un árbol binario
Node * newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

// Encuentra la ruta desde la raíz, guarda la ruta en un vector y evalúa si existe o no dicha ruta
bool findPath(Node *root, vector<int> &path, int k)
{

    if (root == NULL) return false;

    // Almacena en el vector, el nodo se elimina si no existe ruta
    path.push_back(root->key);

    // Verifica si la clave dada es igual a la raíz
    if (root->key == k)
        return true;

    // verifica si la clave es a la derecha o a la izquierda
    if ( (root->left && findPath(root->left, path, k)) ||
         (root->right && findPath(root->right, path, k)) )
        return true;

    // se elimina la raíz, en caso de que no existe relación
    path.pop_back();
    return false;
}

// Devuelve un ancestro común entre 2 números
int findLCA(Node *root, int n1, int n2)
{

    vector<int> path1, path2;

    // Valida las rutas a la raíz
    if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
          return -1;

    //Compara las rutas
    int i;
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
}

// Programa principal
int main()
{

/*
	sqlite3* db;
    int res;
    res = sqlite sqlite3_open("db_tree", &db);
    */


	//Declaraciones de variables del árbol
	int dato_raiz;
	int dato_izq, dato_der;

	int dato_izq_izq, dato_izq_der, dato_der_der, dato_der_izq;
	int dato_izq_izq_izq, dato_izq_izq_der, dato_izq_der_izq, dato_izq_der_der;
	int dato_der_izq_izq, dato_der_izq_der, dato_der_der_izq, dato_der_der_der;


	try
	{
	//Imprime mensajes y pide datos de ingreso:
	cout<< "\n Introduzca el valor del nodo raíz "; cin>> dato_raiz;

	cout<< "\n Introduzca el valor del nodo izquierdo "; cin>> dato_izq;
	cout<< "\n Introduzca el valor del nodo derecho "; cin>> dato_der;

	cout<< "\n Introduzca el valor del nodo izquierdo izquierdo "; cin>> dato_izq_izq;
	cout<< "\n Introduzca el valor del nodo izquierdo derecho  "; cin>> dato_izq_der;

	cout<< "\n Introduzca el valor del nodo derecho izquierdo  "; cin>> dato_der_izq;
	cout<< "\n Introduzca el valor del nodo derecho derecho "; cin>> dato_der_der;

	cout<< "\n Introduzca el valor del nodo izq izq izq "; cin>> dato_izq_izq_izq;
	cout<< "\n Introduzca el valor del nodo izq izq der "; cin>> dato_izq_izq_der;
	cout<< "\n Introduzca el valor del nodo izq der izq "; cin>> dato_izq_der_izq;
	cout<< "\n Introduzca el valor del nodo izq der der "; cin>> dato_izq_der_der;

	cout<< "\n Introduzca el valor del nodo der izq izq "; cin>> dato_der_izq_izq;
	cout<< "\n Introduzca el valor del nodo der izq der "; cin>> dato_der_izq_der;
	cout<< "\n Introduzca el valor del nodo der der izq "; cin>> dato_der_der_izq;
	cout<< "\n Introduzca el valor del nodo der der der "; cin>> dato_der_der_der;

		//"Dibuja" en árbol con los parámetros:
	cout<< "\n";
	cout<< "\n El árbol digitado es: ";
	cout<< "\n";
	cout<< "\n" << "                 " << dato_raiz;
	cout<< "\n";
	cout<< "\n" << "        "  << dato_izq << "                   "<< dato_der  ;
	cout<< "\n";
	cout<< "\n"<< "    "  << dato_izq_izq << "      " << dato_izq_der << "            " << dato_der_izq << "        " <<  dato_der_der ;
	cout<< "\n";
	cout<< "\n"<< " "  << dato_izq_izq_izq << "  " << dato_izq_izq_der <<"   " << dato_izq_der_izq << "    " <<  dato_izq_der_der << "        "  << dato_der_izq_izq << "  " << dato_der_izq_der <<"    " << dato_der_der_izq << "    " <<  dato_der_der_der ;


	//Cadena para almacenar en SQLite

	cout<< "\n";cout<< "\n";
	cout<< "\n Dato para registro en DB: " ;
	cout<< "\n";cout<< "\n";





	// Creación del árbol alimentado por las variables
	    Node * root = newNode(dato_raiz);

	    root->left = newNode(dato_izq);
	    root->right = newNode(dato_der);

	    root->left->left = newNode(dato_izq_izq);
	    root->left->right = newNode(dato_izq_der);

	    root->right->left = newNode(dato_der_izq);
	    root->right->right = newNode(dato_der_der);

	    root->left->left->left = newNode(dato_izq_izq_izq);
	    root->left->left->right = newNode(dato_izq_izq_der);
	    root->left->right->left = newNode(dato_izq_der_izq);
	    root->left->right->right = newNode(dato_izq_der_der);

	    root->right->left->left = newNode(dato_der_izq_izq);
	    root->right->left->right = newNode(dato_der_izq_der);
	    root->right->right->left = newNode(dato_der_der_izq);
	    root->right->right->right = newNode(dato_der_der_der);


	    //Entrega el resultado de la funcion de hallar el ancestro común:
	    cout<< "\n";
	    cout<< "\n";
	    cout << " \n Ancestro común entre " << dato_izq_izq << " y " << dato_izq_der << " es: "  << findLCA(root, dato_izq_izq, dato_izq_der);
	    cout << " \n Ancestro común entre " << dato_izq_izq << " y " << dato_der_izq << " es: "  << findLCA(root, dato_izq_izq, dato_der_izq);
	    cout << " \n Ancestro común entre " << dato_der << " y " << dato_izq_izq << " es: "  << findLCA(root, dato_der, dato_izq_izq);
        cout << " \n Ancestro común entre " << dato_izq << " y " << dato_izq_izq << " es: "  << findLCA(root, dato_izq, dato_izq_izq);

        cout << " \n Ancestro común entre " << dato_izq_izq_der << " y " << dato_izq_der << " es: "  << findLCA(root, dato_izq_izq_der, dato_izq_der);
        cout << " \n Ancestro común entre " << dato_izq_izq_der << " y " << dato_der_izq << " es: "  << findLCA(root, dato_izq_izq_der, dato_der_izq);

        cout << " \n Ancestro común entre " << dato_der_izq << " y " << dato_der_der_der << " es: "  << findLCA(root, dato_der_izq, dato_der_der_der);
        cout << " \n Ancestro común entre " << dato_izq_izq_der << " y " << dato_der_der_izq << " es: "  << findLCA(root, dato_izq_izq_der, dato_der_der_izq);

	}

	catch (int e)
	{
		cout << "Validate error Data in program" << endl;
		cout << e << endl;

	}

    return 0;
}

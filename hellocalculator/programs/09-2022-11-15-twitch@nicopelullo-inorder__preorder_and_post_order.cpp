#include "framework.h"
#include <stdio.h>

#include <iostream>


namespace nicopelullo2
{
using namespace std;

struct tree_node {				//

	int m_iData; 				//					ESTRUCTURA DEL	
	tree_node* m_ptreenodeRight, * m_ptreenodeLeft;			//						NODO
};							// 


struct stack {

	tree_node* m_ptreenodeStack;
	stack* m_pstackNext;

};


stack* inicio = NULL;
stack* g_pstackTime = NULL;
tree_node* create_tree_node(int);
tree_node* g_ptreenodeRoot = NULL;			// Creacion del g_ptreenodeRoot
tree_node* g_ptreenodeCurrent = NULL;
tree_node* pre = NULL;

void tree_node_input(tree_node*&, int);
void pre_order(tree_node*&);
bool busquedaIterativa(int);
int altura(tree_node*);

//Funcion para crear un nuevo nodo
tree_node* create_tree_node(int n) {

	tree_node* nuevo_nodo = ___new tree_node();		//Reserva de memoria

	nuevo_nodo->m_iData = n;
	nuevo_nodo->m_ptreenodeRight = NULL;				//Le asignamos NULL debido a que es un nuevo nodo y por el momento no tiene hijos
	nuevo_nodo->m_ptreenodeLeft = NULL;				//Le asignamos NULL debido a que es un nuevo nodo y por el momento no tiene hijos

	return nuevo_nodo;
}

stack* push(stack* pstack, tree_node* ptreenodNext) {  //le pasamos el inicio de la stack y el nodo que querramos guardar como parametros
	stack* nueva = ___new stack();
	nueva->m_ptreenodeStack = ptreenodNext;  //le asignamos en el nodo que vamos a procesar (fijense que esta pasado por parametro)
	nueva->m_pstackNext = pstack; //en el campo siguiente; le guardamos lo que anteriormente era el inicio de la stack (el nodo anterior)
	pstack = nueva;  //y ahora, el inicio de la stack es esta nueva "stack" que pusimos.

	return pstack; //nos devuelve el nuevo inicio.
}


// -desapila- nodos de la stack de datos.
stack* pop(stack* pstack, tree_node*& ptreenodeCurrent) {
	stack* pstackTime = pstack;  //crea un tipo auxiliar para borrarlo
	ptreenodeCurrent = pstackTime->m_ptreenodeStack; // g_ptreenodeCurrent = NULL? (este paso es una duda, creo que no hace falta y por eso puse g_ptreenodeCurrent = NULL. evaluenlo uds)
	pstack = pstackTime->m_pstackNext;  //pasa el inicio de la lista al nodo que sigue por visitar.
	delete pstackTime;

	return pstack;
}

//Funcion insertar nodos iterativa
void tree_node_input(tree_node*& g_ptreenodeRoot, int n) {
	tree_node* x = g_ptreenodeRoot;
	tree_node* y = NULL;

	if (g_ptreenodeRoot == NULL) {
		g_ptreenodeRoot = create_tree_node(n);
		return;
	}

	while (x != NULL) {
		y = x;

		if (n < x->m_iData) {
			x = x->m_ptreenodeLeft;
		}
		else if (n > x->m_iData) {
			x = x->m_ptreenodeRight;
		}
		else {
			::std::cout << "Valor duplicado" << ::std::endl;
			break;
		}
	}

	if (n < y->m_iData) {
		y->m_ptreenodeLeft = create_tree_node(n);
	}
	else if (n > y->m_iData) {
		y->m_ptreenodeRight = create_tree_node(n);
	}
}



void pre_order(tree_node*& g_ptreenodeRoot) {

	if (g_ptreenodeRoot == NULL) {
		return;
	}

	//crea el inicio de la stack de datos.
	stack* pstack = ___new stack();
	pstack->m_ptreenodeStack = g_ptreenodeRoot;  //en el campo "nodo" del pstack siempre guardamos el nodo en el que estamos parados.
	pstack->m_pstackNext = NULL; //en el campo "sgte" se marca cual es el m_iData siguiente a procesar.

	//ACTUAL indica el nodo en el que estamos parados en la stack.
	tree_node* ptreenodeCurrent = NULL;


	//mientras la lista no este vacia: va mostrando o acumulando datos.
	while (pstack != NULL) {

		//ubica a ACTUAL en donde nos estamos parando actualmente.
		ptreenodeCurrent = pstack->m_ptreenodeStack;

		//muestra el m_iData del nodo en el que estamos parados.
		::std::cout << ptreenodeCurrent->m_iData << " - ";

		//una vez que mostro el m_iData; elimina ese nodo de la stack para poder guardar los siguientes nodos
		pstack = pop(pstack, ptreenodeCurrent);  //libera el pstack de la stack.


		//si hay datos a la derecha de donde estamos actualmente: guarda ese nodo en la stack para visitarlo depsues
		if (ptreenodeCurrent->m_ptreenodeRight != NULL) {
			pstack = push(pstack, ptreenodeCurrent->m_ptreenodeRight);
		}

		//si hay datos a la izquierda: guarda el nodo en la stack y es el primero en salir al volver a evaluar el bucle
		if (ptreenodeCurrent->m_ptreenodeLeft != NULL) {
			pstack = push(pstack, ptreenodeCurrent->m_ptreenodeLeft);
		}
	}

	//recuerden que el Pre-Orden es de tipo RAIZ -> IZQUIERDA -> DERECHA.
}


void post_order(tree_node * ptreenodeRoot) 
{

	if (ptreenodeRoot == nullptr)
	{

		return;

	}

	stack* pstack = nullptr;

	pstack = push(pstack, ptreenodeRoot);

	tree_node* ptreenode = nullptr;

	stack* pstackOut = nullptr;

	while (pstack) 
	{

		pstack = pop(pstack, ptreenode);

		pstackOut = push(pstackOut, ptreenode);

		if (ptreenode->m_ptreenodeLeft != NULL) 
		{
			
			pstack = push(pstack, ptreenode->m_ptreenodeLeft);

		}

		if (ptreenode->m_ptreenodeRight != NULL)
		{
		
			pstack = push(pstack, ptreenode->m_ptreenodeRight);

		}

	}

	while (pstackOut)
	{

		pstackOut = pop(pstackOut, ptreenode);

		::std::cout << ptreenode->m_iData << " - ";

	}

}


void in_order_recursive(tree_node*& ptreenodeRoot)
{

	if (!ptreenodeRoot)
	{

		return;

	}

	in_order_recursive(ptreenodeRoot->m_ptreenodeLeft);

	::std::cout << ptreenodeRoot->m_iData << " - ";

	in_order_recursive(ptreenodeRoot->m_ptreenodeRight);

}


void in_order(tree_node*& ptreenodeRoot) 
{

	if (ptreenodeRoot == NULL)
	{

		return;

	}

	stack * pstack = nullptr;

	tree_node * ptreenode = ptreenodeRoot;

	while (pstack || ptreenode != nullptr)
	{

		if (ptreenode != nullptr)
		{
			
			pstack = push(pstack, ptreenode);
			
			ptreenode = ptreenode->m_ptreenodeLeft;

		}
		else
		{

			pstack = pop(pstack, ptreenode);
			
			::std::cout << ptreenode->m_iData << " - ";

			ptreenode = ptreenode->m_ptreenodeRight;

		}

	}

}


//Funcion de busqueda iterativa
bool busquedaIterativa(int n) {
	if (g_ptreenodeRoot == NULL) {
		return g_ptreenodeRoot;
	}
	else {
		tree_node* arboltemporal = g_ptreenodeRoot;
		while (arboltemporal != NULL) {
			if (n == arboltemporal->m_iData) {
				return arboltemporal;
			}
			else if (n < arboltemporal->m_iData) {
				arboltemporal = arboltemporal->m_ptreenodeLeft;
			}
			else {
				arboltemporal = arboltemporal->m_ptreenodeRight;
			}
		}
		return NULL;
	}
}

} // namespace nicopelullo2


int twitch::nicopelullo_inorder__preorder_and_post_order_main()
{

	int iData, opcion2, opcion, contador = 0;

	int iTest = 1;
	if (iTest == 1)
	{
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 10);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 19);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 6);
		::nicopelullo2::post_order(::nicopelullo2::g_ptreenodeRoot);

	}
	else if (iTest == 2)
	{
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 10);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 19);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 6);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 8);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 17);
		::nicopelullo2::in_order(::nicopelullo2::g_ptreenodeRoot);

	}
	else if (iTest == 3)
	{
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 10);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 19);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 6);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 8);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 17);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 3);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 25);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 1);
		::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, 26);
		::nicopelullo2::in_order(::nicopelullo2::g_ptreenodeRoot);

	}

	do {
		::std::cout << "MENU" << ::std::endl;
		::std::cout << "1. Insertar un nuevo nodo" << ::std::endl;
		::std::cout << "2. Seleccionar orden para mostrar el g_ptreenodeRoot" << ::std::endl;
		::std::cout << "3. Buscar un nodo " << ::std::endl;
		::std::cout << "4. Salir" << ::std::endl;
		::std::cout << "Opcion: ";
		::std::cin >> opcion;

		switch (opcion) {
		case 1: ::std::cout << "Digite un numero: ";
			::std::cin >> iData;
			::nicopelullo2::tree_node_input(::nicopelullo2::g_ptreenodeRoot, iData);

			system("pause");
			break;

		case 2: system("cls");
			::std::cout << "MENU" << ::std::endl;
			::std::cout << "1. Preorden" << ::std::endl;
			::std::cout << "2. Postorden" << ::std::endl;
			::std::cout << "3. Inorden" << ::std::endl;
			::std::cout << "4. Salir" << ::std::endl;
			::std::cout << "Opcion: ";
			::std::cin >> opcion2;

			switch (opcion2) {
			case 1: ::std::cout << "Mostrando el g_ptreenodeRoot en Preorden" << ::std::endl;
				::nicopelullo2::pre_order(::nicopelullo2::g_ptreenodeRoot);

				system("pause");
				break;

			case 2: ::std::cout << "Mostrando el g_ptreenodeRoot en Postorden" << ::std::endl;
				::nicopelullo2::post_order(::nicopelullo2::g_ptreenodeRoot);

				system("pause");
				break;

			case 3: ::std::cout << "Mostrando el g_ptreenodeRoot en Inorden" << ::std::endl;
				::nicopelullo2::in_order(::nicopelullo2::g_ptreenodeRoot);

				system("pause");
				break;

			}

			system("pause");
			break;

		case 3: ::std::cout << "Ingrese el elemento que desee buscar: ";
			::std::cin >> iData;
			if (::nicopelullo2::busquedaIterativa(iData) == true) {
				::std::cout << "\nSu elemento ha sido encontrado" << ::std::endl;
			}
			else {
				::std::cout << "Su elemento no ha sido encontrado" << ::std::endl;
			}

			system("pause");
			break;

		}system("cls");
	} while (opcion != 4);



	return 0;
}
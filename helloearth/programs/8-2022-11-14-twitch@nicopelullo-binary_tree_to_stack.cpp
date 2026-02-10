#include "framework.h"
#include <stdio.h>

#include <iostream>


namespace nicopelullo
{

	struct tree_node
	{						

		int					m_iData; 		
		tree_node*			m_ptreenodeLeft;
		tree_node*			m_ptreenodeRight;

	};


	struct stack
	{
		
		tree_node*			m_ptreenode;
		stack *				m_pstackNext;

	};


	/*stack *pstack=NULL;
	stack *final=NULL;*/
	tree_node* create_node(int);
	tree_node* g_ptreenodeRoot = NULL;			// Creacion del g_ptreenodeRoot
	tree_node* ptreenodeCurrent = NULL;
	tree_node* pre = NULL;

	void insert_tree_node(tree_node*&, int);
	void preorder(tree_node*&);
	bool busquedaIterativa(int);
	int altura(tree_node*);

	//Funcion para crear un nuevo nodo
	tree_node* create_node(int n) 
	{

		tree_node* nuevo_nodo = ___new tree_node();		//Reserva de memoria

		nuevo_nodo->m_iData = n;
		nuevo_nodo->m_ptreenodeRight = NULL;				//Le asignamos NULL debido a que es un nuevo nodo y por el momento no tiene hijos
		nuevo_nodo->m_ptreenodeLeft = NULL;				//Le asignamos NULL debido a que es un nuevo nodo y por el momento no tiene hijos

		return nuevo_nodo;

	}

	//le pasamos el pstack de la stack y el nodo que querramos guardar como parametros
	stack* push(stack* pstack, tree_node* ptreenode)
	{ 

		stack* pstackNew = ___new stack();

		pstackNew->m_ptreenode = ptreenode;  //le asignamos en el nodo que vamos a procesar (fijense que esta pasado por parametro)
		pstackNew->m_pstackNext = pstack; //en el campo siguiente; le guardamos lo que anteriormente era el pstack de la stack (el nodo anterior)

		pstack = pstackNew;  //y ahora, el pstack de la stack es esta nueva "stack" que pusimos.

		return pstack; //nos devuelve el nuevo pstack.
	}


	// -desapila- nodos de la stack de datos.
	stack* pop(stack* pstack, tree_node*& ptreenodeCurrent) {
		stack* pstackTime = pstack;  //crea un tipo auxiliar para borrarlo
		ptreenodeCurrent = pstackTime->m_ptreenode; // ptreenodeCurrent = NULL? (este paso es una duda, creo que no hace falta y por eso puse ptreenodeCurrent = NULL. evaluenlo uds)
		pstack = pstackTime->m_pstackNext;  //pasa el pstack de la lista al nodo que sigue por visitar.
		delete pstackTime;

		return pstack;
	}

	//Funcion insertar nodos iterativa
	void insert_tree_node(tree_node*& ptreenode, int n) {
		tree_node* x = ptreenode;
		tree_node* y = NULL;

		if (ptreenode == NULL) {
			ptreenode = create_node(n);
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
			y->m_ptreenodeLeft = create_node(n);
		}
		else if (n > y->m_iData) {
			y->m_ptreenodeRight = create_node(n);
		}
	}



	void preorder(tree_node*& ptreenode) {

		if (ptreenode == NULL) {
			return;
		}

		//crea el pstack de la stack de datos.
		stack* pstack = ___new stack();
		pstack->m_ptreenode = ptreenode;  //en el campo "nodo" del pstack siempre guardamos el nodo en el que estamos parados.
		pstack->m_pstackNext = NULL; //en el campo "sgte" se marca cual es el m_iData siguiente a procesar.

		//ACTUAL indica el nodo en el que estamos parados en la stack.
		tree_node* ptreenodeCurrent = NULL;



		//mientras la lista no este vacia: va mostrando o acumulando datos.
		while (pstack != NULL) {

			//ubica a ACTUAL en donde nos estamos parando actualmente.
			ptreenodeCurrent = pstack->m_ptreenode;

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

	//Funcion de busqueda iterativa
	bool busquedaIterativa(int n, tree_node * ptreenode) {
		if (ptreenode == NULL) {
			return ptreenode;
		}
		else {
			tree_node* arboltemporal = ptreenode;
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
			return nullptr;
		}
	}


} // namespace nicopelullo


int twitch::nicopelullo_binary_tree_to_stack_main()
{

	int m_iData, opcion = 0;

	do {
		::std::cout << "MENU" << ::std::endl;
		::std::cout << "1. Insertar un nuevo nodo" << ::std::endl;
		::std::cout << "2. Seleccionar orden para mostrar el arbol" << ::std::endl;
		::std::cout << "3. Buscar un nodo " << ::std::endl;
		::std::cout << "4. Salir" << ::std::endl;
		::std::cout << "Opcion: ";
		::std::cin >> opcion;

		switch (opcion) {
		case 1: ::std::cout << "Digite un numero: ";
			::std::cin >> m_iData;
			insert_tree_node(::nicopelullo::g_ptreenodeRoot, m_iData);


			//system("pause");
			break;

		case 2: 
			
			nicopelullo::insert_tree_node(::nicopelullo::g_ptreenodeRoot, 10);
			nicopelullo::insert_tree_node(::nicopelullo::g_ptreenodeRoot, 12);
			nicopelullo::insert_tree_node(::nicopelullo::g_ptreenodeRoot, 8);

			nicopelullo::preorder(::nicopelullo::g_ptreenodeRoot);
			//system("pause");
			break;

			//			case 2: system("cls");
			//					cout<<"MENU"<<endl;
			//					cout<<"1. Preorden"<<endl;
			//					cout<<"2. Postorden"<<endl;
			//					cout<<"3. Inorden"<<endl;
			//					cout<<"4. Salir"<<endl;
			//					cout<<"Opcion: ";
			//					cin>>opcion2;
			//					
			//					switch(opcion2){
			//						case 1: cout<<"Mostrando el arbol en Preorden"<<endl;
			//						preorder(arbol);
			//						
			//						system("pause");
			//						break;
			//						
			//					}
			//					
			//					system("pause");
			//					break;
			//					
			//			case 3: cout<<"Ingrese el elemento que desee buscar: ";
			//					cin>>m_iData;
			//					if(busquedaIterativa(m_iData)==true){
			//						cout<<"\nSu elemento ha sido encontrado"<<endl;
			//					}else{
			//						cout<<"Su elemento no ha sido encontrado"<<endl;
			//					}
			//					
			//					system("pause");
			//					break;

		}
      //system("cls");
	} while (opcion != 4);



	return 0;
}



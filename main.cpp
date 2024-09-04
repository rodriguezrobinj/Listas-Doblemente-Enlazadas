#include <iostream>
using namespace std;

struct Nodo{
    int num;
    Nodo *sig, *ant;
};

Nodo *prepararNodo(int dato) {
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->num = dato;
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;
    return nuevoNodo;
}

void ingresarNodo(Nodo *&cab, Nodo *nuevoNodo) {
    if (cab == NULL) {
        cab = nuevoNodo;
    } else {
        nuevoNodo->sig = cab;
        cab->ant = nuevoNodo;
        cab = nuevoNodo;
    }
}

void ingresarNodoOrdenado(Nodo *&cab, Nodo *nuevoNodo) {
    if (cab == NULL) {
        cab = nuevoNodo;
    } else {
        if (nuevoNodo->num < cab->num) {
            nuevoNodo->sig = cab;
            cab->ant = nuevoNodo;
            cab = nuevoNodo;
        } else {
            Nodo *p = cab;
            bool sw = false;
            while (p != NULL && !sw) {
                if (nuevoNodo->num == p->num) {
                    sw = true;
                } else if (nuevoNodo->num != p->num) {
                    if (nuevoNodo->num > p->num) {
                        if (p->sig == NULL) {
                            p->sig = nuevoNodo;
                            nuevoNodo->ant = p;
                        }
                    } else if (nuevoNodo->num < p->num) {
                        nuevoNodo->sig = p;
                        nuevoNodo->ant = p->ant;
                        (p->ant)->sig = nuevoNodo;
                        p->ant = nuevoNodo;
                        sw = true;
                    }
                    p = p->sig;
                }
            }
        }
    }
}

void ingresarNodoOrdenado(Nodo *&cab, Nodo *&fin, Nodo *nuevoNodo) {
    if (cab == NULL) {
        // Ingresa un nodo cuando la lista se encuentre vacia.
        // Es decir, el nuevo nodo es tanto la cabecera como el fin de la lista.
        cab = nuevoNodo;
        fin = nuevoNodo;
    } else {
        if (nuevoNodo->num < cab->num) {
            // Ingresa un nodo cuando el nuevo nodo a ingresar es menor al de cabecera.
            // Es decir, se convierte en la nueva cabecera.
            nuevoNodo->sig = cab;
            cab->ant = nuevoNodo;
            cab = nuevoNodo;
        } else {
            if (nuevoNodo->num > fin->num) {
                // Ingresa un nodo cuando el nuevo nodo a ingresar es mayor al de fin.
                // Es decir, se convierte en el nuevo fin.
                fin->sig = nuevoNodo;
                nuevoNodo->ant = fin;
                fin = nuevoNodo;
            } else {
                // Ingresa un nodo cuando el nuevo nodo a ingresar es mayor a la cabecera y menor al fin.
                // Es decir, se ingresa en un punto intermedio de la lista que no sea ni en cabecera ni en fin.
                Nodo *temp = cab;
                while ((temp->num < nuevoNodo->num) && (temp != NULL)) {
                    temp = temp->sig;
                }
                nuevoNodo->sig = temp;
                nuevoNodo->ant = temp->ant;
                temp->ant->sig = nuevoNodo;
                temp->ant = nuevoNodo;
            }
        }
    }
}

void imprimirLista(Nodo *cab) {
    if (cab == NULL) {
        cout << "La lista se encuentra vacia, por favor ingrese datos a la lista." << endl;
    } else {
        Nodo *p = cab;
        cout << "NULL <-> ";
        while (p != NULL) {
            cout << p->num << " <-> ";
            p = p->sig;
        }
        cout << "NULL" << endl;
    }
}

bool verificarFibonacci(Nodo *cab) {
    bool sw = true;
    if (cab == NULL) {
        cout << "La lista se encuentra vacia, por favor ingresar minimo 3 nodos." << endl;
    } else {
        if (cab->sig == NULL) {
            cout << "No hay nodos suficientes, por favor ingrese 2 nodos mas." << endl;
        } else {
            if ((cab->sig)->sig == NULL) {
                cout << "No hay nodos suficientes, por favor ingrese 1 nodo mas." << endl;
            } else {

            }
        }
    }
    return sw;
}

int main() {
    Nodo *cab = NULL, *fin = NULL;
    int opcion = 1, dato;
    do {
        system("cls");
        cout << "MENU - LISTA DOBLEMENTE ENLAZADA" << endl;
        cout << "1. Ingresar nuevo nodo a la lista." << endl;
        cout << "2. Imprimir la lista." << endl;
        cout << "3. Verificar si la lista cumple la sucesion de Fibonacci." << endl;
        cout << "4. Salir." << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Digite una opcion: ";
        cin >> opcion;
        cout << "---------------------------------------------------" << endl;
        switch (opcion) {
            case 1:
                cout << "Ingrese el numero a ingresar a la lista: ";
                cin >> dato;
                cout << "---------------------------------------------------" << endl;
                ingresarNodoOrdenado(cab, fin, prepararNodo(dato));
                break;
            case 2:
                imprimirLista(cab);
                cout << "---------------------------------------------------" << endl;
                system("pause");
                break;
            case 3:
                bool sw;
                cout << "---------------------------------------------------" << endl;
                system("pause");
                break;
        }
    } while (opcion != 4);
}
//
void imprimir_lista(Nodo *cab, Nodo *ult) {
	Nodo *q = cab;
    cout << "se imprime la lista de izquierda a derecha";
	while( q != NULL) {
		printf("  %d  <--> ", q->num);
		q = q->sig;
	};
	printf("NULL  \n");
	cout << "***************************";
    cout << "se imprime la lista de derecha a izquierda";
	q = ult;
	while( q != NULL) {
		printf("  %d  <--> ", q->num);
		q = q->ant;
	};
	printf("NULL  \n");
}
//


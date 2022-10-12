//Mariano Perez Piña - 1271949
//Pilas y arreglos simples

#include<stdio.h>
#include<stdlib.h>

struct Pila{
    int top;
    int capacidad;
    int* arreglo;
};

struct Pila* crear(int capacidad){
    struct Pila* pila = (struct Pila*)malloc(sizeof(struct Pila));
    pila->capacidad = capacidad;
    pila->top = -1;
    pila -> arreglo = (int*)malloc(pila->capacidad*sizeof(int));
    return pila;
}

void push(struct Pila* pila, int elemento);
int pop(struct Pila* pila);
int numelementos(struct Pila* pila);
int tope(struct Pila* pila);
void imprimir(struct Pila* pila);
int llena(struct Pila* pila);
int vacia(struct Pila* pila);



int main(){
    int num, tam, op;

    printf("\nBienvenido\nIngrese el tamaño deseado de la pila: ");
    scanf("%d",&tam);
    struct Pila* pila = crear(tam); //se crea con el tamaño deseado
    
    while(tam>0&&(op!=6)){
        printf("\n\n[1]Añadir a la pila\n[2]Eliminar de la pila\n[3]Tamaño actual de la pila\n[4]Ver tope de la pila\n[5]Imprimir pila\n[6]Salir\nSeleccione una opcion --> ");
        scanf("%d",&op);
        switch(op){
            case 1:
                if(llena(pila))
                    printf("\nLa pila esta llena");
                else{
                    printf("\nIngresa el numero que se quiere ingresar a la pila");
                    scanf("%d",&num);
                    push(pila, num);
                }
                break;

            case 2:
                pop(pila);
                break;

            case 3:
                printf("\nLa pila tiene %d elementos\n", numelementos(pila));
                break;

            case 4:
                printf("\nEl tope actual de la pila es %d ", tope(pila));
                break;

            case 5:
                vacia(pila);

                if(pila->top == -1)
                    printf("\nLa pila esta vacia");
                else
                imprimir(pila);
                break;
                
            default:
                printf("\nOpcion ingresada incorrecta, intente de nuevo");
        }
    }
    printf("\nSaliendo...");

}

void push(struct Pila* pila, int elemento){
    if(llena(pila))
        return;
    pila->arreglo[++pila->top]=elemento;
}

int pop(struct Pila* pila){
    if(vacia(pila))
        return 0;
    return pila->arreglo[pila->top--];
}

int numelementos(struct Pila* pila){
    return pila->top+1;
}

int tope(struct Pila* pila){
	int top = pop(pila);
	push(pila,top);
	return top;
}

void imprimir(struct Pila* pila){
    for(int i=0; i<=pila->top; i++)
        printf("%i\n", pila->arreglo[i]);
}

int llena(struct Pila* pila){
    return pila->top == pila->capacidad-1;
}

int vacia(struct Pila* pila){
    return pila->top == -1;
}

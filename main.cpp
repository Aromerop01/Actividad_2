#include <iostream>

int busqdyv(int arreglo[], int izquierda, int derecha, int valor) {
   if (izquierda <= derecha) {
       int medio = izquierda + (derecha - izquierda) / 2;

       if (arreglo[medio] == valor) {
           return medio;  // Se encontró el número en la posición 'medio'
       } else if (arreglo[medio] < valor) {
           return busqdyv(arreglo, medio + 1, derecha, valor);
       } else {
           return busqdyv(arreglo, izquierda, medio - 1, valor);
       }
   }

   return -1;  // El número no se encontró en el arreglo
}

int main() {
   int arreglo[] = {1, 4, 8, 10, 15, 20, 23, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85};
   int tam = sizeof(arreglo) / sizeof(arreglo[0]);

   int valor;
   std::cout << "Ingrese el número a buscar: ";
   std::cin >> valor;

   int resultado = busqdyv(arreglo, 0, tam - 1, valor);

   if (resultado != -1) {
       std::cout << "El número " << valor << " fue encontrado en la posición " << resultado << "." << std::endl;
   } else {
       std::cout << "El número " << valor << " no fue encontrado en el arreglo." << std::endl;
   }

   return 0;
}
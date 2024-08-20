#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Declaración de funciones.
void mostrarMenu();
void ejecutarOpcion(int opcion);
void decodificarHammingParidadPar(const vector<int>& codigoHamming);
void decodificarHammingParidadImpar(const vector<int>& codigoHamming);
int calcularParidadPar(const vector<int>& bits, int p);
int calcularParidadImpar(const vector<int>& bits, int p);
int contarBitsDeParidad(int n);

int main() 
    {
        int opcion;
        do 
            {
                cout << "*********************" << endl;
                cout << "DECODIFICADOR HAMMING" << endl;
                cout << "*********************" << endl;
                cout << endl;
                cout << "NOTA: Usar con Precaucion y NO HAGAS TRAMPA!!!" << endl;
                cout << "      Hace los ejercicios, NO Seas Vago/a..." << endl;
                cout << endl;
                mostrarMenu();
                cout << "Selecciona una opcion: ";
                cin >> opcion;

                ejecutarOpcion(opcion);

            } while (opcion != 0);

        return 0;
    }

// Definición de funciones

    // Función para mostrar el menú
    void mostrarMenu() 
    {
        cout << "Elegi una opcion:" << endl;
        cout << "----------------" << endl;
        cout << "1. Decodificar Codigo Hamming (Paridad Par)" << endl;
        cout << "2. Decodificar Codigo Hamming (Paridad Impar)" << endl;
        cout << "0. Salir" << endl;
    }

    // Función para ejecutar la opción seleccionada.
    void ejecutarOpcion(int opcion) 
        {
            switch (opcion) 
                {
                    case 1: 
                        {
                            string entrada;

                            cout << endl;
                            cout << "Ingresa el Codigo Hamming (maximo 64 bits): ";
                            cin >> entrada;

                            // Convertir la entrada en un vector de bits.
                            vector<int> codigoHamming;
                            for (char c : entrada) 
                                {
                                    codigoHamming.push_back(c - '0');
                                }

                            // Decodificar el código Hamming con paridad par
                            decodificarHammingParidadPar(codigoHamming);

                            break;
                        }
                    case 2: 
                        {
                            string entrada;

                            cout << endl;
                            cout << "Ingresa el Codigo Hamming (maximo 64 bits): ";
                            cin >> entrada;

                            // Convertir la entrada en un vector de bits
                            vector<int> codigoHamming;
                            for (char c : entrada) 
                                {
                                    codigoHamming.push_back(c - '0');
                                }

                            // Decodificar el código Hamming con paridad impar
                            decodificarHammingParidadImpar(codigoHamming);

                            break;
                        }

                    case 0:
                        {
                            cout << endl;
                            cout << "Hasta la Vista Baby..." << endl;

                            break;
                        }
                        
                    default:
                        {   
                            cout << endl;
                            cout << "Opcion no valida, ponete los lentes y trata de nuevo...";

                            break;
                        }         
                }
        }

    // Función para decodificar el dato con Código Hamming y paridad par.
    void decodificarHammingParidadPar(const vector<int>& codigoHamming) 
        {
            int n = codigoHamming.size();
            int numParityBits = log2(n) + 1;
            int errorPosition = 0;

            // Calcular la posición del bit erróneo.
            for (int i = 0; i < numParityBits; ++i) 
                {
                    int parityBitPosition = pow(2, i);
                    int parity = calcularParidadPar(codigoHamming, parityBitPosition);

                    if (parity != 0) 
                        {
                            errorPosition += parityBitPosition;
                        }
                }

            // Mostrar la posición del bit erróneo.
            if (errorPosition != 0) 
                {
                    cout << "Bit Erroneo en la posicion: " << errorPosition << endl;

                } else 
                    {
                        cout << "No hay error en los datos." << endl;
                    }

            // Corregir el bit erróneo si es necesario.
            vector<int> correctedcodigoHamming = codigoHamming;

            if (errorPosition != 0) 
                {
                    correctedcodigoHamming[errorPosition - 1] ^= 1;
                }

            // Mostrar el Código Hamming corregido.
            cout << "Codigo Hamming corregido: ";
            for (int bit : correctedcodigoHamming) 
                {
                    cout << bit;
                }
            cout << endl;

            // Mostrar el dato transmitido (sin los bits de paridad).
            cout << "Dato transmitido: ";
            for (int i = 0; i < n; ++i) 
                {
                    if ((i & (i + 1)) != 0) // Verificar si la posición es de un bit de paridad.
                        {  
                            cout << correctedcodigoHamming[i]; 
                        }  
                } cout << endl;

            cout << endl;
        }

    // Función para decodificar el dato con Código Hamming y paridad impar.
    void decodificarHammingParidadImpar(const vector<int>& codigoHamming) 
        {
            int n = codigoHamming.size();
            int numParityBits = log2(n) + 1;
            int errorPosition = 0;

            // Calcular la posición del bit erróneo.
            for (int i = 0; i < numParityBits; ++i) 
                {
                    int parityBitPosition = pow(2, i);
                    int parity = calcularParidadImpar(codigoHamming, parityBitPosition);

                    if (parity != 0) 
                        {
                            errorPosition += parityBitPosition;
                        }
                }

            // Mostrar la posición del bit erróneo.
            if (errorPosition != 0) 
                {
                    cout << "Bit Erroneo en la posicion: " << errorPosition << endl;

                } else 
                    {
                        cout << "No hay error en los datos." << endl;
                    }

            // Corregir el bit erróneo si es necesario.
            vector<int> correctedcodigoHamming = codigoHamming;
            if (errorPosition != 0) 
                {
                    correctedcodigoHamming[errorPosition - 1] ^= 1;
                }

            // Mostrar el Código Hamming corregido.
            cout << "Codigo Hamming corregido: ";
            for (int bit : correctedcodigoHamming) 
                {
                    cout << bit;
                }
            cout << endl;

            // Mostrar el dato transmitido (sin los bits de paridad).
            cout << "Dato transmitido: ";

            for (int i = 0; i < n; ++i) 
                {
                    if ((i & (i + 1)) != 0) // Verificar si la posición es de un bit de paridad.
                        {  
                            cout << correctedcodigoHamming[i];    
                        } 
                } cout << endl;

            cout << endl;
        }

    // Función para calcular la paridad par.
    int calcularParidadPar(const vector<int>& bits, int p) 
        {
            int paridad = 0;
            int n = bits.size();

            for (int i = p - 1; i < n; i += 2 * p) 
                {
                    for (int j = i; j < i + p && j < n; ++j) 
                        {
                            paridad ^= bits[j];
                        }
                }
            return paridad;
        }

    // Función para calcular la paridad impar.
    int calcularParidadImpar(const vector<int>& bits, int p) 
        {
            int paridad = 1;  // Comenzar con 1 para paridad impar
            int n = bits.size();

            for (int i = p - 1; i < n; i += 2 * p) 
                {
                    for (int j = i; j < i + p && j < n; ++j) 
                        {
                            paridad ^= bits[j];
                        }
                }
            return paridad;
        }

    // Función para contar el número de bits de paridad necesarios.
    int contarBitsDeParidad(int n) 
        {
            int contador = 0;
            int i = 1;

            while (i <= n) 
                {
                    contador++;
                    i <<= 1;
                }
            return contador;
        }
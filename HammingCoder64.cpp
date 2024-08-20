#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Declaración de funciones
void mostrarMenu();
void ejecutarOpcion(int opcion);
vector<int> codificarHammingParidadPar(const vector<int>& bitsDatos);
vector<int> codificarHammingParidadImpar(const vector<int>& bitsDatos);
void mostrarResultado(const vector<int>& codigoHamming);
int calcularParidad(const vector<int>& bits, int p, bool paridadPar);

int main() 
    {
        int opcion;
        do 
            {
                cout << endl;
                cout << "******************************" << endl;
                cout << "CODIFICADOR HAMMING MARCA ACME" << endl;
                cout << "******************************" << endl;
                cout << endl;
                cout << "Pequenio programa que sirve para convertir 1s y 0s" << endl;
                cout << "en mas 1s y 0s..." << endl;
                cout << endl;

                mostrarMenu();

                cout << "Selecciona una opcion: ";
                cin >> opcion;

                ejecutarOpcion(opcion);

            } while (opcion != 0);

        return 0;
    }

// Definición de funciones.

    // Función para mostrar el menú.
    void mostrarMenu() 
        {
            cout << "Elegi tu gusto:" << endl;
            cout << "--------------" << endl;
            cout << "1. Sabor Codigo Hamming (Paridad Par)" << endl;
            cout << "2. Sabor Codigo Hamming (Paridad Impar)" << endl;
            cout << "0. Salir" << endl;
            cout << endl;
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
                        cout << "Ingresa el dato en binario (64 bits maximo): ";
                        cin >> entrada;

                        // Convertir la entrada en un vector de bits.
                        vector<int> bitsDatos;

                        for (char c : entrada) 
                            {
                                bitsDatos.push_back(c - '0');
                            }

                        // Codificar en Código Hamming con paridad par.
                        vector<int> codigoHamming = codificarHammingParidadPar(bitsDatos);

                        // Mostrar resultado.
                        mostrarResultado(codigoHamming);

                        break;
                    }

                case 2: 
                    {
                        string entrada;

                        cout << endl;
                        cout << "Ingresa el dato en binario (64 bits maximo): ";
                        cin >> entrada;

                        // Convertir la entrada en un vector de bits.
                        vector<int> bitsDatos;

                        for (char c : entrada) 
                        {
                            bitsDatos.push_back(c - '0');
                        }

                        // Codificar en Código Hamming paridad impar.
                        vector<int> codigoHamming = codificarHammingParidadImpar(bitsDatos);

                        // Mostrar resultado.
                        mostrarResultado(codigoHamming);

                        break;
                    }

                case 0:
                    {
                        cout << endl;
                        cout << "That is All Folks..." << endl;
                        cout << endl;
                        
                        break;
                    }
                        
                default:
                    {
                        cout << endl;
                        cout << "Le pifiaste... Try again.";

                        break;
                    }   
            }
    }

    // Función para codificar con Código Hamming y paridad par
    vector<int> codificarHammingParidadPar(const vector<int>& bitsDatos) 
        {
            int m = bitsDatos.size();
            int r = 0;

            // Calcular el número de bits de paridad necesarios.
            while ((1 << r) < (m + r + 1)) 
                {
                    r++;
                }

            int n = m + r;
            vector<int> codigoHamming(n, 0);

            // Insertar los bits de datos.
            int j = 0;

            for (int i = 1; i <= n; i++) 
                {
                    if ((i & (i - 1)) != 0) 
                        {
                            codigoHamming[i - 1] = bitsDatos[j++];
                        }
                }

            // Calcular los bits de paridad.
            for (int i = 0; i < r; i++) 
                {
                    int parityBitPosition = (1 << i);

                    codigoHamming[parityBitPosition - 1] = calcularParidad(codigoHamming, parityBitPosition, true);
                }

            return codigoHamming;
        }

    // Función para codificar con Código Hamming y paridad impar.
    vector<int> codificarHammingParidadImpar(const vector<int>& bitsDatos) 
        {
            int m = bitsDatos.size();
            int r = 0;

            // Calcular el número de bits de paridad necesarios.
            while ((1 << r) < (m + r + 1)) 
                {
                    r++;
                }

            int n = m + r;
            vector<int> codigoHamming(n, 0);

            // Insertar los bits de datos.
            int j = 0;

            for (int i = 1; i <= n; i++) {
                if ((i & (i - 1)) != 0) {
                    codigoHamming[i - 1] = bitsDatos[j++];
                }
            }

            // Calcular los bits de paridad.
            for (int i = 0; i < r; i++) 
                {
                    int parityBitPosition = (1 << i);

                    codigoHamming[parityBitPosition - 1] = calcularParidad(codigoHamming, parityBitPosition, false);
                }

            return codigoHamming;
        }

    // Función para calcular la paridad de un bit.
    int calcularParidad(const vector<int>& bits, int p, bool paridadPar) 
        {
            int paridad = paridadPar ? 0 : 1;
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

    // Función para mostrar el resultado.
    void mostrarResultado(const vector<int>& codigoHamming) 
        {
            cout << endl;
            cout << "CODIGO HAMMING RESULTANTE: ";

            for (int bit : codigoHamming) 
                {
                    cout << bit;
                }
            cout << endl;
        }
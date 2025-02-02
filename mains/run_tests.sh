#!/bin/bash

# Ejecutar make
make

# Contador de fallos
failed_tests=0
failed_list=()

# Ejecutar todos los archivos .out
for exec in *.out; do
    if [ -x "$exec" ]; then
        echo "Ejecutando $exec..."
        ./"$exec"
        exit_code=$?

        if [ $exit_code -ne 0 ]; then
            echo "❌ $exec falló con código de estado $exit_code"
            ((failed_tests++))
            failed_list+=("$exec")
        fi
		echo -e "\n\n"
    fi
done

make clean

# Imprimir resultado final
echo "Tests fallados: $failed_tests"
if [ $failed_tests -gt 0 ]; then
    echo "Lista de tests fallados:"
    for test in "${failed_list[@]}"; do
        echo "  - $test"
    done
fi

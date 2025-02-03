#!/bin/bash

# Verificar si se proporcionó el nombre del test
if [ "$#" -ne 1 ]; then
    echo "Uso: show <nombre del test>"
    exit 1
fi

nombre="$1"
archivo="results.txt"  # Nombre fijo del archivo de resultados

# Verificar si el archivo existe
if [ ! -f "$archivo" ]; then
    echo "Error: El archivo '$archivo' no existe en el directorio actual."
    exit 1
fi

# Extraer las líneas entre "Ejecutando <name>.out..." y "✅ <name>.out aprobó."
awk -v name="$nombre" '
    $0 ~ "Ejecutando " name ".out\\.\\.\\." { capturar=1 }  # Comienza a capturar
    capturar { print }  # Imprime mientras capturar esté activo
    $0 ~ name ".out finalizado\\." { capturar=0 }  # Deja de capturar al encontrar la línea final
' "$archivo"

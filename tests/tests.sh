#!/bin/bash
if [ "$#" == 0 ]; then
    echo "Uso: $0 <option> [<args>]"
	echo "<option> = --help para mas detalles."
    exit 1
fi

if [ "$1" != "--help" ] && [ "$1" != "show" ] && [ "$1" != "run" ]; then
	echo "Comando no permitido."
	echo "Usa: $0 --help para mas info."
	exit 1
fi

if [ "$1" == "--help" ]; then
    echo "Uso: $0 [opciones]"
    echo "Opciones:"
    echo "	--help				Muestra este mensaje de ayuda"
	echo "	run				Ejecuta todos los tests (los archivos .c tienen que comenzar por test_)"
	echo "	show <test_name>		Muestra los resultados de un test en particular"
    exit 0
fi

if [ "$1" == "run" ]; then
	echo "" > results.txt

	current_dir=$(pwd)

	cd ..
	make >> ${current_dir}/results.txt
	make clean >> ${current_dir}/results.txt
	cd $current_dir


	# Ejecutar make
	make >> results.txt

	# Contador de fallos
	failed_tests=0
	failed_list=()

	passed_tests=0
	passed_list=()

	# Ejecutar todos los archivos .out
	for exec in *test_*; do
		if [ -x "$exec" ]; then
			echo "Ejecutando $exec..." >> results.txt
			./"$exec" 
			./"$exec" >> results.txt
			exit_code=$?

			if [ $exit_code -ne 0 ]; then
				echo "❌ $exec falló en el Caso $exit_code" >> results.txt
				echo "❌ $exec falló en el Caso $exit_code"
				((failed_tests++))
				failed_list+=("$exec")
			fi
			if [ $exit_code == 0 ]; then
				echo "✅ $exec aprobó." >> results.txt
				echo "✅ $exec aprobó."
				((passed_tests++))
				passed_list+=("$exec")
			fi
			echo "$exec finalizado." >> results.txt
			echo "$exec finalizado."
			echo -e "\n\n" >> results.txt
			echo -e "\n\n"
		fi
	done

	make clean >> results.txt

	echo -e "\n"
	echo "Done!! Check results.txt to see log info."
	echo -e "\n"

	# Imprimir resultado final
	echo "Tests fallados: $failed_tests" >> results.txt
	echo "Tests fallados: $failed_tests"
	if [ $failed_tests -gt 0 ]; then
		echo "Lista de tests fallados:" >> results.txt
		echo "Lista de tests fallados:"
		for test in "${failed_list[@]}"; do
			echo "  - $test" >> results.txt
			echo "  - $test"
		done
	fi

		echo -e "\n" >> results.txt
		echo -e "\n"

	# Imprimir resultado final
	echo "Tests aprobados: $passed_tests" >> results.txt
	echo "Tests aprobados: $passed_tests"
	if [ $passed_tests -gt 0 ]; then
		echo "Lista de tests aprobados:" >> results.txt
		echo "Lista de tests aprobados:"
		for test in "${passed_list[@]}"; do
			echo "  - $test" >> results.txt
			echo "  - $test"
		done
	fi
	exit 0
fi

if [ "$1" == "show" ]; then
	bash show_test_results.sh $2
	exit 0
fi

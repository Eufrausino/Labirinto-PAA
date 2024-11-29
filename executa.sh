#!/bin/bash

read -p "Entrar no modo análise? (s/n) -> s para sim / n para não: " resposta

if [[ "$resposta" == "s" || "$resposta" == "S" ]]; then
    echo "Entrando no modo análise ..."
    make -f Makefile.linux CFLAGS="-DANALISE"
else
    echo "Explorando labirinto normalmente ..."
    make -f Makefile.linux
fi

cd output
./exe.out


# wutmonopolygame

ETAP 3
------------------------------------------------------

Aby uruchomić program bez otwierania projektu w Visual Studio należy pobrać spakowany plik executable.zip i wypakować go.
W środku znajduje się plik wykonawczy .exe oraz katalogi z zasobami. Program nie potrzebuje dodatkowych bibliotek. (a przynajmniej u mnie nie potrzebował).

W stosunku do poprzedniej wersji dodano nową klasę pola trapField. Widać także wyraźnie polimorfizm poprzez różną implementację metody onStepAction() dla tych pól.
Widać go także na przykładzie metody render(), gdyż pola rożnią się elementami, które mogą być wyświetlane.

Dodano także dokumentację w doxygen dla najwazniejszych funkcji.

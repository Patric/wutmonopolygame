# wutmonopolygame


ETAP 3
-----------------------------

Aby uruchomić program bez otwierania projektu w Visual Studio należy pobrać spakowany plik executable.zip i wypakować go, lub sklonować zawartość katalogu executable. W środku znajduje się plik wykonawczy .exe oraz katalogi z zasobami. Program nie potrzebuje dodatkowych bibliotek. (a przynajmniej u mnie nie potrzebował).
Aby projekt uruchomić w Visual studio należy plik z biblioteką SFML o nazwie SFML-2.5.1-windows-vc15-32-bit.zip wypakować do katalogu o 1 wyżej niż plik main.cpp.

Zmiany w stosunku do ETAP 2
---------------------------
Pokazano polimorfizm w lepszy sposób poprzez dodanie podklasy trapField, która ma inną implementację onStepAction niż propertyField. Mają też inną implementację render
z racji różnić w tym jakie elementy wyświetlają. dodano także dokumentację w doxygen.

================================================================================================
BAKALARSKA PRACE - SYSTEM PRO VYPOCET SOFTWAROVYCH METRIK - Martin Ovesny (ovesnmar@fel.cvut.cz)
================================================================================================


Adresarova struktura
====================
.
|- doc
|  |- html                     // adresar obsahuje dokumentaci implementace ASTM vygenerovanou systemem Doxygen (911 souboru)
|  |- AbstractSyntaxTreeMetamodel.pdf  // specifikace ASTM vydana OMG
|  |- CppStandard-ANSI_ISO_IEC_14882_2003.pdf  // standard ANSI/ISO C++ z roku 2003, podle ktereho byl implementovan frontend
|
|- src
|  |- ASTM                     // adresar obsahuje implementaci uzlu stromu (360 souboru)
|  |- Frontends
|  |  |- C++                   // adresar obsahuje zdrojove kody frontendu pro jazyk C++
|  |     |- ActualParsingUnit.cpp  // singleton vracejici instanci parseru
|  |     |- ActualParsingUnit.h
|  |     |- cpp.l              // zdrojovy kod pro Flex
|  |     |- cpp.ypp            // zdrojovy kod pro Bison
|  |     |- CppParser.cpp      // trida poskytujici C++ rozhrani parseru
|  |     |- CppParser.h
|  |     |- editor.sh          // skript sedu, kteru je potrebny pro sestaveni parseru - meni kod vygenerovany Bisonem, aby se dal prelozit tak, jak je pro dobry vysledek potreba
|  |
|  |- Modules
|  |  |- CCN                   // modul pocitajici CCN metriku
|  |  |  |- CCN.cpp
|  |  |  |- CCN.h
|  |  |
|  |  |- COMMDENS              // modul pocitajici COMMDENS metriku
|  |  |  |- COMMDENS.cpp
|  |  |  |- COMMDENS.h
|  |  |
|  |  |- DECDENS               // modul pocitajici DECDENS metriku
|  |  |  |- DECDENS.cpp
|  |  |  |- DECDENS.h
|  |  |
|  |  |- LK                    // modul pocitajici LK metriky
|  |  |  |- LK.cpp
|  |  |  |- LK.h
|  |  |
|  |  |- LOC                   // modul pocitajici SLOC metriky
|  |  |  |- LOC.cpp
|  |  |  |- LOC.h
|  |  |
|  |  |- NOC                   // modul pocitajici NOC metriku
|  |  |  |- NOC.cpp
|  |  |  |- NOC.h
|  |  |
|  |  |- NPATH                 // modul pocitajici NPATH metriku
|  |  |  |- NPATH.cpp
|  |  |  |- NPATH.h
|  |  |
|  |  |- TFC                   // modul pocitajici TFC metriku
|  |  |  |- TFC.cpp
|  |  |  |- TFC.h
|  |  |
|  |  |- ModuleApi.cpp         // API pro usnadneni psani novych modulu - obsahuje nekolik uzitecnych funkci pro praci s ASTM
|  |  |- ModuleApi.h
|  |  |- ModuleBase.cpp        // rozhrani, ktere musi kazdy modul povinne implementovat
|  |  |- ModuleBase.h
|  |
|  |- TinyXML                  // obsahuje zdrojove kody knihovny TinyXML, ktera je do prohramu primo vestavena, aby nebyl zavisly na jeji pritomnosti v systemu, na kterem se program sestavuje
|  |- CMakeLists.txt           // soubor pro generovani Makefile systemem CMake
|  |- config.h                 // konfigurace sestaveni aplikace - obsahuje akorat prepinac, ktery urcuje, zda se maji pri behu aplikace vypisovat debugovaci informace
|  |- main.cpp                 // jadro systemu
|
|- test
|  |- test1...test6            // obsahuji ukazky testu
|  |  |- code.cpp              // zdrojovy kod, ktery dostane system na vstupu
|  |  |- dump.xml              // dump naparsovaneho ASTM, na kterem bude test probihat (tento soubor staci otevrit ve webovem prohlizeci a ten test vyhodnoti)
|  |  |- test.xsl              // vlastni kod testu
|  |
|  |- checker.xsl              // predpripravena sablona pro snadnejsi psani testu, viz ukazky test1-6
|
|- text
|  |- figures
|  |- k336_thesis_macros.sty   // FEL sablona BP pro LaTeX
|  |- reference.bib            // seznam literatury
|  |- thesis.pdf               // PDF vysledne bakalarske prace!
|  |- thesis.tex               // zdrojovy kod BP
|
|- doxygen.cfg                 // konfiguracni soubor pro system Doxygen k vygenerovani dokumentace
|- README.TXT                  // tento soubor
|- src.cpp                     // ukazkovy zdrojovy kod pro analyzu
|- sw_metrics.xsl              // pripravena sablona pro vizualizaci vysledku analyzy



Systemove pozadavky aplikace
============================
Teoreticky je mozne sestavit na jakemkoli systemu, ktery disponuje nastroji
Flex, Bison, GNU Make, CMake, sed, bash, SVN a GCC.

Nicmene veskere testovani probihalo na OS Linux pri nasledujici konfiguraci:
- kernel 2.6.33-ARCH (32bit)
- gcc (GCC) 4.5.0.
- flex 2.5.35
- bison (GNU Bison) 2.4.2
- cmake version 2.8.1
- GNU Make 3.81
- GNU bash, version 4.1.7(2)-release (i686-pc-linux-gnu)
- GNU sed version 4.2.1
- svn, version 1.6.9 (r901367)



Instalace aplikace
==================
Nachazite se v korenovem adresari CD.
Aplikaci sestavite pomoci nasledujici sekvence prikazu:
$ mkdir ./src/build
$ cd ./src/build
$ cmake ..
$ make
Vysledna aplikace se v pracovnim adresari a binarka se jmenuje "sw_metrics".

Pozn.: Kdyby se vyskytl problem pri instalaci, muze jit o spatne nastaveni priznaku
       souboru ../Frontends/C++/editor.sh
$ chmod +x ../Frontends/C++/editor.sh

Krome instalace z CD, je mozne si stahnout zdrojove kody z SVN.
$ svn checkout https://svn.origo.ethz.ch/sw-metrics/trunk sw_metrics



Spusteni aplikace s ukazkovymi daty
===================================
Nasledujicimi prikazi si nakopirujte ukazkovy zdrojovy kod a XSL sablonu do pracovniho adresare:
$ cp ../../src.cpp .
$ cp ../../sw_metrics.xsl .
Ted spuste analyzu prikazem:
$ ./sw_metrics src.cpp
Pokud vse probehne bez chyby, vytvori se soubor "report.xml", ktery obsahuje vysledky analyzy.
Ted si tento soubor otevrete ve webovem prohlizeci, napr.:
$ firefox report.xml
Zobrazi se vysledky analyzy prehledne zformatovane do tabulek.



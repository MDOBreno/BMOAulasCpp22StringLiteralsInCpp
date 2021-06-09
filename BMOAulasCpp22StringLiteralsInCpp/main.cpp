//
//  main.cpp
//  BMOAulasCpp22StringLiteralsInCpp
//
//  Created by Breno Medeiros on 09/06/21.
//

#include <iostream>
#include <string>
#include <stdlib.h>


//Obs: 'const char nome[]' é um Array, e 'const char* nome' é um Ponteiro.

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    const char nomeArrayConstante[6] = "Breno"; //Tudo o que esta dentro de ""(aspas duplas) é chamado de StringLiteral, nesse caso 'const char[7]'
    //Obs: [11:23] StringLiteral estao sempre na memoria como ApenasLeitura no Assemble, mesmo q usassemos [char nomeArrayVariavel[] = "Breno";]
    const char nomeArrayConstanteInterrompido[7] = "Bre\0no"; //Colocar um '\0' no meio da string quebra a coisa toda, entao nao faca isso.
    
    std::cout << nomeArrayConstante << std::endl;
    std::cout << nomeArrayConstanteInterrompido << std::endl; //Somente exibe "Bre" porque ele so considera string o que for ate o '\0'
    
    //Usando uma funcao de C para ver qual o comprimento de 'nomeInterrompido':
    std::cout << strlen(nomeArrayConstanteInterrompido) << std::endl; //Somente exibe 3 porque ele so considera string o que for ate o '\0'
    
    const char* nomePonteiroContante = "Breno"; //Declara-se como 'const' por seguranca,visto q ao instanciar Array o seu tamanho n muda
    char nomeArrayVariavel[] = "Breno"; // Declara-se sem 'const' por, msm seu tamanho n podendo mudar, as posicoes podem mudar d valor
    //nomePonteiroContante[2] = 'u'; //Descomentar essa linha causa erro, pois foi declarado como uma constante
    nomeArrayVariavel[2] = 'u';
    std::cout << nomePonteiroContante << " " << strlen(nomePonteiroContante) << std::endl;
    std::cout << nomeArrayVariavel << " " << strlen(nomeArrayVariavel) << std::endl;
    
    //Para o proximo passo vá/defina em:
    // "ConfiguracoesDoProjetoXcode" -> BuildSettings -> AppleClang-Languages -> CodeWarrior/MS-StyleInlineAssembly -> YES
    //E agora mude o tipo de build de 'Debug' para 'Release':
    // 'Product' -> 'Scheme' -> 'Edit Scheme' -> 'Run' -> 'BuildConfiguration' -> 'Release'
    //Execute o projeto(Command + R) -> (Command + 1) -> Clique com botãoDiteiroDoMouse no arquivo dentro pasta do Produto -> ShowInFinder
    // Assim tanto o executavel(Arquivo *.exec) quando o de simbolos(arquivo *.dSYM) aparecerao. E agora para Assembly(arq *.s) ha 2 formas:
    //1) (Command + 1) -> Clique com botãoDiteiroDoMouse no arquivo -> "ShowInFinder" -> AbraUmTerminalNessaPasta -> Execute$: clang -S main.cpp
    //2) (Command + 1) -> main.cpp -> "Product" na barra superior do Xcode -> "PerformAction" -> Assemble"main.cpp"
    //Sera entao gerado o arquivo Assembly 'main.s' que equivale ao 'Main.asm' do Chermo
    
    //Analise do Assembly(arquivo *.s no MacOS, ou *.asm no windows):
    char nomePonteiroVariavelAssembly[] = "BrenoVariavel";
    nomePonteiroVariavelAssembly[2] = 'u'; //Analise o Assembly com essa linha, e depois semEssaLinha(ou seja, comentada)
    std::cout << nomePonteiroVariavelAssembly << std::endl;
    
    //Quando ele comecar a abrir no programa 'HxD' executavel(arquivo *.exec no MacOS, *.exe no windows), voce precisa baixar no Sublime
    // o pacote 'Hex​Viewer'[ https://facelessuser.github.io/HexViewer/installation/ ] que é um equivalente dentro do Sublime. Entao
    // abra o executavel(arquivo *.exec) no sublime, e para ver o equivalente a esses Hexadecimais em ASCII no sublime faça:
    // 'Tools' -> 'Packages' -> 'HexViewer' -> 'Toogle Hex View'
    
    //Nas duas linhas abaixo o Chermo mostrar que mesmo mudando um caractere logo apos a criacao, no executavel(arquivo *.exec) a StringLiteral
    // "BrenoVariavel" nao é otimizada para ja salvar como "BrenaVariavel", o que se fosse feito otimizaria bem por transformar duas linhas em 1.
    char nomePonteiroVariavelAssembly2[] = "BrenoVariavel";
    nomePonteiroVariavelAssembly2[4] = 'a';
    
    //Lembrando que nunca escreva 'char* nome = "Breno"', por varios motivos. A nao ser que voce queria fazer algo escroto como isso:
    char* nome = (char*)"Breno"; //Mas mesmo assim nao é bom fazer essas merdas, porque so tem tres jeitos que prestam, q é como fizemos em:
    // 'nomeArrayConstante' ou 'nomePonteiroContante' ou 'nomeArrayVariavel'
    
    //E quando queremos usar characteres de tamanhos especificos, temos:
    const char16_t* nome16Bits = u"Breno16Bits"; // (2Bytes=16Bits por 'char',ou seja,'char's interpretados em uft16)
    const char32_t* nome32Bits = U"Breno32Bits"; // (4Bytes=32Bits por 'char',ou seja,'char's interpretados em uft32)
    
    //Informando tambem que alem de 'char'(8Bits por 'char',ou seja,'char's interpretados em uft8),temos tambem o CaractereBranco(WhiteCaracter):
    const wchar_t* nomeCaractereBranco = L"BrenoCaractereBranco"; //Esse 'L' singnifica que essa StringLiteral é formada de CaracteresBrancos
    //Obs: CaractereBranco(WhiteCaracter) tem tamanhos variados: Windows 2Bytes, Linux(e talvez MacOS) 4Bytes.
    
    using namespace std::string_literals; //Serve para nos dar o numero de funcoes(apenas por conveniencia)
    //Obs: Normalmente se coloca todos os "using namespace" no topo do codigo, mas coloquei aqui pra esclarecer q daqui pra baixo é q o usaremos
    
    //Concatenando: o antes e o depois da versao 11 do Cpp:
    std::string    nomeConcatenadoAntesDoCpp11 = std::string("Breno") + ", Ola";//Era assim antes da versao 11 do Cpp. Mas agora podemos assim:
    std::string    nomeConcatenadoDepoisDoCpp11Forma1 = "Breno"s + ", Ola";     //Basicamente esse 's' é uma funcao
    std::string    nomeConcatenadoDepoisDoCpp11Forma2 = u8"Breno"s + ", Ola";   //Mesmo da linha acima, porem explicitando 8Bits por 'char'
    std::wstring   nomeConcatenadoDepoisDoCpp11Forma3 = L"Breno"s + L", Ola";   //Adicao de um 'w' e dois 'L' para uso de CaracteresBrancos
    //std::u32string nomeConcatenadoDepoisDoCpp11Forma4 = U"Breno" + U", Ola";    //32bits=4Bytes //Isso da certo no VSCode mas n no Xcode
    
    //Texto em varias linhas
    const char* nomePonteiroContanteComVariasLinhas1 = R"(Linha1
    Linha2
    Linha3)";
    const char* nomePonteiroContanteComVariasLinhas2 = "Linha1\n"
    "Linha2\n"
    "Linha3\n";
    
    std::cout << "Hello, World!\n";
    return 0;
}

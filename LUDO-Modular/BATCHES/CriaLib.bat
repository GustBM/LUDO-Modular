ECHO Cria a biblioteca a ser utilizada no exemplo \simples
ECHO assume o arcabouco todo construído e correto

pushd  .

nmake /F..\composicao\crialib.make  "PRD="
copy  ..\ArcaboucoTeste.lib \objetos

popd

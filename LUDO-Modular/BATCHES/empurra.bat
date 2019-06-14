@ECHO  OFF
REM  envia para Repositorio com mensagem escrita
REM  
              

pushd  .

if ""=="%1" goto erro

git pull
call LimpaTudo.bat
git add --all
git commit -m "%1"
git push

goto sai

:erro
echo Falta mensagem do commit

:sai
popd

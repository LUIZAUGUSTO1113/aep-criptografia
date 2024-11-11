# aep-criptografia
Sistema de Gerenciamento de Usuários é um projeto de estudo realizado por alunos da Graduação em Engenharia de Software da UniCesumar. O mesmo é parte do processo de avaliação semestral da faculdade.

## 1. Diagrama de caso de uso
![Diagrama de caso de uso](https://github.com/user-attachments/assets/694311fb-6a3a-45f5-b199-69ef54efb471)
### 1.1. Atores: 
- Administrador
### 1.2. Casos de Uso: 
- Acessar Menu: Caso de uso inicial onde o Administrador acessa o sistema e vê o menu com as opções de gerenciamento de usuários.
- Incluir Usuário: O Administrador pode incluir novos usuários no sistema a partir do menu.
- Listar Usuários: O Administrador pode visualizar a lista de usuários registrados.
- Alterar Usuário: O Administrador pode modificar as informações de um usuário existente.
- Deletar Usuário: O Administrador pode excluir um usuário da lista.
### 1.3. Fluxo: 
- O Administrador acessa o menu principal, de onde pode escolher qualquer uma das operações de gerenciamento de usuário.

## 2. Criptografia
A criptografia adotada trabalha com três camadas de proteção, em um primeiro momento a string (senha) é invertida, posteriormente é adcionado 1 a cada caracter visando este na tabela ASCII e por fim é adicionado a cada caracter o tamanho da string obtido pela propriedade `strlen`.

## 3. Arquivos
Devido a necessidade de uso de compilador e por este código ter sido desenvolvido no Visual Studio Code, os arquivos se encontram na pasta de `OUTPUT`.
- usuarios.txt: Arquivo fixo, ao qual simula um banco de dados para guardar o ID, o nome e a senha criptografada dos usuários cadastrados.
- temp.txt: Arquivo criado de forma temporariamente ao utilizar as funções `alterar_usuario()` e `deletar_usuario()`.

OBS: Vale ressaltar que nessa versão beta, o sistema cumpre com os objetivos especificados e entrega um software capaz de sanar as necessidades no contexto dessa aplicação.

## @ 2024 UniCesumar - By Luiz Augusto Holanda, Vinícius da Cruz e João Ariza. - ESOFT2SD

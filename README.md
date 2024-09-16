Пользовательский чат, который состоит из:

-Класс Chat

-Класс Users

-Класс Message

-Класс исключений BadLogin (генерируется исключение при неправильном вводе логина)

-Класс исключений BadPassword (генерируется исключение при неправильном вводе пароля)


Логика работы программы:

-В цикле происходит регистрация пользователей

-Если пользователь с таким логином уже зарегистрирован, то появляется предупреждение

-Далее требуется авторизоваться

-При неправильном вводе логина/ пароля появляется предупреждение

-Есть возможность продолжить ввод или же выйти из программы

-После регистрации можно отправить личное или общее сообщение

-Если больше не требуется отправить сообщение, программа предлагает войти под другим логином

-При авторизации происходит проверка на наличие новых сообщений

-Если логин авторизованного пользователя совпадает с логином получателя или же отправлено общее сообщение, то происходит вывод сообщения на экран

-После вывода сообщения они удаляются из контейнера для авторизованного пользователя. Все просмотренные сообщения хранятся в отдельном контейнере

-Далее в цикле повторяются предыдущие шаги, пока пользователь не захочет выйти из чата

-В конце программы выводятся все сообщения с указанием отправителя - получателя на экран


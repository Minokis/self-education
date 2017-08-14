/*
Как добиться хорошего отображения текста:

- Вам следует сменить шрифт консоли на юникодный,
это позволит работать даже на английской Windows.
- Компилятор Microsoft Visual Studio (по крайней мере, версии 2012 и 2013) компилирует исходники в однобайтных кодировках так, как будто бы они на самом деле в ANSI-кодировке, то есть для случая русской системы — CP1251. Это означает, что кодировка исходников в CP866 — неправильна. (Это важно, если вы используете L"..."-строки.) С другой стороны, если вы храните исходники в CP1251, то эти же исходники не будут нормально собираться на нерусской Windows. Поэтому стоит хранить исходники в Unicode (например, UTF-8).

-использовать Unicode в программе. При этом вы получите правильный вывод не только кириллицы, но и поддержку всех языков (изображение отсутствующих в шрифтах символов будет отсутствовать, но вы сможете с ними работать). Для Windows это означает переход с узких строк (char*, std::string) на широкие (wchar_t*, std::wstring), и использование кодировки UTF-16 для строк.
https://ru.stackoverflow.com/questions/459154/%D0%A0%D1%83%D1%81%D1%81%D0%BA%D0%B8%D0%B9-%D1%8F%D0%B7%D1%8B%D0%BA-%D0%B2-%D0%BA%D0%BE%D0%BD%D1%81%D0%BE%D0%BB%D0%B8
*/


#include <iostream>
#include <io.h>
#include <fcntl.h>

int wmain(int argc, wchar_t* argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin),  _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    std::wcout << L"Unicode -- English -- Русский -- Ελληνικά -- Español." << std::endl;
    // или
    wprintf(L"%s", L"Unicode -- English -- Русский -- Ελληνικά -- Español.\n");

    return 0;
}

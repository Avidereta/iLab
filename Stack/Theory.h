enum Commands
{
    cmd_PUSH = 1,
    cmd_POP = 2,
    cmd_ADD = 3,

};

struct CmdInfo
{
    int num;
    const char* name;

};

//массив структур
const CmdInfo Info[] =
        {
                {cmd_PUSH, "PUSH"}, //[0]
                {cmd_POP, "POP"}, //[1]
                {cmd_ADD, "ADD"}, //[2] индексация Info[c].num == c

        };


/* Линейный поиск и двоичный поиск рабоют по-разному:
 * лин - неважен порядок нумерации в const неважен,
 * двоичный - важен. Зачем он?)
 * Итог: написать assert. проверяющий правильный порядок, отсортированность
 * Индексация - сделать в начале проверку на готовность структуры к индексацинному поиску
 * Можно переключаться между методами после проверки
 *
 */


int main()
{
    if (stricmp(str, "PUSH") == 0)
        fprintf(out, "%d", cmd_PUSH);
    else if ...
};

/* Макрос
 *  CmdList.h - на самом деле всего лишь набор текста
 *  DEF_CMD(PUSH,1)
 *  DEF_CMD(POP, 2)
 *  DEF_CMD(ADD,3)
 * ----------------------
 *  что хотим? не хотим полностью писать enum Commands
 *  define создает сам такую посл
 *
 *  asm.cpp
 * Сгенерировать enum Commands
 *
 *  #define DEF_CMD(name, num) cmd##name = num
 *  enum Commands {
 *      #include "CmdList.h"
 *      cmd_Last чтобы не было ошибки с запятой
 *      };
 *--------------------
 * Сгенерировать проверку
 * #define DEF_CMD(name, num)\
 *  if (stricmp(str, #name) == 0)\
 *      fprintf(out, "%d", cmd_##name)\
 *  else
 * ---
 *  #include "CmdList.h"
 *  printf(Error...);
 *
 * ------------------
 * Добавили параметр
 * CmdList.h - на самом деле всего лишь набор текста
 *  DEF_CMD(PUSH,1,?? {stackPush(&str, v)}...)
 *  DEF_CMD(POP, 2, что нужно сделать, чтобы выполнилось)
 *  DEF_CMD(ADD,3, pop+pop+push)
 * ----------------
 *
 *
 * Сгенерировать Info
 * #define DEF_CMD(name, num)\
 *  {cmd_##name, #name};
 *
 * const CmdInfo Info[] =
 * {
 *  #include "CmdList.h"
 *  {}
 * }
 *
 * switch(cmd[i])
 *  {
 *      #define DEF_CMD(name, num, code)\
 *          case num: {code} break;
 *      #include "Cmd_List.h"
 *      #
 *
 *
 *

 */

Статические и динамические библиотеки
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <array>
#include <cmath>

int GetRandomNumber(int min, int max)
{
  srand(time(NULL));
  return min + rand() % (max - min + 1);
}

int isDigitString(std::string &str)
{
    int sum = 0;
    auto iter = str.begin(); // iter -- ????????; str.begin() -- ???????? ? ??????? ???????? ??????

    for (int i = 0; iter != str.end(); iter++)
    {
        std::cout << *iter << " !! ";
        if (std::isdigit(*iter))
        {
            sum += (int)str[i] - '0';
        }
        i++;
    }
    return sum;
}

int GetMonth(std::string &str)
{
    return (int) (str[3] - '0') * 10 + (str[4] - '0');
}

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"russian");
    
    std::string strName, strAge;
    long int mass[3] = {0, 11111111, 22222222};

    std::cout << "Введите Ваше имя:\n";
    std::cin >> strName;
    std::cout << "Введите дату рождения:\n";
    std::cin >> strAge;

    int number = GetRandomNumber(0, 2);

    int sum = isDigitString(strAge);
    int month = GetMonth(strAge);

    unsigned  mega = pow(sum, month) + mass[number];
    
    std::cout << "mega = " << mega << std::endl;

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = (mega << 12 + 4 * i) >> (28);
        std::cout << arr[i] << " \n";
    }

    std::string music[14] = {"Master of puppets Metallica", "Брошу Pyrokinesis", "Homebody PH1","Червяк Даргомыжский","Russian Ebunny","Enemy Imagine dragons"," Зизазай Огги и тараканы","Valentine Justice","Swimming pools Kendrick Lamar","Night Call Kovinsky","Yesterday The Beatles","Так закалялась сталь Гражданская оборона","За деньги да Инстасамка","Bad habits Ed sheeran"}; 
    std::string movies[14] ={"Короткое замыкание", "Трансформеры", "Полночь", "По соображениям совести","Джентльмены","Ван Хельсинк","Операция Ы","Драйв","Большая игра","Игра в имитацию","Всё везде и сразу","Форрест Гамп","Терминал","Не смотрите наверх"};
    std::string actors[14] = {"Райан Гослинг", "Кристиан Бейл", "Джеки Чан","Эндрю Гарфилд","Леонардо ДиКаприо","Бенедикт Кембербетч","Мэтью Макконахи","Дэвид Линч","Дэниэлл Рэдклифф","Джейк Джиллехолл","Александр Петров","Рональд Рейган","Том Круз","Брэд Питт"}; 
    std::string actriss[14] = {"Наталия Крачковская", "Меган Фокс", "Джениффер Лопез","Эмма Стоун","Эмма Уотсон","Кира Найтли","Милла Йовович","Марго Робби","Мерил Стрип","Скарлет Йоханссон","Александра Бортич","Анджелина Джоли","Шарлиз Терон","Ингеборга Дапкунайте"}; 
    std::string celeb[14] = {"Дейв Майнстейн", "Иван Зола", "Сергей Мавроди", "Екатерина Гордеева", "Роберт Опенгеймер", "Лионель Месси", "Папич", "Хидэо Кодзима", "Ляйсан Утяшева","Павел Воля","Криштиану Роналду","Борис Бурда","Ким Кардашьян","Клава Кока"};
    
    std::cout << "Здравствуйте, " << strName << "!\n";
    std::cout << "Ваша музыка: " << music[arr[0]%14] << '\n';
    std::cout << "Ваш фильм: " << movies[arr[1]%14]<< '\n';
    std::cout << "Ваш актер: " << actors[arr[2]%14] << '\n';
    std::cout << "Ваша актриса: " << actriss[arr[3]%14] << '\n';
    std::cout << "Ваша целеба: " << celeb[arr[4]%14] << '\n';

    return 0;
}
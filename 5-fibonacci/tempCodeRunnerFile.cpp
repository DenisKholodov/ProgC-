r = str.begin();
    for (; iter != str.end() && std::isdigit(*iter); iter++){}
    return !str.empty() && iter == str.end();
}

/*bool isDigitString(char* chars)
{
    int s = sizeof(chars)/sizeof(chars[0]);
    std::cout << s << ' ' << sizeof(chars) << ' ' << '\n';
    for(int i = 0; i < s - 1; i++)
    {
        if (!std::isdigit(chars[i]))
        {
            std::cout << i << ' ' << chars[i] << std::isdigit(chars[i]) << ' ';
            return 0;
        }
    }
    return 1;
}*/
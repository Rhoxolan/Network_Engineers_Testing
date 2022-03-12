//
// [номер теста]_[номер вопроса]_[1 - правильный ответ, 0 - неправильный ответ]_[номер неправильного ответа]
//
// one_one_0_1
//  |   |  | |____ Первый ложный ответ
//  |   |  |______ Ложный ответ
//  |   |_________ Первый вопрос
//  |_____________ Первый тест


//Тест 1
constexpr auto one_one = "Какой тип кабеля лучше всего подходит для передачи данных на расстояние 1км?";
constexpr auto one_one_1 = "Оптоволоконный кабель";
constexpr auto one_one_0_1 = "Витая пара";
constexpr auto one_one_0_2 = "Экранированая витая пара категории 6+";

constexpr auto one_two = "От чего необходимо регулярно очищать корпус ПК?";
constexpr auto one_two_1 = "Пыль";
constexpr auto one_two_0_1 = "Ржавчина";
constexpr auto one_two_0_2 = "Остатки жикости от системы водяного охлаждения";

constexpr auto one_three = "Какой тип сети охватывает одно здание или кампус и предоставляет услуги и приложения людям в рамках общей организационной структуры?";
constexpr auto one_three_1 = "LAN (Local area network)";
constexpr auto one_three_0_1 = "MAN (Metropolitan area network)";
constexpr auto one_three_0_2 = "WAN (Wide area network)";
constexpr auto one_three_0_3 = "SAN (Small area network)";
constexpr auto one_three_0_4 = "BAN (Building area network)";
constexpr auto one_three_0_5 = "CAN (Campus area network)";

constexpr auto one_four = "Сколько жил будет задействовано в витой паре Cat.5e при скорости передачи данных 1 Гб/С?";
constexpr auto one_four_1 = "8";
constexpr auto one_four_0_1 = "Витая пара - моножильный провод, экран не задействован в передаче данных";
constexpr auto one_four_0_2 = "4";
constexpr auto one_four_0_3 = "16";

constexpr auto one_five = "Технический специалист устанавливает HDD. К какому разъему материнской платы техник подключит кабель данных?";
constexpr auto one_five_1 = "SATA";
constexpr auto one_five_0_1 = "ATX";
constexpr auto one_five_0_2 = "PCI";

constexpr auto one_six = "Текущая конфигурация IP в небольшой компании выполняется вручную и требует много времени. Из-за растущего роста сети техническому специалисту требуется более простой способ IP-конфигурации рабочих станций. Какой сервис упростит задачу настройки IP рабочей станции?";
constexpr auto one_six_1 = "DHCP";
constexpr auto one_six_0_1 = "DNS";
constexpr auto one_six_0_2 = "AutoIP";
constexpr auto one_six_0_3 = "Это невозможно; IP-адреса необходимо прописывать и фиксировать вручную, чтобы злоумышленники не смогли получить доступ к сервису и подменить IP-адреса";

constexpr auto one_seven = "Компьютерный техник устанавливает RAID. Если RAID использует зеркалирование и чередование, какой уровень RAID использует технический специалист?";
constexpr auto one_seven_1 = "10";
constexpr auto one_seven_0_1 = "5";
constexpr auto one_seven_0_2 = "5";
constexpr auto one_seven_0_3 = "5";

constexpr auto one_eight = "Клиентский пакет принимается сервером. Пакет имеет номер порта назначения 22. Какое служебное приложение запрашивает клиент?";
constexpr auto one_eight_1 = "SSH";
constexpr auto one_eight_0_1 = "HTTPS";
constexpr auto one_eight_0_2 = "TwentyTwoProtocol";

constexpr auto one_nine = "Какой командой можно посмотреть текущую конфигурацию на коммутаторе, использующем IOS";
constexpr auto one_nine_1 = "Switch# show running-config";
constexpr auto one_nine_0_1 = "Switch# printf running-config";
constexpr auto one_nine_0_2 = "Switch# display running-config";

constexpr auto one_ten = "Какой сжатый формат IPv6-адреса fe80:9ea0:0000:2020:0000:00bf:00e0:9290?";
constexpr auto one_ten_1 = "fe80:9ea0::2020:0:bf:e0:9290";
constexpr auto one_ten_0_1 = "fe80:9:20::b000:290";
constexpr auto one_ten_0_2 = "192.2020.00.9290";

//Тест 2
constexpr auto two_one = "Правда или ложь - IP-адресация работает на 7-м, самом высоком уровне модели OSI";
constexpr auto two_one_1 = "Ложь";
constexpr auto two_one_0_1 = "Правда";

constexpr auto two_two = "Какой уровень модели OSI отвечает за транспортные протоколы UDP и TCP?";
constexpr auto two_two_1 = "4-й";
constexpr auto two_two_0_1 = "1-й";
constexpr auto two_two_0_2 = "Протоколы UDP и TCP не описаны в модели OSI";

constexpr auto two_three = "На какое максимальное расстояние кабель витая пара категории 2 может передавать интернет?";
constexpr auto two_three_1 = "Витая пара категории 2 не используется для передачи интернета";
constexpr auto two_three_0_1 = "40 м";
constexpr auto two_three_0_2 = "450 м";
constexpr auto two_three_0_3 = "100 м";

constexpr auto two_four = "Сколько жил будет задействовано в витой паре Cat.5e при скорости передачи данных 1 Гб/С?";
constexpr auto two_four_1 = "8";
constexpr auto two_four_0_1 = "Витая пара - моножильный провод, экран не задействован в передаче данных";
constexpr auto two_four_0_2 = "4";
constexpr auto two_four_0_3 = "16";

constexpr auto two_five = "Клиентский пакет принимается сервером. Пакет имеет номер порта назначения 110. Какую услугу запрашивает клиент?";
constexpr auto two_five_1 = "POP3";
constexpr auto two_five_0_1 = "DHCP";
constexpr auto two_five_0_2 = "DNS";

constexpr auto two_six = "Клиентский пакет принимается сервером. Пакет имеет номер порта назначения 53. Какую услугу запрашивает клиент?";
constexpr auto two_six_1 = "DNS";
constexpr auto two_six_0_1 = "NetBIOS (NetBT)";
constexpr auto two_six_0_2 = "POP3";

constexpr auto two_seven = "Сетевой администратор добавляет новую локальную сеть в филиал. Новая локальная сеть должна поддерживать 90 подключенных устройств. Какова наименьшая сетевая маска, которую сетевой администратор может использовать для новой сети?";
constexpr auto two_seven_1 = "255.255.255.128";
constexpr auto two_seven_0_1 = "255.255.255.240";
constexpr auto two_seven_0_2 = "255.255.255.248";
constexpr auto two_seven_0_3 = "255.255.255.224";

constexpr auto two_eight = "За что отвечает 6-й уровень модели TCP/IP";
constexpr auto two_eight_1 = "Модели TCP/IP не описывает 6-й уровень";
constexpr auto two_eight_0_1 = "Представление и шифрование данных";
constexpr auto two_eight_0_2 = "Определение маршрута и логическая адресация";

constexpr auto two_nine = "Какой командой можно посмотреть текущую конфигурацию на коммутаторе, использующем IOS";
constexpr auto two_nine_1 = "Switch# show running-config";
constexpr auto two_nine_0_1 = "Switch# printf running-config";
constexpr auto two_nine_0_2 = "Switch# display running-config";

constexpr auto two_ten = "Какой сжатый формат IPv6-адреса fe80:9ea0:0000:2020:0000:00bf:00e0:9290?";
constexpr auto two_ten_1 = "fe80:9ea0::2020:0:bf:e0:9290";
constexpr auto two_ten_0_1 = "fe80:9:20::b000:290";
constexpr auto two_ten_0_2 = "192.2020.00.9290";

//Тест 3
constexpr auto three_one = "Какая комбинация префикса сети и длины префикса используется для создания статического маршрута по умолчанию, который будет соответствовать любому назначению IPv6?";
constexpr auto three_one_1 = "::/0";
constexpr auto three_one_0_1 = "FFFF:/128";
constexpr auto three_one_0_2 = ":/128";
constexpr auto three_one_0_3 = "::1/64";

constexpr auto three_two = "Какой уровень модели OSI отвечает за транспортные протоколы UDP и TCP?";
constexpr auto three_two_1 = "4-й";
constexpr auto three_two_0_1 = "1-й";
constexpr auto three_two_0_2 = "Протоколы UDP и TCP не описаны в модели OSI";

constexpr auto three_three = "Какой маршрут будет использовать маршрутизатор для пересылки пакета IPv4 после проверки своей таблицы маршрутизации на предмет наилучшего совпадения с адресом назначения?";
constexpr auto three_three_1 = "A level 1 ultimate route";
constexpr auto three_three_0_1 = "A level 1 child route";
constexpr auto three_three_0_2 = "A level 2 supernet route";

constexpr auto three_four = "Сетевой администратор разрабатывает ACL. ACL затрагивает сети 192.168.1.0/25, 192.168.0.0/25, 192.168.0.128/25, 192.168.1.128/26 и 192.168.1.192/26. Какая подстановочная маска, если таковая имеется, наиболее эффективна при указании всех этих сетей в одной записи разрешения ACL?";
constexpr auto three_four_1 = "0.0.1.255";
constexpr auto three_four_0_1 = "0.0.0.127";
constexpr auto three_four_0_2 = "0.0.255.255";

constexpr auto three_five = "Какой командой можно узнать как настроен файл текущей загрузки IOS?";
constexpr auto three_five_1 = "S1(config)#show boot";
constexpr auto three_five_0_1 = "S1#show boot";
constexpr auto three_five_0_2 = "S1(config)#show config-file-ios";

constexpr auto three_six = "Какой тип трафика, скорее всего, будет иметь проблемы при прохождении через устройство NAT?";
constexpr auto three_six_1 = "IPsec";
constexpr auto three_six_0_1 = "Telnet";
constexpr auto three_six_0_2 = "HTTP";
constexpr auto three_six_0_3 = "DNS";

constexpr auto three_seven = "Какой командой можно изучить содержимое флеш-каталога на коммутаторе, использующим IOS??";
constexpr auto three_seven_1 = "Switch# show flash";
constexpr auto three_seven_0_1 = "Switch# show flash-congif-boot";
constexpr auto three_seven_0_2 = "Switch# show flash-congif-files";

constexpr auto three_eight = "Каким набором команд можно настроить режим скорости и дуплекса на коммутаторе, использующим IOS?";
constexpr auto three_eight_1 = "S1# configure terminal -> S1(config)#interface FastEthernet 0/1 -> S1(config-if)#duplex full -> S1(config-if)#speed 100 -> S1(config-if)#end";
constexpr auto three_eight_0_1 = "S1# configure terminal -> S1(config)#interface FastEthernet 0/1 -> S1(config-if)#duplex full speef full -> S1(config-if)#end";
constexpr auto three_eight_0_2 = "S1#interface FastEthernet 0/1 -> S1#duplex full -> S1#speed 100 -> S1#end";

constexpr auto three_nine = "Какой командой можно посмотреть текущую конфигурацию на коммутаторе, использующем IOS";
constexpr auto three_nine_1 = "Switch# show running-config";
constexpr auto three_nine_0_1 = "Switch# printf running-config";
constexpr auto three_nine_0_2 = "Switch# display running-config";

constexpr auto three_ten = "Какой сжатый формат IPv6-адреса fe80:9ea0:0000:2020:0000:00bf:00e0:9290?";
constexpr auto three_ten_1 = "fe80:9ea0::2020:0:bf:e0:9290";
constexpr auto three_ten_0_1 = "fe80:9:20::b000:290";
constexpr auto three_ten_0_2 = "192.2020.00.9290";
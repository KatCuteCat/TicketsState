Программу реализует паттерн проектирования "Состояние" на примере работы автомата по продаже билетов, который может находиться в различных состояниях: без денег, деньги вставлены, билет выдан. Паттерн "Состояние" позволяет объекту изменять свое поведение в зависимости от внутреннего состояния.
Программа состоит из двух файлов: заголовочного файла для объявления классов и интерфейсов и cpp файла для их реализации. Каждый раз при изменении состояния должен создаваться новый экземпляр соответствующего состояния, а предыдущий экземпляр должен удаляться.

    Класс TicketMachine
Этот класс является контекстом, который изменяет свое поведение в зависимости от текущего состояния. 

    Интерфейс State
Это абстрактный интерфейс, который определяет методы, необходимые для всех состояний автомата. Методы включают insertMoney, ejectMoney, pressButton и issueTicket.

    Остальные состояния реализуют интерфейс State для более конкретных состояний.
Например:
NoMoneyState: Реализует поведение, когда в автомате нет денег. При вставке денег состояние изменяется на MoneyInsertedState.
MoneyInsertedState: Реализует поведение, когда деньги вставлены. При нажатии кнопки состояние изменяется на TicketIssuedState.
TicketIssuedState: Реализует поведение, когда билет выдан. Автомат возвращается в состояние NoMoneyState.
